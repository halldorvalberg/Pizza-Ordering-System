#ifndef TOPPINGREPCONTROLLER_H
#define TOPPINGREPCONTROLLER_H

#include "MainMenuController.h"


class ToppingRepController
{
    public:
        ToppingRepController();
        virtual ~ToppingRepController();
        void add_topping_to_menu();
        void remove_topping_from_menu();

    protected:

    private:
        void init();
};

#endif // TOPPINGREPCONTROLLER_H
