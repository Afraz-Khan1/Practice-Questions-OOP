#include<iostream>
using namespace std;
class dynammicarray{
int maxsize,size;
int *ptr;
public:
dynammicarray(int s=1){
maxsize=s;
size=0;
ptr=maxsize>0?new int[maxsize]:NULL;
}
void push_back(int data){
if(size==maxsize){
resize();
}
ptr[size]=data;
size++;
}
private:
void resize(){
    int *newptr=maxsize>0?new int[maxsize*2]:NULL;
    for(int i=0;i<size;i++){
        newptr[i]=ptr[i];
    }
    delete []ptr;
    maxsize=maxsize*2;
    ptr=newptr;
}
public:
void pop_back(){
if(size>0){
    size--;
}
}
int return_back(){
if(size>0){
    return ptr[size-1];
}
else{
    cout<<" empty"<<endl;
    return -1;
}
}
int return_size(){
    return size;
}
};
int main(){
    dynammicarray c1;
    c1.push_back(5);
    cout<<c1.return_back()<<endl;
    c1.pop_back();
    cout<<c1.return_size()<<endl;

    return 0;
}