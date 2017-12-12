#ifndef PIZZAREPCONTROLLER_H
#define PIZZAREPCONTROLLER_H

#include "MainMenuController.h"
#include "PizzaNameError.h"
#include "PizzaPriceError.h"
#include "SizeException.h"

class PizzaRepController
{
    public:
        PizzaRepController();
        virtual ~PizzaRepController();
        void init();
        void add_to_menu();
        void remove_element_from_menu();

    protected:

    private:
};

#endif // PIZZAREPCONTROLLER_H
