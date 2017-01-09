#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

class MainWindow :public QMainWindow
{
public:
    MainWindow();

    QMenuBar* menu;

private slots:
    void getCustomerPanel();
};

#endif // MAINWINDOW_H
