#ifndef DEALCONSISTENCE_H
#define DEALCONSISTENCE_H
#include <product.h>

class DealConsistence
{
public:
    DealConsistence();
    int DealConsistenceID;
    Product *product;
    int AmountOfProducts;
};

#endif // DEALCONSISTENCE_H
