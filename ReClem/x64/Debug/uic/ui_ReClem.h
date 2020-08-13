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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReClemClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QWidget *widget_2;
    QFrame *frame;
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
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-1, 529, 1011, 61));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 30, 1011, 31));
        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 1011, 31));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        ReClemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ReClemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1013, 23));
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
    } // retranslateUi

};

namespace Ui {
    class ReClemClass: public Ui_ReClemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECLEM_H
