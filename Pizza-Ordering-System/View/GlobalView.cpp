#include "GlobalView.h"

void GlobalView::dispHeader()
{
    cout << "______ _                _____         _           _               _____           _                 " << endl;
    cout << "| ___ (_)              |  _  |       | |         (_)             /  ___|         | |                " << endl;
    cout << "| |_/ /_ __________ _  | | | |_ __ __| | ___ _ __ _ _ __   __ _  \\ `--. _   _ ___| |_ ___ _ __ ___  " << endl;
    cout << "|  __/| |_  /_  / _` | | | | | '__/ _` |/ _ \\ '__| | '_ \\ / _` |  `--. \\ | | / __| __/ _ \\ '_ ` _ \\ " << endl;
    cout << "| |   | |/ / / / (_| | \\ \\_/ / | | (_| |  __/ |  | | | | | (_| | /\\__/ / |_| \\__ \\ ||  __/ | | | | |" << endl;
    cout << "\\_|   |_/___/___\\__,_|  \\___/|_|  \\__,_|\\___|_|  |_|_| |_|\\__, | \\____/ \\__, |___/\\__\\___|_| |_| |_|" << endl;
    cout << "                                                           __/ |         __/ |                      " << endl;
    cout << "                                                          |___/         |___/           			 " << endl;
    cout << endl;
}

void GlobalView::display_menu()
{
    int i = 1;
    string str;
    fstream fin;

    cout << "\tThe pizza menu" << endl << endl;
    cout << ("            Name:\tPrice:\tsize: ") << endl;

    fin.open("Pizza_Menu_Binary.txt");
    if(fin.is_open()) {
        while(!fin.eof()) {
            getline(fin, str);
            cout << "Pizza nr " << i << ": " <<  str << endl;
            i++;
        }
        fin.close();
    }
    else {
        cout << "Unable to read from file!" << endl;
    }
}
