#ifndef GLOBALVIEW_H
#define GLOBALVIEW_H

#include <iostream>
#include <fstream>

#include "Pizza.h"
#include "DisplayString.h"
#include "GlobalTools.h"

using namespace GlobalTools;
using namespace DisplayString;
using namespace std;

namespace GlobalView
{
   void dispHeader();
   void display_menu();
   void view_order();
};

#endif // GLOBALVIEW_H
