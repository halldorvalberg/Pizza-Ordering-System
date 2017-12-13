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
    bool exit = false;


    while(exit != true){
        clearScreen();
        dispHeader();
        CostumerMenuDisplay();

        cin >> input;

        switch(input){
            case '1' :
                neworder.ordered[++pizzas_ordered] = CostumerMenuController::chooseFromMenu();
                total_price += neworder.ordered[pizzas_ordered].price;
                break;
            case '2' :
                neworder.ordered[++pizzas_ordered] = CostumerMenuController::customOrder();
                total_price += neworder.ordered[pizzas_ordered].price;
                break;
            case '3' :
                view_order(neworder, pizzas_ordered);
                system("pause");
                break;
            case 'q' :
            case 'Q' :
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

                        exit = true;
                    }
                break;
            default :
                outputstring("The option you have selected does not exist.");
                break;
        }
    }
}


Pizza CostumerMenuController::chooseFromMenu(){
    int user_input = 0;

    ///WIP
    clearScreen();
    dispHeader();
    display_menu();

    outputstring("\nSelect pizza to add to order or 0 (zero) to return:");

    cin >> user_input;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(user_input){
        case 0 :
            //CostumerMenuController::init();
            break;
        default :
            if(user_input > 0){
                Pizza hello = PizzaRepo::returnSelectedPizza(user_input);
                return hello;
            }
            break;
    }
}


Pizza CostumerMenuController::customOrder(){
//    Toppings total_toppings[20];
//    Toppings to_add;
//    int sz;
//    double base_price = 1500;
//    double total_price = base_price;
//    char user_input;
//    bool exit = false;
//    int counter = 0;
//
//    while(exit != true){
//        ///WIP
//        clearScreen();
//        dispHeader();
//
//        outputstring("The base price for pizza is : 1500kr.\nYour total toppings may not exceed 20.\n");
//
//        if(counter != 0){
//            CostumerMenuView::ChosenToppings(counter, total_toppings);
//        }
//
//        if(counter != 20){
//            to_add = choose_topping_menu();
//
//            if(to_add.gettoppingprice() == 0){
//                // the user has chosen to exit toppings menu
//            }else{
//                total_toppings[counter++] = to_add;
//            }
//
//            outputstring("***********\nContinue adding toppings? Input either 0 or q if you're done to process.");
//
//            cin >> user_input;
//        }
//
//
//        if((user_input == '0' || user_input == 'q') || counter == 20){
//            outputstring("Your pizza is complete");
//
//            for(auto &x : total_toppings){
//                total_price += x.gettoppingprice();
//            }
//
//            sz = CostumerMenuController::chooseSize();
//
//            cout << "The total cost of your pizza is : " << total_price << endl;
//
//            system("pause");
//            exit = true;
//        }
//    }
    return Pizza();
}

void CostumerMenuController::add_order_to_file(Order neworder)
{
    ofstream fout;

    fout.open("Ordered_Pizzas_Binary.dat", ios::binary|ios::app);

    fout.write((char*)(&neworder), sizeof(Order));

    fout.close();

}

Toppings CostumerMenuController::choose_topping_menu(){
    vector<Toppings> data;

    data.swap(ToppingRepo::getToppingsToVector());

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

int CostumerMenuController::chooseSize(){
    int size1 = 16, size2 = 12, size3 = 8;
    int user_input;

    CostumerMenuView::DisplaySizeMenu();

    cin >> user_input;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(user_input != '0'){
        switch(user_input){
            case 1 :
                return size1;
                break;
            case 2 :
                return size2;
                break;
            case 3 :
                return size3;
                break;
            default:
                outputstring("The selected option does not exist.");
                CostumerMenuController::chooseSize();
                break;
        }
    }else{
        CostumerMenuController::chooseSize();
    }
}
