#ifndef SALESMANMENUCONTROLLER_H
#define SALESMANMENUCONTROLLER_H

#include "MainMenuController.h"

class SalesmanMenuController
{
    public:
        SalesmanMenuController();
        virtual ~SalesmanMenuController();
        void displayPizzas();
        void CheckoutPizza();

    protected:

    private:
        void init();
};

#endif // SALESMANMENUCONTROLLER_H
