#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QModelIndex>
#include <QSqlRecord>

#include <QVariant>

#include "customerrecord.h"

class CustomerWindow :public QObject
{
    Q_OBJECT

public:
    explicit CustomerWindow(QSqlTableModel*);
    explicit CustomerWindow(QSqlTableModel*, QModelIndex&);

private slots:
    void setRecord();

private:
    void setWindow();
    void setMapper();

    QWidget* window;
    QVBoxLayout* layout;

    QSqlTableModel* model;
    QModelIndex index;
    QDataWidgetMapper* mapper;
    QSqlRecord* record;
    CustomerRecord recordGenerator;

    QLabel* m_namelabel;
    QLabel* m_streetlabel;
    QLabel* m_nolabel;
    QLabel* m_citylabel;
    QLabel* m_ziplabel;
    QLabel* m_vatlabel;

    QLineEdit* m_name;
    QLineEdit* m_street;
    QLineEdit* m_no;
    QLineEdit* m_city;
    QLineEdit* m_zip;
    QLineEdit* m_vat;

    QPushButton* okButton;
    QPushButton* cancelButton;
};

#endif // CUSTOMERWINDOW_H
