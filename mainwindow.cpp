#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include "addcustomerform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
    ui->mdiArea->setDocumentMode(true);
    ui->mdiArea->setTabsClosable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCreateCustomerForm()
{
    QMdiSubWindow *createCustomerForm = new QMdiSubWindow(new AddCustomerForm());
    ui->mdiArea->addSubWindow(createCustomerForm);
    createCustomerForm->show();
    connect(this, SIGNAL(ui->actionNew_customer), this, SLOT(openCreateCustomerForm()));
}
