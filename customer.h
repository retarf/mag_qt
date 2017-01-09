#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QSqlTableModel>
#include <QTableView>
#include <QModelIndex>
#include <QWidget>
#include <QAbstractItemView>
#include <QDataWidgetMapper>

#include "program.h"

class Customer :public QObject
{
    Q_OBJECT

public:
    Customer();

    QSqlTableModel* model;
    QTableView* view;
    QModelIndex index;
    QModelIndex ppp;
    QDataWidgetMapper* mapper;

    DbConnection* connection;

    // bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void lala(QModelIndex i);
    void setwindow(QModelIndex);
signals:
    // QAbstractItemView::doubleClicked(const QModelIndex &index);

};

#endif // CUSTOMER_H
