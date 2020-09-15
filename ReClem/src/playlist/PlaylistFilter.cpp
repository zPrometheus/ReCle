#include "PlaylistFilter.h"
//#include <qabstractitemmodel.h>
#include "playlist/PlaylistFilterParser.h"
#include "Playlist.h"

PlaylistFilter::PlaylistFilter(QObject* parent)
	:QSortFilterProxyModel(parent),
	mFilterTree(new NopFilter),
	mQueryHash(0)
{
	setDynamicSortFilter(true);
	mColumnNames["title"] = Playlist::Column_Title;
	mColumnNames["name"] = Playlist::Column_Title;
	mColumnNames["artist"] = Playlist::Column_Artist;
	mColumnNames["album"] = Playlist::Column_Album;
	mColumnNames["albumartist"] = Playlist::Column_AlbumArtist;
	mColumnNames["composer"] = Playlist::Column_Composer;
	mColumnNames["performer"] = Playlist::Column_Performer;
	mColumnNames["grouping"] = Playlist::Column_Grouping;
	mColumnNames["length"] = Playlist::Column_Length;
	mColumnNames["track"] = Playlist::Column_Track;
	mColumnNames["disc"] = Playlist::Column_Disc;
	mColumnNames["year"] = Playlist::Column_Year;
	mColumnNames["originalyear"] = Playlist::Column_OriginalYear;
	mColumnNames["genre"] = Playlist::Column_Genre;
	mColumnNames["score"] = Playlist::Column_Score;
	mColumnNames["comment"] = Playlist::Column_Comment;
	mColumnNames["bpm"] = Playlist::Column_BPM;
	mColumnNames["bitrate"] = Playlist::Column_Bitrate;
	mColumnNames["filename"] = Playlist::Column_Filename;
	mColumnNames["rating"] = Playlist::Column_Rating;

	mNumericalColumns << Playlist::Column_Length << Playlist::Column_Track
		<< Playlist::Column_Disc << Playlist::Column_Year
		<< Playlist::Column_OriginalYear << Playlist::Column_Score
		<< Playlist::Column_BPM << Playlist::Column_Bitrate
		<< Playlist::Column_Rating;
}

// QAbstractItemModel
void PlaylistFilter::sort(int column, Qt::SortOrder order)
{
	sourceModel()->sort(column, order);
}

PlaylistFilter::~PlaylistFilter()
{


}

bool PlaylistFilter::filterAcceptsRow(int row,
	const QModelIndex& parent) const {
	QString filter = filterRegExp().pattern();

	uint hash = qHash(filter);
	if (hash != mQueryHash) {
		// Parse the query
		FilterParser p(filter, mColumnNames, mNumericalColumns);
		mFilterTree.reset(p.parse());

		mQueryHash = hash;
	}

	// Test the row
	return mFilterTree->accept(row, parent, sourceModel());
}
