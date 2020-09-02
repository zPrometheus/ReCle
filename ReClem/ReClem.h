#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ReClem.h"
#include "playlist/PlaylistContainer.h"

class ReClem : public QMainWindow
{
    Q_OBJECT

public:
    ReClem(QWidget *parent = Q_NULLPTR);

private:
    Ui_ReClemClass* ui;
    PlaylistContainer* mPlaylist;


};
