#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ReClem.h"

class ReClem : public QMainWindow
{
    Q_OBJECT

public:
    ReClem(QWidget *parent = Q_NULLPTR);

private:
    Ui::ReClemClass ui;
};
