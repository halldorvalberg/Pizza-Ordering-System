#ifndef BAKERMENUCONTROLLER_H
#define BAKERMENUCONTROLLER_H

#include "MainMenuController.h"


class BakerMenuController
{
    public:
        BakerMenuController();
        virtual ~BakerMenuController();
        void displayPizzas();
        void ChangePizzaStatus();
        void init();

    protected:

    private:

};

#endif // BAKERMENUCONTROLLER_H
