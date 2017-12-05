#include "ToppingRepController.h"

ToppingRepController::ToppingRepController()
{
    //ctor
}

ToppingRepController::~ToppingRepController()
{
    //dtor
}

void ToppingRepController::add_topping_to_menu(){

}
void ToppingRepController::remove_topping_from_menu(){
}

void ToppingRepController::init(){
    string input;

    do{
        ToppingRepMenuDisplay();
        cin >> input;
        clearScrean();
    }while(input[0] != '1' &&
           input[0] != '2' &&
           input[0] != '3' &&
           input[0] != 'q');

    if(input[0] == '1'){
        ///View Toppings Menu
        display_menu();
        outputstring("");
        outputstring("Enter any key to exit");
        cin >> input;
        ToppingRepController trc;
    }
    else if (input[0] == '2'){
        ///Add item to toppings menu
        add_topping_to_menu();
        ToppingRepController trc;
    }
    else if (input[0] == '3'){
        ///Remove Item from toppings menu
        remove_topping_from_menu();
        ToppingRepController trc;
    }
    else if (input[0] == 'q'){
        ///Return to Admin Menu
        AdminMenuController amc;
    }
}
