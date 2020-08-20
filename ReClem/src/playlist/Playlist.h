#pragma once
#include "qabstractitemmodel.h"
class Playlist :
	public QAbstractListModel
{
	Q_OBJECT

public:
	Playlist();
	~Playlist();
};

