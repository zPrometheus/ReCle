#include "PlaylistTabBar.h"
#include <qvariant.h>


PlaylistTabBar::PlaylistTabBar(QWidget* parent)
{

}

int PlaylistTabBar::current_id() const {
	if (currentIndex() == -1) return -1;
	return tabData(currentIndex()).toInt();
}

PlaylistTabBar::~PlaylistTabBar()
{

}
