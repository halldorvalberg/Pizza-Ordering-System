#include "SizeException.h"

SizeException::SizeException()
{
    //ctor
}
SizeException::SizeException(string message){
    this->message = message;
}
string SizeException::getMesssage(){
    return this->message;
}
SizeException::~SizeException()
{
    //dtor
}
