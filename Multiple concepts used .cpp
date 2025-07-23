#include<iostream>
using namespace std;
class vector{
    static int count;
    int x,y;
    public:
    vector(int a=0,int b=0):x(a),y(b){
        count++;
        cout<<"total objects now: "<<count<<endl;
    }
    vector operator +(const vector& other)const{
      vector temp; // temporary object deleted after assignment of answer to sum in main
      temp.x=x+other.x;
      temp.y=y+other.y;
      return temp;
    }
    int update(int a)const{ // it can not change the object data member non static as it allows only read access for object non static members.
        a=a+1;
        cout<<"number is now: "<<a<<endl;
        count++; // we can update static data member as it is not member of the object it is for all classes . and also we can update any local variable
        // inside a const method like a
        cout<<"count: "<<count<<endl;
        return count;
    }
    static int new_update(){ // it can also return local variable(created and used inside the static method) or parameter passed for temporary use.
        // but cannot use object non static data member or return it. 
        count--;
        cout<<"new count: "<<count<<endl;
        
    }
    vector operator *(const vector& other)const{
      vector temp;
      temp.x=x*other.x;
      temp.y=y*other.y;
      return temp;
    }
    vector& operator =(const vector& other){ // to avoid extra copy thats why added an &
      x=other.x;
      y=other.y;
      return *this;
    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
    ~vector(){
        count--;
        cout<<"object gone: total objects now: "<<count<<endl;
    }
};
int vector::count=0;

int main(){
    vector obj(1,2);
    vector obj2(3,4);
    vector sum;
    vector mul;
    sum=obj+obj2;
    cout<<"sum: "<<sum.get_x()<<","<<sum.get_y()<<endl;
    mul=obj*obj2;
    cout<<"multiply: "<<mul.get_x()<<","<<mul.get_y()<<endl;
    sum=mul;
    cout<<"sum is now mul: "<<sum.get_x()<<","<<sum.get_y()<<endl;
    cout<<obj.update(4)<<endl;
    obj.new_update();

}