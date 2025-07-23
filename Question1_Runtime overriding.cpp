#include<iostream>
using namespace std;
class person{
    protected:
    string name,occupation;
    public:
    person(string _occupation="person"):occupation(_occupation){
        
     cout<<"Person constructor invoked: "<<endl;
    }
    virtual void draw(){
        cout<<" Person can draw in many ways: "<<endl;
    }
    void show(){
        cout<<"showing: "<<endl;
    }

};
class artist:public person{
    public:
    artist(string _occupation="Artist"):person(_occupation){
        
        cout<<"Artist constructor invoked: "<<endl;
    }
    void draw()override{ //even if we dont put override it is understood draw will override
     cout<<" Artist can draw with a paint brush: "<<endl;
    }
};
class gunman:public person{
public:
gunman(string _occupation="Gunman"):person(_occupation){
cout<<"Gun man constructor invoked: "<<endl;
}
void draw()override{
    cout<<" Gunman can draw a gun to shoot: "<<endl;
} 

};
int main(){
    person *p[3]; // array of 3 pointers of type person 
    // storing addresses of different objects in pointers which are all of type person.
    p[0]=new person();
    p[1]=new artist();
    p[2]=new gunman();

    p[0]->draw();
    p[1]->draw();
    p[2]->draw();
    p[2]->show(); //through other derived class obj you can access the methods of base class

    // so when you dont put the virtual in base method and than add override keyword in derived class display it will show
    // compile time error. so when you do this shit like person *p=new derivedclass; and p->display so it will invoke the display of base class
    // rather than derived as you didn't add virtual in base method that you want to override nor you can add  the keyowrd
    // of override with derived display method as you didn't put virtual in base method. so it will always invoke base
    // display even you allocate memory of derived in base class pointer. add virtual compulsory. to runtime override


    return 0;
}