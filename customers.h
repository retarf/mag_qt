#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QModelIndex>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QItemSelectionModel>
#include <QModelIndexList>

#include "customerwindow.h"
#include "simplyabstractcontroler.h"

class Customers :public SimplyAbstractControler
{
public:
    Customers(DbConnection *c, QString table);

    virtual void setwindow(QModelIndex) final;
    virtual void setMainConnections() final;

    QWidget* getMainWindow();

private:
    QWidget* mainwindow;

    QPushButton* addbutton;
    QPushButton* delButton;

    CustomerWindow* customerWindow;

    QModelIndexList selectedList;
    QModelIndex selected;

private slots:
    void setaddwindow();
    void saveData();
    void removeRecords();
};

#endif // CUSTOMERS_H
