#pragma once
#include <qlist.h>
#include <qmetatype.h>

class Song
{


public:
	Song();
	~Song();


	
};
//Q_DECLARE_METATYPE(Song)
typedef QList<Song> SongList;
Q_DECLARE_METATYPE(QList<Song>)

