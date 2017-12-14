#include "Locations.h"

Locations::Locations(){


}
Locations::Locations(char local[20])
{
    for(int i = 0; i < 20; i++){
        this->local[i] = local[i];
    }
}
string Locations::getlocation(){
    return this->local;
}

Locations::~Locations()
{
    //dtor
}

istream& operator >> (istream& in, Locations& location){
    cout << "Please enter a location: ";
    in >> location.local;
    return in;
}

ostream& operator << (ostream& out, Locations& location){
    out << location.local << endl;
    return out;
}
ifstream& operator >> (ifstream& in, Locations& location){
    in >> location.local;
    return in;
}

ofstream& operator << (ofstream& out, Locations& location)
{
    out << location.local << endl;
    return out;
}
