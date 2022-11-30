#ifndef WORKER_H
#define WORKER_H

#include <string>

using namespace std;

class Worker {
    
public:
    string name;
    int age;
    int wage;
    int total_wage = 0;
    Worker(string, int, int);
    ~Worker();
    void recieve_payment();
};

#endif
