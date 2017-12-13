#include "ToppingRepController.h"

ToppingRepController::ToppingRepController()
{
    init();
}

ToppingRepController::~ToppingRepController()
{
    //dtor
}


void ToppingRepController::init(){
    string input;
    do{
        clearScreen();
        dispHeader();
        do{
            ToppingRepMenuDisplay();
            cin >> input;
            clearScreen();
        }while(input[0] != '1' &&
               input[0] != '2' &&
               input[0] != '3' &&
               input[0] != 'q');

        if(input[0] == '1'){
            ///View Toppings Menu
            clearScreen();
            displayToppings();
            outputstring("");
            outputstring("Enter any key to exit");
            cin >> input;
        }
        else if (input[0] == '2'){
            ///Add item to toppings menu
            Toppings topping;
            AreToppingsValid(topping);
            outputstring("Enter any key to continue");
            cin >> input;
        }
        else if (input[0] == '3'){
            ///Remove Item from toppings menu
            remove_topping_from_menu();
        }
        else if (input[0] == 'q'){
            break;
        }
    }while(true);

}

void ToppingRepController::add_topping_to_menu(Toppings& topping){

    clearScreen();
    dispHeader();

    ///write the content of this into a file
    string name, price;
    cout << "Your topping: " << topping;
    ofstream fout;
    fout.open("Toppings_Menu_Binary.dat", ios::app|ios::binary);

    fout.write((char*)(&topping), sizeof(Toppings));
    fout.close();
    outputstring("Your topping has been added to menu");

}
void ToppingRepController::remove_topping_from_menu(){
    ///Remove a certain topping from menu
    clearScreen();
    dispHeader();
    displayToppings();

    outputstring("Input number of element to remove: ");

    char element;
    int toremove;

    cin >> element;

    if(element == 'q') {
        ToppingRepController trc;
    }
    else if (48 < element && element < 58) {
        toremove = element - 49;
    }

    ifstream fin;
    fin.open("Toppings_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int rec = fin.tellg() / sizeof(Toppings);
    fin.seekg(0, fin.beg);

    Toppings *data = new Toppings[rec];
    fin.read((char*)data, sizeof(Toppings)*rec);
    fin.close();

    ofstream fout;
    fout.open("Toppings_Menu_Binary.dat", ios::binary);

    for(int i = 0; i < rec; i++) {
        if(i != toremove){
            fout.write((char*)(&data[i]), sizeof(Toppings));
        }
    }
    fout.close();

    delete [] data;
}


void ToppingRepController::AreToppingsValid(Toppings& topping) throw (ToppingNameError, ToppingPriceError){

    string name;
    int price = 0;

    try{
        cin >> topping;
        price = topping.gettoppingprice();
        name = topping.gettoppingname();

        ///if name is not a letter then it throws error
        for(unsigned int i = 0; i < name.length(); i++){
             if(!isalpha(name[i])){
                throw ToppingNameError("Invalid toppings name");
            }
        }

        if(price < 0){
            throw ToppingPriceError ("Not valid topping");
        }
    }

    catch(ToppingNameError e){
        cout << e.getmessage() << endl;
        return;
    }

    catch(ToppingPriceError e){
        cout <<  e.getmessage() << endl;
        return;

    }

    ///this code wont get executed if there's an error in input
    add_topping_to_menu(topping);
}
