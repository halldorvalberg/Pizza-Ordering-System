#ifndef ORDERREPO_H
#define ORDERREPO_H

#include "LocationRepo.h"

class OrderRepo
{
    public:
        OrderRepo();
        virtual ~OrderRepo();
        void DisplayAllOrdersAtLocationBaker();
        void DisplayAllOrdersAtLocationSalesman()
        void changeOrderBaker();
        void changeOrderSalesman();

    protected:

    private:
};

#endif // ORDERREPO_H
