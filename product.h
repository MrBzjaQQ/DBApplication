#include <QString>
#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
public:
    Product();
    int ProductID;
    QString ProductName;
    QString UnitsOfProductAmount;
    int WholesalePrice;
    int RetailPrice;
    QString AboutInformation;
};

#endif // PRODUCT_H
