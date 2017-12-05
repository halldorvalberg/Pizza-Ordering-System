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
    location.selectLocation();
    ifstream fin;
    fin.open("Pizza_order.dat");
    Pizza pizza;
    ///Some code to search in file for said match
    fin.close();
    cout << pizza << endl;
}
void OrderRepo::DisplayAllOrdersAtLocationSalesman(){
    LocationRepo location;
    location.selectLocation();
    ifstream fin;
    fin.open("Pizza_order.dat");
    Pizza pizza;
    ///Some code to search in file for said match
    fin.close();
    cout << pizza << endl;
}
void OrderRepo::changeOrderBaker(){
    cout << "I do nothing yet, please replace me" << endl;
}
void OrderRepo::changeOrderSalesman(){
    cout << "I do nothing yet, please replace me!" << endl;
}
