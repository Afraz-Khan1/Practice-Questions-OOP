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
address(string country="",string province="",string c=""):country(country),province(province),city(c){};
void display(){
    cout<<"Country: "<<country<<endl<<"Province: "<<province<<endl<<"City: "<<city<<endl;
}
};
class person{
address *a;
string name;
int age;
public:
person(address *b1,string name="",int age=0):name(name),age(age){
    a=new address(*b1);
}
~person(){
    delete a;
}

};
int main(){
    //address b1("pakistan","sindh","karachi"); as here obj b1 is not pointer so we need to pass it by reference 
    //person *c1=new person(&b1,"Afraz khan",19); 
    //address b1("pakistan","sindh","karachi");
    //{
    //person c1(&b1,"Afraz khan",19);
    //} // {} this is used for local scop for the person object when we using aggregation but not using dma also as it reach } it will automatically deletes

    address *b1=new address("pakistan","sindh","karachi"); // here it is pointer so we paassed directly
    person *c1=new person(b1,"Afraz khan",19);
    b1->display();
    delete c1;
    b1->display();
    delete b1;
    b1=NULL;  // delete only frees memory but dont set dangling pointer to null by default
    if(b1!=NULL){
    b1->display();    
    }
    else{
        return 1;
    }

    return 0;
}