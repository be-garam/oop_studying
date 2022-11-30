//dotnet run

using System;

public class Worker {
    public string name;
    public int age;
    public int wage;
    public int total_wage;

    public Worker(string _name, int _age, int _wage) {
        name = _name;
        age = _age;
        wage = _wage;
        total_wage = 0;
    }

    ~Worker() {
        System.Console.WriteLine("Instance removed.");
    }

    public void recieve_payment() {
        total_wage = total_wage + wage;
    }
}