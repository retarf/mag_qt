#ifndef DOCUMENTS_H
#define DOCUMENTS_H

#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include <QTableView>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

#include "dbconnection.h"
#include "simplyabstractcontroler.h"
#include "documentwindow.h"

class Documents :public QObject
{
    Q_OBJECT

public:
    Documents(DbConnection *c, QString table);

    void setwindow(QModelIndex);
    void setMainConnections();

    QWidget* getMainWindow();

private:

    DbConnection* connection;

    QSqlRelationalTableModel* model;
    QSqlRelation* customer;

    QTableView* view;

    QWidget* mainwindow;
    QVBoxLayout* layout;

    QPushButton* addButton;
    QPushButton* delButton;

    DocumentWindow* documentWindow;

    QModelIndexList selectedList;
    QModelIndex selected;

private slots:
    void setaddwindow();
    void saveData();
    void removeRecords();
};

#endif // DOCUMENTS_H
