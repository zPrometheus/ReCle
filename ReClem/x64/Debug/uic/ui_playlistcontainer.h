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

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    PlaylistView *playlist;
    QFrame *toolbar;
    QToolButton *create_new;
    QToolButton *load;
    QToolButton *save;
    QToolButton *undo;
    QToolButton *redo;
    PlaylistTabBar *tab_bar;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(959, 616);
        playlist = new PlaylistView(Form);
        playlist->setObjectName(QStringLiteral("playlist"));
        playlist->setGeometry(QRect(-10, 40, 961, 731));
        toolbar = new QFrame(Form);
        toolbar->setObjectName(QStringLiteral("toolbar"));
        toolbar->setGeometry(QRect(-10, 10, 961, 31));
        toolbar->setFrameShape(QFrame::StyledPanel);
        toolbar->setFrameShadow(QFrame::Raised);
        create_new = new QToolButton(toolbar);
        create_new->setObjectName(QStringLiteral("create_new"));
        create_new->setGeometry(QRect(10, 0, 31, 31));
        load = new QToolButton(toolbar);
        load->setObjectName(QStringLiteral("load"));
        load->setGeometry(QRect(40, 0, 31, 31));
        save = new QToolButton(toolbar);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(70, 0, 31, 31));
        undo = new QToolButton(toolbar);
        undo->setObjectName(QStringLiteral("undo"));
        undo->setGeometry(QRect(100, 0, 31, 31));
        redo = new QToolButton(toolbar);
        redo->setObjectName(QStringLiteral("redo"));
        redo->setGeometry(QRect(130, 0, 31, 31));
        tab_bar = new PlaylistTabBar(Form);
        tab_bar->setObjectName(QStringLiteral("tab_bar"));
        tab_bar->setGeometry(QRect(0, 0, 991, 16));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        create_new->setText(QApplication::translate("Form", "...", nullptr));
        load->setText(QApplication::translate("Form", "...", nullptr));
        save->setText(QApplication::translate("Form", "...", nullptr));
        undo->setText(QApplication::translate("Form", "...", nullptr));
        redo->setText(QApplication::translate("Form", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTCONTAINER_H
