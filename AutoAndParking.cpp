#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
    int doors;
    int wheels;
    int speed;
    int color; //використання enum для кольорів

public:
    enum Color {
        RED,
        GREEN,
        BLUE,
        BLACK,
        WHITE
    };
    static const string possibleColors[];

    // конструктор з використанням this-> для коректного присвоєння
    Auto(int doors = 4, int wheels = 4, int speed = 100, Color color = WHITE) {
        this->doors = doors;
        this->wheels = wheels;
        this->speed = speed;
        this->color = color;
    }

    void assignValues(int doors, int wheels, int speed, Color color) {
        this->doors = doors;
        this->wheels = wheels;
        this->speed = speed;
        this->color = color;
    }

    int getDoors() const 
    { 
        return doors; 
    }
    int getWheels() const 
    { 
        return wheels; 
    }
    int getSpeed() const 
    { 
        return speed; 
    }
    string getColor() const 
    { 
        return possibleColors[color]; 
    }
};

const string Auto::possibleColors[] = { "RED", "GREEN", "BLUE", "BLACK", "WHITE" };

class Parking {
private:
    Auto* cars;
    int capacity; // зберігає кількість автомобілів на стоянці

public:
    static int carCount;

    Parking() {
        cars = nullptr;
        capacity = 0;
    }

    ~Parking() { delete[] cars; }

    void addCar(const Auto& car) {
        Auto* temp = new Auto[capacity + 1];
        for (int i = 0; i < capacity; i++) {
            temp[i] = cars[i];
        }
        temp[capacity] = car;

        delete[] cars;
        cars = temp;

        capacity++;
        carCount++;
        cout << "Car drive in. Total cars on parking: " << carCount << endl;
    }

    void removeCar(int index) {
        if (index < 0 || index >= capacity) {
            cout << "Invalid index!" << endl;
            return;
        }

        Auto* temp = new Auto[capacity - 1];
        for (int i = 0, j = 0; i < capacity; i++) {
            if (i != index) {
                temp[j++] = cars[i];
            }
        }

        delete[] cars;
        cars = temp;

        capacity--;
        carCount--;
        cout << "Car drove away((( Total cars on parking: " << carCount << endl;
    }

    void displayCars() const {
        if (capacity == 0) {
            cout << "Parking is empty!!!!!" << endl;
            return;
        }

        for (int i = 0; i < capacity; i++) {
            cout << "Car " << i + 1 << ": "
                << "Doors: " << cars[i].getDoors()
                << ", Wheels: " << cars[i].getWheels()
                << ", Speed: " << cars[i].getSpeed()
                << ", Color: " << cars[i].getColor() << endl;
        }
    }
};

int Parking::carCount = 0;

int main() {
    Parking parking;

    Auto car1(1, 10000000, 12345, Auto::RED);
    Auto car2(11037, 0, 96, Auto::BLUE);

    parking.addCar(car1);
    parking.addCar(car2);

    parking.displayCars();

    parking.removeCar(0);

    parking.displayCars();
}
