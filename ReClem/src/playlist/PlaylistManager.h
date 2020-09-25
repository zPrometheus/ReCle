#pragma once
#include <qobject.h>
#include <qitemselectionmodel.h>
#include "core/Song.h"
#include "playlist/Playlist.h"

class Application;
class Playlist;
class PlaylistContainer;


class PlaylistManagerInterface : public QObject {
	Q_OBJECT

public:
	PlaylistManagerInterface(Application* app, QObject* parent)
		: QObject(parent) {}

	virtual int current_id() const = 0;
	virtual int active_id() const = 0;

	virtual Playlist* playlist(int id) const = 0;
	virtual Playlist* current() const = 0;
	virtual Playlist* active() const = 0;

	// Returns the collection of playlists managed by this PlaylistManager.
	virtual QList<Playlist*> GetAllPlaylists() const = 0;
	// Grays out and reloads all deleted songs in all playlists.
	virtual void InvalidateDeletedSongs() = 0;
	// Removes all deleted songs from all playlists.
	virtual void RemoveDeletedSongs() = 0;

	virtual QItemSelection selection(int id) const = 0;
	virtual QItemSelection current_selection() const = 0;
	virtual QItemSelection active_selection() const = 0;

	virtual QString GetPlaylistName(int index) const = 0;

	//virtual LibraryBackend* library_backend() const = 0;
	//virtual PlaylistBackend* playlist_backend() const = 0;
	//virtual PlaylistSequence* sequence() const = 0;
	//virtual PlaylistParser* parser() const = 0;
	virtual PlaylistContainer* playlist_container() const = 0;

	public slots:
	virtual void New(const QString& name, const SongList& songs = SongList(),
		const QString& special_type = QString()) = 0;
	virtual void Load(const QString& filename) = 0;
	virtual void Save(int id, const QString& filename,
		Playlist::Path path_type) = 0;
	virtual void Rename(int id, const QString& new_name) = 0;
	virtual void Delete(int id) = 0;
	virtual bool Close(int id) = 0;
	virtual void Open(int id) = 0;
	virtual void ChangePlaylistOrder(const QList<int>& ids) = 0;

	virtual void Enque(int id, int index) = 0;

	virtual void SongChangeRequestProcessed(const QUrl& url, bool valid) = 0;

	virtual void SetCurrentPlaylist(int id) = 0;
	virtual void SetActivePlaylist(int id) = 0;
	virtual void SetActiveToCurrent() = 0;

	virtual void SelectionChanged(const QItemSelection& selection) = 0;

	// Convenience slots that defer to either current() or active()
	virtual void ClearCurrent() = 0;
	virtual void ShuffleCurrent() = 0;
	virtual void RemoveDuplicatesCurrent() = 0;
	virtual void RemoveUnavailableCurrent() = 0;
	virtual void SetActivePlaying() = 0;
	virtual void SetActivePaused() = 0;
	virtual void SetActiveStopped() = 0;
//	virtual void SetActiveStreamMetadata(const QUrl& url, const Song& song) = 0;
	// Rate current song using 0.0 - 1.0 scale.
	virtual void RateCurrentSong(double rating) = 0;
	// Rate current song using 0 - 5 scale.
	virtual void RateCurrentSong(int rating) = 0;

//	virtual void PlaySmartPlaylist(smart_playlists::GeneratorPtr generator,
//		bool as_new, bool clear) = 0;

signals:
	void PlaylistManagerInitialized();

	void PlaylistAdded(int id, const QString& name, bool favorite);
	void PlaylistDeleted(int id);
	void PlaylistClosed(int id);
	void PlaylistRenamed(int id, const QString& new_name);
	void PlaylistFavorited(int id, bool favorite);
	void CurrentChanged(Playlist* new_playlist);
	void ActiveChanged(Playlist* new_playlist);

	void Error(const QString& message);
	void SummaryTextChanged(const QString& summary);

	// Forwarded from individual playlists
//	void CurrentSongChanged(const Song& song);

	// Signals that one of manager's playlists has changed (new items, new
	// ordering etc.) - the argument shows which.
	void PlaylistChanged(Playlist* playlist);
	void EditingFinished(const QModelIndex& index);
	void PlayRequested(const QModelIndex& index);
};


class PlaylistManager : public PlaylistManagerInterface
{
public:
	PlaylistManager(Application* app,QObject* parent);
	~PlaylistManager();
	int current_id() const { return current_; }
	QItemSelection current_selection() const { return selection(current_id()); }
	void SelectionChanged(const QItemSelection& selection);
	void PlaylistManager::UpdateSummaryText();

	public slots:
private:
	struct Data {
		Data(Playlist* _p = nullptr, const QString& _name = QString())
			: p(_p), name(_name) {}
		Playlist* p;
		QString name;
		QItemSelection selection;
	};

	int current_;
	QMap<int, Data> playlists_;


};

