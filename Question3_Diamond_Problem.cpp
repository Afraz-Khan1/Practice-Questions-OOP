#include<iostream>
using namespace std;
class account{
    protected:
    int balance;
    public:
    account(int b=0):balance(b){
    cout<<"account constructor invoked: "<<endl;
    }
    void withdraw(double amount){
    balance=balance-amount;
    }
    void deposit(double amount){
    balance=balance+amount;
    }
    double check_balance(){
    return balance;
    }

};
class interest_account:virtual public account{
    protected:
    double interestrate;
    public:
    interest_account(int b=0,double rate=0.3):account(b),interestrate(rate){
    cout<<"interest constructor invoked: "<<endl;
    }
    void deposit(double amount){
    double interest;
    interest=amount*interestrate;
    balance=balance+amount+interest; //added the interest into the balance as we helping the bank by storing our money in there bank.
    }
};
class charging_account:virtual public account{
    protected:
    double fee;
    public:
    charging_account(int b=0,double f=100.0):account(b),fee(f){
    cout<<"charging account constructor invoked: "<<endl;
    }
    protected:
    void withdraw(double amount){
    balance=balance-amount-fee;
    }
};
class aci:public interest_account,charging_account{
    public:
    aci():interest_account(),charging_account(){
        cout<<"aci constructor invoked: "<<endl;
    }
    void transfer(double amount,interest_account& other){
    other.deposit(amount);
    }
    void transfer(double amount,charging_account& other){
    other.deposit(amount);
    }
    void transfer(double amount,account& other){
    other.deposit(amount);
    }
};
int main(){
    aci a;
    interest_account i(6000);
    a.transfer(1000,i);
    cout<<"balance: "<<i.check_balance()<<endl;
    charging_account c(3000);
    a.transfer(500.2,c);
    cout<<"balance: "<<c.check_balance()<<endl;
    return 0;
}