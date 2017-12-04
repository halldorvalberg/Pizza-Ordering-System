#ifndef PIZZA_H
#define PIZZA_H

#include "MainMenuController.h"

#include "Toppings.h"


class Pizza
{
    public:
        Pizza();
        Pizza(string name, int price, char size);
        Pizza(string name, vector<Toppings> toppings, int size, int price);
        string getpizzaname();
        int getpizzasize();
        int getpizzaprice();
        void addtopping();
        friend ifstream& operator >> (ifstream& in, Pizza& pizza);
        friend ofstream& operator << (ofstream& out, Pizza& pizza);
        friend ostream& operator << (ostream& out, Pizza& pizza);
        friend istream& operator >> (istream& in, Pizza& pizza);
        virtual ~Pizza();

    protected:

    private:
        string name;
        int price;
        char size;
        vector <Toppings> toppings;
};

#endif // PIZZA_H
