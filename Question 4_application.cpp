#include<iostream>
using namespace std;
class media{
    int Quantity;
    string borrow="";
    public:
    media(int quan=0):Quantity(quan){
    cout<<"media constuctor invoked: "<<endl;
    }
    virtual void display_info(){
        cout<<"Quantity: "<<Quantity<<endl;
    }
    void returning(){
        if(borrow=="yes"){
            Quantity++;
            cout<<"Item returned: "<<endl;
        }
        else{
            cout<<"are you joking with me: "<<endl;
        }
    }
    void borrowing(){
        if(Quantity>0){
            Quantity--;
            cout<<"Item borrowed: "<<endl;
            borrow="yes";
        }
        else{
            cout<<"Out of stock: "<<endl;
            borrow="";
        }
    }
};
class bookattri{
    int pages;
    string author;
    public:
    bookattri(int pages=100,string author="hehe"):pages(pages),author(author){
    }
    void display(){
        cout<<"Total pages: "<<pages<<endl<<"Author is: "<<author<<endl;
    }
};
class dvdattri{
    string duration,director;
    public:
    dvdattri(string duration="20 mints",string director="i dont care"):duration(duration),director(director){
    }
    void display(){
        cout<<"Duration: "<<duration<<endl<<"Director: "<<director<<endl;
    }
};
class magzineattri{
    string issuenumber;
    public:
    magzineattri(string issuenumber="23"):issuenumber(issuenumber){
    }
    void display(){
        cout<<"Issuenumber: "<<issuenumber<<endl;
    }
};
class dvd:public media,dvdattri{
    public:
   dvd(int quan=3):media(quan),dvdattri(){
   cout<<"dvd constructor invoked: "<<endl;
   }
   void display_info()override{
    dvdattri::display();
    media::display_info();
}

};
class book:public media,bookattri{
    public:
    book(int quan=7):media(quan),bookattri(){
        cout<<"book constuctor invoked: "<<endl;
    }
    void display_info()override{
        bookattri::display();
        media::display_info();
    }
};
class magzine:public media,magzineattri{
    public:
    magzine(int quan=2):media(quan),magzineattri(){
        cout<<"magzine constructor invoked: "<<endl;
    }
    void display_info()override{
        magzineattri::display();
        media::display_info();
    }
};
int main(){
    magzine m;
    m.display_info();
    m.borrowing();

    m.display_info();
    m.borrowing();

    m.display_info();
    m.borrowing();
    m.returning();
    

    return 0;
}