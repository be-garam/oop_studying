#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <list>

#include "server.h"
#include "menu.h"

using namespace std;

class Table {
public:
    list<string> customers;
    int cost = 0;
    list<string> order;
    Table(list<string>);
    ~Table();
    void place_order(list<string>, class Server, class Menu);
    void get_food(string);
    void eat_food();
    void pay_money(class Server);
};

#endif
