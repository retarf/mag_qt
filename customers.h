#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QModelIndex>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "simplyabstractcontroler.h"

class Customers :public SimplyAbstractControler
{
public:
    Customers(DbConnection *c, QString table);

    virtual void setwindow(QModelIndex) final;
    virtual void setMainConnections() final;

public slots:
    void setaddwindow();
    void saveData();

    QWidget* mainwindow;
    QPushButton* addbutton;
};

#endif // CUSTOMERS_H
