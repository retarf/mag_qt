#include "documents.h"

Documents::Documents(DbConnection* c, QString table)
{
    connection = c;

    customer = new QSqlRelation("customers", "vat", "name");

    mainwindow = new QWidget;
    layout = new QVBoxLayout;

    addButton = new QPushButton("Dodaj nowy dokument");
    addButton->setMinimumHeight(50);
    delButton = new QPushButton("Usuń wybrany dokument");

    mainwindow->setStyleSheet("QPushButton#delButton {background-color: red }");

    QPalette pal = delButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    delButton->setAutoFillBackground(true);
    delButton->setPalette(pal);
    delButton->update();


    model = new QSqlRelationalTableModel(this, (connection->db));
    model->setTable(table);
    model->setRelation(4, *customer);
    model->select();


    view = new QTableView;
    view->setModel(&*model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->sortByColumn(1, Qt::AscendingOrder);
    view->hideColumn(0);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(view);
    layout->addWidget(addButton);
    layout->addWidget(delButton);

    mainwindow->setLayout(layout);

    setMainConnections();

}

void Documents::setMainConnections()
{
    connect( view, &QTableView::doubleClicked, this, &Documents::setwindow );
    connect( addButton, &QPushButton::clicked, this, &Documents::setaddwindow );
    connect( delButton, &QPushButton::clicked, this, &Documents::removeRecords );

}

void Documents::setwindow(QModelIndex i)
{
    // customerWindow = new CustomerWindow(model, i);
}

void Documents::setaddwindow()
{
    documentWindow = new DocumentWindow( connection, model );
}

void Documents::saveData()
{
    QModelIndex i = model->index(model->rowCount(), model->columnCount(), QModelIndex());
    model->insertRows(model->rowCount(), 1, i);
}

void Documents::removeRecords()
{
    selectedList = view->selectionModel()->selectedIndexes();

    for (int i = selectedList.count() - 1; i >= 0; --i)
    {
        model->removeRow((selectedList.at(i).row()));
    }

    model->setSort(1,Qt::AscendingOrder);
    model->select();
}

QWidget* Documents::getMainWindow()
{
    return mainwindow;
}
