#ifndef COSTUMERMENUCONTROLLER_H
#define COSTUMERMENUCONTROLLER_H

#include "MainMenuController.h"
#include "ToppingRepController.h"
#include "Order.h"


class CostumerMenuController
{
    public:
        CostumerMenuController();
        virtual ~CostumerMenuController();
        void add_order_to_file(Order neworder);

        Toppings choose_topping_menu();
        int chooseSize();
        Pizza customOrder();
        Pizza chooseFromMenu();

        char name[40];
        int phone_number;
        int pizzas_ordered;
        int total_price;
        int toppings_ordered;

    protected:

    private:
        void init();
};

#endif // COSTUMERMENUCONTROLLER_H
