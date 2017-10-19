#include "table.h"
#include "ui_table.h"
#include "mainwindow.h"
#include <QSqlError>

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->addNewLineButton, SIGNAL(clicked(bool)), this, SLOT(addNewLine()));
    connect(ui->addToDatabase, SIGNAL(clicked(bool)), this, SLOT(updateDatcabase()));
    connect(ui->deleteLineButton, SIGNAL(clicked(bool)), this, SLOT(deleteLine()));
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
/*!
 * \brief Table::addNewLine Adds new row to table
 */
void Table::addNewLine()
{
    int rowCount = ui->tableView->model()->rowCount();
    //ui->tableView->model()->insertRow(rowCount);
    model->insertRow(rowCount);
    model->setData(model->index(rowCount + 1, 0), rowCount + 1 );

}
/*!
 * \brief Table::deleteLine Deletes selected row from table
 */
void Table::deleteLine()
{
    QItemSelectionModel *selection = ui->tableView->selectionModel();
    foreach (QModelIndex index, selection->selectedRows()) {
        model->removeRow(index.row());
    }
}
/*!
 * \brief Table::updateDatcabase Update table data in database.
 */
void Table::updateDatcabase()
{
    QErrorMessage *em = new QErrorMessage();
    if(!model->submitAll())
        em->showMessage("Ошибка обновления содержимого таблицы. Вероятно, не заполнена какая-либо ячейка или обнаружено совпадение первичных ключей.");
}
