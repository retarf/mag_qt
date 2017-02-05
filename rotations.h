#ifndef ROTATIONS_H
#define ROTATIONS_H

#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QString>

#include "dbconnection.h"
#include "rotations.h"

class Rotations :public QObject
{
    Q_OBJECT

public:
    Rotations(DbConnection*);

protected:
    DbConnection* connection;

    QString* table;

    QSqlRelationalTableModel* model;
    QTableView* view;


};

#endif // ROTATIONS_H
