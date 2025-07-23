#include<iostream>
using namespace std;
class arraymultiplier{
public:
virtual int calculate()=0; //used to multiply the elements of the array.

};
class oneD_array:public arraymultiplier{
    int row;
    int *arr;
    public:
    oneD_array(int array[],int r=0):row(r){
    arr=array;
    }
    int calculate()override{
        int ans=1;
     for(int i=0;i<row;i++){
       ans*=arr[i];
     }
     return ans;
    }
    
};
class twoD_array:public arraymultiplier{
int row,col;
int **arr;
public:
twoD_array(int r=0,int c=0):row(r),col(c){
    arr=new int*[row]; //double pointer used pointer arr pointing another pointer which is row pointing to cols.
    for(int i=0;i<c;i++){
        arr[i]=new int[col];
    }
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
         arr[i][j]=j+1;
        }
    }
}

int calculate()override{// so you need to give the columns size inorder to pass the 2d array in a fucntion
    int ans=1; 
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        ans*=arr[i][j];
    }
}
return ans;
}
};
int main(){
    int choice,row=3,col=3;
    cout<<"1) 1D array: "<<endl;
    cout<<"2) 2D array: "<<endl;
    cin>>choice;
    if(choice==1){
        cout<<"size: "<<endl;
        cin>>row;
        int oneDarr[row];
        for(int i=0;i<row;i++){
         oneDarr[i]=i+1;
        }
        oneD_array ob1(oneDarr,row);
        cout<<ob1.calculate()<<endl;
    }
    else if(choice==2){
       
       twoD_array ob2(row,col);
       cout<<ob2.calculate()<<endl;
    }
    
    return 0;
}
