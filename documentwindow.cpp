#include <QSqlQuery>
#include <QDebug>
#include <QCompleter>

#include <QSqlError>
#include <QDebug>
#include <QSqlField>

#include <QSqlIndex>

#include <QSqlQuery>

#include "documentwindow.h"

DocumentWindow::DocumentWindow( DbConnection* c, QSqlRelationalTableModel* m )
{
    connection = c;

    model = m;


    setWindow();

    // connect( okButton, &QPushButton::clicked, this, &DocumentWindow::setRecord );
    connect( okButton, &QPushButton::clicked, window, &QWidget::close );
    connect( cancelButton, &QPushButton::clicked, window, &QWidget::close );

    // TEST  //
}

/* DocumentWindow::CustomerWindow( DbConnection* c, QSqlTableModel* m, QModelIndex& i )
{
    connection = c;

    model = m;
    index = i;

    setWindow();
    setMapper();

    connect( okButton, &QPushButton::clicked, mapper, &QDataWidgetMapper::submit );
    connect( okButton, &QPushButton::clicked, this, &CustomerWindow::setSort);
    connect( okButton, &QPushButton::clicked, window, &QWidget::close );
    connect( cancelButton, &QPushButton::clicked, window, &QWidget::close );
}
*/

void DocumentWindow::setWindow()
{
    window = new QWidget;
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setMinimumWidth(500);
    window->setWindowTitle("DOKUMENT MAGAZYNOWY");

    QGridLayout* layout = new QGridLayout;

    okButton = new QPushButton("Ok");
    cancelButton = new QPushButton("Anuluj");

    layout->addWidget( setDocumentSection(), 0, 0, 2, 2 );
    layout->addWidget( setCustomerSection(), 2, 0, 6, 2 );
    // layout->addWidget( setRotationSection(), 2, 0, 6, 2 );

    layout->addWidget( okButton );
    layout->addWidget( cancelButton );

    window->setLayout(layout);
    window->show();
}


QStringList DocumentWindow::getTypes()
{
        QStringList list;

        QSqlQuery query( connection->db );
        query.prepare( "SELECT type FROM documents_types" );
        query.exec();

        QString row;

        while ( query.next() )
        {
            row = query.value( 0 ).toString();
            list << row;
        }

        return list;
}

QGroupBox* DocumentWindow::setDocumentSection()
{
    QGroupBox* box = new QGroupBox("DOKUMENT");

    QGridLayout* layout = new QGridLayout;

    // Document type field //

    m_type = new QComboBox();
    m_type->addItems( getTypes() );

    // Document number field //

    m_number = new QLineEdit;
    m_number->setText( getDefaultNumber() );

    // Date Field //

    m_date = new QDateEdit;
    m_date->setDate( QDate::currentDate() );

    // Field to finding customer from database //


    QLabel* doctypelab = new QLabel("Typ dokumentu");
    QLabel* docnumberlab = new QLabel("Numer");

    layout->addWidget(m_type, 0, 0);
    layout->addWidget(m_number, 0, 1);
    layout->addWidget(m_date, 0, 2);

    box->setLayout(layout);

    return box;

}

QString DocumentWindow::getDefaultNumber()
{

    QString number;

    std::vector <int> list;

    QSqlQuery query( connection->db );

    query.prepare("SELECT number FROM documents order by number");
    query.exec();

    while ( query.last() )
        number = query.value( 0 ).toString();

    return number;
}


