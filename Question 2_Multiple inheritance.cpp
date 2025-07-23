#include<iostream>
using namespace std;
class character{
    string name;
    int level,health;
    public:
    character(string n="",int l=0,int h=0):name(n),level(l),health(h){
        cout<<"Character constructor invoked: "<<endl;
    }
    virtual void display(){
     cout<<"Name: "<<name<<endl<<"Health: "<<health<<endl<<"Level: "<<level<<endl;
    }

};
class warrior:virtual public character{
 int strength;
 string ability,proficiency;
    public:
    warrior(string n="",int l=0,int h=0):character(n,l,h){
    strength=200;
    proficiency= "meele weapons";
    ability="slash";
    cout<<"warrior constructor invoked: "<<endl;
    }
    void display()override{
    cout<<"Strength: "<<strength<<endl<<"Proficiency: "<<proficiency<<endl<<"Ability: "<<ability<<endl;
    }
};
class mage: virtual public character{
    string intelligence,proficiency,ability;
    public:
    mage(string n="",int l=0,int h=0):character(n,l,h){
       intelligence="high";
       proficiency="spell casting";
       ability="Fire ball";
       cout<<"Mage Constructr invoked: "<<endl;
    }
    void display()override{
    cout<<"Intelligence: "<<intelligence<<endl<<"Proficiency: "<<proficiency<<endl<<"Ability: "<<ability<<endl;
    }
};
class archer:public character{
    string dexterity,proficiency,ability;
    public:
    archer(string n="",int l=0,int h=0):character(n,l,h){
    dexterity="archery";
    proficiency="ranged weapons";
    ability="rapid shot";
    cout<<" Archer constructor invoked: "<<endl;
    }
};
class npc:public character{
    string dialogues[3]={"i am going to kill you","i am pro","yo are noob"};
    public:
    npc(string n="",int l=0,int h=0):character(n,l,h){
    cout<<"NPC constructor invoked: "<<endl;
    }
};
class mighty:public warrior,mage{

    public:
    mighty(string n="",int l=0,int h=0):character(n,l,h),warrior(),mage(){
     cout<<"Mighty constructor invoked: "<<endl;
    }
    void display()override{
    character::display();
    warrior::display();
    mage::display();
    }
};
int main(){
mighty obj("Mighty",4,100);
obj.display(); 

    return 0;
}