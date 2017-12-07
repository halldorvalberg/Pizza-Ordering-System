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
    validPizzaInput(pizza);
    outputstring("\nYour pizza: \n");
    cout << pizza;

    ofstream fout;

    fout.open("Pizza_Menu_Binary.dat", ios::binary|ios::app);

    fout.write((char*)(&pizza), sizeof(Pizza));

    fout.close();

    outputstring("Your Pizza has been added to the menu\n");


}

void PizzaRepController::remove_element_from_menu()
{
    //Bilað
    outputstring("Bilað");
    /*
    display_menu();
    int counter;
    int nr;
    string str;

    vector<string> temp;
    ///Dump content of file to vector
    ifstream fin;
    fin.open("Pizza_Menu_Binary.txt");
    if(fin.is_open()) {
        while(!fin.eof()) {
            getline(fin, str);
            temp.push_back(str);
            counter++;
        }
        fin.close();
    }
    else {
        cout << "Unable to read from file!" << endl;
    }

    ///Select element to remove
    outputstring("Select 0 to return: \nSelect element to remove: ");
    cin >> nr;
    if(nr == 0){
        PizzaRepController prc;
    }

    ///Selected element removed
    temp.erase(temp.begin()+nr-1);

    ///Refill file without selected element
    counter = temp.size();
    ofstream fout;
    fout.open("Pizza_Menu_Binary.txt", ios::out|ios::trunc);
    for(int i = 0; i < counter; i++){
        fout << temp[i] << endl;
    }
    fout.close();
    */
}

void PizzaRepController::validPizzaInput(Pizza& pizza){
    string name, price;
    int number;
   // number = pizza.getnumber();
   // name = pizza.getname();
   // price = pizza.getprice();
    try{
        cin >> number;
        if (number < 0){
            cout << "Invalid number" << endl;
        }
        cin >> price;
        for (unsigned int i = 0; i < price.size(); i++){
            if(!isdigit(price[i])){
                throw PizzaPriceError("Invalid price");
            }
        }

        cin >> name;
        for(unsigned int i = 0; i < name.size(); i++){
            if(!islower(name[i])&& !isupper(name[i])){
                throw PizzaNameError("Invalid name");
            }
        }
    }
    catch(PizzaNameError pn){
        cout << pn.getmessage() << endl;
        add_to_menu();

    }
    catch(PizzaPriceError pe){
        cout << pe.getmessage() << endl;
        add_to_menu();
    }
}
