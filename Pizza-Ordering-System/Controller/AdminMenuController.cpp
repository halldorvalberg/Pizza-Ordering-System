#include "AdminMenuController.h"

AdminMenuController::AdminMenuController()
{
    clearScrean();
    dispHeader();
    init();
}

AdminMenuController::~AdminMenuController()
{
    //dtor
}

void AdminMenuController::init()
{
    string admininput;

    do{
        AdminMenudisplay();
        cin >> admininput;


    }while(admininput[0] != '1' &&
           admininput[0] != '2' &&
           admininput[0] != '3' &&
           admininput[0] != '4' &&
           admininput[0] != 'q');

    if( admininput == "1"){
        ///PizzaMenu
        PizzaRepController prc;
    }
    else if( admininput == "2"){
        outputstring("I do nothing yet");
        AdminMenuController amc;
    }
    else if( admininput == "3"){
        outputstring("I do nothing yet");
        AdminMenuController amc;
    }
    else if( admininput == "4"){
        outputstring("I do nothing yet");
        AdminMenuController amc;
    }
    else if( admininput == "q"){
        MainMenuController mmc;
    }

}
