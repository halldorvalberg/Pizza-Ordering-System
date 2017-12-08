#ifndef LOCATIONREPO_H
#define LOCATIONREPO_H

#include "Locations.h"
#include <fstream>
#include <string>

class LocationRepo
{
    public:
        LocationRepo();
        virtual ~LocationRepo();
        void AddLocation();
        void DisplayAllLocations();
        string selectLocation();

    protected:

    private:
};

#endif // LOCATIONREPO_H
