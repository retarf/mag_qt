#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <QModelIndex>

#include "simplyabstractcontroler.h"

class Products :public SimplyAbstractControler
{
public:
    Products(DbConnection *c, QString table);

    virtual void setwindow(QModelIndex) final;
    virtual void setMainConnections() final;
};

#endif // PRODUCTS_H
