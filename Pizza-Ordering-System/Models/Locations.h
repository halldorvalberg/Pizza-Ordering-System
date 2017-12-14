#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Locations
{
    public:
        Locations();
        Locations(char local[20]);
        virtual ~Locations();
        string getlocation();

        friend istream& operator >> (istream& in, Locations& place);
        friend ostream& operator << (ostream& out, Locations& place);
        friend ifstream& operator >> (ifstream& in, Locations& locat);
        friend ofstream& operator << (ofstream& in, Locations& locat);


    protected:

    private:
        char local[20];

};

#endif // LOCATIONS_H
