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

    // zmiana

    view->setColumnWidth(1, 100);
    view->setColumnWidth(2, 100);
    view->setColumnWidth(3, 100);
    view->setColumnWidth(4, 100);
    view->setColumnWidth(5, 100);
    view->setColumnWidth(6, 100);

    mainwindow = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;
    addbutton = new QPushButton("Dodaj nowego clienta");
    layout->addWidget(view);
    layout->addWidget(addbutton);
    mainwindow->setLayout(layout);

    setMainConnections();

}

void Customers::setMainConnections()
{
    connect(view, &QTableView::doubleClicked, this, &Customers::setwindow );
    connect(addbutton, &QPushButton::clicked, this, &Customers::setaddwindow);

}

void Customers::setwindow(QModelIndex i)
{
    customerWindow = new CustomerWindow(model, i);

    /*
    QWidget* window = new QWidget;
    window->setAttribute(Qt::WA_DeleteOnClose);

    QVBoxLayout* layout = new QVBoxLayout;

    QLabel* m_namelabel = new QLabel("Nazwa:");
    QLabel* m_streetlabel = new QLabel("Ulica:");
    QLabel* m_nolabel = new QLabel("Numer:");
    QLabel* m_citylabel = new QLabel("Miasto:");
    QLabel* m_ziplabel = new QLabel("Kod pocztowy:");
    QLabel* m_vatlabel = new QLabel("NIP:");

    QLineEdit* m_name = new QLineEdit;
    QLineEdit* m_street = new QLineEdit;
    QLineEdit* m_no = new QLineEdit;
    QLineEdit* m_city = new QLineEdit;
    QLineEdit* m_zip = new QLineEdit;
    QLineEdit* m_vat = new QLineEdit;

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setCurrentModelIndex(index);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);


    layout->addWidget(m_namelabel);
    layout->addWidget(m_name);
    layout->addWidget(m_streetlabel);
    layout->addWidget(m_street);
    layout->addWidget(m_nolabel);
    layout->addWidget(m_no);
    layout->addWidget(m_citylabel);
    layout->addWidget(m_city);
    layout->addWidget(m_ziplabel);
    layout->addWidget(m_zip);
    layout->addWidget(m_vatlabel);
    layout->addWidget(m_vat);

    QPushButton* but = new QPushButton("Ok");
    QPushButton* anuluj = new QPushButton("Anuluj");

    layout->addWidget(but);
    layout->addWidget(anuluj);

    connect(view, &QTableView::destroyed, window, &QWidget::close );
    connect(but, &QPushButton::clicked, mapper, &QDataWidgetMapper::submit );
    connect(but, &QPushButton::clicked, window, &QWidget::close );
    connect(but, &QPushButton::clicked, view, &QTableView::reset );
    connect(anuluj, &QPushButton::clicked, window, &QWidget::close );

    window->setLayout(layout);
    window->show();

    mapper->addMapping(m_name, 1);
    mapper->addMapping(m_street, 2);
    mapper->addMapping(m_city, 3);
    mapper->addMapping(m_zip, 4);
    mapper->addMapping(m_vat, 5);
    mapper->addMapping(m_no, 6);

    mapper->revert();

    */
}

void Customers::setaddwindow()
{
    customerWindow = new CustomerWindow(model);

    /*
    QWidget* window = new QWidget;
    window->setAttribute(Qt::WA_DeleteOnClose);

    QVBoxLayout* layout = new QVBoxLayout;

    QLabel* m_namelabel = new QLabel("Nazwa:");
    QLabel* m_streetlabel = new QLabel("Ulica:");
    QLabel* m_nolabel = new QLabel("Numer:");
    QLabel* m_citylabel = new QLabel("Miasto:");
    QLabel* m_ziplabel = new QLabel("Kod pocztowy:");
    QLabel* m_vatlabel = new QLabel("NIP:");

    QLineEdit* m_name = new QLineEdit;
    QLineEdit* m_street = new QLineEdit;
    QLineEdit* m_no = new QLineEdit;
    QLineEdit* m_city = new QLineEdit;
    QLineEdit* m_zip = new QLineEdit;
    QLineEdit* m_vat = new QLineEdit;

    layout->addWidget(m_namelabel);
    layout->addWidget(m_name);
    layout->addWidget(m_streetlabel);
    layout->addWidget(m_street);
    layout->addWidget(m_nolabel);
    layout->addWidget(m_no);
    layout->addWidget(m_citylabel);
    layout->addWidget(m_city);
    layout->addWidget(m_ziplabel);
    layout->addWidget(m_zip);
    layout->addWidget(m_vatlabel);
    layout->addWidget(m_vat);

    QPushButton* but = new QPushButton("Ok");
    QPushButton* anuluj = new QPushButton("Anuluj");

    layout->addWidget(but);
    layout->addWidget(anuluj);

    connect(mainwindow, &QWidget::destroyed, window, &QWidget::close );
    connect(but, &QPushButton::clicked, mapper, &QDataWidgetMapper::submit );
    connect(but, &QPushButton::clicked, window, &QWidget::close );
    connect(but, &QPushButton::clicked, view, &QTableView::reset );
    connect(anuluj, &QPushButton::clicked, window, &QWidget::close );

    window->setLayout(layout);
    window->show();

    */
}


void Customers::saveData()
{
    QModelIndex i = model->index(model->rowCount(), model->columnCount(), QModelIndex());
    model->insertRows(model->rowCount(), 1, i);
}
