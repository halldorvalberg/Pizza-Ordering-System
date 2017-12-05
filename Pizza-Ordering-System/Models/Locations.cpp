#include "Locations.h"

Locations::Locations(string location)
{
    this->location = location;
}

Locations::~Locations()
{
    //dtor
}
string Locations::getLocation(){
    return this->location;
}
istream& operator >> (istream& in, Locations& place){
    in >> place.location;
    return in;
}
ostream& operator << (ostream& out, Locations& place){
    out << place.location;
    return out;
}
