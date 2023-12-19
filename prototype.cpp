// Включаємо бібліотеки
#include <iostream>;
#include <string>;
#include <vector>;
#include <memory>;
#include <Windows.h>;


// Абстрактний клас кави, який має метод Clone для створення копій
class Coffee {
public:
    // Віртуальний деструктор
    virtual ~Coffee() {}
    // Віртуальний метод Clone, який повертає вказівник на копію об'єкта
    virtual Coffee* Clone() const = 0;
    // Віртуальний метод GetInfo, який виводить інформацію про каву
    virtual void GetInfo() const = 0;
};

// Клас Еспресо, який є нащадком класу кави
class Espresso : public Coffee {
public:
    // Конструктор з параметром
    Espresso(int strength) : strength_(strength) {}
    // Перевизначений метод Clone, який створює копію еспресо
    Coffee* Clone() const override {
        return new Espresso(strength_);
    }
    // Перевизначений метод GetInfo, який виводить інформацію про еспресо
    void GetInfo() const override {
        std::cout << "Еспресо з міцністю " << strength_ << "\n";
    }
private:
    // Поле, яке зберігає міцність еспресо
    int strength_;
};

// Клас Капучіно, який є нащадком класу кави
class Cappuccino : public Coffee {
public:
    // Конструктор з параметрами
    Cappuccino(int strength, int foam) : strength_(strength), foam_(foam) {}
    // Перевизначений метод Clone, який створює копію капучіно
    Coffee* Clone() const override {
        return new Cappuccino(strength_, foam_);
    }
    // Перевизначений метод GetInfo, який виводить інформацію про капучіно
    void GetInfo() const override {
        std::cout << "Капучіно з міцністю " << strength_ << " та пінкою " << foam_ << "\n";
    }
private:
    // Поля, які зберігають міцність та пінку капучіно
    int strength_;
    int foam_;
};

// Клас Кав'ярня, який має вектор вказівників на каву
class Cafe {
public:
    // Метод AddCoffee, який додає каву до вектора
    void AddCoffee(Coffee* coffee) {
        coffees_.push_back(coffee);
    }
    // Метод GetCoffee, який повертає копію кави за індексом
    Coffee* GetCoffee(int index) const {
        if (index >= 0 && index < coffees_.size()) {
            return coffees_[index]->Clone();
        }
        else {
            return nullptr;
        }
    }
    // Метод ShowCoffees, який виводить інформацію про всі кави в векторі
    void ShowCoffees() const {
        for (const auto& coffee : coffees_) {
            coffee->GetInfo();
        }
    }
private:
    // Вектор вказівників на каву
    std::vector<Coffee*> coffees_;
};

// Головна функція
int main() {
    SetConsoleOutputCP(1251);
    // Створюємо об'єкт кав'ярні
    Cafe cafe;
    // Створюємо та додаємо кави до кав'ярні
    cafe.AddCoffee(new Espresso(5));
    cafe.AddCoffee(new Cappuccino(3, 2));
    cafe.AddCoffee(new Espresso(7));
    cafe.AddCoffee(new Cappuccino(4, 3));
    // Виводимо інформацію про всі кави в кав'ярні
    cafe.ShowCoffees();
    // Створюємо копію кави за індексом 1
    Coffee* coffee = cafe.GetCoffee(1);
    // Виводимо інформацію про копію
    coffee->GetInfo();
    // Звільняємо пам'ять
    delete coffee;
    return 0;
}
