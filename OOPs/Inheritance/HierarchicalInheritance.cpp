#include <iostream>
using namespace std;

class Vehicle{
    public:
        Vehicle(){
            cout << "This is a vehicle\n";
        }
        
};
class FourWheeler: public Vehicle{
    public:
        FourWheeler(){
            cout << "This has four wheel\n";
        }
        void drive(){
            cout << "Driving\n";
        }
};
class TwoWheeler: public Vehicle{
    public:
        TwoWheeler(){
            cout << "This has two wheel\n";
        }
        void ride(){
            cout << "Riding\n";
        }
};
class Car: public FourWheeler{
    public:
        Car(){
            cout << "This is a car\n";
        }
};
class Bike: public TwoWheeler{
    public:
        Bike(){
            cout << "This is a Bike\n";
        }
};

int main() {
    Car c1;
    // This is a vehicle
    // This has four wheel
    // This is a car
    c1.drive();
    // Driving
    cout << "\n";
    Bike b1;
    // This is a vehicle
    // This has two wheel
    // This is a Bike
    b1.ride();
    // Riding
    int arr[] = {1,2,3,4};
    
    return 0;
}