#include "BakerMenuController.h"

BakerMenuController::BakerMenuController()
{
    clearScrean();
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
    //selectlocation();
    if (input == 'd' || input == 'D'){
        outputstring("Displaying all pizzas" );
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
