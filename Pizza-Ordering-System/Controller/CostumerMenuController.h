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
        void customOrder(Order &order);
        void OrderFromMenu(Order &order);
        void add_to_order(int e, Order &order);
        void get_id();
        void add_order_to_file(Order neworder);
        void addToppingsToOrder(int e, Pizza &order);
        void InputForEachPizza(int amount, int menu);

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
