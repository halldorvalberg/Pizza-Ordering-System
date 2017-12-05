#include "BakerMenuController.h"

BakerMenuController::BakerMenuController()
{
    clearScreen();
    init();
}

BakerMenuController::~BakerMenuController()
{
    //dtor
}

void BakerMenuController::init(){

    char input;
    do{
        BakerMenuDisplay();
        cin >> input;
    }while(input !='D'&& input != 'd' &&
          input !='c'&& input != 'C' &&input !='q'&& input != 'Q');
        outputstring("Please select your location: ");
        BakerMenuController bmc;
    if (input == 'd' || input == 'D'){
        outputstring("Displaying all pizzas" );
        displayPizzas();
        BakerMenuController bmc;
    }
    else if(input == 'c' || input == 'C'){
        cout << "Change a pizza" << endl;
        BakerMenuController bmc;

    }
    else if (input == 'q' || input == 'Q'){
        MainMenuController mmc;
    }
    else{
        cout << "Invalid input" << endl;
    }
}
void BakerMenuController::displayPizzas(){
    LocationRepo location;
    cout << "Please select your location" << endl;
    location.SelectLocation();
    cout << "Displaying all pizza orders at your location" << endl;
    //displayAllOrdersAtLocation();
}
void BakerMenuController::ChangePizzaStatus(){
    int ordernr;
    displayPizzas();
    cout << "Please select the order which is ready" << endl;
    cin >> ordernr;
    //some code here to display the pizza and change the status to ready
    cout << "Order has been changed!" << endl;
}
