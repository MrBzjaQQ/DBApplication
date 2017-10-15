#ifndef DEAL_H
#define DEAL_H
#include <customer.h>
#include <dealconsistence.h>

class Deal
{
public:
    Deal();
    int DealID;
    Customer *customer;
    DealConsistence *dealConsistence;
    int Discount;
    int Price;
};

#endif // DEAL_H
