#include <iostream>
#include <string>
#include <memory> // для std::unique_ptr
#include <vector>;
#include <windows.h>;

// Абстрактний базовий клас для продуктів
class Product {
public:
    // Конструктор за замовчуванням з ініціалізацією членів класу
    Product() : name(""), price(0.0), description("") {}

    // Гетери для атрибутів класу
    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    std::string getDescription() const {
        return description;
    }

    // Сетери для атрибутів класу
    void setName(const std::string& name) {
        this->name = name;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void setDescription(const std::string& description) {
        this->description = description;
    }

    // віртуальний метод для виводу інформації про продукцію
    virtual void printInfo() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Price: " << price << "\n";
        std::cout << "Description: " << description << "\n";
    }

    // віртуальний деструктор
    virtual ~Product() {}

protected:
    // Атрибути класу
    std::string name;
    double price;
    std::string description;
};

// Абстрактний базовий клас для будівельників
class Builder {
public:
    // Віртуальний деструктор
    virtual ~Builder() {}

    // Чисто віртуальні методи для створення і налаштування продуктів
    virtual void createNewProduct() = 0;
    virtual void setName(const std::string& name) = 0;
    virtual void setPrice(double price) = 0;
    virtual void setDescription(const std::string& description) = 0;
    virtual Product* getProduct() = 0;
};

// Конкретний будівельник для книг
class BookBuilder : public Builder {
public:
    // Конструктор, ініціалізує розумний вказівник на продукт
    BookBuilder() : currentProduct(std::make_unique<Book>()) {}

    // Методи для створення та налаштування продукту
    void createNewProduct() override {
        currentProduct = std::make_unique<Book>();
    }

    void setName(const std::string& name) override {
        currentProduct->setName(name);
    }

    void setPrice(double price) override {
        currentProduct->setPrice(price);
    }

    void setDescription(const std::string& description) override {
        currentProduct->setDescription(description);
    }

    // Специфічні методи для книг
    void setAuthor(const std::string& author) {
        currentProduct->setAuthor(author);
    }

    void setGenre(const std::string& genre) {
        currentProduct->setGenre(genre);
    }

    // Метод для отримання продукту
    Product* getProduct() override {
        return currentProduct.get();
    }

private:
    // Клас книги спадковий від продукта
    class Book : public Product {
    public:
        // Гетери для специфічних атрибутів
        std::string getAuthor() const {
            return author;
        }

        std::string getGenre() const {
            return genre;
        }

        // Сетери для специфічних атрибутів
        void setAuthor(const std::string& author) {
            this->author = author;
        }

        void setGenre(const std::string& genre) {
            this->genre = genre;
        }

        // Переопределенный метод для виводу інформації о книзі
        void printInfo() const override {
            Product::printInfo();
            std::cout << "Author: " << author << "\n";
            std::cout << "Genre: " << genre << "\n";
        }

    private:
        // Специфічні атрибути
        std::string author;
        std::string genre;
    };

    // Розумний вказівник на продукт
    std::unique_ptr<Book> currentProduct;
};

// Конкретний будівельник одягу
class ClothingBuilder : public Builder {
public:
    // Конструктор, инициализує розумний вказівник
    ClothingBuilder() : currentProduct(std::make_unique<Clothing>()) {}

    // Методи для створення та налаштування
    void createNewProduct() override {
        currentProduct = std::make_unique<Clothing>();
    }

    void setName(const std::string& name) override {
        currentProduct->setName(name);
    }

    void setPrice(double price) override {
        currentProduct->setPrice(price);
    }

    void setDescription(const std::string& description) override {
        currentProduct->setDescription(description);
    }

    // Специфические методы для одежды
    void setSize(const std::string& size) {
        currentProduct->setSize(size);
    }

    void setColor(const std::string& color) {
        currentProduct->setColor(color);
    }

    // Метод для отримання продукту
    Product* getProduct() override {
        return currentProduct.get();
    }

private:
    // Класс одягу, спадковий від продукта
    class Clothing : public Product {
    public:
        // Гетери для специфічних атрибутів
        std::string getSize() const {
            return size;
        }

        std::string getColor() const {
            return color;
        }

        // Сетери для атрибутів
        void setSize(const std::string& size) {
            this->size = size;
        }

        void setColor(const std::string& color) {
            this->color = color;
        }

        // Переопределенный метод для виводу інформації про одяг
        void printInfo() const override {
            Product::printInfo();
            std::cout << "Size: " << size << "\n";
            std::cout << "Color: " << color << "\n";
        }

    private:
        // атрибути
        std::string size;
        std::string color;
    };

    // розумний вказівник
    std::unique_ptr<Clothing> currentProduct;
};

// Конкретний будівельник для техніки
class ElectronicsBuilder : public Builder {
public:
    // Конструктор, инициализирующий умный указатель на продукт
    ElectronicsBuilder() : currentProduct(std::make_unique<Electronics>()) {}

