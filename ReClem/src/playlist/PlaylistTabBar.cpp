#include "PlaylistTabBar.h"
#include <qvariant.h>


PlaylistTabBar::PlaylistTabBar(QWidget* parent)
{

}

int PlaylistTabBar::current_id() const {
	if (currentIndex() == -1) return -1;
	return tabData(currentIndex()).toInt();
}

void PlaylistTabBar::set_current_id(int id) { setCurrentIndex(index_of(id)); }

int PlaylistTabBar::index_of(int id) const {
	for (int i = 0; i < count(); ++i) {
		if (tabData(i).toInt() == id) {
			return i;
		}
	}
	return -1;

}

PlaylistTabBar::~PlaylistTabBar()
{

}
