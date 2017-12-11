#include "ToppingPriceError.h"

ToppingPriceError::ToppingPriceError(){
}

ToppingPriceError::ToppingPriceError(string message)
{
    this->message = message;
}

ToppingPriceError::~ToppingPriceError()
{
    //dtor
}
string ToppingPriceError::getmessage(){
    return this->message;
}
