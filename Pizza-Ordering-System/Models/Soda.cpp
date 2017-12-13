#include "Soda.h"

Soda::Soda()
{

}

Soda::~Soda()
{
    //dtor
}
ostream& operator << (ostream& out, Soda& soda){
    out << soda.name << " " << soda.price << " kr";
    return out;
}

istream& operator >> (istream& in, Soda& soda){
    cout << "Name: ";
    in >> soda.name;
    cout << "Price: ";
    in >> soda.price;
    return in;
}
