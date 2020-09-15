#pragma once
#include <qabstractitemmodel.h>
#include <playlist/PlaylistFilter.h>

class PlaylistFilter;
class QSortFilterProxyModel;

typedef QMap<int, Qt::Alignment> ColumnAlignmentMap;

class Playlist :
	public QAbstractListModel
{
	Q_OBJECT

public:
	Playlist(QObject* parent);
	~Playlist();

	enum Column {
		Column_Title = 0,
		Column_Artist,
		Column_Album,
		Column_AlbumArtist,
		Column_Composer,
		Column_Length,
		Column_Track,
		Column_Disc,
		Column_Year,
		Column_Genre,
		Column_BPM,
		Column_Bitrate,
		Column_Samplerate,
		Column_Filename,
		Column_BaseFilename,
		Column_Filesize,
		Column_Filetype,
		Column_DateCreated,
		Column_DateModified,
		Column_Rating,
		Column_PlayCount,
		Column_SkipCount,
		Column_LastPlayed,
		Column_Score,
		Column_Comment,
		Column_Source,
		Column_Mood,
		Column_Performer,
		Column_Grouping,
		Column_OriginalYear,
		ColumnCount
	};

	static const char* kSettingsGroup;

	QSortFilterProxyModel* Playlist::proxy() const;

private:
	PlaylistFilter* mProxy;
};

