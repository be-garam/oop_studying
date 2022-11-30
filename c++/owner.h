#ifndef OWNER_H
#define OWNER_H

#include <string>
#include <list>

#include "worker.h"

using namespace std;

class Owner {
public:
    string name;
    int total_money;
    list<class Worker> workers;
    Owner(string, int);
    ~Owner();
    void get_worker(class Worker);
    void recieve_total_money(int);
    int wage_payment();
};

#endif
