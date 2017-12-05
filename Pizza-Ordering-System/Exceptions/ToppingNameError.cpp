#include "ToppingNameError.h"

ToppingNameError::ToppingNameError(string message)
{
    this->message = message;
}

ToppingNameError::~ToppingNameError()
{
    //dtor
}

string ToppingNameError::getmessage(){
    return this->message;
}