QGroupBox* DocumentWindow::setCustomerSection()
{
    QGroupBox* box = new QGroupBox("KONTRAHENT");
    QGridLayout* layout = new QGridLayout;

    QLineEdit* customerFind = new QLineEdit;
    QCompleter* customerCompleter = new QCompleter( getCustomer(), this );
    customerCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    customerFind->setCompleter( customerCompleter );

    // Customer name fields

    QLabel* name = new QLabel("Nazwa");
    QLabel* street = new QLabel("Ulica");
    QLabel* no = new QLabel("Nr");
    QLabel* zip = new QLabel("Kod pocztowy");
    QLabel* city = new QLabel("Miasto");
    QLabel* vat = new QLabel("NIP");

    m_customerName = new QLineEdit;
    m_customerStreet = new QLineEdit;
    m_customerNo = new QLineEdit;
    m_customerCity = new QLineEdit;
    m_customerZip = new QLineEdit;
    m_customerVat = new QLineEdit;

    // QObject::connect(m_qlecustomer, SIGNAL( editingFinished() ), this, SLOT( chengecustomername() ));
    // QObject::connect(m_customername, SIGNAL( editingFinished() ), this, SLOT( changecustomervat() ));

    layout->addWidget( customerFind, 0, 0, 1, 1, Qt::AlignJustify );
    layout->addWidget( name, 2, 0 );
    layout->addWidget( m_customerName, 2, 1 );
    layout->addWidget( street, 3, 0 );
    layout->addWidget( m_customerStreet, 3, 1 );
    layout->addWidget( no, 4, 0 );
    layout->addWidget( m_customerNo, 4, 1 );
    layout->addWidget( zip, 5, 0 );
    layout->addWidget( m_customerZip, 5, 1 );
    layout->addWidget( city, 6, 0 );
    layout->addWidget( m_customerCity, 6, 1 );
    layout->addWidget( vat, 7, 0 );
    layout->addWidget( m_customerVat, 7, 1 );
    // layout->addStretch(1);

    box->setLayout(layout);

    return box;

}

/*

void DocumentWindow::setdoctype(QString type)
{
    if( ( type != "WZ" ) && ( type != "RW" ) && ( type != "PZ" ) && ( type != "PW" ) )
    {
            qDebug() << "Wrong document type";
    }
    else
    {
            m_doctype = type;
    }
}

QStringList DocumentWindow::getList(QString column, QString table)
{

    QStringList list;

    QSqlQuery query(connection->db);

    query.prepare("SELECT vat FROM customers"); // ----------------------------------------------------> dynamic binding addBindValue() do not work. This must be checked.

    query.exec();

    QString row;

    while (query.next())
    {
        row = query.value(0).toString();
//        qDebug() << row;
        list << row;
    }

    return list;
}
*/
QStringList DocumentWindow::getCustomer()
{

    QStringList list;

    QSqlQuery query( connection->db );

    query.prepare("SELECT name FROM customers");

    query.exec();

    QString row;

    while (query.next())
    {
        row = query.value(0).toString();
        list << row;
    }

    return list;
}

/*

QString DocumentWindow::selectcustomername(QString vat)
{
    QSqlQuery query( connection->db );

    long long int vatint;

    vatint = vat.toInt();

    query.prepare("SELECT name FROM customers where (vat=:vat)");
    query.bindValue(":vat", vatint);
    query.exec();

    QString name;
    while (query.next())
    {
        name = query.value(0).toString();
    }

    return name;
}



QString DocumentWindow::selectcustomervat(QString name)
{
    QSqlQuery query( connection->db );

    query.prepare("SELECT vat FROM customers where (name=:name)");
    query.bindValue(":name", name);
    query.exec();

    QString vat;
    while (query.next())
    {
        vat = query.value(0).toString();
    }

    return vat;
}

void DocumentWindow::changecustomervat()
{
    QString vat;
    QString name;

    name = m_customername->text();
    vat = selectcustomervat(name);

//    if(vat != "")
//    {
        m_qlecustomer->setText(vat);
//    }
    qDebug() << "changecustomervat(): signal";

}

void DocumentWindow::chengecustomername()
{
    QString vat;
    QString name;

    vat = m_qlecustomer->text();
    name = selectcustomername(vat);

//    if(name != "")
//    {
        m_customername->setText(name);
//    }
    qDebug() << "changecustomername(): signal";
}

/*
void DocumentWindow::setMapper()
{
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
}

void DocumentWindow::setRecord()
{
    record = new QSqlRecord;

    record = recordGenerator.getRecord();

    record->setValue("name", QVariant(m_name->text()));
    record->setValue("street", QVariant(m_street->text()));
    record->setValue("no", QVariant(m_no->text()));
    record->setValue("city", QVariant(m_city->text()));
    record->setValue("zip", QVariant(m_zip->text()));
    record->setValue("vat", QVariant(m_vat->text()));

    model->insertRecord(0, *record);

    setSort();
}

void DocumentWindow::setSort()
{
    model->setSort(1,Qt::AscendingOrder);
    model->select();
}

*/
