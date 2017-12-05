#include "CostumerMenuController.h"

CostumerMenuController::CostumerMenuController()
{
    clearScrean();
    dispHeader();
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
    }while(input !='1'&& input !='2'&&
           input !='q'&& input != 'Q');


    if (input == '1'){
        OrderFromMenu();
        CostumerMenuController cmc;
    }
    else if(input == '2'){
        customOrder();
        CostumerMenuController cmc;
    }
    else if (input == 'q' || input == 'Q'){
        MainMenuController mmc;
    }
}

void CostumerMenuController::OrderFromMenu(){
    display_menu();


    int input;
    cin >> input;


}



void CostumerMenuController::customOrder(){ ///work in progress
    cout << "Custom order" << endl;
    cout << "Please select toppings for your pizza: ";
}
