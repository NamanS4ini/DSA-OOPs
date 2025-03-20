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
class FourWheeler{
    public:
        FourWheeler(){
            cout << "This has four wheel\n";
        }
};
class Car: public Vehicle, public FourWheeler{
    public:
        Car(){
            cout << "This is a car\n";
        }
};

int main() {
    Car c1;
    // This is a vehicle
    // This has four wheel
    // This is a car
    c1.drive();
    // Driving
    return 0;
}