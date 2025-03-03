#include<iostream>
#include<string.h>
#include<cstdlib>
#include<time.h>
using namespace std;
class game{
    int team_hits,enemy_hits;
    int number1,number2;
public:
game():team_hits(0),enemy_hits(0),number1(0),number2(0){} // used initialization list with body emtpy we can aslo initialize inside body but this is efficient
void number_generater(){
    cout<<"\nPair Of Numbers: "<<endl;
    number1=1 + rand() %4;
    number2=1 + rand() %4;
    cout<<"Number1 is : "<<number1<<endl;
    cout<<"Number2 is : "<<number2<<endl;
    if(number1==number2){
        cout<<"Enemy Got Hit By Your Team!"<<endl;
        team_hits++;
    }
    else{
        cout<<"You Got Hit By The Enemy Team!"<<endl;
        enemy_hits++;
    }
}
void score(){
    if(team_hits>enemy_hits){
        cout<<"Your Team Won!!"<<endl;
    }
    else if(team_hits==enemy_hits){
        cout<<"Its A Draw!!"<<endl;
    }
    else{
        cout<<"Enemy Team Won!!"<<endl;
    }
}

};
int main(){
    int n;
    srand(time(0));
    n=2+rand() %4;
    game *obj=new game;
    cout<<"Total Number Of Players In Your Team: "<<n<<"\n"<<endl;
    for(int i=0;i<n;i++){
        obj->number_generater();
    }
    obj->score();
    return 0;
}