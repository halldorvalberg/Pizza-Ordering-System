#include "MainMenuController.h"

MainMenuController::MainMenuController()
{
    clearScrean();
    init();
}

MainMenuController::~MainMenuController()
{
    //dtor
}


void MainMenuController::init()
{
    string inputString;

    do{
//        displayMenu();
         cin >> inputString;
    }while (inputString[0] != 'a' &&
            inputString[0] != 'b' &&
            inputString[0] != 'c' &&
            inputString[0] != 's' &&
            inputString[0] != 'q');

    if( inputString == "a"){
        AdminMenuController amc;
    }
    else if( inputString == "b"){
        BakerMenuController amc;
    }
    else if( inputString == "c"){
        CostumerMenuController amc;
    }
    else if( inputString == "s"){
        SalesmanMenuController amc;
    }
    else if( inputString == "q"){
//        exitAplication();
    }

}

