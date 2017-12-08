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

    for(unsigned int i = 0; i < val.size(); i++) {
        this->price += val[i].price;
    }
    this->ordervector.swap(val);

}

Order::~Order()
{
    //dtor
}
istream& operator >> (istream& in, Order& order){
    in >> order.state;
    in >> order.payed;
    in >> order.id;
    in >> order.date_of;
    in >> order.date_by;
    return in;
}
ostream& operator << (ostream& out, Order& order){
    out << order.state;
    out << order.payed;
    out << order.id;
    out << order.date_of;
    out << order.date_by;
    return out;
}
