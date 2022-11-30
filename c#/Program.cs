Owner owner = new Owner("Su(Owner)", 1000000);
Server s1 = new Server("Ri(Server)", 22, 50000);
Cook ck1 = new Cook("Nam(Cook)", 23, 50000);
owner.get_worker(s1);
owner.get_worker(ck1);
Menu menu = new Menu();

Customer c1 = new Customer("Hwang(C1)");
List<string> t1_data = new List<string>() {c1.name};
Table t1 = new Table(t1_data);
List<string> t1_menu = new List<string>() {"meal", "cidar"};
t1.place_order(t1_menu, s1, menu);
s1.send_order(ck1);
ck1.send_food(s1);
s1.serve_food();
t1.eat_food();
t1.pay_money(s1);

Customer c2 = new Customer("Jeong(C2)");
Customer c3 = new Customer("Min(C3)");
List<string> t2_data = new List<string>() {c2.name, c3.name};
Table t2 = new Table(t2_data);
List<string> t2_menu = new List<string>() {"special_meal", "special_meal", "coke", "cidar"};
t2.place_order(t2_menu, s1, menu);
s1.send_order(ck1);
ck1.send_food(s1);
s1.serve_food();
t2.eat_food();
t2.pay_money(s1);    

System.Console.WriteLine("------------end------------");
s1.give_total_money(owner);
System.Console.WriteLine("before payment: " +  s1.name + ":" + s1.total_wage + ck1.name + ":" + ck1.total_wage);
owner.wage_payment();
System.Console.WriteLine("after payment: " +  s1.name + ":" + s1.total_wage + ck1.name + ":" + ck1.total_wage);
System.Console.WriteLine("final: " + owner.total_money);
