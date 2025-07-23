#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

// This is Association: here we have coded for aggregation as we deleted person object in main and printed address obj b1 display and it showed output even the obj where it was created that class 
// person objecte is deleted

class address{
string country,province;
string city;
public:
address(string country="",string province="",string c=""):country(country),province(province),city(c){
    cout<<" constructor invoked: "<<endl;
};
void display(){
    cout<<"Country: "<<country<<endl<<"Province: "<<province<<endl<<"City: "<<city<<endl;
}
};
class person{
address *a;    
string name;
int age;
public:
person(string country="",string province="",string c="",string name="",int age=0):name(name),age(age){
   a=new address(country,province,c);
   cout<<" address object created: "<<endl;
}
void display(){
    cout<<"Name: "<<name<<endl;
    a->display();
}
~person(){
    delete a;
    cout<<"person destructor invoked, address object deleted: "<<endl;
}

};
int main(){
    //address b1("pakistan","sindh","karachi"); as here obj b1 is not pointer so we need to pass it by reference 
    //person *c1=new person(&b1,"Afraz khan",19); 
    // here it is pointer so we paassed directly
     
    person *c1=new person("Pakistan","sindh","karachi","Afraz khan",19);
    c1->display();
    delete c1;
    c1=NULL;
    if(c1!=NULL){
    c1->display();
    }
    else{
        cout<<" person object no longer exists"<<endl;
    }
    
    return 0;
}