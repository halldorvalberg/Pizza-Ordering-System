#include "Pizza.h"

Pizza::Pizza()
{
    this->name = "";
    this->price = 0;
    this->size = 0;
}

Pizza::~Pizza()
{
    //dtor
}
Pizza::Pizza(string name, vector<Toppings> toppings, int size, int price){
    this->name = name;
    this->toppings = toppings;
    this->size = size;
    this->price = price;
}
void Pizza::addtopping(){
    toppings.push_back();
}
string Pizza::getpizzaname(){
    return this->name;
}

int Pizza::getpizzasize(){
    return this->size;
}

int Pizza::getpizzaprice(){
    return this->price;
}

ifstream& operator >> (ifstream& in, Pizza& pizza){
    in >> pizza.name >> pizza.size >> pizza.price;
    return in;
}

ofstream& operator << (ofstream& out, Pizza& pizza)
{
    out << pizza.name << " " << pizza.size <<" " << pizza.price << endl;
    return out;
}
