#include "PizzaRepo.h"

PizzaRepo::PizzaRepo()
{
    //ctor
}

PizzaRepo::~PizzaRepo()
{
    //dtor
}

Pizza PizzaRepo::returnSelectedPizza(int pizza_number)){
    Pizza pizza;
    ifstream fin;

    fin.open("Pizza_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Pizza);
    fin.seekg(0, fin.beg);

    if(records >= pizza_number) {

    for(int i = 0; i < pizza_number; i++){
        fin.read((char*)(&pizza), sizeof(Pizza));
    }
    fin.close();
    }

    return pizza;
}
