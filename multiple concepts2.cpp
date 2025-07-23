#include<iostream>
#include<fstream>
using namespace std;
class vehical {
int model;
string name;
public:
vehical(int m=0,string n=""):model(m),name(n){
cout<<" vehical constructor invoked: "<<endl;
}
 virtual void display(){
    ofstream file1("file1.txt");
    string line;
    cout<<" enter content: (write END on new line to stop)"<<endl;
    while(true){
        getline(cin,line);
        if(line=="END"){
            break;
        }
        else{
            file1<<line<<"\n"; // stores line on a seperate line for each content line
        }
    }
    file1.close();
    

    cout<<"model: "<<model<<endl;
    cout<<"name: "<<name<<endl;
}
void getmodel(){
    cout<<"model: "<<model<<endl;
}
void getname(){
    cout<<"name: "<<name<<endl;
}

};
class car :public virtual vehical{
    int kilo;
    public:
    car(int model=0,string n="",int kilo=0):vehical(model,n),kilo(kilo){
     cout<<"car constructor invoked: "<<endl;
    }
    void display(){
        ofstream file1("file1.txt",ios::app);
        string line;
        cout<<" enter content: (write END on new line to stop)"<<endl;
        while(true){
            getline(cin,line);
            if(line=="END"){
             break;
            }
            else{
                file1<<line<<"\n";
            }
        }
        file1.close();
    cout<<"kilometer: "<<kilo<<endl;
    }
};
class bike :public virtual vehical{
    int wheels;
    public:
    bike(int model=0,string n="",int wh=0):vehical(model,n),wheels(wh){
     cout<<"bike constucotr invoked: "<<endl;
    }
    void display(){
        ifstream file1("file1.txt");
        string line;
        while(getline(file1,line)){
            cout<<line<<endl;
        }
        file1.close();
        cout<<"wheels: "<<wheels<<endl;
    }
};
class rickshaw:public car,bike{
public:
rickshaw(int model=0,string n="",int kilo=0,int wheel=0):vehical(model,n),car(model,n,kilo),bike(model,n,wheel){
    cout<<"rickshaw constructor invoked: "<<endl;
}
void display(){
    vehical::display();
    car::display();
    bike::display();
}
};
int main(){
    rickshaw ob1(2000,"corolla",500,3);
    ob1.display();
    
    return 0;
}