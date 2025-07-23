#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    string designation;
    float salary;

public:
    Employee(string n, int i, string d, float s) {
        name = n;
        id = i;
        designation = d;
        salary = s;
    }

    void display() {
        cout << "Name: " << name << ", ID: " << id
             << ", Designation: " << designation
             << ", Salary: " << salary << endl;
    }

    friend void updateSalary(Employee &e, float newSalary); // Friend function
};

void updateSalary(Employee &e, float newSalary) {
    e.salary = newSalary;
}

int main() {
    Employee emp("Ali", 101, "Manager", 50000);

    emp.display();
    updateSalary(emp, 60000);
    emp.display();

    return 0;
}