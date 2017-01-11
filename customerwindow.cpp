#include "customerwindow.h"

CustomerWindow::CustomerWindow(QSqlTableModel* m)
{
    model = m;

    setWindow();
    setRecord();
}

CustomerWindow::CustomerWindow(QSqlTableModel* m, QModelIndex& i)
{
    model = m;
    index = i;

    setWindow();
    setMapper();

    connect(but, &QPushButton::clicked, mapper, &QDataWidgetMapper::submit );
    connect(but, &QPushButton::clicked, window, &QWidget::close );
    connect(anuluj, &QPushButton::clicked, window, &QWidget::close );
}

QSqlRecord& getRecord();

void setRecord();


void CustomerWindow::setWindow()
{
    window = new QWidget;
    window->setAttribute(Qt::WA_DeleteOnClose);

    layout = new QVBoxLayout;

    m_namelabel = new QLabel("Nazwa:");
    m_streetlabel = new QLabel("Ulica:");
    m_nolabel = new QLabel("Numer:");
    m_citylabel = new QLabel("Miasto:");
    m_ziplabel = new QLabel("Kod pocztowy:");
    m_vatlabel = new QLabel("NIP:");

    m_name = new QLineEdit;
    m_street = new QLineEdit;
    m_no = new QLineEdit;
    m_city = new QLineEdit;
    m_zip = new QLineEdit;
    m_vat = new QLineEdit;

    okButton = new QPushButton("Ok");
    cancelButton = new QPushButton("Anuluj");

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
    layout->addWidget(but);
    layout->addWidget(anuluj);

    window->setLayout(layout);
    window->show();
}

void CustomerWindow::setMapper()
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

void CustomerWindow::setRecord()
{
    record = new QSqlRecord;

    record->isGenerated(1);
    record->setValue("name", QVariant(m_name));
    record->setValue("street", QVariant(m_street));
    record->setValue("no", QVariant(m_no));
    record->setValue("city", QVariant(m_city));
    record->setValue("m_zip", QVariant(m_zip));
    record->setValue("m_vat", QVariant(m_vat));

    model->setRecord(0, record);
}
