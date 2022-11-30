using System;
using System.Collections.Generic;

public class Server:Worker {
    public List<List<string>> order;
    public string food;
    public List<Table> tables;
    public int day_money;
    protected List<string> sending_order;
    protected Table table;

    public Server(string _name, int _age, int _wage): base(_name, _age, _wage) {
        order = new List<List<string>>();
        food = "";
        tables = new List<Table>();
        day_money = 0;
    }

    ~Server() {
        System.Console.WriteLine("Instance removed.");
    }

    public void recieve_order(Table table, List<string> orders){
        this.tables.Add(table);
        this.order.Add(orders);
        System.Console.WriteLine(this.name + "recieved orders from" + table.customers);
    }

    public void send_order(Cook cook) {
        sending_order = this.order[0];
        this.order.RemoveAt(0);
        cook.recieve_checked_order(sending_order);
        System.Console.WriteLine("sended" + order + "to" + cook.name);
    }

    public void recieve_checked_food(string foods) {
        this.food = foods;
        System.Console.WriteLine(this.name + "recieved " + this.food);
    }

    public void serve_food() {
        table = this.tables[0];
        this.tables.RemoveAt(0);
        System.Console.WriteLine("serve " + this.food + " to table");
        table.get_food(this.food);
        this.food = "";
    }

    public void recieve_money(int money) {
        this.day_money += money;
    }

    public void give_total_money(Owner owner) {
        owner.recieve_total_money(this.day_money);
        this.day_money = 0;
    }
}
