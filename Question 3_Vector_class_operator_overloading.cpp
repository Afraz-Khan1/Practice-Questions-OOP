#include<iostream>
using namespace std;
class vector{
    public:
float x,y;
vector(float x=0.0,float y=0.0):x(x),y(y){}
vector(const vector& z){
cout<<" copy constructor called"<<endl;
x=z.x;
y=z.y;
}
vector operator +(const vector& v){
    vector temp;
    temp.x=x+v.x;
    temp.y=y+v.y;
return temp;
}
vector operator -(const vector& v){
vector temp;
temp.x=x-v.x;
temp.y=y-v.y;
return temp;
}
vector operator *(const vector& v){
vector temp;
temp.x=x*v.x;
temp.y=y*v.y;
return temp;
}
 void display()const{
cout<<x<<" "<<y<<endl;
 }
};
int main(){
    vector v1(3,4.2),v3(5.2,1);
    vector v2(v1);
    vector sum=v1+v2+v3; //v1.+operator(v2)
    sum.display();
    sum=v1-v2;
    sum.display();
    sum=v1*v2;
    sum.display();
    return 0;
}