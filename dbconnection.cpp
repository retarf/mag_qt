#include <QSqlDatabase>
#include <QWidget>
#include <QObject>

#include <QDebug>
#include <QSqlError>

#include "dbconnection.h"

DbConnection::DbConnection()
{
    db = QSqlDatabase::addDatabase(db_type, conn_name);
    db.database(conn_name);
    db.setHostName(h_name);
    db.setDatabaseName(db_name);
    db.setUserName(user);
    db.setPassword(db_pass);

    if(!db.open())
    {
        qDebug() << "DbConnection::DbConnection(): Database not opened: " << db.lastError();
    }
}
