#include "owner.h"
#include <string>
#include <iostream>

using namespace std;

Owner::Owner(string _name, int _total_money) {
    name = _name;
    total_money = _total_money;
    workers = list<class Worker>();
}

Owner::~Owner() {
    cout << "Instance removed." << endl;
}

void Owner::get_worker(Worker worker) {
    this -> workers.push_back(worker);
}

void Owner::recieve_total_money(int day_money) {
    this -> total_money = this -> total_money + day_money;
}

int Owner::wage_payment() {
    for (Worker worker : this -> workers){
        this->total_money = this->total_money - worker.wage;
        worker.recieve_payment();
    }
    return this -> total_money;
}

