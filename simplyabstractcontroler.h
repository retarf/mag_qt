#ifndef SIMPLYABSTRACTCONTROLER_H
#define SIMPLYABSTRACTCONTROLER_H

#include <QSqlTableModel>
#include <QTableView>
#include <QModelIndex>
#include <QWidget>
#include <QAbstractItemView>
#include <QDataWidgetMapper>

#include "dbconnection.h"
#include "program.h"

class SimplyAbstractControler :public QObject
{
    Q_OBJECT

public:
    SimplyAbstractControler(DbConnection*, QString);

    QSqlTableModel* model;
    QTableView* view;

    QDataWidgetMapper* mapper;

    DbConnection* connection;

public slots:
    virtual void setwindow(QModelIndex) = 0;
    virtual void setMainConnections() = 0;
};

#endif // SIMPLYABSTRACTCONTROLER_H
