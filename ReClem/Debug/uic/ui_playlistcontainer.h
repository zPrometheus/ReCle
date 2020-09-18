/********************************************************************************
** Form generated from reading UI file 'playlistcontainer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTCONTAINER_H
#define UI_PLAYLISTCONTAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "playlist/PlaylistTabBar.h"
#include "playlist/PlaylistView.h"
#include "qocoa/SearchField.h"

QT_BEGIN_NAMESPACE

class Ui_playlistcontainer
{
public:
    PlaylistView *playlist;
    QFrame *toolbar;
    QToolButton *create_new;
    QToolButton *load;
    QToolButton *save;
    QToolButton *undo;
    QToolButton *redo;
    SearchField *filter;
    PlaylistTabBar *tab_bar;

    void setupUi(QWidget *playlistcontainer)
    {
        if (playlistcontainer->objectName().isEmpty())
            playlistcontainer->setObjectName(QStringLiteral("playlistcontainer"));
        playlistcontainer->resize(960, 844);
        playlist = new PlaylistView(playlistcontainer);
        playlist->setObjectName(QStringLiteral("playlist"));
        playlist->setGeometry(QRect(-10, 30, 961, 741));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(playlist->sizePolicy().hasHeightForWidth());
        playlist->setSizePolicy(sizePolicy);
        toolbar = new QFrame(playlistcontainer);
        toolbar->setObjectName(QStringLiteral("toolbar"));
        toolbar->setGeometry(QRect(0, 10, 951, 22));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolbar->sizePolicy().hasHeightForWidth());
        toolbar->setSizePolicy(sizePolicy1);
        toolbar->setFocusPolicy(Qt::StrongFocus);
        toolbar->setFrameShape(QFrame::StyledPanel);
        toolbar->setFrameShadow(QFrame::Sunken);
        create_new = new QToolButton(toolbar);
        create_new->setObjectName(QStringLiteral("create_new"));
        create_new->setGeometry(QRect(0, 0, 23, 22));
        load = new QToolButton(toolbar);
        load->setObjectName(QStringLiteral("load"));
        load->setGeometry(QRect(20, 0, 23, 22));
        save = new QToolButton(toolbar);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(40, 0, 23, 22));
        undo = new QToolButton(toolbar);
        undo->setObjectName(QStringLiteral("undo"));
        undo->setGeometry(QRect(60, 0, 23, 22));
        redo = new QToolButton(toolbar);
        redo->setObjectName(QStringLiteral("redo"));
        redo->setGeometry(QRect(80, 0, 23, 22));
        filter = new SearchField(toolbar);
        filter->setObjectName(QStringLiteral("filter"));
        filter->setGeometry(QRect(100, 0, 851, 22));
        tab_bar = new PlaylistTabBar(playlistcontainer);
        tab_bar->setObjectName(QStringLiteral("tab_bar"));
        tab_bar->setGeometry(QRect(0, 0, 951, 10));

        retranslateUi(playlistcontainer);

        QMetaObject::connectSlotsByName(playlistcontainer);
    } // setupUi

    void retranslateUi(QWidget *playlistcontainer)
    {
        playlistcontainer->setWindowTitle(QApplication::translate("playlistcontainer", "Form", nullptr));
        create_new->setText(QApplication::translate("playlistcontainer", "...", nullptr));
        load->setText(QApplication::translate("playlistcontainer", "...", nullptr));
        save->setText(QApplication::translate("playlistcontainer", "...", nullptr));
        undo->setText(QApplication::translate("playlistcontainer", "...", nullptr));
        redo->setText(QApplication::translate("playlistcontainer", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playlistcontainer: public Ui_playlistcontainer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTCONTAINER_H
