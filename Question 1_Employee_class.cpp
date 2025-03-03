#include<iostream>
#include<string.h>
using namespace std;
class employee{
char *ename;
int const eid;
public:
employee(const char *name="default",int id=0):eid(id){
    ename=new char[strlen(name)+1];
    strcpy(ename,name);
}
void set_name(const char *name){
    ename=new char[strlen(name)+1];
    strcpy(ename,name);
}
void display()const{
    cout<<" Details of employee: "<<endl<<"Name: "<<ename<<endl<<"Employee Id: "<<eid<<endl;
}
~employee(){
    delete []ename;
}
};
int main(){
char name[20];
int id;
cout<<" enter employee name: "<<endl;
cin>>name;
cout<<" enter employee id"<<endl;
cin>>id;
employee e1(name,id);
e1.display();
employee e2("afraz",45);
e2.display();
employee e3("daniyal",90);
e3.display();
e1.set_name("saimsaqib");
e1.display();

    return 0;
}