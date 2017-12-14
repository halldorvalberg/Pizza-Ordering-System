#include "SodaRepo.h"

SodaRepo::SodaRepo()
{
    //ctor
}

SodaRepo::~SodaRepo()
{
    //dtor
}

void SodaRepo::writeSoda(Soda& soda){

    ofstream fout("Soda.dat", ios::binary|ios::app);

    fout.write((char*)(&soda), sizeof(Soda));

    fout.close();
}

void SodaRepo::displaySoda(){
    Soda soda;
    ifstream fin;
    fin.open("Soda.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Soda);
    fin.seekg(0, fin.beg);


    for(int i = 0; i < records; i++){
        fin.read((char*)(&soda), sizeof(Soda));
        cout << "Soda nr " << i+1 << ": "<< soda << endl;
    }
    fin.close();
}

void SodaRepo::validSoda(){
    Soda soda;
    try{
        cin >> soda;
        string name = soda.name;
        int price = soda.price;
        for(unsigned int i = 0; i < name.length(); i++){
            if(!isalpha(name[i])){
                throw SodaNameException("Invalid soda name");
                break;
            }
        }
        if (price < 0){
            throw SodaPriceException("Invalid Soda price");
        }
    }
    catch(SodaNameException sne){
        cout << sne.getmessage();
        return;
    }
    catch(SodaPriceException spe){
        spe.getmessage();
        return;
    }

}
