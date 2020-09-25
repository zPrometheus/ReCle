#pragma once
#include <qwidget.h>

#include <QWidget>
#include <QPointer>

class SearchFieldPrivate;
class SearchField : public QWidget
{
	Q_OBJECT
public:
	explicit SearchField(QWidget *parent);
	~SearchField();

	QString text() const;
	QString placeholderText() const;
	//void setFocus(Qt::FocusReason reason);

	public slots:
	void setText(const QString &text);
	void setPlaceholderText(const QString &text);
	void clear();
	//void selectAll();
	//void setFocus();

signals:
	void textChanged(const QString &text);
	void editingFinished();
	void returnPressed();

protected:
	void resizeEvent(QResizeEvent*);
	bool eventFilter(QObject*, QEvent*);

private:
	friend class SearchFieldPrivate;
	QPointer <SearchFieldPrivate> pimpl;

	Q_PROPERTY(
		QString placeholderText READ placeholderText WRITE setPlaceholderText)
};


