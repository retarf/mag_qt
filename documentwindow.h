#ifndef DOCUMENTWINDOW_H
#define DOCUMENTWINDOW_H

#include <QObject>
#include <QSqlTableModel>
#include <QModelIndex>

#include <QVBoxLayout>

#include <QGroupBox>

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>

#include <QStringList>

#include <QPushButton>

#include "dbconnection.h"
#include "incomes.h"
#include "expenditures.h"

class DocumentWindow :public QObject
{
    Q_OBJECT

public:
    DocumentWindow( DbConnection*, QSqlRelationalTableModel* );

private:
    DbConnection* connection;
    QSqlRelationalTableModel* model;

    QWidget* window;

    void setWindow();

    // === Document Section === //

    QGroupBox* setDocumentSection();

    QString getDefaultNumber();
    QStringList getTypes();

    QComboBox* m_type;
    QLineEdit* m_number;
    QDateEdit* m_date;

    // === END Document Section === //

    QGroupBox* setCustomerSection();

    QStringList getCustomer();

    QLineEdit* m_customer;  // Customer VAT //

    QLineEdit* m_customerName;
    QLineEdit* m_customerStreet;
    QLineEdit* m_customerNo;
    QLineEdit* m_customerCity;
    QLineEdit* m_customerZip;
    QLineEdit* m_customerVat;

    QGroupBox* setProductsSection();

    // === Buttons === //

    QPushButton* okButton;
    QPushButton* cancelButton;

    Rotations* m_rotations;

    // ---------------------------- //

};

#endif // DOCUMENTWINDOW_H
