#include "MainMenuController.h"

MainMenuController::MainMenuController()
{
    clearScreen();
    dispHeader();
    clear_order("Costumer_Order_Binary.dat");
    onLoad();
    init();
}

MainMenuController::~MainMenuController()
{
    //dtor
}


void MainMenuController::init()
{
    string inputString;

    do{
        MainMenudisplay();
        cin >> inputString;
    }while (inputString[0] != 'a' &&
            inputString[0] != 'b' &&
            inputString[0] != 'c' &&
            inputString[0] != 's' &&
            inputString[0] != 'q');

    if( inputString == "a"){
        AdminMenuController amc;
    }
    else if( inputString == "b"){
        BakerMenuController amc;
    }
    else if( inputString == "c"){
        CostumerMenuController amc;
    }
    else if( inputString == "s"){
        SalesmanMenuController amc;
    }
    else if( inputString == "q"){
        exitApplication();
    }

}

void MainMenuController::onLoad()
{

    ofstream fout;
    fout.open("Orders_Binary.dat", ios::binary);
    fout.close();


    ifstream fin;

    fin.open("Orders_Binary.dat", ios::binary);

    fin.seekg(0, fin.end);
    int records = fin.tellg() / sizeof(Order);
    fin.seekg(0, fin.beg);

    Order *data = new Order[records];

    fin.read((char*)data, sizeof(Order) * records);

    fin.close();

    for (int i = 0; i < records; i++) {
        OrderVector.push_back(data[i]);
    }





}

