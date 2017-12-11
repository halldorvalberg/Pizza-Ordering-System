#ifndef GLOBALTOOLS_H
#define GLOBALTOOLS_H

#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <string>

#include "Pizza.h"
#include "Order.h"

using namespace std;

namespace GlobalTools
{
    void clearScreen();
    void exitApplication();
    void clear_order(string e);
    void add_all_to_file(string data, string location);
    void baker_mark_element_ready(int input);


  /*  vector<Order> getOrders();
    vector<Pizza> getPizza();
    vector<Toppings> getToppings();
*/
};

#endif // GLOBALTOOLS_H
