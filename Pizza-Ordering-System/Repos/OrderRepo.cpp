#include "OrderRepo.h"

OrderRepo::OrderRepo()
{
    //ctor
}

OrderRepo::~OrderRepo()
{
    //dtor
}
void OrderRepo::DisplayAllOrdersAtLocationBaker(){
    LocationRepo location;
    string str;
    location.selectLocation(str);
    ifstream fin;
    fin.open("Pizza_order.dat", ios::binary);
    Pizza pizza;
    ///Some code to search in file for said match
    fin.close();
    cout << pizza << endl;
}
void OrderRepo::DisplayAllOrdersAtLocationSalesman(){
    LocationRepo location;
    string str;
    location.selectLocation(str);
    ifstream fin;
    fin.open("Pizza_order.dat", ios::binary);
    Pizza pizza;
    ///Some code to search in file for said match, work in progress
    fin.close();
    cout << pizza << endl;
}
void OrderRepo::changeOrderBaker(){
    cout << "I do nothing yet, please replace me" << endl;
    ///change the state of the order is ready
    ///work in progress
}
void OrderRepo::changeOrderSalesman(){
    cout << "I do nothing yet, please replace me!" << endl;
    ///change the state of the order being paid
    ///work in progress
}
