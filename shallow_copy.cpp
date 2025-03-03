#include<iostream>
using namespace std;
class ja{
int *a,*b;
public:
ja(int x=0,int y=0){
    a=new int(x);
    b=new int(y);
}

/*ja(const ja& wall){ // this is deep copy constructor value is copied thats why independent copy is done for each obj and changing one value of obj1 doesn't affect other obj value like ob2
*a=*wall.a;  
*b=*wall.b;
}*/

ja(const ja& wall){
a=wall.a;  // actually in shallow copy the pointer(address where it points too) is copied not the value so when ever one obj values changes other auto changes with it. if value copied it will be deep copied
b=wall.b;  // also destroying other will lead to dangling pointer and double memory free thats why its good to use deep copy in dma usage if not used deep copy in dma than auto shallow copy wil be done by compiler
}
void setdetails(int x,int y){
*a=x;
*b=y;
}
int geta(){
    return *a;
}
int getb(){
    return *b;
}
~ja(){
    delete a;
    delete b;
}

};
int main(){
    int x,y;
    cout<<" Enter number 1: "<<endl;
    cin>>x;
    cout<<" Enter number 2: "<<endl;
    cin>>y;
    ja c1(x,y);
    ja c2(c1);
    cout<<" c1 values"<<" "<<c1.geta()<<" "<<c1.getb()<<endl;
    cout<<" c2 values"<<" "<<c2.geta()<<" "<<c2.getb()<<endl;
    cout<<" After changing c1: "<<endl;
    c1.setdetails(77,88);
    cout<<" c1 values"<<" "<<c1.geta()<<" "<<c1.getb()<<endl;
    cout<<" c2 values"<<" "<<c2.geta()<<" "<<c2.getb()<<endl;

}