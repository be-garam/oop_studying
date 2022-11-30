#include "worker.h"
#include <string>
#include <iostream>

using namespace std;

Worker::Worker(string _name, int _age, int _wage) {
    name = _name;
    age = _age;
    wage = _wage;
    total_wage = 0;
}

Worker::~Worker() {
    cout << "Instance removed." << endl;
}

void Worker::recieve_payment() {
    this -> total_wage = this -> total_wage + this -> wage;
}

