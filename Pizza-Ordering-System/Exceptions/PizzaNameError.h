#ifndef PIZZANAMEERROR_H
#define PIZZANAMEERROR_H

#include <string>
using namespace std;

class PizzaNameError
{
    public:
        PizzaNameError(string message);
        virtual ~PizzaNameError();
        string getmessage();

    protected:

    private:
        string message;
};

#endif // PIZZANAMEERROR_H
