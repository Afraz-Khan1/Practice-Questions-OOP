#include<iostream>
using namespace std;
class item{
public:
string name;
int quantity;
item(string name="",int quantity=0):name(name),quantity(quantity){}
void display(){
    cout<<"\nProduct Name: "<<name<<endl<<" Quantity is: "<<quantity<<endl;
}
void set_name(string name){
    this->name=name;
}
void set_quantity(int quantity){
    this->quantity=quantity;
}
};

class bakedgoods:public item{
public:
bakedgoods(string name="",int quantity=0):item(name,quantity){}
float discount=10;
float total_price(int price){
return price-(price*discount/100);
}
};

class cake:public bakedgoods{
    int price=600;
    public:
    cake(string name="",int quantity=0):bakedgoods(name,quantity){}
void cake_discount_display(){
    display();
    price=price*quantity;
    float totalprice=total_price(price);
    cout<<" Price for "<<quantity<<" cake pieces is "<<price<<" and after discount of "<<discount<<"% is :"<<totalprice<<endl;
}
};

class bread:public bakedgoods{
    int price=200;
public:
bread(string name="",int quantity=0):bakedgoods(name,quantity){}
void bread_discount_display(){
    display();
    price=price*quantity;
    float totalprice=total_price(price);
    cout<<" Price for "<<quantity<<" bread pieces is "<<price<<" and after discount of "<<discount<<"% is :"<<totalprice<<endl;
}
};

class drink:public item{
int price=100;
float discount=5;
public:
drink(string name="",int quantity=0):item(name,quantity){}
void drinks_price_display(){
    display();
    price=price*quantity;
    float totalprice=price-(price*discount/100);
    cout<<" Price for "<<quantity<<" drinks is "<<price<<" and after discount of "<<discount<<"% is :"<<totalprice<<endl;
}
};

int main(){ 
    string name;
    int quantity;

    cout << "Enter bread name and quantity: ";
    cin >> name >> quantity;
    bread c1(name, quantity);
    c1.bread_discount_display();

    cout << "Enter cake name and quantity: ";
    cin >> name >> quantity;
    cake c2(name, quantity);
    c2.cake_discount_display();

    cout << "Enter drink name and quantity: ";
    cin >> name >> quantity;
    drink c3(name, quantity);
    c3.drinks_price_display();

    c2.set_name("cadbery cake");
    cout<<"\n After chaning name of cake: "<<endl;
    c2.cake_discount_display();
    c3.set_quantity(5);
    cout<<"\nAfter chaning quanitity of drinks: "<<endl;
    c3.drinks_price_display();

    return 0;
}