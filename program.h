#ifndef PROGRAM_H
#define PROGRAM_H

#include <QWidget>

#include "dbconnection.h"

class Program // :public QWidget
{
public:
    Program();

    DbConnection* connection;
};

#endif // PROGRAM_H
