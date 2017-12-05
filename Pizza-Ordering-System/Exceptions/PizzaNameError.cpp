#include "PizzaNameError.h"

PizzaNameError::PizzaNameError(string message)
{
    this->message = message;
}
string PizzaNameError::getmessage(){
    return this->message;
}
PizzaNameError::~PizzaNameError()
{
    //dtor
}
