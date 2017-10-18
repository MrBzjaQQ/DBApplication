#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

#include <QtSql/QSqlDatabase>
#include <QErrorMessage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString lastError;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
     QSqlDatabase db;
     QSqlTableModel *customerModel;
     QSqlTableModel *dealModel;
     QSqlTableModel *productModel;
     QSqlTableModel *dealConsistenceModel;

private:
     QErrorMessage *em;
    Ui::MainWindow *ui;
public slots:
    void openCustomersTable();
    void connectToDatabase();
    void disconnectDatabase();
    void openDealTable();
    void openDealConsistenceTable();
    void openProductTable();
};

#endif // MAINWINDOW_H
