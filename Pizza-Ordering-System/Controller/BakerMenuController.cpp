#include "BakerMenuController.h"

BakerMenuController::BakerMenuController()
{
    //ctor
}

BakerMenuController::~BakerMenuController()
{
    //dtor
}

void init(){
    BakerView();

    char input;
    cin >> input;
    cout << "Please select your location: ";
    //selectlocation();
    if (input == 'd' || input == 'D'){
        cout << "Displaying all pizzas" << endl;
        //displaypizzas()
    }
    else if(input == 'c' || input == 'C'){

        cout << "Change a pizza" << endl;
    }
    else if (input == 'q' || input == 'Q'){
        MainMenuController mmc;
    }
    else{
        cout << "Invalid input" << endl;
    }
}
