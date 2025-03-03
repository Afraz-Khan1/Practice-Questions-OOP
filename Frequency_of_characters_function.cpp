#include<iostream>
#include<string.h>
using namespace std;
int *frequency(string& str){
    int *count=new int[str.length()]();
    for(int i=0;str[i]!='\0';i++){
        for(int j=0;str[j]!='\0';j++){
        if((str[i]==str[j])&&(str[j]!=' ')){
        count[i]+=1;
        }
        }
    }
    return count;
}
int main(){
    string str;
    cout<<"Enter Sentence: "<<endl;
    getline(cin,str);
    int *freq=frequency(str);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
        cout<<str[i]<<":"<<freq[i]<<endl;
        for(int j=1+i;str[j]!='\0';j++){
        if(str[i]==str[j]){
           str[j]=' ';
          }
         }
       }
    }
    return 0;
}