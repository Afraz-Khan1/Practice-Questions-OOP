#include<iostream>
using namespace std;
class number{
    public:
float x,y;
number(float x=0.0,float y=0.0):x(x),y(y){}
number(const number& z){
cout<<" copy constructor called"<<endl;
x=z.x;
y=z.y;
}
number operator +(const number& v){
    number temp;
    temp.x=x+v.x;
    temp.y=y+v.y;
return temp;
}
number operator -(const number& v){
number temp;
temp.x=x-v.x;
temp.y=y-v.y;
return temp;
}
number operator *(const number& v){
number temp;
temp.x=x*v.x;
temp.y=y*v.y;
return temp;
}
 void display()const{
cout<<x<<" "<<y<<endl;
 }
};
int main(){
    number v1(3,4.2),v3(5.2,1);
    number v2(v1);
    number sum=v1+v2+v3; //v1.+operator(v2)
    sum.display();
    sum=v1-v2;
    sum.display();
    sum=v1*v2;
    sum.display();
    return 0;
}