#ifndef LOCATIONREPO_H
#define LOCATIONREPO_H

#include "LocationException.h"

#include "Locations.h"
#include "MainMenuController.h"

#include <fstream>
#include <string>

class LocationRepo
{
    public:
        LocationRepo();
        virtual ~LocationRepo();
        void AddLocation(Locations& location);
        void DisplayAllLocations();
        Locations selectLocation();
        void validLocation();
        void DisplayAllOrdersAtLocationBaker();
        void DisplayAllOrdersAtLocationSalesman();

    protected:

    private:
};

#endif // LOCATIONREPO_H
