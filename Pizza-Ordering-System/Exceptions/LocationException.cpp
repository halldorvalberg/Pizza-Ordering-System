#include "LocationException.h"

LocationException::LocationException(string str)
{
    this->str = str;
}

LocationException::~LocationException()
{
    //dtor
}
string LocationException::getmessage(){
    return this->str;
}
