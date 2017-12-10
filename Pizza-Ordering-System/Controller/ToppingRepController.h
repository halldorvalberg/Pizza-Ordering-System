#ifndef TOPPINGREPCONTROLLER_H
#define TOPPINGREPCONTROLLER_H

#include "Toppings.h"
#include "MainMenuController.h"
#include <iostream>
using namespace std;


class ToppingRepController
{
    public:
        ToppingRepController();
        virtual ~ToppingRepController();
        void add_topping_to_menu();
        void remove_topping_from_menu();
        void AreToppingsValid(Toppings& topping);
        void displayToppings();

    protected:

    private:
        void init();
};

#endif // TOPPINGREPCONTROLLER_H
