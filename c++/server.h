#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <list>

#include "worker.h"
#include "server.h"
#include "menu.h"
#include "table.h"
#include "cook.h"
#include "owner.h"

using namespace std;

class Server: public Worker {
private:
    // string name;
    // int age;
    // int wage;
    

public:
    list<list<string>> order;
    string food;
    list<class Table> tables;
    int day_money = 0;
    Server(string, int, int);
    ~Server();
    void recieve_order(class Table, list<string>);
    void send_order(class Cook);
    void recieve_checked_food();
    void serve_food();
    void recieve_money(int);
    void give_total_money(class Owner);
};

#endif
