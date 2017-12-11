#include "Pizza.h"

Pizza::Pizza()
{

}

Pizza::Pizza(int price, int sz, char name[50], vector<Toppings> tv)
{
    this->price = price;
    this->sz = sz;

    for (int i = 0; i < 50; i++) {
        this->name[i] = name[i];
    }

    //this->toppingsVector.swap(tv);
}

Pizza::~Pizza()
{
    //dtor
}


ifstream& operator >> (ifstream& in, Pizza& pizza){
    in >> pizza.name >> pizza.sz >> pizza.price;
    return in;
}

ofstream& operator << (ofstream& out, Pizza& pizza)
{
    out << pizza.name << " " << pizza.sz <<" " << pizza.price << endl;
    return out;
}

ostream& operator << (ostream& out, Pizza& pizza)
{
    out << "Name: " << pizza.name << "\tPrice: " << pizza.price << " kr.\tSize: " << pizza.sz;
    return out;
}
istream& operator >> (istream& in, Pizza& pizza)
{
    cout << "Input Pizza name (50): ";
    in >> ws;
    in.getline(pizza.name, 50);
    cout << "input Pizza price: ";
    in >> pizza.price;
    cout << "Input Pizza size: ";
    in >> pizza.sz;

    return in;
}
