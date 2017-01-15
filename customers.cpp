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
#include <QVBoxLayout>

#include "dbconnection.h"
#include "simplyabstractcontroler.h"
#include "customers.h"

Customers::Customers(DbConnection* c, QString table)
    :SimplyAbstractControler(c, table)
{
    mainwindow = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;
    addbutton = new QPushButton("Dodaj nowego clienta");
    addbutton->setMinimumHeight(50);
    delButton = new QPushButton("Usuń wybranego klienta");

    mainwindow->setStyleSheet("QPushButton#delbutton {background-color: red }");

    QPalette pal = delButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    delButton->setAutoFillBackground(true);
    delButton->setPalette(pal);
    delButton->update();

    view->setColumnWidth(1, 100);
    view->setColumnWidth(2, 100);
    view->setColumnWidth(3, 100);
    view->setColumnWidth(4, 100);
    view->setColumnWidth(5, 100);
    view->setColumnWidth(6, 100);

    layout->addWidget(view);
    layout->addWidget(addbutton);
    layout->addWidget(delButton);
    mainwindow->setLayout(layout);

    setMainConnections();

}

void Customers::setMainConnections()
{
    connect(view, &QTableView::doubleClicked, this, &Customers::setwindow );
    connect(addbutton, &QPushButton::clicked, this, &Customers::setaddwindow);

    connect(delButton, &QPushButton::clicked, this, &Customers::removeRecords);

}

void Customers::setwindow(QModelIndex i)
{
    customerWindow = new CustomerWindow(model, i);
}

void Customers::setaddwindow()
{
    customerWindow = new CustomerWindow(model);
}

void Customers::saveData()
{
    QModelIndex i = model->index(model->rowCount(), model->columnCount(), QModelIndex());
    model->insertRows(model->rowCount(), 1, i);
}

void Customers::removeRecords()
{
    selectedList = view->selectionModel()->selectedIndexes();

    for (int i = selectedList.count() - 1; i >= 0; --i)
    {
        model->removeRow((selectedList.at(i).row()));
    }

    model->setSort(1,Qt::AscendingOrder);
    model->select();
}

QWidget* Customers::getMainWindow()
{
    return mainwindow;
}
