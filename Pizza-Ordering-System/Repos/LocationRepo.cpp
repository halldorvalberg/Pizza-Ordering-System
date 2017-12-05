#include "LocationRepo.h"

LocationRepo::LocationRepo()
{
    //ctor
}

LocationRepo::~LocationRepo()
{
    //dtor
}
void LocationRepo::AddLocation(){
    Locations location;
    ofstream fout;
    fout.open("Locations.txt", ios::app);
    if(fout.isopen()){
        fout << location;
        fout.close();
    }
}
void LocationRepo::DisplayAllLocations(){
    Locations location;
    string str;
    ifstream fin;
    fin.open("Locations.txt");
    while(!fin.eof()){
        str.getline(fin, str);
        cout << location << endl;
    }
    fin.close();
}

void LocationRepo::selectLocation(){
}
