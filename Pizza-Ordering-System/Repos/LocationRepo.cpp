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
void LocationRepo::validLocation(string str){
    try{
        for(unsigned int i = 0; i < str.size(); i++){
        if (!isalpha(str[i])){
            throw LocationException("Invalid location");
        }
        }
    }
    catch (LocationException ex){
        cout << ex.getmessage() << endl;
    }
}

///checking if the location which is put in is on the list (valid)
void LocationRepo::AddLocation(){
    string str;
    Locations location(str);
    cin >> str;
    //validLocation(str);
    ofstream fout;

    fout.open("Locations.txt", ios::app);
    if(fout.is_open()){
        fout << str;
        fout.close();
    }
    else{
        cout << "File is not open!" << endl;
    }
}

void LocationRepo::DisplayAllLocations(){
    string stri, str;
    Locations location(stri);
    validLocation(str);
    ifstream fin;
    try{
    fin.open("Locations.txt");
    if(fin.is_open()){
        while(!fin.eof()){
          getline(fin, str);
            cout << location << endl;
            return;
        }
    throw LocationException("Not a valid locaiton");
    fin.close();
    }
    else{
        cout << "File is not open!" << endl;
    }
    }
    catch (LocationException l){
        cout << l.getmessage() << endl;
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
}
