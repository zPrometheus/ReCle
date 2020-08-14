#pragma once
#include <QWidget>

class PlaylistContainer :public QWidget
{
	Q_OBJECT
public:
	PlaylistContainer(QWidget* parent = nullptr);
	
	~PlaylistContainer();
};

