#include <iostream>
#include<Windows.h>



// Клас Vehicle, абстрактний базовий клас для транспортних засобів
class Vehicle {
public:
    virtual Vehicle* clone() const = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void accelerate() = 0;
};

// Клас Car, конкретний тип транспортного засобу
class Car : public Vehicle {
public:
    Vehicle* clone() const override {
        return new Car(*this);
    }
    void start() override {
        std::cout << "Car started." << std::endl;
    }
    void stop() override {
        std::cout << "Car stopped." << std::endl;
    }
    void accelerate() override {
        std::cout << "Car accelerated." << std::endl;
    }
};

// Клас Motorcycle, ще один конкретний тип транспортного засобу
class Motorcycle : public Vehicle {
public:
    Vehicle* clone() const override {
        return new Motorcycle(*this);
    }
    void start() override {
        std::cout << "Motorcycle started." << std::endl;
    }
    void stop() override {
        std::cout << "Motorcycle stopped." << std::endl;
    }
    void accelerate() override {
        std::cout << "Motorcycle accelerated." << std::endl;
    }
};

int main() {
    Vehicle* originalCar = new Car();
    Vehicle* clonedCar = originalCar->clone();

    Vehicle* originalMotorcycle = new Motorcycle();
    Vehicle* clonedMotorcycle = originalMotorcycle->clone();

    // Використовуйте клоновані об'єкти
    originalCar->start();
    originalCar->accelerate();
    originalCar->stop();

    clonedCar->start();
    clonedCar->accelerate();
    clonedCar->stop();

    originalMotorcycle->start();
    originalMotorcycle->accelerate();
    originalMotorcycle->stop();

    clonedMotorcycle->start();
    clonedMotorcycle->accelerate();
    clonedMotorcycle->stop();

    delete originalCar;
    delete clonedCar;

    delete originalMotorcycle;
    delete clonedMotorcycle;

    return 0;
}
