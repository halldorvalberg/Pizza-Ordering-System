#ifndef LOCATIONEXCEPTION_H
#define LOCATIONEXCEPTION_H

#include <string>
using namespace std;

class LocationException
{
    public:
        LocationException(string str);
        virtual ~LocationException();
        string getmessage();

    private:
        string str;
};

#endif // LOCATIONEXCEPTION_H
