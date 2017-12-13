#include "SodaPriceException.h"

SodaPriceException::SodaPriceException()
{
    //ctor
}

SodaPriceException::~SodaPriceException()
{
    //dtor
}
SodaPriceException::SodaPriceException(string message){
    this->message = message;
}

string SodaPriceException::getmessage(){
    return this->message;
}
