#include "Pizza.h"

Pizza::Pizza()
{
    nr = -1;
    name[0] = '\0';
    price[0] = '\0';
    size[0] = '\0';

}

Pizza::~Pizza()
{
    //dtor
}


/*
void Pizza::addtopping(){
//    toppings.push_back();
}
string Pizza::getpizzaname(){
    return this->name;
}

int Pizza::getpizzaprice(){
    return this->price;
}
*/
ifstream& operator >> (ifstream& in, Pizza& pizza){
    in >> pizza.name >> pizza.size >> pizza.price;
    return in;
}

ofstream& operator << (ofstream& out, Pizza& pizza)
{
    out << pizza.name << " " << pizza.size <<" " << pizza.price << endl;
    return out;
}

ostream& operator << (ostream& out, Pizza& pizza)
{
    out << "Name: " << pizza.name << "\tPrice: " << pizza.price << " kr.\tSize: " << pizza.size;
    return out;
}
istream& operator >> (istream& in, Pizza& pizza)
{
    cout << "Input Pizza name (50): ";
    in >> ws;
    in.getline(pizza.name, 50);
    cout << "input Pizza price (10): ";
    in.getline(pizza.price, 10);
    cout << "Input Pizza size (10): ";
    in.getline(pizza.size, 10);

    return in;
}
