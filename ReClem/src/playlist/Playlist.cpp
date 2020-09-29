#include "Playlist.h"
#include <qsortfilterproxymodel.h>
#include "core/Song.h"


const char* Playlist::kSettingsGroup = "Playlist";
Playlist::Playlist(QObject* parent)
	:QAbstractListModel(parent),
	mProxy(new PlaylistFilter(this))
{
	mProxy->setSourceModel(this);

}
QSortFilterProxyModel* Playlist::proxy() const { return mProxy; }

SongList Playlist::GetAllSongs() const {
	SongList ret;
	for (PlaylistItemPtr item : items_) {
		ret << item->Metadata();
	}
	return ret;
}

Playlist::~Playlist()
{
}
