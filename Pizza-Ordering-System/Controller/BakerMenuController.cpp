#include "BakerMenuController.h"

BakerMenuController::BakerMenuController()
{
    init();
}

BakerMenuController::~BakerMenuController()
{
    //dtor
}

void BakerMenuController::init(){
    bool in_process = false;
    char input;
    do{
        do{
            clearScreen();
            dispHeader();
            BakerMenuDisplay();
            cin >> input;
        }while(input !='1'&& input != '2' &&
               input !='Q'&& input != 'q');


        if (input == '1'){
            outputstring("Displaying all pizzas" );
            clearScreen();
            dispHeader();
            BakerOrderView();
            outputstring("Input any key to continue");
            char cont;
            cin >> cont;

        }
        else if(input == '2'){
            ChangePizzaStatus();
        }
        else if (input == 'q' || input == 'Q'){
            break;
        }
        else{
            cout << "Invalid input" << endl;
        }
    }while(in_process == true);
}

void BakerMenuController::ChangePizzaStatus()
{
    clearScreen();
    dispHeader();
    BakerOrderView();
    outputstring("Select Order to mark ready or 0 to return: ");
    int input;
    cin >> input;
    if(input != 0) {
        baker_mark_element_ready(input);
    }

}
