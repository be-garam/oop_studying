#include "customer.h"
#include <string>
#include <iostream>

using namespace std;

Customer::Customer(string _name) {
    name = _name;
}

Customer::~Customer() {
    cout << "Instance removed." << endl;
}
