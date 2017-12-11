#ifndef TOPPINGPRICEERROR_H
#define TOPPINGPRICEERROR_H

#include <string>
using namespace std;

class ToppingPriceError
{
    public:
        ToppingPriceError();
        ToppingPriceError(string message);
        virtual ~ToppingPriceError();
        string getmessage();

    protected:

    private:
        string message;
};

#endif // TOPPINGPRICEERROR_H
