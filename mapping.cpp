#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int>data;
    data["afraz"]=19;
    data["shanzay"]=20;
    data["abdullah"]=26;
    for(auto mp:data){
        cout<<mp.first<<" is "<<mp.second<<" years old"<<endl;
    }

    return 0;
}