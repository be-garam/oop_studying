//g++ cook.cpp worker.cpp customer.cpp menu.cpp owner.cpp server.cpp table.cpp -o main

#include "worker.h"
#include "cook.h"
#include "customer.h"
#include "menu.h"
#include "owner.h"
#include "server.h"
#include "table.h"

#include <string>
#include <iostream>
#include <list>

using namespace std;

int main() {
	Owner owner("Su(Owner)", 1000000);
    Server s1("Ri(Server)", 22, 50000);
    Cook ck1("Nam(Cook)", 23, 50000);
    owner.get_worker(s1);
    owner.get_worker(ck1);
    Menu menu;

    Customer c1("Hwang(C1)");

	list<string> t1_data;
	t1_data.push_back(c1.name);
    Table t1(t1_data);
	
	list<string> order_1;
	order_1.push_back("meal");
	order_1.push_back("cidar");
    t1.place_order(order_1, s1, Menu());
    
	s1.send_order(ck1);
    ck1.send_food(s1);
    s1.serve_food();
    t1.eat_food();
    t1.pay_money(s1);

    Customer c2("Jeong(C2)");
    Customer c3("Min(C3)");

	list<string> t2_data;
	t2_data.push_back(c2.name);
	t2_data.push_back(c3.name);
    Table t2(t2_data);

	list<string> order_2;
	order_2.push_back("special_meal");
	order_2.push_back("cidar");
	order_2.push_back("special_meal");
	order_2.push_back("coke");
    t2.place_order(order_2, s1, menu);
    s1.send_order(ck1);
    ck1.send_food(s1);
    s1.serve_food();
    t2.eat_food();
    t2.pay_money(s1);    

    cout << "------------end------------" << endl;
    s1.give_total_money(owner);
    cout << "before payment: " <<  s1.name << ":" << s1.total_wage << ck1.name <<":"<<ck1.total_wage<<endl;
    owner.wage_payment();
    cout << "after payment: " <<  s1.name << ":" << s1.total_wage << ck1.name <<":"<<ck1.total_wage<<endl;

    cout << "final: " << owner.total_money << endl;
	return 0;
}
