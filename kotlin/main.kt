// kotlinc main.kt -include-runtime -d main.jar
// java -jar main.jar

class Customer(_name: String){
    var name: String = _name
}

class Table(_customers: ArrayList<*>){
    var customers: ArrayList<*> = _customers
    var cost: Int = 0
    var order: ArrayList<*> = ArrayList<String>()

    fun place_order(orders:ArrayList<String>, server:Server, menu:Menu){
        println("place orders to ${server.name}")
        server.recieve_order(this, orders)
        this.order = orders
        for (order in orders){
            this.cost = this.cost + menu.get_food_cost(order)
        }
    }

    fun get_food(foods:String){
        this.order.clear()
        println("get food")
    }

    fun eat_food(){
        println("eating food")
    }

    fun pay_money(server:Server){
        server.recieve_money(cost)
        println("pay money ${cost}")
    }
}

open class Worker(_name: String, _age: Int, _wage:Int) {
    var name: String = _name
    var age: Int = _age
    var wage: Int = _wage
    var total_wage = 0

    fun recieve_payment(){
        total_wage = total_wage + wage
    }
}

class Server(_name: String, _age: Int, _wage:Int):Worker(_name, _age, _wage){
    var order: ArrayList<ArrayList<String>> = arrayListOf<ArrayList<String>>()
    var food: String = ""
    var tables: ArrayList<Table> = arrayListOf<Table>()
    var day_money: Int = 0

    fun recieve_order(table:Table, orders:ArrayList<String>){
        this.tables.add(table)
        this.order.add(orders)
        println("${this.name} recieved orders from ${table.customers}")
    }

    fun send_order(cook:Cook){
        var sending_order = this.order.elementAt(0)
        order.removeAt(0)
        cook.recieve_checked_order(sending_order)
        println("sended ${order} to ${cook.name}")
    }

    fun recieve_checked_food(foods:String){
        this.food = foods
        println("${this.name} recieved ${this.food}")
    }

    fun serve_food(){
        var table = this.tables.elementAt(0)
        this.tables.removeAt(0)
        println("serve ${this.food} to table")
        table.get_food(this.food)
        this.food = ""
    }

    fun recieve_money(money: Int){
        this.day_money += money
    }

    fun give_total_money(owner:Owner){
        owner.recieve_total_money(this.day_money)
        this.day_money = 0
    }
}

class Cook(_name: String, _age: Int, _wage:Int):Worker(_name, _age, _wage){
    var order: ArrayList<String> = arrayListOf<String>()
    var food: ArrayList<String> = arrayListOf<String>()

    fun recieve_checked_order(orders:ArrayList<String>){
        this.order = orders
        println("${this.name} recieved orders")
        this.cook_food()
    }

    fun cook_food(){
        var foods = this.order
        this.order.clear()
        println("cook")
        this.food = foods
    }

    fun send_food(server:Server){
        var foods = this.food
        println("sended ${foods} to ${server.name}")
        server.recieve_checked_food(foods.joinToString())
        this.food.clear()
    }
}

class Owner(_name: String, _total_money: Int){
    var name: String = _name
    var total_money: Int = _total_money
    var workers:ArrayList<Worker> = ArrayList<Worker>()

    fun get_worker(worker:Worker){
        this.workers.add(worker)
    }

    fun recieve_total_money(day_money:Int){
        this.total_money = this.total_money + day_money
    }

    fun wage_payment(): Int{
        for (worker in this.workers){
            this.total_money = this.total_money - worker.wage
            worker.recieve_payment()
        }
        return this.total_money
    }
}

class Menu(){
    fun get_food_cost(food:String): Int{
        var cost = 0
        when (food){
            "meal" -> cost = 5000
            "special_meal" -> cost = 7000
            "coke" -> cost = 2000
            "cidar" -> cost = 2000
            else -> cost = 0
        }
        return cost
    }
}

fun main() {
    val owner = Owner("Su(Owner)", 1000000)
    val s1 = Server("Ri(Server)", 22, 50000)
    val ck1 = Cook("Nam(Cook)", 23, 50000)
    owner.get_worker(s1)
    owner.get_worker(ck1)
    val menu = Menu()

    val c1 = Customer("Hwang(C1)")
    val t1 = Table(arrayListOf<String>(c1.name))
    t1.place_order(arrayListOf<String>("meal", "cidar"), s1, menu)
    s1.send_order(ck1)
    ck1.send_food(s1)
    s1.serve_food()
    t1.eat_food()
    t1.pay_money(s1)

    val c2 = Customer("Jeong(C2)")
    val c3 = Customer("Min(C3)")
    val t2 = Table(arrayListOf<String>(c2.name, c3.name))
    t2.place_order(arrayListOf<String>("special_meal", "special_meal", "cidar", "coke"), s1, menu)
    s1.send_order(ck1)
    ck1.send_food(s1)
    s1.serve_food()
    t2.eat_food()
    t2.pay_money(s1)    

    println("------------end------------")
    s1.give_total_money(owner)
    println("before payment: ${s1.name}: ${s1.total_wage}, ${ck1.name}: ${ck1.total_wage}")
    owner.wage_payment()
    println("after payment: ${s1.name}: ${s1.total_wage}, ${ck1.name}: ${ck1.total_wage}")

    println("final: ${owner.total_money}")

    //println()
}