    // Методи для створення і налаштування продукту
    void createNewProduct() override {
        currentProduct = std::make_unique<Electronics>();
    }

    void setName(const std::string& name) override {
        currentProduct->setName(name);
    }

    void setPrice(double price) override {
        currentProduct->setPrice(price);
    }

    void setDescription(const std::string& description) override {
        currentProduct->setDescription(description);
    }

    // Специфічні методи техніки
    void setBrand(const std::string& brand) {
        currentProduct->setBrand(brand);
    }

    void setModel(const std::string& model) {
        currentProduct->setModel(model);
    }

    // Метод для отримання продукту
    Product* getProduct() override {
        return currentProduct.get();
    }

private:
    // Класс техніки, спадковий від продукту
    class Electronics : public Product {
    public:
        // Гетери для спец атрибутів
        std::string getBrand() const {
            return brand;
        }

        std::string getModel() const {
            return model;
        }

        // Сетери спец атрибутів
        void setBrand(const std::string& brand) {
            this->brand = brand;
        }

        void setModel(const std::string& model) {
            this->model = model;
        }

        // Переопределенный метод для виводу інформації про техніку
        void printInfo() const override {
            Product::printInfo();
            std::cout << "Brand: " << brand << "\n";
            std::cout << "Model: " << model << "\n";
        }

    private:
        // Спец атрибути
        std::string brand;
        std::string model;
    };

    // Розумний вказівець на продукт
    std::unique_ptr<Electronics> currentProduct;
};

// Класс директора, який керує процесами створення різних продуктів іншими будівельниками (прораб)
class Director {
public:
    // Конструктор, отримуючий вказівець на будівельника
    Director(Builder* builder) : builder(builder) {}

    // Метод для встановлення будівельника
    void setBuilder(Builder* builder) {
        this->builder = builder;
    }

    // Метод для створення продукту з заданими параметрами
    Product* createProduct(const std::string& name, double price, const std::string& description, const std::vector<std::string>& params) {
        // ...
        // Створюємо новий продукт за допомогою будівельника
        builder->createNewProduct();
        // Встановуюємо ім'я ціну і опис
        builder->setName(name);
        builder->setPrice(price);
        builder->setDescription(description);

        // Перевіряєм, який тип будівельника ми використовуємо
        if (BookBuilder* bookBuilder = dynamic_cast<BookBuilder*>(builder)) {
            // Якщо це будівельник для книг, то встановлюємо автора і жанр
            bookBuilder->setAuthor(params[0]);
            bookBuilder->setGenre(params[1]);
        }
        else if (ClothingBuilder* clothingBuilder = dynamic_cast<ClothingBuilder*>(builder)) {
            // Якщо одягу, розмір і колір
            clothingBuilder->setSize(params[0]);
            clothingBuilder->setColor(params[1]);
        }
        else if (ElectronicsBuilder* electronicsBuilder = dynamic_cast<ElectronicsBuilder*>(builder)) {
            // якщо техніки, бренд і модель
            electronicsBuilder->setBrand(params[0]);
            electronicsBuilder->setModel(params[1]);
        }

        // вертаємо показник на створений продукт
        return builder->getProduct();
    }

private:
    // показник на будівельника
    Builder* builder;
};

// Функція main,в котрій тестуємо код
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Створюємо будівельників для різниї типів продуктів
    BookBuilder* bookBuilder = new BookBuilder();
    ClothingBuilder* clothingBuilder = new ClothingBuilder();
    ElectronicsBuilder* electronicsBuilder = new ElectronicsBuilder();

    // Створюємо прораба який буде використовувати будівельників))
    Director* director = new Director(bookBuilder);

    // Створюємо та виводимо інфу про книгу
    Product* book = director->createProduct("О дивний новий світ", 1000, "Утопія Олдоса Хакслі", { "Олдос Хакслі", "Фантастика" });
    book->printInfo();

    // Змінюємо будівельника на будівельника одягу
    director->setBuilder(clothingBuilder);

    // Інфа про одяг
    Product* clothing = director->createProduct("Футболка", 500, "Бавовняна футболка с принтом", { "M", "Чорний" });
    clothing->printInfo();

    // будівельник техніки
    director->setBuilder(electronicsBuilder);

    // інфа про техніку
    Product* electronics = director->createProduct("Ноутбук", 30000, "Ноут для роботи та ігор", { "ASUS", "ROG Zephyrus" });
    electronics->printInfo();

    // Звільняємо пам'ять зайняту продуктами,будівельниками і Директором
    delete book;
    delete clothing;
    delete electronics;
    delete bookBuilder;
    delete clothingBuilder;
    delete electronicsBuilder;
    delete director;

    return 0;
}
