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
    string str;
    LocationRepo location;
    cout << "Please select your location" << endl;
    location.SelectLocation();
    cout << "Displaying all pizza orders at your location" << endl;
    //displayAllOrdersAtLocation();
}
void BakerMenuController::ChangePizzaStatus(){
    displayPizzas();
    cout << "Please select the order you are going to modify" << endl;
    cout << "r: for ready" << endl <<"p: still in progress" << endl;
    //selectPizzaOrder();
    cout << "I do nothing yet" << endl;
}
