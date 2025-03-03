#include<iostream>
using namespace std;
class shape{
int num_slides;
public:
float area;
shape(int num_slides=0,float area=0.0):num_slides(num_slides),area(area){}

void set_slides(int num_slides){
this->num_slides=num_slides;
}
void set_area(float area){
this->area=area;
}
int get_slides(){
    return num_slides;
}
float get_area(){
    return area;
}
};
class rectangle:protected shape{
 public:
 int length,width;
 rectangle(int length=0,int width=0,int num_slides=0,float area=0.0):shape(num_slides,area){
 this->length=length;
 this->width=width;
 }
 float generate_area(){
    area=length*width;
    return area;
 }
};
class square:protected rectangle{
int oneside;
public:
square(int oneside=0,int num_slides=0,float area=0.0):rectangle(oneside,oneside,num_slides,area),oneside(oneside){}
bool checkside(){
if(width==length){
    return true;
}
else{
    return false;
}
}
float generate_area(){
    return rectangle::generate_area();
};
};
class triangle:protected shape{
int height,base;
public:
triangle(int height=0,int base=0,int number_slides=0,float area=0.0):shape(number_slides,area),height(height),base(base){}
float generate_area(){
    area=(base*height)/2;
    return area;
 }
};
class circle:protected shape{
int radius;
public:
circle(int radius=0,int number_slides=0,float area=0.0):shape(number_slides,area),radius(radius){}
float generate_area(){ // method overridding
    area=3.14*radius*radius;
    return area;
 }
};
int main(){
    square s1(3,4);
    if(s1.checkside()==true){
        cout<<"Area of square is: "<<s1.generate_area()<<endl;  
    }
    else{
        cout<<" Area of Square, The sides are not equal: "<<endl;
    }
    triangle t1(2,3,3);
    cout<<" Area of triangle: "<<t1.generate_area()<<endl;
    rectangle r1(3,5,4);
    cout<<" Area of rectangle is: "<<r1.generate_area()<<endl;
    circle c1(2);
    cout<<" Area of circle is: "<<c1.generate_area()<<endl;
    return 0;
}