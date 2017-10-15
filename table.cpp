#include "table.h"
#include "ui_customers.h"

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

void Table::setSqlModel(QSqlTableModel *sqlModel)
{
    this->model = sqlModel;
    model->select();
    ui->tableView->setModel(model);
}

Table::~Table()
{
    delete ui;
}
