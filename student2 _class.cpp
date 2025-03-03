#include<iostream>
#include<string.h>
using namespace std;
class student{
    char *name;
    char sec;
    int roll,sem;
    public:
 student(int roll=0,int sem=0,int sec=0,const char *n="default"){ // this *n is pointing an array it can also be written as char n[] actually an array is being passed form main thats why it is wrote like this
    this->roll=roll;
    this->sem=sem;
    this->sec=sec;
    name=new char[strlen(n)+1];
    strcpy(name,n);
 }
 int getsec(){
    return sec;
 }
 void student_details(){
    cout<<"\n";
    cout<<"Student Name: "<<name<<endl;
    cout<<"Student Roll: "<<roll<<endl;
    cout<<"Student Section: "<<sec<<endl;
    cout<<"Student Semester: "<<sem<<endl;
 }

};
int main(){
    student *obj=new student[4]; // dynamic memory allocated objects
    char n[10];
    int roll,sem;
    char sec;
    for(int i=0;i<4;i++){
    cout<<"Enter Name: "<<endl;
    cin>>n;
    cout<<"Enter Roll: "<<endl;
    cin>>roll;
    cout<<"Enter Section: "<<endl;
    cin>>sec;
    cout<<"Enter Semester: "<<endl;
    cin>>sem;
    obj[i]=student(roll,sem,sec,n);
    }
    for(int i=0;i<4;i++){
        if(obj[i].getsec()=='a'){ // access each obj members or method by obj[i].--;  and obj-> is used when one obj dynamically created .now you use -> to access its members and methods
        obj[i].student_details();
        }
    }
    delete []obj;
    return 0;
}