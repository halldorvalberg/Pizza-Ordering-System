#ifndef TOPPINGREPCONTROLLER_H
#define TOPPINGREPCONTROLLER_H

#include "MainMenuController.h"
#include "ToppingNameError.h"
#include "ToppingPriceError.h"
#include <iostream>
#include <algorithm>
using namespace std;


class ToppingRepController
{
    public:
        ToppingRepController();
        virtual ~ToppingRepController();
        void add_topping_to_menu(Toppings& topping);
        void remove_topping_from_menu();
        void AreToppingsValid(Toppings& topping) throw (ToppingNameError, ToppingPriceError);
        void displayToppings();

    protected:

    private:
        void init();
};

#endif // TOPPINGREPCONTROLLER_H
