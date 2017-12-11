#include "GlobalView.h"

void GlobalView::dispHeader()
{
    cout << "______ _                _____         _           _               _____           _                 " << endl;
    cout << "| ___ (_)              |  _  |       | |         (_)             /  ___|         | |                " << endl;
    cout << "| |_/ /_ __________ _  | | | |_ __ __| | ___ _ __ _ _ __   __ _  \\ `--. _   _ ___| |_ ___ _ __ ___  " << endl;
    cout << "|  __/| |_  /_  / _` | | | | | '__/ _` |/ _ \\ '__| | '_ \\ / _` |  `--. \\ | | / __| __/ _ \\ '_ ` _ \\ " << endl;
    cout << "| |   | |/ / / / (_| | \\ \\_/ / | | (_| |  __/ |  | | | | | (_| | /\\__/ / |_| \\__ \\ ||  __/ | | | | |" << endl;
    cout << "\\_|   |_/___/___\\__,_|  \\___/|_|  \\__,_|\\___|_|  |_|_| |_|\\__, | \\____/ \\__, |___/\\__\\___|_| |_| |_|" << endl;
    cout << "                                                           __/ |         __/ |                      " << endl;
    cout << "                                                          |___/         |___/           			 " << endl;
    cout << endl;
}

void GlobalView::display_menu()
{

    outputstring("\tPizza Menu: ");


    //Read menu from binary file
    Pizza pizza;

    ifstream fin;

    fin.open("Pizza_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Pizza);
    fin.seekg(0, fin.beg);

    for(int i = 0; i < records; i++){
        fin.read((char*)(&pizza), sizeof(Pizza));
        cout << "Pizza nr " << i+1 << ": " << pizza << endl;

    }
    fin.close();

}

void GlobalView::view_order(Order order, int rec)
{

    cout << rec << endl;

    Pizza *pizzas = new Pizza[rec];

    for(int i = 0; i < rec; i++) {
        pizzas[i] = order.ordered[i];
    }

    clearScreen();
    dispHeader();

    outputstring("Your Order: ");

    for(int i = 0; i < rec; i++) {
        cout << pizzas[i] << endl;
    }
    delete [] pizzas;

}

void GlobalView::displayToppings(){

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


void GlobalView::BakerOrderView()
{
    ifstream fin;

    fin.open("Ordered_Pizzas_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int rec = fin.tellg() / sizeof (Order);
    fin.seekg(0, fin.beg);

    Order *data = new Order[rec];
    fin.read((char*)data, sizeof(Order) * rec);

    fin.close();
    int j = 1;
    for(int i = 0; i < rec; i++) {
        if(!data[i].state) {
            cout << "Order nr: " << j << endl;
            cout << data[i] << endl;
            j++;
        }
    }
    delete[] data;
}
