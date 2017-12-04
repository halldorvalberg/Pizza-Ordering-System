#include "CostumerMenuController.h"

CostumerMenuController::CostumerMenuController()
{
    //ctor
}

CostumerMenuController::~CostumerMenuController()
{
    //dtor
}
void CostumerMenuController::init(){
    char input;
    cin >> input;
    if (input == 'm' || input == 'M'){
        OrderFromMenu();
    }
    else if(input == 'c' || input == 'C'){
        customOrder();

    }
    else if (input == 'q' || input == 'Q'){
        MainMenuController mmc;
    }
    else{
        cout << "Invalid input" << endl;
    }
}

void CostumerMenuController::customOrder(){
    cout << "Custom order" << endl;
    cout << "Please select toppings for your pizza: ";
    //displayToppings();
}
void CostumerMenuController::OrderFromMenu(){
    cout << "Make a new pizza from menu" << endl;
        cout << "Please select your pizza"
        //displaymenu()
}
