#include "Playlist.h"
#include <qsortfilterproxymodel.h>

const char* Playlist::kSettingsGroup = "Playlist";
Playlist::Playlist(QObject* parent)
	:QAbstractListModel(parent)
{


}
QSortFilterProxyModel* Playlist::proxy() const { return mProxy; }

Playlist::~Playlist()
{
}
