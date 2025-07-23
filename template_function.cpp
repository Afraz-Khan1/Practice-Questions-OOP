#include<iostream>
using namespace std;
template<typename t1,typename t2,typename t3>
t3 operation(t1 a,t2 b,char op){
 
    switch(op){
    case '+': 
    return a+b;
    break;
    case '-':
    return a-b;
    break;
    case '*':
    return a*b;
    break;
    case '/':
    return a/b;
    break;
    default:
    cout<<" select correction : "<<endl;
    return 0;
    }
}
template<>
char operation(char t1,char t2,char op){
cout<<" Can't add two characters in c++: "<<endl;
return 0;
}
int main(){
    char choice;
    cout<<"1) +"<<endl<<"2) -"<<endl<<"3) *"<<endl<<"4) /"<<endl;
    cin>>choice;
    cout<<operation<double,int,double>(4,3,choice)<<endl; // <int,double,double> t1,t2,t3

    return 0;
}