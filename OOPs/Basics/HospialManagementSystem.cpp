#include <iostream>

using namespace std;

class Doctor{
    public:
    string name;
    string specialization;
    Doctor(){
        name = "";
        specialization = "";

    }
    Doctor(string name, string specialization){
        this->name = name;
        this->specialization = specialization;
    }
    void display(){
        cout << "Doctor's name: " << name << "\n";
        cout << "Doctor's Specialization: " << specialization << "\n";

    }
};

class Department{
    public:
    string name;
    Doctor doctors[10];
    int doctor_count;
    Department(){
        name= "";
        doctor_count = 0;
    }
    Department(string name){
        this->name = name;
        doctor_count = 0;
    }
    void add_doctor(string name, string specialization){
        doctors[doctor_count++] = Doctor(name, specialization);
    }
    void remove_doctor(string name){
        for (int i = 0; i < doctor_count; i++)
        {
            if (doctors[i].name == name)
            {
                for (int j = i; j < doctor_count-1; j++)
                {
                    doctors[j] = doctors[j+1];
                }
                doctor_count--;
                return;
            }
            
        }
        cout << "Doctor not found \n";
    }
    void display(){
        cout << "Department's name: " << name;
        cout << "Doctors in department: \n";
        for(int i = 0; i < doctor_count; i++){
            cout << i << ". ";
            doctors[i].display();
        }
    }
};

class Hospital{
    public:
    string name;
    string location;
    Department departments[5];
    int department_count;
    Hospital(string name, string location){
        this->name = name;
        this->location = location;
        department_count = 0;
    }
    void add_department(string name){
        departments[department_count++] = Department(name);
    }
    int findDepartment(string deptName) {
        for (int i = 0; i < department_count; i++) {
            if (departments[i].name == deptName) return i;
        }
        return -1;
    }
};

int main(){
    Hospital h1("Hospital", " Universe");
    h1.add_department("dep");

    int index = h1.findDepartment("dep");
    if (index != -1)
    {
        h1.departments[index].add_doctor("Naman", "everything");
        h1.departments[index].display();
    }
    
    
}