#ifndef SODAPRICEEXCEPTION_H
#define SODAPRICEEXCEPTION_H

#include <string>
using namespace std;

class SodaPriceException
{
    public:
        SodaPriceException();
        virtual ~SodaPriceException();

        SodaPriceException(string message);
        string getmessage();

    protected:

    private:
        string message;
};

#endif // SODAPRICEEXCEPTION_H
