#ifndef GLOBALTOOLS_H
#define GLOBALTOOLS_H

#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <string>

#include "Pizza.h"

using namespace std;

namespace GlobalTools
{
    void clearScreen();
    void exitApplication();
    void clear_order(string e);
    void add_all_to_file(string data, string location);

  /*  vector<Order> getOrders();
    vector<Pizza> getPizza();
    vector<Toppings> getToppings();
*/
};

#endif // GLOBALTOOLS_H
