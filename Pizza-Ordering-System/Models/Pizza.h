#ifndef PIZZA_H
#define PIZZA_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "Toppings.h"

using namespace std;

class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();
        Pizza(int price, int sz, char name[50], vector<Toppings> tv);
        friend ifstream& operator >> (ifstream& in, Pizza& pizza);
        friend ofstream& operator << (ofstream& out, Pizza& pizza);
        friend ostream& operator << (ostream& out, Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);

        int price;
        int sz;
        char name[50];
        Toppings toppings[20];
        //vector<Toppings> toppingsVector;
        //vector<string> toppings;
};

#endif // PIZZA_H
