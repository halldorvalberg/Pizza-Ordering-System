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
    fin.open("Pizza_order.dat", ios::binary);
    Pizza pizza;
    ///Some code to search in file for said match
    fin.close();
    cout << pizza << endl;
}
void OrderRepo::DisplayAllOrdersAtLocationSalesman(){
    LocationRepo location;
    string str, lc;
    lc = location.selectLocation();
    ifstream fin;
    fin.open("Pizza_order.dat", ios::binary);
    Pizza pizza;
    ///binary something here
    getline(fin, str, ':'); ///þar sem staðsetning er í binary file
    if(lc == str){ ///if there's a match in the binary file, then print it out
        cout << pizza << endl;
        ///add to vector to be used later
    }
    fin.close();
}
void OrderRepo::changeOrderBaker(){
    Pizza pizza;
    ///find the order which is ready, change status to ready and overwrite the binary file
    cout << "I do nothing yet, please replace me" << endl;
}
void OrderRepo::changeOrderSalesman(){
    cout << "I do nothing yet, please replace me!" << endl;
}
