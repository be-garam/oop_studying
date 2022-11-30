#include "table.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;

Table::Table(list<string> _customers) {
    customers = _customers;
    cost = 0;
    order = list<string>();
}

Table::~Table() {
    cout << "Instance removed." << endl;
}

void Table::place_order(list<string> orders, Server server, Menu menu) {
    cout << " place orders to" << server.name << endl;
    this->order = orders;
    for (string order : orders){
        this->cost = this->cost + menu.get_food_cost(order);
    }
    server.recieve_order(*this, orders);
}

void Table::get_food(string foods) {
    this->order.clear();
    cout << "get food" << endl;
}

void Table::eat_food() {
    cout << "eating food" << endl;
}

void Table::pay_money(Server server) {
    server.recieve_money(this -> cost);
    cout << "pay money" << this -> cost << endl;
}
