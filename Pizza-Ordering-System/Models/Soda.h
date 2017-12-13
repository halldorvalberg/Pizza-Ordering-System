#ifndef SODA_H
#define SODA_H

#include <iostream>
using namespace std;

class Soda
{
    public:
        Soda();
        virtual ~Soda();

        friend ostream& operator << (ostream& out, Soda& soda);
        friend istream& operator >> (istream& in, Soda& soda);



        string name;
        double price;
};

#endif // SODA_H
