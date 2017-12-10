#ifndef TOPPINGS_H
#define TOPPINGS_H

#include <iostream>
#include <fstream>

using namespace std;

class Toppings
{
    public:
        Toppings();
        Toppings(char name[20], int price);

       // char gettoppingname();
       // int gettoppingprice();

        friend istream& operator >> (istream& in, Toppings& topping);
        friend ostream& operator << (ostream& out, Toppings& topping);
        friend ifstream& operator >> (ifstream& in, Toppings& topping);
        friend ofstream& operator << (ofstream& out, Toppings& topping);

    protected:

    private:
        char name[20];
        int price;
};

#endif // TOPPINGS_H
