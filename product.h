#ifndef PRODUCT_H
#define PRODUCT_H

#include <QSqlTableModel>
#include <QTableView>

#include <QWidget>
#include <QDataWidgetMapper>

#include "dbconnection.h"

class Product
{
public:
    Product(DbConnection* );

private:
    DbConnection* connection;

    QSqlTableModel* model;
    QTableView* view;

    QModelIndex* index;

    QWidget* itemWindow;
    QDataWidgetMapper* mapper;

};

#endif // PRODUCT_H
