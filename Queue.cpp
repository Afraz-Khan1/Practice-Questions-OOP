#include<iostream>
using namespace std;
template<typename t>
class queue{
   t *ptr;
   int maxsize,size;
   public:
   queue(int max=0,int s=0):maxsize(max),size(s){
    ptr=(maxsize!=0)?new t[maxsize]:new t[1];maxsize=1;
   }
   void resize(){
    t *newptr;
    int newmax=0;
    newmax=maxsize*2; 
    newptr=(newmax!=0)?new t[newmax]:throw bad_alloc();   //bad_alloc("maxsize can't be zero") cant throw arguments
    for(int i=0;i<size;i++){
        newptr[i]=ptr[i];
    }
    delete[] ptr;
    ptr=newptr;
    maxsize=newmax;
   }
   void enqueue(t val){
    if(size==maxsize){
        resize();
    }
    if(size>0){
     for(int i=size;i>0;i--){
        ptr[i]=ptr[i-1];
    }
    }
    ptr[0]=val;
    size++;
    
   }
   void dequeue(){
    size--;
   }
   void show_elements(){
    cout<<"queue elements(from rear): "<<endl;
    for(int i=0;i<size;i++){
        cout<<i+1<<")"<<ptr[i]<<endl;
    }
   }
   void size_show(){
    cout<<"size: "<<size<<endl;
   }
   ~queue(){
    delete[] ptr;
   }

};
int main(){
    try{
    queue<int>ob1;
    ob1.enqueue(24);
    ob1.enqueue(9);
    ob1.enqueue(1);
    ob1.enqueue(25);
    ob1.show_elements();
    ob1.size_show();
    ob1.dequeue();
    ob1.show_elements();
    }
    catch(const bad_alloc &msg){
     cout<<msg.what()<<endl;        
    }
    

    return 0;
}