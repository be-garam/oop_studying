using System;
using System.Collections.Generic;

public class Cook:Worker {
    public List<string> order;
    public List<string> food;

    public Cook(string _name, int _age, int _wage): base(_name, _age, _wage) {
        order = new List<string>();
        food = new List<string>();
    }

    ~Cook() {
        System.Console.WriteLine("Instance removed.");
    }

    public void recieve_checked_order(List<string> orders){
        this.order = orders;
        System.Console.WriteLine(this.name + "recieved orders");
        this.cook_food();
    }

    public void cook_food(){
        List<string> foods = this.order;
        this.order.Clear();
        System.Console.WriteLine("cook");
        this.food = foods;
    }

    public void send_food(Server server) {
        List<string>foods = this.food;
        System.Console.WriteLine("sended " + foods + " to " + server.name);
        server.recieve_checked_food(String.Join(", ", foods.ToArray()));
        this.food.Clear();
    }
}
