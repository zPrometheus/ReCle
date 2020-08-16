#include "PlaylistContainer.h"
#include "ui_playlistcontainer.h"

#include <qlabel.h>

PlaylistContainer::PlaylistContainer(QWidget* parent)
	:QWidget(parent),mUndo(nullptr),mRedo(nullptr),
	mNoMatchesLabel(nullptr),
	ui(new Ui_playlistcontainer)
{
	ui->setupUi(this);
	mNoMatchesLabel = new QLabel(ui->playlist);
	mNoMatchesLabel->setAttribute(Qt::WA_TransparentForMouseEvents);//
	mNoMatchesLabel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	mNoMatchesLabel->setText("avd");
	
	QPalette NoMatcherPalette = mNoMatchesLabel->palette();
	const QColor NoMatcherColor = NoMatcherPalette.color(QPalette::Disabled, QPalette::Text);
	NoMatcherPalette.setColor(QPalette::Normal, QPalette::WindowText,
		NoMatcherColor);
	NoMatcherPalette.setColor(QPalette::Inactive, QPalette::WindowText,
		NoMatcherColor);
	mNoMatchesLabel->setPalette(NoMatcherPalette);

	ui->toolbar->setStyleSheet("QFrame {border:0px;}");
}


PlaylistContainer::~PlaylistContainer()
{


}
