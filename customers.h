#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QWidget>

namespace Ui {
class Customers;
}

class Customers : public QWidget
{
    Q_OBJECT

public:
    explicit Customers(QWidget *parent = 0);
    ~Customers();

private:
    Ui::Customers *ui;
};

#endif // CUSTOMERS_H
