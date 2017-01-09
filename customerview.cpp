#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>

#include <QString>

#include "customerview.h"

CustomerView::CustomerView()
{
    this->setView();
}

/*
CustomerView::CustomerView(CustomerModel*& model)
{
    this->setView(model->name, model->street, model->no, model->city, model->zip, model->vat);
}
*/

void CustomerView::setView(QString name, QString street, QString no, QString city, QString zip, QString vat)
{
    layout = new QVBoxLayout;

    m_namelabel = new QLabel("Nazwa:");
    m_streetlabel = new QLabel("Ulica:");
    m_nolabel = new QLabel("Numer:");
    m_citylabel = new QLabel("Miasto:");
    m_ziplabel = new QLabel("Kod pocztowy:");
    m_vatlabel = new QLabel("NIP:");

    m_name = new QLineEdit(name);
    m_street = new QLineEdit(street);
    m_no = new QLineEdit(no);
    m_city = new QLineEdit(city);
    m_zip = new QLineEdit(zip);
    m_vat = new QLineEdit(vat);

    this->layout->addWidget(m_namelabel);
    this->layout->addWidget(m_name);
    this->layout->addWidget(m_streetlabel);
    this->layout->addWidget(m_street);
    this->layout->addWidget(m_nolabel);
    this->layout->addWidget(m_no);
    this->layout->addWidget(m_citylabel);
    this->layout->addWidget(m_city);
    this->layout->addWidget(m_ziplabel);
    this->layout->addWidget(m_zip);
    this->layout->addWidget(m_vatlabel);
    this->layout->addWidget(m_vat);
}

QGroupBox* CustomerView::setBox()
{
    box = new QGroupBox("KLIENT");
    box->setLayout(layout);

    return box;
}

void CustomerView::setWindow()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setLayout(layout);
    this->show();
}

