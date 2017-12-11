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
        //Order(int kt, vector<Pizza> val);
        virtual ~Order();

        void add_pizza(Pizza pizza);

        friend istream& operator >> (istream& in, Order& order);
        friend ostream& operator << (ostream& out, Order& order);


        bool state;
        bool payed;
        int price;
        char name[40];
        int phone_number;
        int number_of_pizzas;
        Pizza ordered[20];
        //int id;
        //time_t date_of;
        //time_t date_by;
      //  vector <Pizza> ordervector;
};

#endif // ORDER_H
