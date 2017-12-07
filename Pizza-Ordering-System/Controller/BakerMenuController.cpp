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
    }while(input != 'D'&& input != 'd' &&
          input != 'c'&& input != 'C' &&
          input != 'q'&& input != 'Q');
    if (input == 'd' || input == 'D'){
        outputstring("Displaying all pizzas at your current location" );
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
    int bla;
    LocationRepo location;
    OrderRepo order;
    cout << "Please select your location" << endl;
    location.DisplayAllLocations();
    cin >> bla;
    cout << "Displaying all pizza orders at your location" << endl;
    order.DisplayAllOrdersAtLocationBaker();
}
void BakerMenuController::ChangePizzaStatus(){
    int ordernr;
    OrderRepo order;
    displayPizzas();
    cout << "Please select the order which is ready" << endl;
    cin >> ordernr;
    //some code here to display the pizza and change the status to ready
    order.changeOrderBaker();
    cout << "Order has been changed!" << endl;
}
