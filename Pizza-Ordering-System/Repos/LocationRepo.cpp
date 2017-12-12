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

    fout.open("Locations.txt", ios::app);
    if(fout.is_open()){
        fout << location;
        fout.close();
    }
    else{
        cout << "File is not open!" << endl;
    }
}

void LocationRepo::DisplayAllLocations(){
    string str;
    Locations location;
    ifstream fin;
    fin.open("Locations.txt");

    if(fin.is_open()){

        while(!fin.eof()){
          getline(fin, str);
            cout << location << endl;
            return;
        }

    fin.close();
    }
    else{
        cout << "File is not open!" << endl;
    }

}

void LocationRepo::selectLocation(string bb){
    string str;
    ifstream fin;
    fin.open("Location.txt");

    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin, str);
            if(bb == str){
                cout << str << endl;
            }
        }
        fin.close();
    }
    else{
        cout << "File is not open" << endl;
    }
}
