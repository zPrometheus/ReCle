/********************************************************************************
** Form generated from reading UI file 'ReClem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECLEM_H
#define UI_RECLEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "playlist/PlaylistContainer.h"

QT_BEGIN_NAMESPACE

class Ui_ReClemClass
{
public:
    QWidget *centralWidget;
    QWidget *player_controls_container;
    QWidget *status_bar;
    QFrame *player_controls;
    QToolButton *clear_playlist_button;
    QFrame *line;
    QToolButton *back_button;
    QToolButton *pause_play_button;
    QToolButton *stop_button;
    QToolButton *forward_button;
    QToolButton *love_button;
    QFrame *line_2;
    QWidget *analyzer;
    PlaylistContainer *playlist;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ReClemClass)
    {
        if (ReClemClass->objectName().isEmpty())
            ReClemClass->setObjectName(QStringLiteral("ReClemClass"));
        ReClemClass->resize(1013, 658);
        centralWidget = new QWidget(ReClemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        player_controls_container = new QWidget(centralWidget);
        player_controls_container->setObjectName(QStringLiteral("player_controls_container"));
        player_controls_container->setGeometry(QRect(-1, 529, 1011, 51));
        status_bar = new QWidget(player_controls_container);
        status_bar->setObjectName(QStringLiteral("status_bar"));
        status_bar->setGeometry(QRect(0, 30, 1011, 21));
        player_controls = new QFrame(player_controls_container);
        player_controls->setObjectName(QStringLiteral("player_controls"));
        player_controls->setGeometry(QRect(0, 0, 1011, 31));
        player_controls->setFrameShape(QFrame::StyledPanel);
        player_controls->setFrameShadow(QFrame::Raised);
        clear_playlist_button = new QToolButton(player_controls);
        clear_playlist_button->setObjectName(QStringLiteral("clear_playlist_button"));
        clear_playlist_button->setGeometry(QRect(0, 0, 31, 31));
        line = new QFrame(player_controls);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 0, 16, 31));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        back_button = new QToolButton(player_controls);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(30, 0, 31, 31));
        pause_play_button = new QToolButton(player_controls);
        pause_play_button->setObjectName(QStringLiteral("pause_play_button"));
        pause_play_button->setGeometry(QRect(60, 0, 31, 31));
        stop_button = new QToolButton(player_controls);
        stop_button->setObjectName(QStringLiteral("stop_button"));
        stop_button->setGeometry(QRect(90, 0, 41, 31));
        forward_button = new QToolButton(player_controls);
        forward_button->setObjectName(QStringLiteral("forward_button"));
        forward_button->setGeometry(QRect(130, 0, 31, 31));
        love_button = new QToolButton(player_controls);
        love_button->setObjectName(QStringLiteral("love_button"));
        love_button->setGeometry(QRect(160, 0, 31, 31));
        line_2 = new QFrame(player_controls);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(180, 0, 16, 31));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        analyzer = new QWidget(player_controls);
        analyzer->setObjectName(QStringLiteral("analyzer"));
        analyzer->setGeometry(QRect(190, 0, 681, 31));
        playlist = new PlaylistContainer(centralWidget);
        playlist->setObjectName(QStringLiteral("playlist"));
        playlist->setGeometry(QRect(-1, 0, 1011, 531));
        ReClemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ReClemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1013, 26));
        ReClemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ReClemClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ReClemClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ReClemClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ReClemClass->setStatusBar(statusBar);

        retranslateUi(ReClemClass);

        QMetaObject::connectSlotsByName(ReClemClass);
    } // setupUi

    void retranslateUi(QMainWindow *ReClemClass)
    {
        ReClemClass->setWindowTitle(QApplication::translate("ReClemClass", "ReClem", nullptr));
        clear_playlist_button->setText(QApplication::translate("ReClemClass", "...", nullptr));
        back_button->setText(QApplication::translate("ReClemClass", "...", nullptr));
        pause_play_button->setText(QApplication::translate("ReClemClass", "...", nullptr));
        stop_button->setText(QApplication::translate("ReClemClass", "...", nullptr));
        forward_button->setText(QApplication::translate("ReClemClass", "...", nullptr));
        love_button->setText(QApplication::translate("ReClemClass", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReClemClass: public Ui_ReClemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECLEM_H
