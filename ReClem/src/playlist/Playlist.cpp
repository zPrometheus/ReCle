#include "Playlist.h"
#include <qsortfilterproxymodel.h>

const char* Playlist::kSettingsGroup = "Playlist";
Playlist::Playlist(QObject* parent)
	:QAbstractListModel(parent),
	mProxy(new PlaylistFilter(this))
{
	mProxy->setSourceModel(this);

}
QSortFilterProxyModel* Playlist::proxy() const { return mProxy; }

Playlist::~Playlist()
{
}
