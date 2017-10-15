#include "addcustomerform.h"
#include "ui_addcustomerform.h"

AddCustomerForm::AddCustomerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomerForm)
{
    ui->setupUi(this);
}

AddCustomerForm::~AddCustomerForm()
{
    delete ui;
}
