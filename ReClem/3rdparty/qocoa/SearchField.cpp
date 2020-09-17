#include "SearchField.h"
#include <qlineedit.h>
#include <qtoolbutton.h>
#include <qstyle.h>
#include <qpointer.h>
#include "ui/IconLoader.h"
#include <qlayout.h>

class SearchFieldPrivate : public QObject
{
public:
	SearchFieldPrivate(SearchField *searchField, QLineEdit *lineEdit, QToolButton *clearButton)
		: QObject(searchField), lineEdit(lineEdit), clearButton(clearButton) {}
	int lineEditFrameWidth() const {
		return lineEdit->style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
	}
	int clearButtonPaddedWidth() const {
		return clearButton->width() + lineEditFrameWidth() * 2;
	}
	int clearButtonPaddedHeight() const {
		return clearButton->height() + lineEditFrameWidth() * 2;
	}
	QPointer<QLineEdit> lineEdit;
	QPointer<QToolButton> clearButton;
};

SearchField::SearchField(QWidget *parent) : QWidget(parent)
{
	QLineEdit *lineEdit = new QLineEdit(this);
	connect(lineEdit, SIGNAL(textChanged(QString)),
		this, SIGNAL(textChanged(QString)));
	connect(lineEdit, SIGNAL(editingFinished()),
		this, SIGNAL(editingFinished()));
	connect(lineEdit, SIGNAL(returnPressed()),
		this, SIGNAL(returnPressed()));
	connect(lineEdit, SIGNAL(textChanged(QString)),
		this, SLOT(setText(QString)));

	QIcon clearIcon(IconLoader::Load("edit-clear-locationbar-ltr", IconLoader::Base));

	QToolButton *clearButton = new QToolButton(this);
	clearButton->setIcon(clearIcon);
	clearButton->setIconSize(QSize(16, 16));
	clearButton->setStyleSheet("border: none; padding: 0px;");
	clearButton->resize(clearButton->sizeHint());
	connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));

	pimpl = new SearchFieldPrivate(this, lineEdit, clearButton);

	const int frame_width = lineEdit->style()->pixelMetric(QStyle::PM_DefaultFrameWidth);

	lineEdit->setStyleSheet(QString("QLineEdit { padding-left: %1px; } ").arg(clearButton->width()));
	const int width = frame_width + qMax(lineEdit->minimumSizeHint().width(), pimpl->clearButtonPaddedWidth());
	const int height = frame_width + qMax(lineEdit->minimumSizeHint().height(), pimpl->clearButtonPaddedHeight());
	lineEdit->setMinimumSize(width, height);

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setMargin(0);
	layout->addWidget(lineEdit);

	lineEdit->installEventFilter(this);
}

QString SearchField::placeholderText() const {
#if QT_VERSION >= 0x040700
	return pimpl->lineEdit->placeholderText();
#else
	return QString();
#endif
}

void SearchField::setPlaceholderText(const QString &text)
{
	Q_ASSERT(pimpl && pimpl->lineEdit);
	if (!(pimpl && pimpl->lineEdit))
		return;

#if QT_VERSION >= 0x040700
	pimpl->lineEdit->setPlaceholderText(text);
#endif
}

QString SearchField::text() const
{
	Q_ASSERT(pimpl && pimpl->lineEdit);
	if (!(pimpl && pimpl->lineEdit))
		return QString();

	return pimpl->lineEdit->text();
}


SearchField::~SearchField()
{
}
