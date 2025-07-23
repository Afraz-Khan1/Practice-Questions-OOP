#include<iostream>
#include<math.h>
using namespace std;
class vector{
    int **arr;
    int x,y;
    public:
    vector(int xx=0,int yy=0):x(xx),y(yy){
    arr=new int*[x];
    for(int i=0;i<x;i++){
    arr[i]=new int[y];
    }
    }
    vector operator+(const vector &other)const{
        vector result;
        result.x=x+other.x;
        result.y=y+other.y;
        return result;
    }
    vector operator*(const vector &other)const{
        vector result; // as we are not changing the values of current object here. only creating a new object and storing answer in that and returning it. 
        result.x=x*other.x;
        result.y=y*other.y;
        return result;
    }
    int magnitude(){
        int result;
        result=x*x + y*y;
        result=sqrt(result);
        return result;
    }
    int get_x(){
        return x;

    }
    int get_y(){
        return y;
    }
    
};
int main(){
    vector ob1(3,4);
    vector ob2(4,5);
    vector sum=ob1+ob2;
    vector mul=ob1*ob2;
    cout<<"sum: "<<sum.get_x()<<","<<sum.get_y()<<endl;
    cout<<"multiply: "<<mul.get_x()<<","<<mul.get_y()<<endl;
    cout<<"magnitude object1: "<<ob1.magnitude()<<endl;
    cout<<"magnitude object2: "<<ob2.magnitude()<<endl;
}