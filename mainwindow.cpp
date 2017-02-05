#include <QDockWidget>
#include <QVBoxLayout>
#include <QGroupBox>

#include <QDebug>

#include "products.h"
#include "customers.h"
#include "documents.h"
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

    QObject::connect( customersMenu, &QAction::triggered, this, &MainWindow::getCustomerPanel);
    QObject::connect( productsMenu, &QAction::triggered, this, &MainWindow::getProductsPanel);
    QObject::connect( documentsMenu, &QAction::triggered, this, &MainWindow::getDocumentsPanel);

    this->setMinimumHeight(500);
    this->setMinimumWidth(900);
    this->setMenuBar(menu);
    this->show();

}

void MainWindow::getCustomerPanel()
{
    QDockWidget* central = new QDockWidget("Panel klientów", this);
    central->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    Customers* customers = new Customers(dbc, "customers");
    central->setWidget(customers->getMainWindow());
    this->addDockWidget(Qt::BottomDockWidgetArea, central);
    central->show();
}

void MainWindow::getProductsPanel()
{
    QDockWidget* central = new QDockWidget("Panel produktów", this);
    central->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    Products* products = new Products(dbc, "products");
    central->setWidget(products->view);
    this->addDockWidget(Qt::BottomDockWidgetArea, central);
    central->show();
}

void MainWindow::getDocumentsPanel()
{
    QDockWidget* central = new QDockWidget("Panel dokumentów", this);
    central->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    Documents* documents = new Documents(dbc, "documents");
    central->setWidget(documents->getMainWindow());
    this->addDockWidget(Qt::BottomDockWidgetArea, central);
    central->show();
}

