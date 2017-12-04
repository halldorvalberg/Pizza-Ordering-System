#ifndef LOCATIONS_H
#define LOCATIONS_H


class Locations
{
    public:
        Locations();
        virtual ~Locations();
        string getLocation();
        friend ifstream& operator >> (ifstream& in, Locations place);

    protected:

    private:
        string location;
};

#endif // LOCATIONS_H
