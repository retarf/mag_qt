#include <QApplication>

#include "program.h"
#include "customer.h"

#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    //Program* program = new Customer;
    MainWindow m;

    return app.exec();
}
