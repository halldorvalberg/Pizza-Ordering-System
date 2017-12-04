#ifndef TOPPINGS_H
#define TOPPINGS_H

#include <iostream>
#include <fstream>
using namespace std;

class Toppings
{
    public:
        Toppings();
        Toppings(string name, int price);

        string gettoppingname();
        int gettoppingprice();

        friend ifstream& operator >> (ifstream& in, Toppings& topping);
        friend ofstream& operator >> (ofstream& out, Toppings& topping);

    protected:

    private:
        string name;
        int price;
};

#endif // TOPPINGS_H
