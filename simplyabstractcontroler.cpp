#include <QDebug>
#include <QAbstractItemView>
#include <QPushButton>
#include <QMouseEvent>
#include <QDataWidgetMapper>

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QString>

#include "simplyabstractcontroler.h"
#include "dbconnection.h"

SimplyAbstractControler::SimplyAbstractControler(DbConnection* c, QString table)
{
    connection = c;

    model = new QSqlTableModel(this, (connection->db));
    model->setTable(table);
    model->select();

    view = new QTableView;
    view->setModel(&*model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->sortByColumn(1, Qt::AscendingOrder);
    view->hideColumn(0);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // setMainConnections();

    // connect(view, &QTableView::doubleClicked, this, &Customers::setwindow );
}
