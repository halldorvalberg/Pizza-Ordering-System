#ifndef COSTUMERMENUCONTROLLER_H
#define COSTUMERMENUCONTROLLER_H

#include "MainMenuController.h"

class CostumerMenuController
{
    public:
        CostumerMenuController();
        virtual ~CostumerMenuController();
        void customOrder();
        void OrderFromMenu();
        void add_to_order(int e);

    protected:

    private:
        void init();
};

#endif // COSTUMERMENUCONTROLLER_H
