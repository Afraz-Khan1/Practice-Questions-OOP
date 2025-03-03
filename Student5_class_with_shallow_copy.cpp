#include<iostream>
#include<string.h>
using namespace std; // in shallow copy copies the pointer not the memory in ponits to . if other obj deltes the memory the first obj will be dangling and show undefined behaviour.thats why use deep copy in dma
class student{
char *name;
int *roll,*semester;
public:
student(int r=0,int sem=0,const char *n="default"){
roll=new int(r);// value also given at the same time 1 memory address allocated
semester=new int(sem);
name=new char[strlen(n)+1];
strcpy(name,n);
}
student(const student& obj){
roll=obj.roll;
semester=obj.semester;
name=obj.name; // you dont have to allocate new memory just copy the address of location for shallow copy as new memory allocation come for deep copy
 // charcter pointer is this *name *n but string pointer is name it will point the whole string

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
*roll=r;
*semester=sem;
strcpy(name,n);   // we dont need to use the strcpy as string can be explicitly copied to other string variable by this =  if we are using using namespace std
// and this strcpy is used when we want to copy  char* variable holding whole string or a character if a chracter we can use both variable name and *name as one character is carried 
// for whole string carried by a char *name variable we will use only name in strcpy as it will point to hold string carried by a char array to see what i am saying check student class4 other one. 
}
~student(){
    delete []name;
    delete semester;
    delete roll;
}

};
int main(){
    student c1;
    cout<<c1.getname()<<" "<<c1.getsem()<<" "<<c1.getroll()<<endl;
    char *n=new char[20];
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
    c1.setdetails(34,3,"khan");
    cout<<c1.getname()<<" "<<c1.getsem()<<" "<<c1.getroll()<<endl;
    cout<<c2.getname()<<" "<<c2.getsem()<<" "<<c2.getroll()<<endl;

    cout<<" After c2 changing"<<endl;
    c1.setdetails(1,1,"pathan");
    cout<<c1.getname()<<" "<<c1.getsem()<<" "<<c1.getroll()<<endl;
    cout<<c2.getname()<<" "<<c2.getsem()<<" "<<c2.getroll()<<endl;
    delete []n;
    return 0;
}