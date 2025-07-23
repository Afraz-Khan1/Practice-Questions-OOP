#include<iostream>
using namespace std;
template<class t>
class stack{
    t *ptr;
    int maxsize,size;
    public:
    stack(int max=0,int s=0):maxsize(max),size(s){
     
        if(maxsize!=0){
         ptr=new t[maxsize];
        }
        else{
          ptr=nullptr;
          throw "maxsize is zero";
        }
    }
    void display(){
        cout<<"elements inside the stack: "<<endl;
        for(int i=0;i<size;i++){
            cout<<ptr[i]<<endl;
        }
    }
    void resize(){
     t *newptr;
     int newmaxsize=maxsize*2;
     newptr=(maxsize>0)?new t[newmaxsize]:new t();
     for(int i=0;i<size;i++){
        newptr[i]=ptr[i];
     }
     delete[] ptr;
     ptr=newptr; 
     maxsize=newmaxsize; 

    }
    void push(t val){
        if(size==maxsize){
            resize();
        }
        ptr[size]=val;
        size++;
        
    }
    void pop(){
        
     if(size>0){
        
        cout<<"After removing the top element of the stack which is : "<<ptr[size-1]<<endl;
        size--;
        for(int i=0;i<size;i++){
         cout<<ptr[i]<<endl;
        }
     }
    }
    bool isfull(){
        if(size==maxsize){
         return true;
        }
        return false;
    }
    bool isempty(){
        if(size==0){
            return true;
        }
        return false;
    }
    int show_size(){
     return size;
    }
~stack(){
    delete[] ptr;
}
};

int main(){
    string name;
    try{
     stack<string> ob1(4); // initialize here
for(int i=0;i<4;i++){
cout<<"Enter Name to push in stack: "<<endl;
getline(cin,name);

ob1.push(name);
}
cout<<"size = "<<ob1.show_size()<<endl;
cout<<"Stack is full or not? "<<ob1.isfull()<<endl;
ob1.display();
cout<<"after adding one element: "<<endl;
ob1.push("shanzey");
ob1.display();
ob1.pop();
cout<<"stack is empty or not? "<<ob1.isempty()<<endl;
cout<<"Stack is full or not? "<<ob1.isfull()<<endl;
    }
    catch(const char* msg){
     cout<<msg<<endl;
    }

    return 0;
}