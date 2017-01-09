#include <QDockWidget>
#include <QVBoxLayout>
#include <QGroupBox>

#include "customer.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
    menu = new QMenuBar(this);
    QAction* opencustomerpanel = new QAction("Panel Klienta", menu);
    menu->addAction(opencustomerpanel);

    QObject::connect(opencustomerpanel, &QAction::triggered, this, &MainWindow::getCustomerPanel);

    this->setMinimumHeight(500);
    this->setMinimumWidth(900);
    this->setMenuBar(menu);
    this->show();

}

void MainWindow::getCustomerPanel()
{
    QDockWidget* central = new QDockWidget("Prog", this);
    central->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    Customer* customer = new Customer;
    central->setWidget(customer->view);
    this->addDockWidget(Qt::BottomDockWidgetArea, central);
    central->show();



    // QVBoxLayout* layout = new QVBoxLayout;
    // layout->addWidget(new Customer);
    // central->setLayout(layout);//  ->setCentralWidget(centralpanel);
}
