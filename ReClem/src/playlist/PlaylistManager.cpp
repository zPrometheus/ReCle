#include "PlaylistManager.h"



PlaylistManager::PlaylistManager(Application* app,QObject* parent)
	:PlaylistManagerInterface(app,parent)
{



}

void PlaylistManager::SelectionChanged(const QItemSelection& selection) {
	playlists_[current_id()].selection = selection;
	UpdateSummaryText();
}

void PlaylistManager::UpdateSummaryText() {
	int tracks = current()->rowCount();
	quint64 nanoseconds = 0;
	int selected = 0;

	// Get the length of the selected tracks
	for (const QItemSelectionRange& range : playlists_[current_id()].selection) {
		if (!range.isValid()) continue;

		selected += range.bottom() - range.top() + 1;
		for (int i = range.top(); i <= range.bottom(); ++i) {
			qint64 length =
				range.model()->index(i, Playlist::Column_Length).data().toLongLong();
			if (length > 0) nanoseconds += length;
		}
	}

	//to be continuted

}

PlaylistManager::~PlaylistManager()
{


}


