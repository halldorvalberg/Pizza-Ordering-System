#ifndef SALESMANMENUCONTROLLER_H
#define SALESMANMENUCONTROLLER_H

#include "MainMenuController.h"

class SalesmanMenuController
{
    public:
        SalesmanMenuController();
        virtual ~SalesmanMenuController();
        void mark_pizza_ready();

    protected:

    private:
        void init();
};

#endif // SALESMANMENUCONTROLLER_H
