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
    AreToppingsValid(topping); ///check if error is in the input
    ///write the content of this into a file
    ofstream fout;

    fout.open("Toppings_Menu_Binary.dat", ios::app|ios::binary);

    if(fout.is_open()){
        fout << str << "\t" << i << endl;
        fout.close();
    }
    else{
        cerr << "File is not open" << endl;
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
        clearScreen();
    }while(input[0] != '1' &&
           input[0] != '2' &&
           input[0] != '3' &&
           input[0] != 'q');

    if(input[0] == '1'){
        ///View Toppings Menu
        displayToppings();
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

void ToppingRepController::AreToppingsValid(Toppings& topping){
    ///holy mac n cheese! ég náði þessu :O
    int price = topping.gettoppingprice();
    string str = topping.gettoppingname();

    try{

    if(price < 0){
        throw ToppingPriceError("Invalid topping price!");
    }
    for(unsigned int i = 0; i < str.length(); i++){
        if(!islower(str[i])&& !isupper(str[i])){
            throw ToppingNameError("Invalid topping name!");
            break;
            }
        }
    }
    catch(ToppingNameError n){
        cout << n.getmessage() << endl;
        add_topping_to_menu();
    }

    catch(ToppingPriceError p){
        cout << p.getmessage() << endl;
        add_topping_to_menu();
    }
}

void ToppingRepController::displayToppings(){
    Toppings topping;
    ifstream fin;
    fin.open("Toppings_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Toppings);
    fin.seekg(0, fin.beg);

    for(int i = 0; i < records; i++){
        fin.read((char*)(&topping), sizeof(Toppings));
//        cout << "Topping nr " << i+1 << ": " << topping << endl;
    }
    fin.close();
}
