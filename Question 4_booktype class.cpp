#include<iostream>
#include<string.h>
using namespace std;
class booktype{
int isbn,year_publication,book_stock;
string publisher,title;
string author[4];
float price;
public:
booktype(int isbn=0,int year_publication=0,int book_stock=0,string title="",string Publisher="",const string *Author=nullptr,float price=0.0):isbn(isbn) // parametrized // default
,year_publication(year_publication),book_stock(book_stock),publisher(Publisher),title(title),price(price){ 
for(int i=0;i<4;i++){
    author[i]=Author ? Author[i] : "default";
}
}
void set_details(int isbn,string title,int year_publication,int book_stock,const string *Author,int price,string Publisher){
this->isbn=isbn;
this->title=title;
this->year_publication=year_publication;
this->book_stock=book_stock;
for(int i=0;i<4;i++){
    author[i]=Author[i];
}
this->price=price;
publisher=Publisher;
}
void display(){
    cout<<" Details Of Book"<<endl<<
    "Isbn: "<<isbn<<endl<<"Title: "<<title<<endl<<"Price: "<<price<<endl<<"Year of Publication: "<<year_publication<<endl<<"Book copies: "<<book_stock<<endl<<"Publisher: "<<publisher<<endl;
    for(int i=0;i<4;i++){
        cout<<"Author "<<i+1<<": "<<author[i]<<endl;
    }
}
int get_isbn(){
    return isbn;
}
string get_title(){
    return title;
}
bool search_book_title(string title){
    return this->title==title;
}
bool search_book_by_isbn(int isbn){
    return this->isbn==isbn;
}
void update_book_stock(int add_stock){
book_stock+=add_stock;
cout<<" New Stock is: "<<book_stock<<endl;
}
void update_book_publisher(string Publisher ){
publisher=Publisher;
cout<<" New Publisher is: "<<publisher<<endl;
}
void update_book_isbn(int isbn){
this->isbn=isbn;
cout<<" New Isbn: "<<isbn<<endl;
}
void update_book_price(float price){
this->price=price;
cout<<" New Price: "<<price<<endl;
}
void update_book_authors(string old,string neww){
for(int i=0;i<4;i++){
    if(author[i]==old){author[i]=neww;}
    cout<<author[i]<<endl;
}
}
};
int main(){
    string title,Author[4];
    string Publisher;
    float price;
    int isbn,year_publication,book_stock;

    booktype book[2];
    int check1=0;
    for(int i=0;i<2;i++){

    for(int j=0;check1==0;j++){
    cout<<" Enter book tile: "<<endl;
    getline(cin,title);
    cout<<" Enter book isbn: <6 digits "<<endl;
    cin>>isbn;
    cin.ignore();
    for(int k=0;k<2;k++){
    if(book[k].get_title()==title||book[k].get_isbn()==isbn){
    cout<<" Values can't match other books title: "<<endl;
    check1=0;
    break;
    }
    else if(book[k].get_title()!=title&&book[k].get_isbn()!=isbn){
    check1++;
    }
    }
    if(check1==2){
    break;
    }
    }
    cout<<" Enter book publisher: "<<endl;
    getline(cin,Publisher);
    cout<<" Enter Publication year: "<<endl;
    cin>>year_publication;
    cout<<" Enter book price: "<<endl;
    cin>>price;
    cout<<" Enter book copies: "<<endl;
    cin>>book_stock;
    cin.ignore();
    for(int l=0;l<4;l++){
    cout<<" Enter book author "<<l+1<<endl;
    getline(cin,Author[l]);
    }
    book[i].set_details(isbn,title,year_publication,book_stock,Author,price,Publisher);
    check1=0;
    }

    char ch;
    int isbn1,found=-1;
    string title1;
    cout<<" Search Book By A) Isbn , B) Title "<<endl;
    cin>>ch;
    
    if(ch=='A'||ch=='a'){
    cout<<" Enter ISBN: "<<endl;
    cin>>isbn1;
    for(int i=0;i<2;i++){
    if(book[i].get_isbn()==isbn1){
    cout<<" Book Title "<<book[i].get_title()<<" :Available "<<endl;
    found=i;
    break;
    }
    }
    if(found==-1){
    cout<<" Not found"<<endl;
    }
    else{
        while(1){
    cout<<" 1) Show Details: "<<endl;
    cout<<" 2) Update Stock: "<<endl;
    cout<<" 3) Update Authors: "<<endl;
    cout<<" 4) Update Price: "<<endl;
    cout<<" 5) Update Publisher: "<<endl;
    cout<<" 6) Update Isbn: "<<endl;
    cout<<" 7) Exit: "<<endl;
    cout<<" Enter Option: "<<endl;
    cin>>isbn1;
    string old,neww;
    switch(isbn1){
        case 1:
        book[found].display();
        break;
        case 2:
        cout<<" Enter New stock: "<<endl;
        cin>>book_stock;
        book[found].update_book_stock(book_stock);
        break;
        case 3:
        cout<<"old author: "<<endl;
        cin>>old;
        cout<<"new author: "<<endl;
        cin>>neww;
        cout<<"new authors:"<<endl;
        book[found].update_book_authors(old,neww);
        break;
        case 4:
        cout<<" Enter new price: "<<endl;
        cin>>price;
        book[found].update_book_price(price);
        break;
        case 5:
        cout<<" Enter new publisher: "<<endl;
        cin>>Publisher;
        book[found].update_book_publisher(Publisher);
        break;
        case 6:
        cout<<" Enter new isbn:"<<endl;
        cin>>isbn;
        book[found].update_book_isbn(isbn);
        break;
        case 7:
        return 0;
        default:
        cout<<"wrong input: "<<endl;
    }
    }
    }
    }
    else if(ch=='B'||ch=='b'){
    cout<<" Enter title: "<<endl;
    cin.ignore();
    getline(cin,title1);
    for(int i=0;i<2;i++){
    if(book[i].get_title()==title1){
    cout<<" Book Title "<<book[i].get_title()<<" :Available "<<endl;
    found=i;
    break;
    }
    }
    if(found==-1){
    cout<<" Not found:"<<endl;
    }
    else{
        while(1){
    cout<<" 1) Show Details: "<<endl;
    cout<<" 2) Update Stock: "<<endl;
    cout<<" 3) Update Authors: "<<endl;
    cout<<" 4) Update Price: "<<endl;
    cout<<" 5) Update Publisher: "<<endl;
    cout<<" 6) Update Isbn: "<<endl;
    cout<<" 7) Exit: "<<endl;
    cout<<" Enter Option: "<<endl;
    cin>>isbn1;
    string old,neww;
    switch(isbn1){
        case 1:
        book[found].display();
        break;
        case 2:
        cout<<" Enter New stock: "<<endl;
        cin>>book_stock;
        book[found].update_book_stock(book_stock);
        break;
        case 3:
        cout<<"old author: "<<endl;
        cin>>old;
        cout<<"new author: "<<endl;
        cin>>neww;
        cout<<"new authors:"<<endl;
        book[found].update_book_authors(old,neww);
        break;
        case 4:
        cout<<" Enter new price: "<<endl;
        cin>>price;
        book[found].update_book_price(price);
        break;
        case 5:
        cout<<" Enter new publisher: "<<endl;
        cin>>Publisher;
        book[found].update_book_publisher(Publisher);
        break;
        case 6:
        cout<<" Enter new isbn:"<<endl;
        cin>>isbn;
        book[found].update_book_isbn(isbn);
        break;
        case 7:
        return 0;
        default:
        cout<<"wrong input: "<<endl;
    }
    }
    }
    }
    return 0;
}