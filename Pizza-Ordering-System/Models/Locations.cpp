#include "Locations.h"

Locations::Locations()
{
    this->location = "";
}

Locations::~Locations()
{
    //dtor
}
string Locations::getLocation(){
    return this->location;
}
ifstream& operator >> (ifstream& in, Locations place){
    in >> place.location;
    return in;
}
ostream& operator << (ostream& out, Locations place){
    out << place.location;
    return out;
}
