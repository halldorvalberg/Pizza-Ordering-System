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

        for(unsigned int i = 0; i < 20 ; i++){
                ///if there is end to the input, break out of loop
            if (i < 20 && name[i] == '\0'){
                break;
            }
            else if(!isalpha(name[i])){
                throw ToppingNameError("Invalid Pizza name");
            }
        }

        if(price < 0){
            throw ToppingPriceError ("Not valid topping");
        }
    }

    catch(ToppingNameError e){
        cout << e.getmessage() << endl;
    }

    catch(ToppingPriceError e){
        cout <<  e.getmessage() << endl;

    }

    add_topping_to_menu(topping);
}
