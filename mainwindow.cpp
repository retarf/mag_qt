#include <QDockWidget>
#include <QVBoxLayout>
#include <QGroupBox>

#include "customer.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
    dbc = new DbConnection;

    menu = new QMenuBar(this);
    QAction* productsMenu = new QAction("Towary", menu);
    QAction* customersMenu = new QAction("Klienci", menu);
    QAction* documentsMenu = new QAction("Dokumenty", menu);
    QAction* raportsMenu = new QAction("Raporty", menu);

    menu->addAction(productsMenu);
    menu->addAction(customersMenu);
    menu->addAction(documentsMenu);
    menu->addAction(raportsMenu);

    QObject::connect(customersMenu, &QAction::triggered, this, &MainWindow::getCustomerPanel);

    this->setMinimumHeight(500);
    this->setMinimumWidth(900);
    this->setMenuBar(menu);
    this->show();

}

void MainWindow::getCustomerPanel()
{
    QDockWidget* central = new QDockWidget("Panel klienta", this);
    central->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    Customer* customer = new Customer(dbc);
    central->setWidget(customer->view);
    this->addDockWidget(Qt::BottomDockWidgetArea, central);
    central->show();
}
