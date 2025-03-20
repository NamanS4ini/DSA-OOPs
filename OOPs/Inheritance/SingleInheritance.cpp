#include <iostream>
using namespace std;

class Vehicle{
    public:
        Vehicle(){
            cout << "This is a vehicle\n";
        }
        void drive(){
            cout << "Driving\n";
        }
};
class Car: public Vehicle{
    public:
        Car(){
            cout << "This is a car\n";
        }
};

int main() {
    Car c1;
    // This is a vehicle
    // This is a car
    c1.drive();
    // Driving
    return 0;
}