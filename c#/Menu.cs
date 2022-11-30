using System;

public class Menu {
    public Menu() {
    }

    ~Menu() {
        System.Console.WriteLine("Instance removed.");
    }

    public int get_food_cost(string food) {
        switch (food) {
            case "meal":
                return 5000;
            case "special_meal":
                return 7000;
            case "coke":
                return 2000;
            case "cidar":
                return 2000;
            default:
                return 0;
        }
    }
}
