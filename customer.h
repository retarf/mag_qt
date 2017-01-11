#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QSqlTableModel>
#include <QTableView>
#include <QModelIndex>
#include <QWidget>
#include <QAbstractItemView>
#include <QDataWidgetMapper>

#include "dbconnection.h"
#include "program.h"

class Customer :public QObject
{
    Q_OBJECT

public:
    Customer(DbConnection*);

    QSqlTableModel* model;
    QTableView* view;

    QDataWidgetMapper* mapper;

    DbConnection* connection;

public slots:
    void setwindow(QModelIndex);
};

#endif // CUSTOMER_H
