#include "ToppingRepo.h"

ToppingRepo::ToppingRepo()
{
    //ctor
}

ToppingRepo::~ToppingRepo()
{
    //dtor
}

vector<Toppings> ToppingRepo::getToppingsToVector(){
    vector<Toppings> data;
    ifstream fin;
    fin.open("Toppings_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Toppings);
    fin.seekg(0, fin.beg);

    for(int i = 0; i < records; i++){
        fin.read((char*)(&topping), sizeof(Toppings));
        data.push_back(topping);
    }
    fin.close();

    return data;
}
