#include "CostumerMenuController.h"

CostumerMenuController::CostumerMenuController()
{
    clearScrean();
    init();
}

CostumerMenuController::~CostumerMenuController()
{
    //dtor
}
void CostumerMenuController::init(){
    char input;
    do{
        CostumerMenuDisplay();
        cin >> input;
    }while(input !='m'&& input != 'M' &&
          input !='c'&& input != 'C' &&input !='q'&& input != 'Q');
    if (input == 'm' || input == 'M'){
        OrderFromMenu();
        CostumerMenuController cmc;
    }
    else if(input == 'c' || input == 'C'){
        customOrder();
        CostumerMenuController cmc;
    }
    else if (input == 'q' || input == 'Q'){
            MainMenuController mmc;
    }
    else{
        cout << "Invalid input, please try again." << endl;
    }
}

void CostumerMenuController::customOrder(){ ///work in progress
    cout << "Custom order" << endl;
    cout << "Please select toppings for your pizza: ";
}
void CostumerMenuController::OrderFromMenu(){ ///work in progress
    cout << "Make a new pizza from menu" << endl;
    cout << "Please select your pizza";
}
