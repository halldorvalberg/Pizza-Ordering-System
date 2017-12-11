#include "ToppingRepController.h"

ToppingRepController::ToppingRepController()
{
    clearScreen();
    dispHeader();
    init();
}

ToppingRepController::~ToppingRepController()
{
    //dtor
}

void ToppingRepController::add_topping_to_menu(Toppings& topping){
    ///write the content of this into a file
    string name, price;
    cout << "Your toppings: " << topping;
    ofstream fout;
    fout.open("Toppings_Menu_Binary.dat", ios::app|ios::binary);

    fout.write((char*)(&topping), sizeof(Toppings));
    fout.close();
    outputstring("Your topping has been added to menu");

}
void ToppingRepController::remove_topping_from_menu(){
    ///Remove a certain topping from menu, work in progress!!
    outputstring("I do nothing yet, replace me!!");
}

void ToppingRepController::init(){
    string input;

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
        ToppingRepController trc;
    }
    else if (input[0] == '2'){
        ///Add item to toppings menu
        Toppings topping;
        AreToppingsValid(topping);
        outputstring("Enter any key to continue");
        cin >> input;
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

void ToppingRepController::AreToppingsValid(Toppings& topping) throw (ToppingNameError, ToppingPriceError){

    char name[20];

    int price = 0;

    try{
        ///name input error isn't working like it should do
        cin >> topping;
        name[20] = topping.gettoppingname();
        price = topping.gettoppingprice();
/*
        for(unsigned int i = 0; i < sizeof(name) ; i++){
            if(name[i] == '\0'){
                break;
            }
            else if(!isalpha(name[i])){
                throw ToppingNameError ("Not valid name");
            }
        }*/
        if(price < 0){
            throw ToppingPriceError ("Not valid topping");
        }
    }
/*
    catch(ToppingNameError e){
        cout << "Invalid topping name" << endl;
    }
*/
    catch(ToppingPriceError e){
        cout << "Invalid topping price" << endl;

    }
    add_topping_to_menu(topping);

}

void ToppingRepController::displayToppings(){

    Toppings topping;
    clearScreen();
    dispHeader();
    cout << "Topping menu: " << endl;

    ifstream fin;
    fin.open("Toppings_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Toppings);
    fin.seekg(0, fin.beg);

    for(int i = 0; i < records; i++){
        fin.read((char*)(&topping), sizeof(Toppings));
        cout << "topping nr " << i+1 << ": "<< topping << endl;
    }
    fin.close();
}
