class Customer():
    def __init__(self, name):
        self.name = name

    def __del__(self):
        print("Instance destructed.")

class Table():
    def __init__(self, customers):
        self.customers = customers
        self.cost = 0
        self.order = []

    def __del__(self):
        print("Instance destructed.")

    def place_order(self, orders, server, menu):
        print(f"place {orders} to {server.name}")
        server.recieve_order(self, orders)
        self.order = orders
        for order in orders:
            self.cost += menu.get_food_cost(order)
    
    def get_food(self, foods):
        self.order = []
        print("get food")

    def eat_food(self):
        print("eating food")

    def pay_money(self, server):
        server.recieve_money(self.cost)
        print(f"pay money {self.cost}")

class Worker():
    def __init__(self, name, age, wage):
        self.name = name
        self.age = age
        self.wage = wage
        self.total_wage = 0

    def __del__(self):
        print("Instance destructed.")

    def recieve_payment(self):
        self.total_wage += self.wage


class Server(Worker):
    def __init__(self, name, age, wage):
        super().__init__(name, age, wage)
        self.order = []
        self.food = None
        self.tables = []
        self.day_money = 0

    def __del__(self):
        print("Instance destructed.")
    
    def recieve_order(self, table, orders):
        self.tables.append(table)
        self.order.append(orders)
        print(f"{self.name} recieved {orders} from {table.customers}")
        # print(f"left orders: {self.tables}, {self.order}")

    def send_order(self, cook):
        order = self.order.pop(0)
        cook.recieve_checked_order(order)
        print(f"sended {order} to {cook.name}")
        # print(f"left orders: {self.tables}, {self.order}")

    def recieve_checked_food(self, foods):
        self.food = foods
        print(f"{self.name} recieved {self.food}")
        # self.serve_food()

    def serve_food(self):
        table = self.tables.pop(0)
        print(f"serve {self.food} to {table.customers}")
        table.get_food(self.food)
        self.food = None

    def recieve_money(self, money):
        self.day_money += money

    def give_total_money(self, owner):
        owner.recieve_total_money(self.day_money)
        self.day_money = 0


class Cook(Worker):
    def __init__(self, name, age, wage):
        super().__init__(name, age, wage)
        self.order = []
        self.food = None

    def recieve_checked_order(self, orders):
        self.order += orders
        print(f"{self.name} recieved {orders}")
        self.cook_food()

    def cook_food(self):
        foods = self.order
        print("cook")
        self.food = foods

    def send_food(self, server):
        foods = self.food
        print(f"sended {foods} to {server.name}")
        server.recieve_checked_food(foods)
        self.food = None

class Owner():
    def __init__(self, name, total_money):
        self.name = name
        self.total_money = total_money
        self.workers = []

    def __del__(self):
        print("Instance destructed.")

    def get_worker(self, worker):
        self.workers.append(worker)

    def recieve_total_money(self, day_money):
        self.total_money += day_money

    def wage_payment(self):
        for worker in self.workers:
            self.total_money -= worker.wage
            worker.recieve_payment()
        return self.total_money
        

class Menu():
    # dictionary를 쓰고 싶지만, 타 언어에서 해당 개념 문법에 오류를 많이 겪어 if문으로 대체
    def __init__(self):
        self.meal = 5000
        self.special_meal = 7000
        self.coke = 2000
        self.cider = 2000
    
    def __del__(self):
        print("Instance destructed.")

    def get_food_cost(self, food):
        # 주문표에 있는 주문만 받고, 그외의 주문은 그냥 넘어간다고 가정
        # 추후, 모든 언어의 exception을 알면 error 메시지 전달로 변경
        if food == "meal":
            return self.meal
        elif food == "special_meal":
            return self.special_meal
        elif food == "coke":
            return self.coke
        elif food == "cider":
            return self.cider
        else:
            return 0

# 시나리오 
# 설정) 초기자본: 1000000, 서빙 1명, 요리 1명, 일급은 각 50000
# 워크 프로세스 가정: cook은 요리를 1개씩만 할 수 있기 때문에, 모든 주문의 control은 server가 진행한다.(보통의 식당에서 수쉐프가 하는 일)
# 쉽게 말하면 주문을 여러개 받을 수 있지만, 주문을 server가 cook에게는 1개씩 배정하여 전달한다. 
# 또한 모든 음식은 순서대로 나온다고 가정한다. -> dictionary를 쓰지 않고, 올바른 customer에게 전달하기 위해서
owner = Owner("Su(Owner)", 1000000)
s1 = Server("Ri(Server)", 22, 50000)
ck1 = Cook("Nam(Cook)", 23, 50000)
owner.get_worker(s1)
owner.get_worker(ck1)
menu = Menu()

# 1. 식당에 c1(손님 1)이 들어와서 정식 1, 사이다 1 주문
c1 = Customer("Hwang(C1)")
t1 = Table([c1.name])
t1.place_order(["meal", "cider"], s1, menu)
s1.send_order(ck1)
ck1.send_food(s1)
s1.serve_food()
t1.eat_food()
t1.pay_money(s1)

# 2. 식당에 c2, c3가 들어와서 특식 2, 콜라 2 주문
# 기존 코드는 Customer 한명당이 아닌, Tabel 기준으로 생각, 이에 따라 Tabel 객체의 추가
c2 = Customer("Jeong(C2)")
c3 = Customer("Min(C3)")
t2 = Table([c2.name, c3.name])
t2.place_order(["special_meal", "special_meal", "cider", "cider"], s1, menu)
s1.send_order(ck1)
ck1.send_food(s1)
s1.serve_food()
t2.eat_food()
t2.pay_money(s1)

# 3. 하루 엄무 마무리, 사장이 종업원에게 일급 지급
print("------------end------------")
s1.give_total_money(owner)
print("before payment: ", s1.name, ":", s1.total_wage, ", ", ck1.name, ":", ck1.total_wage)
owner.wage_payment()
print("after payment: ", s1.name, ":", s1.total_wage, ", ", ck1.name, ":", ck1.total_wage)

# 4. 장사를 마치고, 사장이 남긴 잔액 return
print("final: ", owner.total_money)