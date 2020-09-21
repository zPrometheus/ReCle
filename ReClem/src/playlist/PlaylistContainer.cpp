#include "PlaylistContainer.h"
#include "ui_playlistcontainer.h"
#include "core/Appearance.h"
#include "core/Application.h"
#include "playlist/PlaylistManager.h"

#include <qlabel.h>
#include <qsettings.h>
#include <qtimeline.h>
#include <qtimer.h>
#include <qobject.h>
const char* PlaylistContainer::kSettingsGroup = "playlist";
const int PlaylistContainer::kFilterDelayMs = 100;

PlaylistContainer::PlaylistContainer(QWidget* parent)
	:QWidget(parent),mUndo(nullptr),mRedo(nullptr),
	mNoMatchesLabel(nullptr),mDirty(false),mTabBarAnimation(new QTimeLine(500,this)),
	mFilterTimer(new QTimer(this)),
	mManager(nullptr),
	ui(new Ui_playlistcontainer)
{
	ui->setupUi(this);
	mNoMatchesLabel = new QLabel(ui->playlist);
	mNoMatchesLabel->setAttribute(Qt::WA_TransparentForMouseEvents);//
	mNoMatchesLabel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	mNoMatchesLabel->setText("no matches label is here");
	
	QPalette NoMatcherPalette = mNoMatchesLabel->palette();
	const QColor NoMatcherColor = NoMatcherPalette.color(QPalette::Disabled, QPalette::Text);
	NoMatcherPalette.setColor(QPalette::Normal, QPalette::WindowText,
		NoMatcherColor);
	NoMatcherPalette.setColor(QPalette::Inactive, QPalette::WindowText,
		NoMatcherColor);
	mNoMatchesLabel->setPalette(NoMatcherPalette);

	ui->toolbar->setStyleSheet("QFrame {border:0px;}");

	QSettings settings;
	settings.beginGroup(Appearance::kSettingsGroup);
	bool hide_toolbar = settings.value("b_hide_filter_toolbar", false).toBool();
	ui->toolbar->setVisible(!hide_toolbar);

	QFont NoMatchesFont = mNoMatchesLabel->font();
	NoMatchesFont.setBold(true);
	mNoMatchesLabel->setFont(NoMatchesFont);

	ui->tab_bar->setExpanding(false);
	ui->tab_bar->setMovable(true);

	connect(mTabBarAnimation, SIGNAL(frameChanged(int)), SLOT(SetTabBarHeight(int)));
	ui->tab_bar->setMaximumHeight(0);

	// Connections
	connect(ui->tab_bar, SIGNAL(currentChanged(int)), SLOT(DirtyTabBar()));
	connect(ui->tab_bar, SIGNAL(Save(int)), SLOT(SavePlaylist(int)));

	mFilterTimer->setSingleShot(true);
	mFilterTimer->setInterval(kFilterDelayMs);
	connect(mFilterTimer, SIGNAL(timeout()), this, SLOT(UpdateFilter()));

	connect(ui->filter, SIGNAL(textChanged(QString)), SLOT(MaybeUpdateFilter()));
	connect(ui->playlist, SIGNAL(FocusOnFilterSignal(QKeyEvent*)),
		SLOT(FocusOnFilter(QKeyEvent*)));

	ui->filter->installEventFilter(this);

}

PlaylistView* PlaylistContainer::view() const{
	return ui->playlist;
}


void PlaylistContainer::setViewModel(Playlist* playlist)
{
	mPlist = playlist;

	playlist->IgnoreSorting(true);  //?
	view()->setModel(playlist->proxy()); //m
	view()->SetPlaylist(playlist);

	view()->selectionModel()->select(mManager->current_selection(),
		QItemSelectionModel::ClearAndSelect);
	playlist->IgnoreSorting(false);

	connect(view()->selectionModel(),
		SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this,
		SLOT(SelectionChanged()));
	emit ViewSelectionModelChanged();
}

void PlaylistContainer::SelectionChanged() {
	mManager->SelectionChanged(view()->selectionModel()->selection());
}


void PlaylistContainer::UpdateFilter()
{
	

}

void PlaylistContainer::Save(QSettings* settings) {
  if (mStartingUp || !mDirty) return;
  mDirty = false;

  settings->beginGroup(kSettingsGroup);
  settings->setValue("current_playlist", ui->tab_bar->current_id());
  settings->endGroup();
}

void PlaylistContainer::SetTabBarHeight(int height)
{
	ui->tab_bar->setMaximumHeight(height);
}

void PlaylistContainer::DirtyTabBar() {
	mDirty = true;
	mApp->DirtySettings();
}

PlaylistContainer::~PlaylistContainer()
{


}
