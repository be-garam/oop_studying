using System;

public class Customer {
    public string name;

    public Customer(string _name) {
        name = _name;
    }

    ~Customer() {
        System.Console.WriteLine("Instance removed.");
    }
}
