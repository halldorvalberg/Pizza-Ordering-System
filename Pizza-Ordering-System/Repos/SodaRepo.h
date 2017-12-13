#ifndef SODAREPO_H
#define SODAREPO_H

#include <fstream>

#include "Soda.h"

#include "SodaNameException.h"
#include "SodaPriceException.h"

class SodaRepo
{
    public:
        SodaRepo();
        virtual ~SodaRepo();
        void writeSoda(Soda& soda);
        void displaySoda();
        void validSoda();

    protected:

    private:
};

#endif // SODAREPO_H
