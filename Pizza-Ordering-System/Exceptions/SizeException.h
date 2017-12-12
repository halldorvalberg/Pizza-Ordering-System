#ifndef SIZEEXCEPTION_H
#define SIZEEXCEPTION_H

#include <string>
using namespace std;

class SizeException
{
    public:
        SizeException();
        SizeException(string message);
        virtual ~SizeException();
        string getMesssage();

    private:
        string message;
};

#endif // SIZEEXCEPTION_H
