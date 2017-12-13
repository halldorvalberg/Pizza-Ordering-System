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
        //add_to_menu();
        isPizzainputValid();
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


void PizzaRepController::add_to_menu(Pizza& pizza)
{
    string name, price, size;
    vector<string> toppings;

    dispHeader();

    //Pizza pizza;
    //cin >> pizza;
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

void PizzaRepController::isPizzainputValid(){
    ///handles error in pizza input
    Pizza pizza;

    try{
        cin >> pizza;

        ///name is valid if there are only letters.
        for(unsigned int i = 0; i < 50 ; i++){
            if (i < 50 && pizza.name[i] == '\0'){
                break;
            }
            else if(!isalpha(pizza.name[i])){
                throw PizzaNameError("Invalid Pizza name");
            }

        }
        ///if pizza size is not specific value, then throw error
        if(pizza.sz != 8 && pizza.sz != 16 && pizza.sz != 12){
            throw SizeException("Invalid size");
        }
        ///Price of pizza must be more than the price of base pizza
        if (pizza.price < 1500){
            throw PizzaPriceError("Not valid price");
        }
    }
    catch(PizzaNameError n){
        cout << n.getmessage() << endl;
        return;
    }
    catch(SizeException szi){
        cout << szi.getMesssage() << endl;
        return;
    }

    catch(PizzaPriceError p){
        cout << p.getmessage() << endl;
        return;
    }

    ///if manage to go through all the input check with no errors then a new pizza can be added to menu
    ///otherwise this code won't get executed
    add_to_menu(pizza);
}
