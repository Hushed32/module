#include <iostream>
#include <windows.h>

// Клас Car, який представляє автомобіль
class Car {
private:
    std::string model;
    std::string color;
    int price;

public:
    Car(std::string m, std::string c, int p) : model(m), color(c), price(p) {}

    void display() const {
        std::cout << "Модель: " << model << ", Колір: " << color << ", Ціна: " << price << "₴\n";
    }
};

// Singleton клас AutoSalon
class AutoSalon {
private:
    static AutoSalon* instance;
    Car* car;

    // Приватний конструктор
    AutoSalon() : car(nullptr) {}

public:
    // Отримання єдиного екземпляру AutoSalon
    static AutoSalon* getInstance() {
        if (instance == nullptr) {
            instance = new AutoSalon();
        }
        return instance;
    }

    void setCar(Car* c) {
        car = c;
    }

    Car* getCar() const {
        return car;
    }
};

// Ініціалізація статичного члена класу AutoSalon
AutoSalon* AutoSalon::instance = nullptr;

int main() {
    SetConsoleOutputCP(1251);
    // Створення автомобіля
    Car* myCar = new Car("Tesla Model S", "Червоний", 3000000);

    // Отримання екземпляру AutoSalon
    AutoSalon* salon = AutoSalon::getInstance();
    salon->setCar(myCar);

    // Відображення інформації про автомобіль
    salon->getCar()->display();

    delete myCar; // Очищення пам'яті
    return 0;
}
