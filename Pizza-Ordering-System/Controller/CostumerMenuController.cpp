#include "CostumerMenuController.h"

CostumerMenuController::CostumerMenuController()
{
    clearScreen();
    dispHeader();
    init();
}

CostumerMenuController::~CostumerMenuController()
{
    //dtor
}
void CostumerMenuController::init(){

    char input;

    do{
        CostumerMenuDisplay();
        cin >> input;
    }while(input !='1'&& input !='2'&&
           input !='q'&& input != 'Q');


    if (input == '1'){
        ///Order pizza from menu
        OrderFromMenu();
        CostumerMenuController cmc;
    }
    else if(input == '2'){
        ///View Order
        view_order();
        //global view
        outputstring("Continu");
        cin >> input;

        CostumerMenuController cmc;
    }
    else if (input == 'q' || input == 'Q'){
        MainMenuController mmc;
    }
}

void CostumerMenuController::OrderFromMenu(){ ///WIP
    clearScreen();
    dispHeader();
    display_menu();

    outputstring("\nSelect pizza to add to order or 0 (zero) to return:");
    int input;
    do{
    cin >> input;
    }while(0 > input);

    if(input == 0){
        CostumerMenuController cmc;
    }
    else{
        //ATH hvort innslag samvarist lista
        add_to_order(input);
    }
}



void CostumerMenuController::customOrder(){ ///work in progress
    cout << "Custom order" << endl;
    cout << "Please select toppings for your pizza: ";
}

void CostumerMenuController::add_to_order(int e)
{
    Pizza order;
    ifstream fin;

    fin.open("Pizza_Menu_Binary.dat", ios::binary);

    fin.read((char*)(&order), sizeof(Pizza) * e-1);

    fin.close();

    ofstream fout;

    fout.open("Costumer_Order_Binary.dat", ios::binary|ios::app);

    fout.write((char*)(&order), sizeof(Pizza));

    fout.close();
}
