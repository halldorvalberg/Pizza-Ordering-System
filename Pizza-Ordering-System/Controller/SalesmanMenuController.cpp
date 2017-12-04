#include "SalesmanMenuController.h"

SalesmanMenuController::SalesmanMenuController()
{
    //ctor
}

SalesmanMenuController::~SalesmanMenuController()
{
    //dtor
}

void init(){
    SalemanView();

    char input;
    cin >> input;
    cout << "Please select your location: ";
    //selectlocation();
    if (input == 'd' || input == 'D'){
        cout << "Displaying all pizzas" << endl;
        //displaypizzas()
    }
    else if(input == 'c' || input == 'C'){

        cout << "Please select a pizza order" << endl;
    }
    else if (input == 'q' || input == 'Q'){
        MainMenuController mmc;
    }
    else{
        cout << "Invalid input" << endl;
    }
}
