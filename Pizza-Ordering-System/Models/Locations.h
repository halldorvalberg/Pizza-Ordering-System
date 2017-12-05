#ifndef LOCATIONS_H
#define LOCATIONS_H
#include <iostream>
#include <string>
using namespace std;

class Locations
{
    public:
        Locations(string location);
        virtual ~Locations();
        string getLocation();
        friend istream& operator >> (istream& in, Locations& place);
        friend ostream& operator << (ostream& out, Locations& place);

        string location;
    protected:

    private:

};

#endif // LOCATIONS_H
