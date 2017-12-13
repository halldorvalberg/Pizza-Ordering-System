#include "SodaNameException.h"

SodaNameException::SodaNameException()
{
    //ctor
}

SodaNameException::~SodaNameException()
{
    //dtor
}
SodaNameException::SodaNameException(string message){
    this->message = message;
}
string SodaNameException::getmessage(){
    return this->message;
}
