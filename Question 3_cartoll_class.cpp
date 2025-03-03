#include<iostream>
using namespace std;
class cartoll{
int totalcars;
double total_amount;
public:
cartoll(){
    totalcars=0;
    total_amount=0.0;
}
void carpay(){

total_amount+=0.50;
totalcars++;

}
int getcars()const {
    return totalcars;
}
double getamount()const {
    return total_amount;
}

};
int main(){
    cartoll c1;
    for(int i=0;i<3;i++){
    c1.carpay();
    }
    cout<<" Total Amount: "<<c1.getamount()<<"$"<<", Total Car Passed "<<c1.getcars()<<endl;

    return 0;
}