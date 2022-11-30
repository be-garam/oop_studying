#include "menu.h"
#include <string>
#include <iostream>

using namespace std;

Menu::Menu() {
}

Menu::~Menu() {
    cout << "Instance removed." << endl;
}

int Menu::get_food_cost(string food) {
    int cost = 0;
    if (food == "meal")
        cost = 5000;
    else if (food == "special_meal")
        cost = 7000;
    else if (food == "coke")
        cost = 2000;
    else if (food == "cidar")
        cost = 2000;
    else
        cost = 0;
        
    return cost;
}
