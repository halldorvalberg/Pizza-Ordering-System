#include "CostumerMenuController.h"

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
    clearScreen();
    dispHeader();
    displayToppings();

    int amount;
    outputstring("How many toppings do you want on your pizza? ");
    cin >> amount;
    outputstring("\nSelect Toppings to add to order or 0 (zero) to return:");
    int menu;
    do{
    cin >> menu;
    }while(menu < 0);

    if(menu == 0){
        CostumerMenuController cmc;
    }
    else{
       InputForEachPizza(amount, menu);

    }
}
void CostumerMenuController::InputForEachPizza(int amount, int menu){
    Pizza pizza;
    Order order;
    int counter = 1;
    double basepizza = 1500; ///Price of basic pizza with nothing on it
    int size = 0;
    while(counter < amount){
    addToppingsToOrder(menu, pizza);
    }
    cout << "choose a size for your pizza";
    cin >> size;
    total_price = pizza.price + basepizza;

}

void CostumerMenuController::add_order_to_file(Order neworder)
{
    ofstream fout;

    fout.open("Ordered_Pizzas_Binary.dat", ios::binary|ios::app);

    fout.write((char*)(&neworder), sizeof(Order));

    fout.close();

}

void CostumerMenuController::addToppingsToOrder(int e, Pizza &order){
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
