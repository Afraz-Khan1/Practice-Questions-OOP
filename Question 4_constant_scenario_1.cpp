#include<iostream>
using namespace std;
class car{
private:
int const model;
float price;
public:
static int count;
car(int year=0,float price=0.0):model(year),price(price){
count++;
}
void set_price(float price){
    this->price=price;
}
void display() const{
cout<<"details: "<<" Model: "<<model<<endl<<"price: "<<price<<endl;
}
~car(){
    cout<<" obj deleted: "<<count<<endl;
    count--;
}

};
int car::count=0;
int main(){
int n;
cout<<" Enter manufacturing year of car: "<<endl;
cin>>n;
car c1(n);
c1.set_price(432.32);
c1.display();
car c2[2];
cout<<"count of obj:"<<c1.count<<endl;
cout<<"count of obj:"<<car::count<<endl;

    return 0;
}