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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReClemClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ReClemClass)
    {
        if (ReClemClass->objectName().isEmpty())
            ReClemClass->setObjectName(QStringLiteral("ReClemClass"));
        ReClemClass->resize(600, 400);
        menuBar = new QMenuBar(ReClemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ReClemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ReClemClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ReClemClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ReClemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ReClemClass->setCentralWidget(centralWidget);
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
