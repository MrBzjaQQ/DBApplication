#include "customers.h"
#include "ui_customers.h"

Customers::Customers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Customers)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

Customers::~Customers()
{
    delete ui;
}
