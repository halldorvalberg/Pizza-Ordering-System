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

    char input;

    do{
        BakerView();
        cin >> input;
    while(input !='D'&& input != 'd' &&
          input !='c'&& input != 'C' &&input !='q'&& input != 'Q');

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
