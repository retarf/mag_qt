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

#include "mtableview.h"
#include "customer.h"

#include "dbconnection.h"

Customer::Customer()
{
    connection = new DbConnection;

    model = new QSqlTableModel(this, (connection->db));
    model->setTable("customers");
    model->select();

    view = new MTableView;
    view->setModel(&*model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(view, &QTableView::doubleClicked, this, &Customer::setwindow );
}

void Customer::lala(QModelIndex i)
{

    qDebug() << i.model()->data(i, Qt::DisplayRole).toString();

    qDebug() << "signal";

    index.row();
    index.column();
}

void Customer::setwindow(QModelIndex index)
{

    qDebug() << index.isValid();


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

    mapper->addMapping(m_name, 1);
    mapper->addMapping(m_street, 2);
    mapper->addMapping(m_city, 3);
    mapper->addMapping(m_zip, 4);
    mapper->addMapping(m_vat, 5);
    mapper->addMapping(m_no, 6);

    mapper->revert();

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

    window->setLayout(layout);
    window->show();

    connect(view, &QTableView::destroyed, window, &QWidget::close );
    connect(but, &QPushButton::clicked, mapper, &QDataWidgetMapper::submit );
    connect(but, &QPushButton::clicked, window, &QWidget::close );
    connect(anuluj, &QPushButton::clicked, window, &QWidget::close );
}
