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
    string str;
    Locations location(str);
    cin >> str;
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
    int counter = 1;
    Locations location(stri);
    ifstream fin;
    fin.open("Locations.txt");
    if(fin.is_open()){
        while(!fin.eof()){
            getline(fin, str);
            cout << counter  << " " << str << endl;
            counter++;
        }
    fin.close();
    }
    else{
        cout << "File is not open" << endl; ///throw FileOpenException()
    }

}

void LocationRepo::selectLocation(){
}
