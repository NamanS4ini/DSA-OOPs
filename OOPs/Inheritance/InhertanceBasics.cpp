#include <iostream>

using namespace std;

class Base{
    private:
        int a;
    public:
        int b;
        protected:
        int c;
};

class Derived: public Base{
    public:
        int d;
};


int main(){
    Derived der;
    cout << der.d;
} 