#include<iostream>
using namespace std;
class circle{
float *radius;
public:
circle(float r=0.0){
radius=new float(r);
}
circle(const circle& c){
    radius=new float(*c.radius);
}
void setradius(float r){
*radius=r;
}

float circumference(){
    return 2*3.14*(*radius);
}
float area(){
    return 3.14 *(*radius)*(*radius);
}
~circle(){
    delete radius;
}

};
int main(){
    float r;
    cout<<" Enter radius : "<<endl;
    cin>>r;
    circle c1(r);
    circle c2(c1);
    cout<<" The Area of circle 1 is : "<<c1.area()<<endl;
    cout<<" The Circumference of circle 1 is : "<<c1.circumference()<<endl;
    cout<<" The Area of circle 2 is : "<<c2.area()<<endl;
    cout<<" The Circumference of circle 2 is : "<<c2.circumference()<<endl;

    cout<<" Enter radius : "<<endl;
    cin>>r;
    cout<<" After changing c1: "<<endl;
    c1.setradius(r);
    
    cout<<" The Area of circle 1 is : "<<c1.area()<<endl;
    cout<<" The Circumference of circle 1 is : "<<c1.circumference()<<endl;
    cout<<" The Area of circle 2 is : "<<c2.area()<<endl;
    cout<<" The Circumference of circle 2 is : "<<c2.circumference()<<endl;
    return 0;
}