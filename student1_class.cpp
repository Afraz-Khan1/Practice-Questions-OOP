#include<iostream>
#include<string.h>
using namespace std;
class student{
 private:
 int roll,sem;
 char *name;
 char sec;
 public:
 void setdetails(int roll,int sem,char sec,const char *n){
 this->roll=roll;
 this->sem=sem;
 this->sec=sec;
 name=new char[strlen(n)+1];
 strcpy(name,n);
 }
 string getname(){
    return name;
 }
 int getroll(){
    return roll;
 }
 int getsem(){
    return sem;
 }
 char getsec(){
    return sec;
 }
};
int main(){
    student *obj=new student[4];
    char n[10];
    char sec;
    int roll,sem;
    for(int i=0;i<4;i++){
    cout<<"Enter Name: "<<endl;
    cin>>n;
    cout<<"Enter rollnumber: "<<endl;
    cin>>roll;
    cout<<"Enter section: "<<endl;
    cin>>sec;
    cout<<"Enter semester: "<<endl;
    cin>>sem;
    obj[i].setdetails(roll,sem,sec,n);
    }
    for(int i=0;i<4;i++){
    if(obj[i].getsec()=='a'){
    cout<<"Student Name: "<<obj[i].getname()<<endl;
    cout<<"Student Roll: "<<obj[i].getroll()<<endl;
    cout<<"Student Section: "<<obj[i].getsec()<<endl;
    cout<<"Student Semester: "<<obj[i].getsem()<<endl;
    }
    }
    delete []obj;
    return 0;
}