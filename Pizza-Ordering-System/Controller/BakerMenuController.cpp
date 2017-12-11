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
    OrderRepo order;

    string str;
    cout << "Please select your location" << endl;
    cin >> str;

    location.selectLocation(str);
    cout << "Displaying all pizza orders at your location" << endl;

    order.DisplayAllOrdersAtLocationBaker();
}
void BakerMenuController::ChangePizzaStatus(){
    int ordernr;
    OrderRepo order;

    displayPizzas();
    cout << "Please select the order which is ready" << endl;
    cin >> ordernr;
    order.changeOrderBaker();
    cout << "Order has been changed!" << endl;
}
