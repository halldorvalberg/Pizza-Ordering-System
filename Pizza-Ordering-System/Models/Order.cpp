#include "Order.h"

Order::Order()
{
    state = false;
    payed = false;
    price = 0;
}

Order::~Order()
{
    //dtor
}

istream& operator >> (istream& in, Order& order){
    cout << "Enter your name: ";
    in >> ws;
    in.getline(order.name, 40);
    cout << "Enter your phone number: ";
    in >> order.phone_number;

//    in >> order.state;
//    in >> order.payed;
//    in >> order.id;
//    in >> order.date_of;
//    in >> order.date_by;
    return in;
}
ostream& operator << (ostream& out, Order& order){
    string str(order.name);

    out << "Order placed by: " << str << endl;
    out << "\tNumber: " << order.phone_number << endl;
    for (int i = 0; i < order.number_of_pizzas; i++) {
        out << order.ordered[i] << endl;
    }


    out << order.state;
    out << order.payed;

    return out;
}
