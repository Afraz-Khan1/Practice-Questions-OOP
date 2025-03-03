#include<iostream>
#include<string.h>
using namespace std;
class student{
char *name;
int *roll;
int *semester;
public:
student(int r=0,int sem=0,const char *n="default"){
roll=new int(r); // value also given at the same time 1 memory address allocated
semester=new int(sem);
name=new char[strlen(n)+1];
strcpy(name,n);
}
student(const student& obj){
roll=new int;
*roll=*obj.roll;
semester=new int(*obj.semester);
name=new char[strlen(obj.name)+1];
strcpy(name,obj.name); // charcter pointer is this *name *n but string pointer is name it will point the whole string

}
int getroll(){
    return *roll;
}
string getname(){
    return name;
}
int getsem(){
    return *semester;
}
void setdetails(int r,int sem,const char *n){
      // here no validation check is need that if pointer is null dont delete as its okay to delete a null pointer in this case of program
    strcpy(name,n); // it will copy new values to the same memory allocated in default constructor or parametrized
    *roll=r;
    *semester=sem;
}
~student(){
    delete []name;
    delete roll;
    delete semester;
}

};
int main(){
    student c1;
    cout<<c1.getname()<<" "<<c1.getsem()<<" "<<c1.getroll()<<endl;
    char n[20];
    int r,sem;
    cout<<" Enter name: "<<endl;
    cin>>n;
    cout<<" Enter roll number: "<<endl;
    cin>>r;
    cout<<" Enter semester: "<<endl;
    cin>>sem;
    c1.setdetails(r,sem,n);
    cout<<c1.getname()<<" "<<c1.getsem()<<" "<<c1.getroll()<<endl;
    student c2(c1);
    cout<<c2.getname()<<" "<<c2.getsem()<<" "<<c2.getroll()<<endl;
    cout<<" After c1 changing"<<endl;
    c1.setdetails(34,3,"khan"); // so c2 didn't chnage after changing c1 so its deep copy
    cout<<c1.getname()<<" "<<c1.getsem()<<" "<<c1.getroll()<<endl;
    cout<<c2.getname()<<" "<<c2.getsem()<<" "<<c2.getroll()<<endl;

    return 0;
}