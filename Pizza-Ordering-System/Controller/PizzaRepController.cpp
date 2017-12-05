#include "PizzaRepController.h"

PizzaRepController::PizzaRepController()
{
    clearScrean();
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
        clearScrean();
    }while(input[0] != '1' &&
           input[0] != '2' &&
           input[0] != '3' &&
           input[0] != 'q');

    if(input[0] == '1'){
        ///View Pizza Menu
        clearScrean();
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
    int nr;
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
