#include "Order.h"

Order::Order()
{

}

Order::Order(int kt, vector<Pizza> val)

{
    this->state = false;
    this->payed = false;
    this->id = kt;
    this->date_of = time(0);
    this->date_by = time(0) + 900;

    for(int i = 0; i < val.size(); i++) {
        this->price += val[i].price;
    }
    this->ordervector.swap(val);

}

Order::~Order()
{
    //dtor
}
