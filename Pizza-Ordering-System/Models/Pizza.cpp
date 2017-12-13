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
    out << pizza.name << " " << pizza.sz << " " << pizza.price << endl;
    return out;
}

ostream& operator << (ostream& out, Pizza& pizza)
{
    out << "Name: " << pizza.name << "\t Size: " << pizza.sz << "\t Price: " << pizza.price << " kr";
    return out;
}
istream& operator >> (istream& in, Pizza& pizza)
{
    cout << "Input Pizza name (50): ";
    in >> ws;
    in.getline(pizza.name, 50);
    cout << "Input Pizza size (8 / 12 / 16): ";
    in >> pizza.sz;
     cout << "input Pizza price (above 1500) : ";
    in >> pizza.price;

    return in;
}
