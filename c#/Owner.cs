using System;
using System.Collections.Generic;

public class Owner {
    public string name;
    public int total_money;
    public List<Worker> workers;

    public Owner(string _name, int _total_money) {
        name = _name;
        total_money = _total_money;
        workers = new List<Worker>();
    }

    ~Owner() {
        System.Console.WriteLine("Instance removed.");
    }

    public void get_worker(Worker worker) {
        this.workers.Add(worker);
    }

    public void recieve_total_money(int day_money) {
        this.total_money = this.total_money + day_money;
    }

    public int wage_payment() {
        for (int i = 0; i < this.workers.Count; i++){
            this.total_money = this.total_money - workers[i].wage;
            workers[i].recieve_payment();
        }
        return this.total_money;
    }
}
