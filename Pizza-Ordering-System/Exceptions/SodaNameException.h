#ifndef SODANAMEEXCEPTION_H
#define SODANAMEEXCEPTION_H

#include <string>
using namespace std;
class SodaNameException
{
    public:
        SodaNameException();
        SodaNameException(string message);
        virtual ~SodaNameException();
        string getmessage();

    protected:

    private:
        string message;
};

#endif // SODANAMEEXCEPTION_H
