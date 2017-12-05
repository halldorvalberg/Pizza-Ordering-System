#include "PizzaPriceError.h"

PizzaPriceError::PizzaPriceError(string message)
{
    this->message = message;
}

PizzaPriceError::~PizzaPriceError()
{
    //dtor
}
string PizzaPriceError::getmessage(){
    return this->message;
}
