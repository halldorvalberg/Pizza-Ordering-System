#include "GlobalTools.h"


void GlobalTools::clearScreen()
{
    system("CLS");
}

void GlobalTools::exitApplication()
{
    exit(0);
}

void GlobalTools::clear_order(string e)
{
    ofstream ofs;
    ofs.open(e.c_str(), ios::out|ios::trunc);
    ofs.close();
}

void GlobalTools::add_all_to_file(string data, string location)
{
    ifstream fin;

    fin.open(data.c_str(), ios::binary);

    fin.seekg(0, fin.end);
    int rec = fin.tellg() / sizeof(Pizza);
    fin.seekg(0, fin.beg);

    Pizza *pizza = new Pizza[rec];
    fin.read((char*)pizza, sizeof(pizza) * rec);

    fin.close();

    ofstream fout;

    fout.open(location.c_str(), ios::binary|ios::app);

    for(int i = 0; i < rec; i++) {

        fout.write((char*)(&pizza[i]), sizeof(Pizza));

    }

    fout.close();



}
