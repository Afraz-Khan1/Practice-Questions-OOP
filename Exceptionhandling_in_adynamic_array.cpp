#include<iostream>
using namespace std;
class dynamic_array{
int *ptr;
int maxsize,size;
public:
dynamic_array(int max=0,int s=0):maxsize(max),size(s){ // constructor
    try{
    if(maxsize<=0){
    throw "Terminate called as maxsize is zero."; // if not uding try just throwing you have to make try and catch in main but dont need to make throw again in try.
    }
    ptr=new int[maxsize];
          
    }
    catch(const logic_error& e){
     cout<<e.what()<<endl;
     exit(1);
    }
}

void display(){
    cout<<" Vector elements: "<<endl;
    for(int i=0;i<size;i++){
        cout<<i+1<<") "<<ptr[i]<<endl;
    }
}

int& operator [](int index){
    if(index<0||index>size){
      throw out_of_range("index out of range");
    }
return ptr[index];
}

void resize(){
int *newptr;
int new_maxsize;
if(maxsize!=0){
   // maxsize=maxsize*2; do this program will terminate by what() bad_allocation comes under exception handling. as maxsize is used in new int[maxsize] changing its value before new memory allcoation
    // terminates the program. use newmaxsize than copy it to old one.
    new_maxsize=maxsize*2;
    newptr=new int[new_maxsize];
}
for(int i=0;i<size;i++){ 
    newptr[i]=ptr[i];
}
delete[] ptr; // this frees the prevous allocated memory of ptr and new ptr as ptr have the address of previous memory of newptr. new ptr is allocated new memory in second resize.so ptr delete its previous memory in second resize
ptr=newptr;
maxsize=new_maxsize;

}

void push_back(int num){
  if(size==maxsize){
      resize();      
  }
  ptr[size]=num;
  size++;

}

void pop_back(){
if(size>0){
size--;
}
}

int show_size(){
    return size;
}

int show_maxsize(){
return maxsize;
}
~ dynamic_array(){

    delete[] ptr;
    
}

};
int main(){
    //terminate called here
    //dynamic_array ob1;
    
    dynamic_array ob2(3);

    for(int i=0;i<3;i++){
        ob2.push_back(i+2);
    }
    ob2.display();
    
    cout<<"Size: "<<ob2.show_size()<<endl;

    //resize invoke here
    for(int i=0;i<6;i++){
        ob2.push_back(i+3);
    }
    ob2.display();
    ob2.pop_back();
    ob2.display();
    
    try{
        (ob2[15]==ob2[1])? cout<<ob2[0]<<" Equal to "<<ob2[1]<<endl:cout<<ob2[0]<<" Not Equal to "<<ob2[1]<<endl;
    }
    catch(const out_of_range& e){
    cout<<"Error, "<<e.what()<<endl;
    }
     
     
     

    return 0;
}