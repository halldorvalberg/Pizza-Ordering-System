#include "LocationRepo.h"

LocationRepo::LocationRepo()
{
    //ctor
}

LocationRepo::~LocationRepo()
{
    //dtor
}

///valid input of the location
void LocationRepo::validLocation(){
    string str;
    cin >> str;

    try{
        for(unsigned int i = 0; i < str.size(); i++){
            if(!isalpha(str[i])){
                throw LocationException("Invalid location");
            }

        }
    }

    catch (LocationException ex){
        cout << ex.getmessage() << endl;
    }
    ///if valid input then it goes to this
    Locations location(str);
    AddLocation(location);
}

///checking if the location which is put in is on the list (valid)
void LocationRepo::AddLocation(Locations& location){
    ofstream fout;

    fout.open("Locations.dat", ios::binary|ios::app);

    fout.write((char*)(&location), sizeof(Locations));

    fout.close();
}

void LocationRepo::DisplayAllLocations(){

    Locations location;
    ifstream fin;
    fin.open("Locations.dat");

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Locations);
    fin.seekg(0, fin.beg);

    for(int i = 0; i < records; i++){
        fin.read((char*)(&location), sizeof(Locations));
        cout << "Location " << i+1 << ": "<< location << endl;
    }

    fin.close();
    }


int LocationRepo::selectLocation(){
    int loc;
    DisplayAllLocations();
    do{
        cin >> loc;
    }while(0 > loc);
    if(loc == 0){

    }
    return loc;

}
void LocationRepo::DisplayAllOrdersAtLocationBaker(){
    /// WIP
    Locations location;
    int loc = selectLocation();

    ifstream fin;

    fin.open("Pizza_Menu_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Locations);
    fin.seekg(0, fin.beg);

    ///if there is a match for location
    if(records == loc) {
        ///goes to search for Baker order at that location
        cout << location;
        int input;
        cin >> input;

        ///here it goes to look for a match for orders at that location
        ///needs to be done
    }
    fin.close();
}

void LocationRepo::DisplayAllOrdersAtLocationSalesman(){
    ///WIP
}
