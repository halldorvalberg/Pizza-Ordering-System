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

    Locations location;

    try{
        cin >> location;
         string local = location.getlocation();
        for(unsigned int i = 0; i < local.length(); i++){
            if(!isalpha(local[i])){
                throw LocationException("Invalid location");
            }

        }
    }

    catch (LocationException ex){
        cout << ex.getmessage() << endl;
        return;
    }
    ///if valid input then it goes to this
    AddLocation(location);
}

///checking if the location which is put in is on the list (valid)
void LocationRepo::AddLocation(Locations& location){

    string local;
    cout << location;
    ofstream fout;
    fout.open("Locations.dat", ios::binary|ios::app);

    fout.write((char*)(&location), sizeof(Locations));

    fout.close();
}

void LocationRepo::DisplayAllLocations(){

    Locations location;
    ifstream fin;
    fin.open("Locations.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Locations);
    fin.seekg(0, fin.beg);

    for(int i = 0; i < records; i++){
        fin.read((char*)(&location), sizeof(Locations));
        cout << "Location " << i+1 << ": "<< location << endl;
    }

    fin.close();
    }


Locations LocationRepo::selectLocation(){
    Locations location;
    Locations currentlocation;
    int loc;
    char element;
    DisplayAllLocations();
    outputstring("select your location or q to cancel");
    cin >> element;
    if(element != 'q' && 48 < element && element < 58) {
        loc = element - 49;
    }
        ifstream fin;

    fin.open("Locations.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Locations);
    fin.seekg(0, fin.beg);

  //  Locations *data = new Locations[records];

    ///if there is a match for location
    for(int i = 0; i < records; i++){
     fin.read((char*)(&location), sizeof(Locations));
    if(i == loc) {
        currentlocation = location;
        break;
    }

        ///here it goes to look for a match for orders at that location
        ///needs to be done

    }
    fin.close();
    return currentlocation;

}
void LocationRepo::DisplayAllOrdersAtLocationBaker(){
    /// WIP
    outputstring("Pizzas at your location");
    Locations loc;
    loc = selectLocation();
    cout << loc << endl;


}

void LocationRepo::DisplayAllOrdersAtLocationSalesman(){
    ///WIP
    outputstring("Pizzas at your location");
    Locations loc;
    loc = selectLocation();
    cout << loc << endl;
}
