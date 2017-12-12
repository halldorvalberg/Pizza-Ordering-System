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
    ///Removes a certain pizza from menu
    clearScreen();
    dispHeader();
    display_menu();

    outputstring("Input number of element to remove or q to cancel: ");

    char element;
    int toremove;

    cin >> element;

    if(element != 'q' && 48 < element && element < 58) {
        toremove = element - 49;


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

}

void isPizzainputValid(){
    ///handles error in pizza input, doesn't do anything
    Pizza pizza;

    try{
        cin >> pizza;
        if (pizza.price < 0){
            throw PizzaPriceError("Not valid price");
        }
        if(pizza.sz < 0){
            throw SizeException("Invalid size");
        }

        for(unsigned int i = 0; i < 50 ; i++){
            ///value for A-Z and A-Z in ascii table
            if(pizza.name[i] < 65 && pizza.name[i] > 123){
                throw PizzaNameError ("Not valid name");
            }
            ///the input between 91 and 96 in Ascii table except for \ which wasnt working
            else if(pizza.name[i] == '[' && pizza.name[i] == ']' && pizza.name[i] == '^' && pizza.name[i] == '`'){
                throw PizzaNameError("Not valid name");
            }
        }
    }

    catch(PizzaPriceError p){
        cout << p.getmessage() << endl;
    }
    catch(SizeException szi){
        cout << szi.getMesssage() << endl;
    }
    catch(PizzaNameError n){
        cout << n.getmessage() << endl;
    }

}
