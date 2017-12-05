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
        outputstring("Place order (y/n)");
        char confirm;
        cin >> confirm;
        if(confirm == 'y' || confirm == 'Y') {
            add_all_to_file("Costumer_Order_Binary.dat", "Ordered_Pizzas_Binary.dat");
        }
        else{
        CostumerMenuController cmc;
        }
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
    int menu;
    do{
    cin >> menu;
    }while(0 > menu);

    if(menu == 0){
        CostumerMenuController cmc;
    }
    else{
        //ATH hvort innslag samvarist lista
        add_to_order(menu);
    }
}



void CostumerMenuController::customOrder(){ ///work in progress
    cout << "Custom order" << endl;
    cout << "Please select toppings for your pizza: ";
}

void CostumerMenuController::add_to_order(int e)
{
    Pizza pizza;

    ifstream fin;

    fin.open("Pizza_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Pizza);
    fin.seekg(0, fin.beg);

    if(records >= e) {

    for(int i = 0; i < e; i++){
        fin.read((char*)(&pizza), sizeof(Pizza));
    }
    fin.close();

    ofstream fout;

    fout.open("Costumer_Order_Binary.dat", ios::binary|ios::app);

    fout.write((char*)(&pizza), sizeof(Pizza));

    fout.close();

    }
    else {
        outputstring("Fatal ERROR");
    }



}
