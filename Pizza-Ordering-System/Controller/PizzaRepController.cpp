#include "PizzaRepController.h"

PizzaRepController::PizzaRepController()
{
    clearScrean();
    dispHeader();
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
        add_to_menu();
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

void PizzaRepController::add_to_menu()
{
    ofstream fout;
    fout.open("Pizza_Menu_Binary.dat", ios::binary|ios::app);
    fout.close();
}
