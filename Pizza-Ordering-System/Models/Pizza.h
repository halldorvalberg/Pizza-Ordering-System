#ifndef PIZZA_H
#define PIZZA_H

#include "Toppings.h"


class Pizza
{
    public:
        Pizza();
        Pizza(string name, int price, int size);
        string getname();
        int getsize();
        int getprice();
        friend ifstream& operator >> (ifstream& in, Pizza& pizza);
        friend ofstream& operator >> (ofstream& out, Pizza& pizza);

        virtual ~Pizza();

    protected:

    private:
        string name;
        int price;
        int size;
        vector <Toppings> toppings;
};

#endif // PIZZA_H
