#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include<string>
#include<iostream>

#include "GlobalTools.h"
#include "AdminMenuController.h"
#include "BakerMenuController.h"
#include "CostumerMenuController.h"
#include "SalesmanMenuController.h"


using namespace GlobalTools;
using namespace std;


class MainMenuController
{
    public:
        MainMenuController();
        virtual ~MainMenuController();
        void init();
    protected:

    private:
};

#endif // MAINMENUCONTROLLER_H
