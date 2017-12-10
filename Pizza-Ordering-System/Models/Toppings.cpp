#include "Toppings.h"

Toppings::Toppings()
{
    this->name = "";
    this->price = 0;
}

Toppings::Toppings(string name, int price){
    this->name = name;
    this->price = price;
}

string Toppings::gettoppingname(){
    return this->name;
}
int Toppings::gettoppingprice(){
    return this->price;
}

istream& operator >> (istream& in, Toppings& topping){
    cout << "Name: ";
    in >> topping.name;
    cout << "Price: ";
    in >> topping.price;
    return in;
}

ofstream& operator << (ofstream& out, Toppings& topping){
    out << topping.name << " ";
    out << topping.price << "kr" << endl;
    return out;
}
