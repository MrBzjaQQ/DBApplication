#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include "addcustomerform.h"
#include "customers.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
    ui->mdiArea->setTabsMovable(true);
     ui->mdiArea->setTabsClosable(true);

    connect(ui->actionNew_customer, SIGNAL(triggered(bool)), this, SLOT(openCreateCustomerForm()));
    connect(ui->actionCustomer, SIGNAL(triggered(bool)), this, SLOT(openCustomersTable()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCreateCustomerForm()
{
    AddCustomerForm *form = new AddCustomerForm();
    form->show();
}

void MainWindow::openCustomersTable()
{
    Customers *customers = new Customers();
    QMdiSubWindow *subWindow = new QMdiSubWindow();
    subWindow->setWidget(customers);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->show();
}
