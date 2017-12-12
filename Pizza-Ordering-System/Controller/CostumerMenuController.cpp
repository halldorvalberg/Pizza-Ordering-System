#include "CostumerMenuController.h"

#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

CostumerMenuController::CostumerMenuController()
{
    clearScreen();
    dispHeader();
    init();
}

CostumerMenuController::~CostumerMenuController()
{
    //dtor
}

void CostumerMenuController::init(){
    Order neworder;
    cin >> neworder;


    char input;
    pizzas_ordered = 0;
    total_price = 0;
    toppings_ordered = 0;
    bool orderinprosess = true;


    do{
        clearScreen();
        dispHeader();

            do{
                CostumerMenuDisplay();
                cin >> input;
            }while(input !='1'&& input !='2'&&
                   input !='3'&& input !='q'&&
                   input != 'Q');

        if (input == '1'){
            ///Order pizza from menu
            OrderFromMenu(neworder);
        }
        else if(input == '2'){
            customOrder(neworder);
        }
        else if(input == '3'){

            ///View Order
            view_order(neworder, pizzas_ordered);

            outputstring("\nInput any key to exit: ");
            char confirm;
            cin >> confirm;


            if(confirm == 'y' || confirm == 'Y') {
                add_all_to_file("Costumer_Order_Binary.dat", "Ordered_Pizzas_Binary.dat");
            }
            else{
            }
        }
        else if (input == 'q' || input == 'Q'){
            char quit;
            view_order(neworder, pizzas_ordered);

            neworder.price = total_price;
            neworder.number_of_pizzas = pizzas_ordered;

            outputstring("Total price: ");
            cout << neworder.price;
            outputstring(" kr.\n");

            outputstring("Confirm Order? (y/n)");
            cin >> quit;

                if(quit == 'y') {

                    add_order_to_file(neworder);

                    outputstring("\nYour order has been placed. ");

                    orderinprosess = false;
                    break;
                }
        }
    }while(orderinprosess == true);
}

void CostumerMenuController::OrderFromMenu(Order &order){ ///WIP
    clearScreen();
    dispHeader();
    display_menu();

    outputstring("\nSelect pizza to add to order or 0 (zero) to return:");
    int menu;
    do{
    cin >> menu;
    }while(0 > menu);

    if(menu == 0){
        CostumerMenuController cmc;
    }
    else{
        add_to_order(menu, order);
    }
}

void CostumerMenuController::add_to_order(int e, Order &order)
{
    Pizza pizza;

    ifstream fin;

    fin.open("Pizza_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Pizza);
    fin.seekg(0, fin.beg);

    if(records >= e) {

    for(int i = 0; i < e; i++){
        fin.read((char*)(&pizza), sizeof(Pizza));
    }
    fin.close();
    }

    order.ordered[pizzas_ordered] = pizza;
    pizzas_ordered++;
    total_price += pizza.price;

}

void CostumerMenuController::customOrder(Order &order){
    Toppings total_toppings[20];
    Toppings to_add;
    int sz;
    double base_price = 1500;
    double total_price = base_price;
    char user_input;
    bool exit = false;
    int counter = 0;

    while(exit != true){
        ///WIP
        clearScreen();
        dispHeader();

        outputstring("The base price for pizza is : 1500kr.\nYour total toppings may not exceed 20.\n");

        if(counter != 0){
            outputstring("Your current toppings are : ");
            for(int i = 0; i < counter;i++){
                cout << total_toppings[i] << endl;
            }
            cout << "Their total count is : " << counter << endl << endl;
        }

        if(counter != 20){
            to_add = choose_topping_menu();

            if(to_add.gettoppingprice() == 0){
                // the user has chosen to exit toppings menu
            }else{
                total_toppings[counter++] = to_add;
            }

            cout << "***********\nContinue adding toppings? Input either 0 or q if you're done to process." << endl;

            cin >> user_input;
        }


        if((user_input == '0' || user_input == 'q') || counter == 20){
            outputstring("Your pizza is complete");

            for(auto &x : total_toppings){
                total_price += x.gettoppingprice();
            }

            // have to add size of pizza

            cout << "The total cost of your pizza is : " << total_price << endl;

            system("pause");
            exit = true;
        }
    }

}

void CostumerMenuController::add_order_to_file(Order neworder)
{
    ofstream fout;

    fout.open("Ordered_Pizzas_Binary.dat", ios::binary|ios::app);

    fout.write((char*)(&neworder), sizeof(Order));

    fout.close();

}

void CostumerMenuController::addToppingsToOrder(int e, Pizza &order){
    ///WIP
    Toppings topping;
    Order orderr;
    ifstream fin;

    fin.open("Toppings_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Toppings);
    fin.seekg(0, fin.beg);

    if(records >= e) {

    for(int i = 0; i < e; i++){
        fin.read((char*)(&topping), sizeof(Toppings));
    }
    fin.close();
    }
    orderr.ordered[pizzas_ordered] = order;
    pizzas_ordered++;
    total_price += order.price;

}


Toppings CostumerMenuController::choose_topping_menu(){
    Toppings topping;
    vector<Toppings> data;
    //load in data
    ifstream fin;
    fin.open("Toppings_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Toppings);
    fin.seekg(0, fin.beg);

    for(int i = 0; i < records; i++){
        fin.read((char*)(&topping), sizeof(Toppings));
        data.push_back(topping);
    }
    fin.close();

    displayToppings();

    outputstring("Please, choose from the menu, anything else will exit this menu : ");

    int user_choice;

    cin >> user_choice;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(user_choice < (data.size() + 1) && user_choice > 0){
        cout << "You have added : " << data[user_choice - 1] << endl;
        return data[user_choice - 1];
    }else{
        cout << "You have chosen to exit." << endl;
        return Toppings();
    }

}
