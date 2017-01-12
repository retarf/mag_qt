#ifndef CUSTOMERRECORD_H
#define CUSTOMERRECORD_H

#include <QSqlRecord>
#include <QSqlField>

class CustomerRecord
{
public:
    CustomerRecord();
    QSqlRecord* getRecord();

private:
    QSqlRecord* record;

    QSqlField* id;
    QSqlField* name;
    QSqlField* street;
    QSqlField* no;
    QSqlField* city;
    QSqlField* zip;
    QSqlField* vat;
};

#endif // CUSTOMERRECORD_H
