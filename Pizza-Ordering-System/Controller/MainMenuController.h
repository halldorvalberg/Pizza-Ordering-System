#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include<string>
#include<iostream>
#include<fstream>
#include<vector>

#include "GlobalTools.h"
#include "MainMenuView.h"
#include "AdminMenuView.h"
#include "DisplayString.h"
#include "BakerMenuView.h"
#include "CostumerMenuView.h"
#include "SalesmanMenuView.h"
#include "GlobalView.h"
#include "PizzaRepMenuView.h"
#include "ToppingRepMenuView.h"

#include "AdminMenuController.h"
#include "BakerMenuController.h"
#include "CostumerMenuController.h"
#include "SalesmanMenuController.h"
#include "PizzaRepController.h"
#include "Pizza.h"
#include "Toppings.h"

#include "ToppingNameError.h"
#include "ToppingPriceError.h"
#include "Toppings.h"

using namespace std;
using namespace ToppingRepMenuView;
using namespace PizzaRepMenuView;
using namespace GlobalView;
using namespace SalesmanMenuView;
using namespace CostumerMenuView;
using namespace BakerMenuView;
using namespace DisplayString;
using namespace AdminMenuView;
using namespace MainMenuView;
using namespace GlobalTools;


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
