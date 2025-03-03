#include<iostream>
using namespace std;
class complex{
float real,img;
int static count;
public:
complex(float real=0.0,float img=0.0):real(real),img(img){
this->real=real;
this->img=img;
}
complex(const complex& v){
cout<<" copy constructor invoked: "<<endl;
real=v.real;
img=v.img;
}
complex add(const complex& v1){
cout<<" two operator add invoked: "<<endl;
complex temp;
temp.real=real+v1.real;
temp.img=img+v1.img;
return temp;
}
static void multi(int a){
count=count*a;
cout<<" count multi your number "<<a<<" is "<<count<<endl;
}
void add(const complex& v1,const complex& v2){
cout<<" three objects add invoked: "<<endl;
this->real=real+v1.real+v2.real;
this->img=img+v1.img+v2.img;
}

void display()const{
cout<<"("<<real<<","<<img<<"i)"<<endl;
}
};
int complex::count=2;
int main(){
    complex c1(3.4,4);
    complex c2(c1);
    complex c3;
    c3.add(c1,c2);
    c3.display();
    c3=c3.add(c1); //you are returning answer in this method if you didnt store than method answer is discarded.
    c3.display();
    int a;
    cout<<" Enter number to multiply by 2: "<<endl;
    cin>>a;
    complex::multi(a); //static method only works and modify static variable (also called class variable) but can't access instance variable(object type variable)
                       //you can access an static method without an instance variable its memory efficient(means without making object). 
    return 0;
}