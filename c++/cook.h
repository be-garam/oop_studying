#ifndef COOK_H
#define COOK_H

#include <string>
#include <list>

#include "worker.h"
#include "server.h"
#include "menu.h"
#include "table.h"
#include "cook.h"
#include "owner.h"

using namespace std;

class Cook: public Worker {
private:
    // string name;
    // int age;
    // int wage;

public:
    list<string> order;
    list<string> food;
    Cook(string, int, int);
    ~Cook();
    void recieve_checked_order(list<string>);
    void cook_food();
    void send_food(class Server);
};

#endif
