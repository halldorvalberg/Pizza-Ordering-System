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

