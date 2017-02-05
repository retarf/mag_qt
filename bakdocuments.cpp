/*
#include "dbconnection.h"
#include "documents.h"

Documents::Documents(DbConnection* c, QString table)
{
    connection = c;
    /*
    model = new QSqlRelationalTableModel(this, (connection->db));
    // model = new QSqlTableModel(this, (connection->db));
    model->setTable(table);
    model->select();

    view = new QTableView;
    view->setModel(&*model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->sortByColumn(1, Qt::AscendingOrder);
    view->hideColumn(0);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}

QWidget* Documents::getView()
{
    return view;
}
*/
