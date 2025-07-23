#include<iostream>
using namespace std;
class dynamicarray_2D{
    int **arr;
    int row,col;
    public:
    dynamicarray_2D():arr(nullptr),row(0),col(0){} //default constructor

    dynamicarray_2D(int r,int c):row(r),col(c){ //parametrized constructor
        arr=new int*[r];
        for(int i=0;i<row;i++){
            arr[i]=new int[c];
        }
        cout<<" Constructor invoked:"<<endl;
    }

    dynamicarray_2D(const dynamicarray_2D& other){ // copy constructor
        row=other.row;
        col=other.col;
        arr=new int*[row];
        for(int i=0;i<row;i++){
            arr[i]=new int[col];
            for(int j=0;j<col;j++){
                arr[i][j]=other.arr[i][j];
            }
        }
    }

    dynamicarray_2D operator +(const dynamicarray_2D& other){
        // for this result variable constructor will also be invoked so that memory is allocated.
        dynamicarray_2D result(row,col); // row , col are of left operand (this) or (a) in main in a+b // purpose of this new class type variable to store sum of both a+b and return the created object result which is copied all to sum class type variable in main.
        for(int i=0;i<row;i++){

            for(int j=0;j<col;j++){
                result.arr[i][j] = arr[i][j] + other.arr[i][j];
            }
        }

        return result;
    }

    dynamicarray_2D operator -(const dynamicarray_2D& other){
        dynamicarray_2D result(row,col);

        for(int i=0;i<row;i++){

            for(int j=0;j<col;j++){
                result.arr[i][j] = arr[i][j] - other.arr[i][j];
            }
        }
        
        return result;
    }

    dynamicarray_2D operator *(const dynamicarray_2D& other){
        dynamicarray_2D result(row,col);
        
        for(int i=0;i<row;i++){

            for(int j=0;j<col;j++){
                result.arr[i][j] = arr[i][j] * other.arr[i][j];
            }
        }
        return result;
    }

    dynamicarray_2D& operator =(const dynamicarray_2D& other){ // why & cuz all changes should reflect to the this* obj or if you dont put & it will return copy of obj not effeting current object this*. this is a poniter to obj this is dereferenced of the obj means value.
        
        if(this != &other)
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[i][j]= other.arr[i][j];  // the other is the one which the operator returns and values of that are copied to this (which will be sum variable of class type) and then return the sum varibale this.
            }
        }
        
        return *this; 
    }

    int *operator [](int index){ // as arr** so int* return a pointer to a row pointing to col.
        return arr[index];
    }

    void display() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    bool search(int target){
        int mid,start,end;
        for(int i=0;i<row;i++){
            start=0;
            end=col-1;
            for(int j=0;j<col;j++){
                   mid=(start+end)/2;
                   if(target>arr[i][mid]){
                     start=mid+1;
                   }
                   else if(target<arr[i][mid]){
                     end=mid;
                   }
                   else if(target==arr[i][mid]||start==end){
                    return true;
                   }
            }
        }
        return false;
    }

    ~dynamicarray_2D(){
        for(int i=0;i<row;i++){
            delete[] arr[i]; // deleting all cols of first row
        }
        delete[] arr; // deleting row
    }

};
int main(){
    dynamicarray_2D ob1(2,2),ob2(2,2);
    ob1[0][0]=2 ;ob1[0][1]=3;
    ob1[1][0]=1 ;ob1[1][1]=2;

    ob2[0][0]=1 ;ob2[0][1]=3;
    ob2[1][0]=3 ;ob2[1][1]=2;

    cout<<"matrice A: "<<endl;
    ob1.display();
    cout<<"matrice B: "<<endl;
    ob2.display();

    dynamicarray_2D sum= ob1+ob2;
    sum.display();
    dynamicarray_2D prod= ob1*ob2; // product is dont element wise this is not standard. not like we do in real.
    prod.display();
    
    dynamicarray_2D matrix(3,4);
    matrix[0][0]=1; matrix[0][1]=3; matrix[0][2]=5; matrix[0][3]=7;
    matrix[1][0]=10; matrix[1][1]=11; matrix[1][2]=16; matrix[1][3]=20;
    matrix[2][0]=23; matrix[2][1]=30; matrix[2][2]=34; matrix[2][3]=60;

    int target;
    cout<<" Give Number to search in matrix: "<<endl;
    cin>>target;

    if(matrix.search(target)==true){
        cout<<" Target "<<target<<" found! "<<endl;
    }
    else{
        cout<<" Target "<<target<<" not found! "<<endl;
    }




    return 0;
}