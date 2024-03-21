#include <iostream>
using namespace std;

class Vehicle {
    int power; 

public:
    Vehicle() { power = 1; }
    Vehicle(int power) {
        this->power = power;
    }
    int getPower() const {
        return power;
    }
};

class Car : public Vehicle {
    string color;
    int wheels;

public:
    Car(int power, const string &color, int wheels)
        : Vehicle(power), color(color), wheels(wheels) {}

    friend ostream& operator<<(ostream &out, const Car &car) {
        out << car.getPower() << ' ' << car.color << ' ' << car.wheels;
        return out;
    }
};

int main() {
    Car sonata(125, "RED", 4); // Sonata with 4 wheels and red color
    cout << sonata << endl;
    return 0;
}