#ifndef EXPENDITURES_H
#define EXPENDITURES_H

#include "dbconnection.h"
#include "rotations.h"

class Expenditures :public Rotations
{
public:
    Expenditures(DbConnection*);
};

#endif // EXPENDITURES_H
