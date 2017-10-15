#include <QString>
#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer
{
public:
    Customer();
    int CustomerID;
    QString CustomerName;
    QString CompanyName;
    QString CompanyAddress;
    QString MobilePhone;
};

#endif // CUSTOMER_H
