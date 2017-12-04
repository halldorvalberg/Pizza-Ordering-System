#ifndef COSTUMERMENUCONTROLLER_H
#define COSTUMERMENUCONTROLLER_H
#include "CostumerMenuView.h"
#include "CostumerMenu.h"
class CostumerMenuController
{
    public:
        CostumerMenuController();
        virtual ~CostumerMenuController();
        void customOrder();

    protected:

    private:
        void init();
};

#endif // COSTUMERMENUCONTROLLER_H
