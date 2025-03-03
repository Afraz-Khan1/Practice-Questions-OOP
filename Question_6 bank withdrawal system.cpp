#include <iostream>
using namespace std;

void saving(){
int account_number,totalbank_amount=200000;
float amount,set_tax;

    cout<<"Enter Account Number: "<<endl;
    cin>>account_number;
    cout<<"Enter Amount For Withdrawing: "<<endl;
    cin>>amount;
    if(amount>0 && amount<=50000){
    set_tax=amount*0.02;
    amount=amount-set_tax;
    totalbank_amount=totalbank_amount-amount;
    cout<<"The Withdrawn Amount After 2% Tax: "<<amount<<endl;
    cout<<"Remaining Amount In Account after withdrawal: "<<totalbank_amount<<" \nThank you."<<endl;
    }
    else if(amount>50000&&amount<=100000){
    set_tax=amount*0.05;
    amount=amount-set_tax;
    totalbank_amount-=amount;
    cout<<"The Withdrawn Amount After 5% Tax: "<<amount<<endl;
    cout<<"Remaining Amount In Account After witdrawal: "<<totalbank_amount<<" \nThank you."<<endl;
    }
    else{
        cout<<"Not in the withdrawal limit: :("<<endl;
    }
}

void current(){
int account_number,totalbank_amount=200000;
float amount,set_tax;

    cout<<"Enter Account Number: "<<endl;
    cin>>account_number;
    cout<<"Enter Amount For Withdrawing: "<<endl;
    cin>>amount;
    if(amount>0 && amount<=50000){
    set_tax=100;
    amount=amount-set_tax;
    totalbank_amount-=amount;
    cout<<"The Withdrawn Amount After 100rs Tax: "<<amount<<endl; 
    cout<<"Remaining Amount In Account After witdrawal: "<<totalbank_amount<<" \nThank you."<<endl;
    }
    else if(amount>50000&&amount<=100000){
    set_tax=amount*0.05;
    amount=amount-set_tax;
    totalbank_amount-=amount;
    cout<<"The Withdrawn Amount After 5% Tax: "<<amount<<endl;
    cout<<"Remaining Amount In Account After witdrawal: "<<totalbank_amount<<" \nThank you."<<endl;
    }
    else{
        cout<<"Not in the withdrawal limit: :("<<endl;
    }

}

int main(){
    char account_type;
    
    cout<<"Accounts:"<<" \n"<<"{S} for Saving Account:"<<" \n"<<"{C} for Current Account:"<<"\nEnter Account: "<<endl;
    cin>>account_type;
    if(account_type=='S'){
    saving();
    }
    else if(account_type=='C'){
    current();
    }
    else{
        cout<<"Select correct account type: "<<endl;
    }
    
    return 0;
}