#ifndef ORDER_H
#define ORDER_H

#include<vector>
#include<iostream>
#include<ctime>

#include"Pizza.h"

using namespace std;

class Order
{
    public:
        Order();
        Order(int kt, vector<Pizza> val);
        virtual ~Order();
        friend istream& operator >> (istream& in, Order& order);
        friend ostream& operator << (ostream& out, Order& order);

    protected:

    private:
        bool state;
        bool payed;
        int id;
        int price;
        time_t date_of;
        time_t date_by;
        vector <Pizza> ordervector;
};

#endif // ORDER_H
