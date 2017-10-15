#include "table.h"
#include "ui_customers.h"

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}
/*!
 * \brief Table::setSqlModel Sets up sql model for this table. Shows all data from table in tableView.
 * \param sqlModel Pointer for sqlModel, which needs to be set up.
 */
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
