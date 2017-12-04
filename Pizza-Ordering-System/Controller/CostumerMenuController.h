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

    protected:

    private:
        void init();
};

#endif // COSTUMERMENUCONTROLLER_H
