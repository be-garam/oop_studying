using System;
using System.Collections.Generic;

public class Table {
    public List<string> customers;
    public int cost;
    public List<string> order;

    public Table(List<string> _customers) {
        customers = _customers;
        cost = 0;
        order = new List<string>();
    }

    ~Table() {
        System.Console.WriteLine("Instance removed.");
    }

    public void place_order(List<string> orders, Server server, Menu menu) {
        System.Console.WriteLine("place orders to " + server.name);
        server.recieve_order(this, orders);
        this.order = orders;
        for (int i = 0; i < orders.Count; i++){
            this.cost = this.cost + menu.get_food_cost(orders[i]);
        }
    }
    public void get_food(string foods) {
        this.order.Clear();
        System.Console.WriteLine("get food");
    }

    public void eat_food() {
        System.Console.WriteLine("eating food");
    }

    public void pay_money(Server server) {
        server.recieve_money(cost);
        System.Console.WriteLine("pay money" + cost);
    }
}
