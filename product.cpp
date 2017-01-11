#include <QDebug>
#include <QAbstractItemView>
#include <QPushButton>
#include <QMouseEvent>
#include <QDataWidgetMapper>

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "product.h"

Product::Product(DbConnection* c)
{
    connection = c;


}
