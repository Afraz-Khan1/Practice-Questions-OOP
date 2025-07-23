#include<iostream>
using namespace std;
class accountant{
private:
int const account_number,security_code;
float account_balance;
static int count;
public:
accountant(int number=0,int code=0,float balance=0.0):account_number(number),security_code(code),account_balance(balance){
    count++;
}
void set_balance(float balance){
account_balance=balance;
}
void display(){
    cout<<" Details: "<<endl<<"Account number: "<<account_number<<endl<<"Security code: "<<security_code<<endl<<"Account balance: "<<account_balance<<endl;
}
static int getcount(){ // static method are helpfull when there is no obj to access a data. they allow accessing the staic value without an obj, they only work for static variable. but non static
    // work for both non and static member and can also return a static member but they need an obj for it.
    return count;
}
~accountant(){
    count--;
}
};
int accountant::count=0;
int main(){
    int number,code;
    cout<<" Enter Account Number: "<<endl;
    cin>>number;
    cout<<" Enter Account Security Code: "<<endl;
    cin>>code;
    accountant c1(number,code);    
    c1.display();
    c1.set_balance(2232.23);
    cout<<" After entering balance in c1: "<<endl;
    c1.display();
    accountant c2;
    cout<<" No values given: "<<endl;
    cout<<" after giving only balance as other are static: "<<endl;
    c2.set_balance(54353.43);
    c2.display();
    cout<<" Total Number of objects: "<<accountant::getcount()<<endl;
    return 0;
}