#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include "table.h"
#include <QtSql/QSqlDatabase>
#include <QtSql>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
    ui->mdiArea->setTabsMovable(true);
    ui->mdiArea->setTabsClosable(true);
    connectToDatabase();
    connect(ui->actionCustomer, SIGNAL(triggered(bool)), this, SLOT(openCustomersTable()));
    connect(ui->actionConnect_to_database, SIGNAL(triggered(bool)), this, SLOT(connectToDatabase()));
    connect(ui->actionDeal, SIGNAL(triggered(bool)), this, SLOT(openDealTable()));
    connect(ui->actionDeal_consistence, SIGNAL(triggered(bool)), this, SLOT(openDealConsistenceTable()));
    connect(ui->actionProduct, SIGNAL(triggered(bool)), this, SLOT(openProductTable()));
    connect(ui->actionDisconnect_from_database, SIGNAL(triggered(bool)), this, SLOT(disconnectDatabase()));
    const QIcon dbMainIcon = QIcon::fromTheme("app-main", QIcon(":/Icons/DBMain.png"));
    this->setWindowIcon(dbMainIcon);
    const QIcon dbIcon = QIcon::fromTheme("open-db", QIcon(":/Icons/DB.png"));
    ui->menuDatabase->setIcon(dbIcon);
    const QIcon tableIcon = QIcon::fromTheme("open-table", QIcon(":/Icons/DBTable.png"));
    ui->menuOpen->setIcon(tableIcon);
    const QIcon dbConnectIcon = QIcon::fromTheme("connect-db", QIcon(":/Icons/DBConnect.png"));
    ui->actionConnect_to_database->setIcon(dbConnectIcon);
    const QIcon dbDisconnectIcon = QIcon::fromTheme("connect-db", QIcon(":/Icons/DBDisconnect.png"));
    ui->actionDisconnect_from_database->setIcon(dbDisconnectIcon);
    const QIcon customerIcon = QIcon::fromTheme("connect-db", QIcon(":/Icons/CustomerIcon.png"));
    ui->actionCustomer->setIcon(customerIcon);
    const QIcon productIcon = QIcon::fromTheme("connect-db", QIcon(":/Icons/ProductIcon.png"));
    ui->actionProduct->setIcon(productIcon);
    const QIcon dealConsistenceIcon = QIcon::fromTheme("connect-db", QIcon(":/Icons/DealConsistence.png"));
    ui->actionDeal_consistence->setIcon(dealConsistenceIcon);
    const QIcon dealIcon = QIcon::fromTheme("connect-db", QIcon(":/Icons/DealIcon.png"));
    ui->actionDeal->setIcon(dealIcon);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*!
 * \brief MainWindow::connectToDatabase Makes connection to my local database
 *
!*/
void MainWindow::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();
    db.setDatabaseName("Driver={SQL Server};Server=(local);Trusted_Connection=Yes;Database=Оптово-розничная продажа товаров;");
    db.setHostName("LAPTOP-3IMO1OQI");
    db.setUserName("xp47x");
    if (db.open())
    {
    this->setWindowTitle("Database application [connected]");
    ui->actionConnect_to_database->setText("Connect to database [connected]");
    ui->actionConnect_to_database->setEnabled(false);
    ui->menuOpen->setEnabled(true);
    ui->actionDisconnect_from_database->setEnabled(true);
    customerModel = new QSqlTableModel(this, db);
    customerModel->setTable("Customer");
    customerModel->setEditStrategy(QSqlTableModel::OnRowChange);
    dealModel = new QSqlTableModel(this,db);
    dealModel->setTable("Deal");
    dealModel->setEditStrategy(QSqlTableModel::OnRowChange);
    dealConsistenceModel = new QSqlTableModel(this,db);
    dealConsistenceModel->setTable("Deal_consistence");
    dealConsistenceModel->setEditStrategy(QSqlTableModel::OnRowChange);
    productModel = new QSqlTableModel(this,db);
    productModel->setTable("Product");
    productModel->setEditStrategy(QSqlTableModel::OnRowChange);
    }
    else
    {
        ui->actionConnect_to_database->setText("Connect to database [disconnected]");
        qDebug() << "Cannot open database: " << db.lastError();
    }
}
/*!
 * \brief MainWindow::disconnectDatabase Disconnect from database. Also delete all QSqlTableModel objects.
 */
void MainWindow::disconnectDatabase()
{
    db.removeDatabase(db.connectionName());
    /*!
      \bug Необходимо закрыть все открытые таблицы, иначе вылет приложения.
      !*/
    if (!db.open())
    {
        ui->actionConnect_to_database->setText("Connect to database [disconnected]");
        ui->actionConnect_to_database->setEnabled(true);
        ui->menuOpen->setEnabled(false);
        ui->actionDisconnect_from_database->setEnabled(false);
        this->setWindowTitle("Database application [disconnected]");
    }
    else
    {
        em = new QErrorMessage();
        em->showMessage(db.lastError().databaseText());
    }

}

void MainWindow::openDealTable()
{
    QMdiSubWindow *subWindow = new QMdiSubWindow(this);
    Table *table = new Table(this);
    table->setWindowTitle("Deal");
    table->setSqlModel(dealModel);
    subWindow->setWidget(table);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    subWindow->show();
}

void MainWindow::openDealConsistenceTable()
{
    QMdiSubWindow *subWindow = new QMdiSubWindow(this);
    Table *table = new Table(this);
    table->setWindowTitle("Deal_consistence");
    table->setSqlModel(dealConsistenceModel);
    subWindow->setWidget(table);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    subWindow->show();
}

void MainWindow::openProductTable()
{
    QMdiSubWindow *subWindow = new QMdiSubWindow(this);
    Table *table = new Table(this);
    table->setWindowTitle("Product");
    table->setSqlModel(productModel);
    subWindow->setWidget(table);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    subWindow->show();
}

/*!
 * \brief MainWindow::openCustomersTable Open customers table to edit.
 */
void MainWindow::openCustomersTable()
{
    QMdiSubWindow *subWindow = new QMdiSubWindow(this);
    Table *table = new Table(this);
    table->setWindowTitle("Customer");
    table->setSqlModel(customerModel);
    subWindow->setWidget(table);
    ui->mdiArea->addSubWindow(subWindow);
    subWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    subWindow->show();
}
