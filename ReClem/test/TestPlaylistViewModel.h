#pragma once
#include <QAbstractItemModel>

class TestPlaylistViewModel:public QAbstractListModel
{
public:
	TestPlaylistViewModel(QObject* parent = nullptr);
	~TestPlaylistViewModel();
};

