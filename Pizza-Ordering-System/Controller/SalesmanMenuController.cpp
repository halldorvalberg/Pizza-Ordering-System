#include "SalesmanMenuController.h"

SalesmanMenuController::SalesmanMenuController()
{
    clearScrean();
    init();
}

SalesmanMenuController::~SalesmanMenuController()
{
    //dtor
}

void SalesmanMenuController::
    init(){
    SalesmanMenuDisplay();

    char input;
    do{
    cin >> input;
    }while(input !='D'&& input != 'd' &&
          input !='c'&& input != 'C' &&input !='q'&& input != 'Q');

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
