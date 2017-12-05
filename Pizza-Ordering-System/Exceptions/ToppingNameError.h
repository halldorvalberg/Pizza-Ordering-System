#ifndef TOPPINGNAMEERROR_H
#define TOPPINGNAMEERROR_H

#include <string>
using namespace std;

class ToppingNameError
{
    public:
        ToppingNameError(string message);
        virtual ~ToppingNameError();
        string getmessage();

    protected:

    private:
        string message;
};

#endif // TOPPINGNAMEERROR_H
