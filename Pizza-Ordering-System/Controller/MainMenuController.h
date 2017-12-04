#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include<string>
#include<iostream>

#include "GlobalTools.h"
#include "MainMenuView.h"
#include "AdminMenuView.h"
#include "DisplayString.h"
#include "BakerMenuView.h"
#include "CostumerMenuView.h"
#include "SalesmanMenuView.h"

#include "AdminMenuController.h"
#include "BakerMenuController.h"
#include "CostumerMenuController.h"
#include "SalesmanMenuController.h"
#include "PizzaRepController.h"

using namespace SalesmanMenuView;
using namespace CostumerMenuView;
using namespace BakerMenuView;
using namespace DisplayString;
using namespace AdminMenuView;
using namespace MainMenuView;
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
