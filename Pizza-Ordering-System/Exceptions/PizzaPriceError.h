#ifndef PIZZAPRICEERROR_H
#define PIZZAPRICEERROR_H

#include <string>
using namespace std;

class PizzaPriceError
{
    public:
        PizzaPriceError(string message);
        virtual ~PizzaPriceError();
        string getmessage();

    protected:

    private:
        string message;
};

#endif // PIZZAPRICEERROR_H
