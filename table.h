#ifndef TABLE_H
#define TABLE_H

#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0);
    void setSqlModel(QSqlTableModel *sqlModel);
    ~Table();
    QSqlTableModel *model;


private:
    Ui::Table *ui;
signals:
    void Error();
public slots:
    void addNewLine();
    void deleteLine();
    void updateDatcabase();
};

#endif // CUSTOMERS_H
