#include "CostumerMenuView.h"

void CostumerMenuView::CostumerMenuDisplay(){
    cout << "Add pizzas to your order" << endl << endl;

	cout << "1: Add Pizza from Menu" << endl;
	cout << "2: Add Custom Pizza" << endl;
	cout << "3: View your Order" << endl;
	cout << "q: Finish order" << endl;
}

void CostumerMenuView::ChosenToppings(int counter, Toppings total_toppings[20]){
    outputstring("Your current toppings are : ");
    for(int i = 0; i < counter;i++){
        cout << total_toppings[i] << endl;
    }
    cout << "Their total count is : " << counter << endl << endl;
}

void CostumerMenuView::DisplaySizeMenu(){
    cout << "Choose the size of your pizza" << endl << endl;

    cout << "1. 16 inch" << endl;
    cout << "2. 12 inch" << endl;
    cout << "3. 8 inch" << endl;
}
