#include "SalesmanMenuController.h"

SalesmanMenuController::SalesmanMenuController()
{
    clearScreen();
    init();
}

SalesmanMenuController::~SalesmanMenuController()
{
    //dtor
}

void SalesmanMenuController::init(){
    SalesmanMenuDisplay();

    char input;
    do{
    cin >> input;
    }while(input !='D'&& input != 'd' &&
          input !='c'&& input != 'C' &&input !='q'&& input != 'Q');

    cout << "Please select your location: ";
    if (input == 'd' || input == 'D'){
        cout << "Displaying all pizzas" << endl;
        SalesmanMenuController smc;
    }
    else if(input == 'c' || input == 'C'){
        cout << "Please select a pizza order" << endl;
        SalesmanMenuController smc;
    }
    else if (input == 'q' || input == 'Q'){
        MainMenuController mmc;
    }
    else{
        cout << "Invalid input" << endl;
    }
}
void SalesmanMenuController::displayPizzas(){
    LocationRepo location;
    OrderRepo order;
    cout << "Please select your location" << endl;
    location.selectLocation();
    cout << "Displaying all pizza orders at your location" << endl;
    order.DisplayAllOrdersAtLocationSalesman();
}
void SalesmanMenuController::CheckoutPizza(){
    int ordernr;
    OrderRepo order;
    displayPizzas();
    cout << "Please select the order which" << endl;
    cin >> ordernr;
    order.changeOrderSalesman();
    cout << "Order has been changed!" << endl;
}
