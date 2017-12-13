#include "SalesmanMenuController.h"

SalesmanMenuController::SalesmanMenuController()
{
    init();
}

SalesmanMenuController::~SalesmanMenuController()
{
    //dtor
}

void SalesmanMenuController::init(){
    bool in_process = true;
    char input;

    do{
        do{
            clearScreen();
            dispHeader();
            SalesmanMenuDisplay();
            cin >> input;

        }while(input !='1' && input != '2' &&
               input !='q' && input != 'Q');

    if (input == '1'){
            //Display ready pizzas
            clearScreen();
            dispHeader();
            outputstring("Displaying all ready Orders");
            SalesmanOrderView();
            outputstring("Input any key to continue");
            char cont;
            cin >> cont;
    }
    else if(input == '2'){
            mark_pizza_ready();
    }
    else if (input == 'q' || input == 'Q'){
        break;
    }
    }while(in_process);
}

void SalesmanMenuController::mark_pizza_ready()
{
    clearScreen();
    dispHeader();
    SalesmanOrderView();
    outputstring("Select Order to mark ready or 0 to return");
    int input;
    cin >> input;
    if(input != 0){
        sales_mark_element_ready(input);
    }
}
