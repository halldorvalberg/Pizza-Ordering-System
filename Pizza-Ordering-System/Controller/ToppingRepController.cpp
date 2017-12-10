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

void ToppingRepController::add_topping_to_menu(){
    ///write the content of this into a file
    string name, price;
    Toppings topping;
    cin >> topping;
    cout << "Your toppings: " << topping;
    ofstream fout;
    fout.open("Toppings_Menu_Binary.dat", ios::app|ios::binary);

    fout.write((char*)(&topping), sizeof(Toppings));
    fout.close();
    outputstring("Your topping has been added to menu");

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
        clearScreen();
        displayToppings();
        outputstring("");
        outputstring("Enter any key to exit");
        cin >> input;
        ToppingRepController trc;
    }
    else if (input[0] == '2'){
        ///Add item to toppings menu
        add_topping_to_menu();
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

void ToppingRepController::AreToppingsValid(){
    Toppings topping;
 /*   try{
        cin >> topping;
        if(topping.gettoppingprice() < 0){
        throw ToppingPriceError("Invalid topping price!");
        }

        string str = topping.gettoppingname();
        for(unsigned int i = 0; i < str.length(); i++){
        if(!islower(str[i])&& !isupper(str[i])){
            throw ToppingNameError("Invalid topping name!");
            }
        }
    }
  //  catch(ToppingNameError n){
    //    cout << n.getmessage() << endl;
     //   return;
    //}
    catch(ToppingPriceError p){
        cout << p.getmessage() << endl;
        return;
    }
    add_topping_to_menu();
    */
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
