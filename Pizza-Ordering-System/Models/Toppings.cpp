#include "Toppings.h"

Toppings::Toppings()
{
    name[0] = '\0';
    price = 0;
}

Toppings::Toppings(char name[20], int price){
    for(int i = 0; i < 20; i++){
        this->name[i] = name[i];
    }
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
    in >> ws;
    in.getline(topping.name, 20);
    cout << "Price: ";
    in >> topping.price;
    return in;
}

ostream& operator << (ostream& out, Toppings& topping){
    out <<"Name: " << topping.name << " Price: " << topping.price << " kr" << endl;
    return out;
}
ifstream& operator >> (ifstream& in, Toppings& topping){
    in >> topping.name >> topping.price;
    return in;
}

ofstream& operator << (ofstream& out, Toppings& topping)
{
    out << topping.name << " " << topping.price << endl;
    return out;
}
