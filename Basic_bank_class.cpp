#include<iostream>
#include<string.h>
using namespace std;
class bank{
int trans_count;
float deposit,withdrawl,balance,interest;
public:
bank(float balance=0.0,float withdrawl=0.0,float deposit=0.0,int trans_count=0){
this->balance=balance;
this->withdrawl=withdrawl;
this->deposit=deposit;
this->trans_count=trans_count;
}
void display_account_balance(){
    cout<<" \nBank Balance: "<<balance<<endl;
}
void display_transactions(){
    cout<<" \nTotal Transtion: "<<trans_count<<endl;
}
void display_interest(){
    float time_period=1.0/12;// after 1 month the interest you will get on your balance
    float interest_rate=0.05;
    interest=balance*interest_rate*time_period;
    balance+=interest;
    cout<<" \nInterest Earned On One Month Time Period: "<<interest<<endl;
}
void make_deposit(){
    balance+=deposit;
}
void make_withdrawl(){
    if(balance!=0){
    balance-=withdrawl;
    trans_count++;
    }
    else{
        cout<<" \nSorry No Balance Left: "<<endl;
    }
}
void set_withdrawl(float withdrawl){
    this->withdrawl=withdrawl;
}
void set_deposit(float deposit){
    this->deposit=deposit;
}

};
int main(){
    bank *obj=new bank;
    float balance;
    int choice;
    float withdrawl,deposit;

    cout<<" Enter Account balance:"<<endl;
    cin>> balance;
    *obj=bank(balance);

    for(int i=1; ;i++){
    cout<<"\n1 Display the account balance: "<<endl;
    cout<<"2 Display the number of transactions: "<<endl;
    cout<<"3 Display interest earned for this period: "<<endl;
    cout<<"4 Make a deposit: "<<endl;
    cout<<"5 Make a withdrawl: "<<endl;
    cout<<"6 Exist the program: "<<endl;
    cout<<"Enter Number: ";
    cin>>choice;
    
    switch(choice){
        case 1:
        obj->display_account_balance();
        break;
        case 2:
        obj->display_transactions();
        break;
        case 3:
        obj->display_interest();
        break;
        case 4:
        cout<<" \nEnter Amount For Deposit:"<<" "<<endl;
        cin>>deposit;
        obj->set_deposit(deposit);
        obj->make_deposit();
        break;
        case 5:
        cout<<" \nEnter Amount For Withdrawl:"<<" "<<endl;
        cin>>withdrawl;
        obj->set_withdrawl(withdrawl);
        obj->make_withdrawl();
        break;
        case 6:
        return 0;
        break;
        default:
        cout<<" \nChoose correct option: "<<endl;
        break;
    }
    
    }
    return 0;
}