#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

#include "dbconnection.h"

class MainWindow :public QMainWindow
{
public:
    MainWindow();

    QMenuBar* menu;

    DbConnection* dbc;

private slots:
    void getCustomerPanel();
};

#endif // MAINWINDOW_H
