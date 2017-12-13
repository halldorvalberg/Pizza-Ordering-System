#ifndef SODAREPO_H
#define SODAREPO_H

#include <fstream>

#include "Soda.h"

class SodaRepo
{
    public:
        SodaRepo();
        virtual ~SodaRepo();
        void writeSoda();
        void displaySoda();
        void validSoda();

    protected:

    private:
};

#endif // SODAREPO_H
