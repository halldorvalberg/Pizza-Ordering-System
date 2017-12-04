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
Pizza::Pizza(string name, int price, int size){
    this->name = name;
    this->size = size;
    this->price = price;
}

string Pizza::getname(){
    return this->name;
}

int Pizza::getprice(){
    return this->price;
}

int Pizza::getprice(){
    return this->price;
}

ifstream& operator >> (ifstream& in, Pizza& pizza){
    in >> pizza.name >> pizza.size >> pizza.price;
    return in;
}

ofstream& operator << (ofstream& out, Pizza& pizza);
{
    out << pizza.name << " " << pizza.size <<" " << pizza.price << endl;
}
