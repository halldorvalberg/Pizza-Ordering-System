#include "ToppingRepController.h"

ToppingRepController::ToppingRepController()
{
    //ctor
}

ToppingRepController::~ToppingRepController()
{
    //dtor
}

void ToppingRepController::add_topping_to_menu(){
    string str;
    int i;

    cin >> str >> i;

    Toppings topping(str, i);
    ///write the content of this into a file
    ofstream fout;
    fout.open("Toppings_Menu_Binary.txt", ios::app);

    if(fout.is_open()){
    fout << str << "\t" << i << endl;
    fout.close();
    }
    else{
        cout << "File could not be opened!" << endl;
    }
}
void ToppingRepController::remove_topping_from_menu(){
    ///Remove a certain topping from menu, work in progress!!
    cout << "I do nothing yet, replace me!!" << endl;
}

void ToppingRepController::init(){
    string input;

    do{
        ToppingRepMenuDisplay();
        cin >> input;
        clearScrean();
    }while(input[0] != '1' &&
           input[0] != '2' &&
           input[0] != '3' &&
           input[0] != 'q');

    if(input[0] == '1'){
        ///View Toppings Menu
        display_menu();
        outputstring("");
        outputstring("Enter any key to exit");
        cin >> input;
        ToppingRepController trc;
    }
    else if (input[0] == '2'){
        ///Add item to toppings menu
        add_topping_to_menu();
        ToppingRepController trc;
    }
    else if (input[0] == '3'){
        ///Remove Item from toppings menu
        remove_topping_from_menu();
        ToppingRepController trc;
    }
    else if (input[0] == 'q'){
        ///Return to Admin Menu
        AdminMenuController amc;
    }
}