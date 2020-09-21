#include "PlaylistManager.h"



PlaylistManager::PlaylistManager(Application* app,QObject* parent)
	:PlaylistManagerInterface(app,parent)
{



}

void PlaylistManager::SelectionChanged(const QItemSelection& selection) {
	playlists_[current_id()].selection = selection;
	UpdateSummaryText();
}

PlaylistManager::~PlaylistManager()
{
}
