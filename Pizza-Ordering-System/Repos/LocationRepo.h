#ifndef LOCATIONREPO_H
#define LOCATIONREPO_H

#include "Locations.h"

class LocationRepo
{
    public:
        LocationRepo();
        virtual ~LocationRepo();
        void AddLocation();
        void DisplayAllLocations();
        void selectLocation();

    protected:

    private:
};

#endif // LOCATIONREPO_H
