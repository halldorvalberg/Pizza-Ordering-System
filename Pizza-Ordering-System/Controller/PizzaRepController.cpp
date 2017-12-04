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
        display_menu();
        outputstring("");
        outputstring("Enter any key to exit");
        cin >> input;
        PizzaRepController prc;
    }
    else if (input[0] == '2'){
        ///Add item to pizza menu
        add_to_menu();
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

    string str;
    int i;
    char c;

    cin >> str >> i >> c;

    Pizza pizza(str, i, c);

    ofstream fout;
    fout.open("Pizza_Menu_Binary.txt", ios::app);

    if(fout.is_open()){
    fout << str << "\t" << i << "\t" << c << endl;
    fout.close();
    }
    else{
        cout << "File could not be opened!" << endl;
    }
}

void PizzaRepController::remove_element_from_menu()
{
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
}
