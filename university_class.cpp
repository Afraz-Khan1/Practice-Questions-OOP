#include<iostream>
using namespace std;
class uni{
string name;
int const unicode;
int student_id;
public:
static int count;
uni(string name="",int unicode=0,int student_id=0):name(name),unicode(unicode),student_id(student_id){
count++;
cout<<"count initial: "<<count<<endl;
}
void set_name(string name){
    this->name=name;
}
void set_id(int student_id){
    this->student_id=student_id;
}
//void set_code(int unicode){ // must be modifiable value on this
  //  this->unicode=unicode;
//}
string get_name()const{
    return name;
}
int get_code()const{
return unicode;
}
int get_id()const{
    return student_id;
}
~uni(){
    cout<<"after deleting count is "<<count<<endl;
    count--;
}
};
int uni::count=0;
int main(){
    uni c1,c2;
    uni c3("afraz",24,78);
    cout<<" count after object creating: "<<uni::count<<endl;
    c3.set_name("khan");
    cout<<c3.get_name()<<endl;
    


    return 0;
}