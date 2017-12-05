#include "AdminMenuController.h"

AdminMenuController::AdminMenuController()
{
    clearScrean();
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
           admininput[0] != '5' &&
           admininput[0] != '6' &&
           admininput[0] != '7' &&
           admininput[0] != 'q');

    if( admininput == "1"){
        ///PizzaMenu
        PizzaRepController prc;
    }
    else if( admininput == "2"){
        outputstring("I do nothing yet");
    }
    else if( admininput == "3"){
        outputstring("I do nothing yet");
    }
    else if( admininput == "4"){
        outputstring("I do nothing yet");
    }
    else if( admininput == "5"){
        outputstring("I do nothing yet");
    }
    else if( admininput == "6"){
        outputstring("I do nothing yet");
    }
    else if( admininput == "7"){
        outputstring("I do nothing yet");
    }
    else if( admininput == "q"){
        MainMenuController mmc;
    }

}
