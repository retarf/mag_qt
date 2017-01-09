#ifndef CUSTOMERVIEW_H
#define CUSTOMERVIEW_H

#include <QLineEdit>

#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>

#include <QLineEdit>
#include <QLabel>

// #include "customermodel.h"

class CustomerView :public QWidget
{
    Q_OBJECT

public:
    explicit CustomerView();
    // explicit CustomerView(CustomerModel*&);

public:
    void setWindow();
    QGroupBox* setBox();

private:
    void setView(QString="", QString="", QString="", QString="", QString="", QString="");

    QVBoxLayout* layout;
    QGroupBox* box;

    QLineEdit* m_name;
    QLineEdit* m_street;
    QLineEdit* m_no;
    QLineEdit* m_city;
    QLineEdit* m_zip;
    QLineEdit* m_vat;

    QLabel* m_namelabel;
    QLabel* m_streetlabel;
    QLabel* m_nolabel;
    QLabel* m_citylabel;
    QLabel* m_ziplabel;
    QLabel* m_vatlabel;

    friend class CustomerModel;
};

#endif // CUSTOMERVIEW_H
