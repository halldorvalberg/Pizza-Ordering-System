#include "Toppings.h"

Toppings::Toppings()
{
    //ctor
}

Toppings::Toppings(string name, int price);

string Toppings::gettoppingname(){
    return this->name;
}
int Toppings::gettoppingprice(){
    return this->price;
}

ifstream& operator >> (ifstream& in, Toppings& topping){
    in >> topping.name >> topping.price;
    return in;
}

ofstream& operator >> (ofstream& out, Toppings& topping){
    out << topping.name << " " << topping.price << endl;
    return out;
}
