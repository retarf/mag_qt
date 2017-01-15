#include "customerrecord.h"

CustomerRecord::CustomerRecord()
{
    record = new QSqlRecord;

    id = new QSqlField("id", QVariant::Int);
    id->setGenerated(false);
    name = new QSqlField("name", QVariant::String);
    street = new QSqlField("street", QVariant::String);
    city = new QSqlField("city", QVariant::String);
    zip = new QSqlField("zip", QVariant::Int);
    vat = new QSqlField("vat", QVariant::Int);
    no = new QSqlField("no", QVariant::String);

    record->append(*id);
    record->append(*name);
    record->append(*street);
    record->append(*no);
    record->append(*city);
    record->append(*zip);
    record->append(*vat);
}

QSqlRecord* CustomerRecord::getRecord()
{
    return record;
}
