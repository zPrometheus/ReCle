#include "Playlist.h"


const char* Playlist::kSettingsGroup = "Playlist";
Playlist::Playlist(QObject* parent)
	:QAbstractListModel(parent)
{


}


Playlist::~Playlist()
{
}
