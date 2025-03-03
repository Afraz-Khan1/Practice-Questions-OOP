#include <iostream>
using namespace std;
void surface_area(int radius){
float area;
area=4*3.14*radius*radius;
cout<<" The Surface area of sphere is: "<<area<<endl;
}
void volume(int radius){
float volume;
volume=(3.14*radius*radius*radius)*4.0/3;
cout<<" The Volume of sphere is: "<<volume;
}
int main(){
    int radius;
    cout<<" Enter Radius: "<<endl;
    cin>>radius;
    surface_area(radius);//surface area of sphere
    volume(radius);// volume of sphere

    return 0;
}