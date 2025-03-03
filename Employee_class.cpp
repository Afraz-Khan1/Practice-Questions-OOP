#include<iostream>
#include<string.h>
using namespace std;
class employee{
char *first_name;
string last_name;
float salary;
public:
void set_details(char *first_n,string last_n,float salary){
first_name=new char[strlen(first_n)+1];
strcpy(first_name,first_n);
last_name=last_n;
this->salary=salary;
}
float get_salary_yearly(){
    return salary*12;
}
string get_lastname(){
    return last_name;
}
char get_firstname(){
    return *first_name;
}
float get_salary_raised(){
    return salary+(salary*10.0/100);
}
~employee(){
    delete []first_name;
}
};
int main(){
    employee *obj=new employee[2];
    char *first_name=new char[12];
    string last_n;
    float salary;
    for(int i=0;i<2;i++){
    cout<<"Enter first name: "<<endl;
    cin>>first_name;
    cout<<"Enter last name: "<<endl;
    cin>>last_n;
    cout<<"Enter salary: "<<endl;
    cin>>salary;
    if(salary<0){
        salary=0;
    }
    obj[i].set_details(first_name,last_n,salary);
    cout<<"yearly salary: "<<obj[i].get_salary_yearly()<<endl;
    cout<<"Salary after 10% raise: "<<obj[i].get_salary_raised()<<endl;
    obj[i].get_salary_raised();
    }
    
    delete []obj;
    return 0;
}