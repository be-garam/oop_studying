#include "cook.h"

#include <string>
#include <iostream>
#include <list>

using namespace std;

Cook::Cook(string _name, int _age, int _wage): Worker(_name, _age, _wage) {
    order = list<string>();
    food = list<string>();
}

Cook::~Cook() {
    cout << "Instance removed." << endl;
}

void Cook::recieve_checked_order(list<string> orders) {
    this -> order = orders;
    cout << this -> name << "recieved orders" << endl;
    this -> cook_food();
}

void Cook::cook_food() {
    list<string> foods;
    foods = this -> order;
    this -> order.clear();
    cout << "cook" << endl;
    this -> food = foods;
}

void Cook::send_food(Server server) {
    //list<string> foods;
    //foods = this -> food;
    // cout << "sended" << foods << "to" << server.name << endl;
    //std::string joined = boost::algorithm::join(foods, ",");
    server.recieve_checked_food();
    this -> food.clear();
}
