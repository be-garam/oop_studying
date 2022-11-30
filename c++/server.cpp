#include "server.h"

#include <string>
#include <iostream>
#include <list>

using namespace std;

Server::Server(string _name, int _age, int _wage): Worker(_name, _age, _wage) {
    order = list<list<string>>();
    food = string();
    tables = list<class Table>();
    day_money = 0;
}

Server::~Server() {
    cout << "Instance removed." << endl;
}

void Server::recieve_order(Table table, list<string> orders) {
    this -> tables.push_back(table);
    this -> order.push_back(orders);
    cout << this -> name << "recieved orders"<< endl;
}

void Server::send_order(Cook cook) {
    cout << this->name << endl;
    cook.recieve_checked_order(order.front());
    order.pop_front();
    cout << "sended order to" << cook.name << endl;
}

void Server::recieve_checked_food() {
    //this -> food = foods;
    cout << this->name << "recieved food" << endl;
}

void Server::serve_food() {
    cout << "serve" << this -> food << "to table" << endl;
    tables.front().get_food(this -> food);
    tables.pop_front();
    this -> food = "";
}

void Server::recieve_money(int money) {
    this -> day_money += money;
}

void Server::give_total_money(Owner owner) {
    owner.recieve_total_money(this -> day_money);
    this -> day_money = 0;
}
