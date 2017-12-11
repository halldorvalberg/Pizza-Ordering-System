#include "PizzaRepController.h"

PizzaRepController::PizzaRepController()
{
    clearScreen();
    dispHeader();
    init();
}

PizzaRepController::~PizzaRepController()
{
    //dtor
}

void PizzaRepController::init()
{
    string input;

    do{
        PizzaRepMenuDisplay();
        cin >> input;
        clearScreen();
    }while(input[0] != '1' &&
           input[0] != '2' &&
           input[0] != '3' &&
           input[0] != 'q');

    if(input[0] == '1'){
        ///View Pizza Menu
        clearScreen();
        dispHeader();
        display_menu();
        outputstring("");
        outputstring("Enter any key to exit");
        cin >> input;
        PizzaRepController prc;
    }
    else if (input[0] == '2'){
        ///Add item to pizza menu
        add_to_menu();
        outputstring("Enter any key to continue");
        cin >> input;
        PizzaRepController prc;
    }
    else if (input[0] == '3'){
        ///Remove Item from pizza menu
        remove_element_from_menu();
        PizzaRepController prc;
    }
    else if (input[0] == 'q'){
        ///Return to Admin Menu
        AdminMenuController amc;
    }
}


void PizzaRepController::add_to_menu()
{
    string name, price, size;
    vector<string> toppings;

    dispHeader();

    Pizza pizza;
    cin >> pizza;
    outputstring("\nYour pizza: \n");
    cout << pizza;

    ofstream fout;

    fout.open("Pizza_Menu_Binary.dat", ios::binary|ios::app);

    fout.write((char*)(&pizza), sizeof(Pizza));

    fout.close();

    outputstring("\n\nYour Pizza has been added to the menu\n");


}

void PizzaRepController::remove_element_from_menu()
{
    clearScreen();
    dispHeader();
    display_menu();

    outputstring("Input number of element to remove: ");

    char element;
    int toremove;

    cin >> element;

    if(element == 'q') {
        PizzaRepController prc;
    }
    else if (48 < element && element < 58) {
        toremove = element - 49;
    }

    ifstream fin;
    fin.open("Pizza_Menu_Binary.dat", ios::binary);
    fin.seekg(0, fin.end);
    int rec = fin.tellg() / sizeof(Pizza);
    fin.seekg(0, fin.beg);
    Pizza *data = new Pizza[rec];
    fin.read((char*)data, sizeof(Pizza)*rec);
    fin.close();

    ofstream fout;
    fout.open("Pizza_Menu_Binary.dat", ios::binary);

    for(int i = 0; i < rec; i++) {
        if(i != toremove){
            fout.write((char*)(&data[i]), sizeof(Pizza));
        }
    }
    fout.close();

    delete [] data;

}

