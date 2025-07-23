#include <iostream>
using namespace std;

class Payroll; // Forward declaration why needed? if there is circular case if employee needed to use payroll inside it then this declaration is required.
// but if only payroll needes to use employee member than no need of forward declaration as employee didn't use payroll inside of it . it will work without this.

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

    friend class Payroll; // Declare Payroll as friend
};

class Payroll {
public:
    void updateSalary(Employee &e, float newSalary) {
        e.salary = newSalary;
    }
};

int main() {
    Employee emp("Ali", 101, "Manager", 50000);
    Payroll p;

    emp.display();
    p.updateSalary(emp, 60000);
    emp.display();

    return 0;
}