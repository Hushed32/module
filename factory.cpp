// Програма "університет" на C++ з використанням патерну фабрика

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

// Абстрактний клас Person, який визначає загальний інтерфейс для класів Student і Teacher
class Person {
public:
    // Віртуальний метод для отримання імені
    virtual string getName() = 0;
    // Віртуальний метод для отримання ролі (студент або викладач)
    virtual string getRole() = 0;
};

// Клас Student, який успадковується від класу Person і реалізує його методи
class Student : public Person {
private:
    // Поле для зберігання імені студента
    string name;
public:
    // Конструктор, який приймає ім'я студента
    Student(string name) {
        this->name = name;
    }
    // Метод для отримання імені студента
    string getName() {
        return name;
    }
    // Метод для отримання ролі студента
    string getRole() {
        return "студент";
    }
};

// Клас Teacher, який успадковується від класу Person і реалізує його методи
class Teacher : public Person {
private:
    // Поле для зберігання імені викладача
    string name;
public:
    // Конструктор, який приймає ім'я викладача
    Teacher(string name) {
        this->name = name;
    }
    // Метод для отримання імені викладача
    string getName() {
        return name;
    }
    // Метод для отримання ролі викладача
    string getRole() {
        return "викладач";
    }
};

// Клас PersonFactory, який відповідає за створення об'єктів класів Student і Teacher
class PersonFactory {
public:
    // Статичний метод, який приймає ім'я і роль і повертає об'єкт відповідного класу
    static Person* makePerson(string name, string role) {
        // Якщо роль - студент, то створюємо і повертаємо об'єкт класу Student
        if (role == "студент") {
            return new Student(name);
        }
        // Якщо роль - викладач, то створюємо і повертаємо об'єкт класу Teacher
        else if (role == "викладач") {
            return new Teacher(name);
        }
        // Інакше виводимо повідомлення про помилку і повертаємо nullptr
        else {
            cout << "Помилка в PersonFactory::makePerson(), роль " << role << " не є допустимою\n\n";
            return nullptr;
        }
    }
};

// Головна функція програми
int main() {
    // Додаємо цей рядок, щоб виводити на консоль символи української мови
    SetConsoleOutputCP(1251);
    // Створюємо вектор для зберігання вказівників на об'єкти класу Person
    vector<Person*> persons;
    // Додаємо в вектор об'єкти, створені за допомогою фабрики
    persons.push_back(PersonFactory::makePerson("Анна", "студент"));
    persons.push_back(PersonFactory::makePerson("Борис", "викладач"));
    persons.push_back(PersonFactory::makePerson("Василь", "студент"));
    persons.push_back(PersonFactory::makePerson("Галина", "викладач"));
    // Виводимо інформацію про кожен об'єкт в векторі
    for (auto& person : persons) {
        cout << "Ім'я: " << person->getName() << "\n";
        cout << "Роль: " << person->getRole() << "\n\n";
    }
    // Звільняємо пам'ять, виділену під об'єкти
    for (auto& person : persons) {
        delete person;
    }
    // Повертаємо 0, як знак успішного завершення програми
    return 0;
}
