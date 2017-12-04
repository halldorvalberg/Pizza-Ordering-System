#include "PizzaRepController.h"

PizzaRepController::PizzaRepController()
{
    clearScrean();
    init();
}

PizzaRepController::~PizzaRepController()
{
    //dtor
}

void PizzaRepController::init()
{
    string input;

    do{
        PizzaRepMenuDisplay();
        cin >> input;
        clearScrean();
    }while(input[0] != '1' &&
           input[0] != '2' &&
           input[0] != '3' &&
           input[0] != 'q');

    if(input[0] == '1'){
        ///View Pizza Menu
        outputstring("I don't do anything yet");
        PizzaRepController prc;
    }
    else if (input[0] == '2'){
        ///Add item to Pizza Menu
        outputstring("I don't do anything yet");
        PizzaRepController prc;
    }
    else if (input[0] == '3'){
        ///Remove Item from pizza menu
        outputstring("I don't do anything yet");
        PizzaRepController prc;
    }
    else if (input[0] == 'q'){
        ///Return to Admin Menu
        AdminMenuController amc;
    }
}
