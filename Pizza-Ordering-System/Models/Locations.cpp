#include "Locations.h"

Locations::Locations(){

}
Locations::Locations(string location)
{
    this->location = location;
}

Locations::~Locations()
{
    //dtor
}

istream& operator >> (istream& in, Locations& place){
    cout << "Please enter a location";
    in >> place.location;
    return in;
}

ostream& operator << (ostream& out, Locations& place){
    out << place.location;
    return out;
}
