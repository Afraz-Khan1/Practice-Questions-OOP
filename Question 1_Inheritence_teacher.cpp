#include<iostream>
using namespace std;
class teacher{
string name, institute;
int age;
public:
teacher(string name="",string institute="",int age=0):name(name),institute(institute),age(age){}
void display(){
    cout<<" Name: "<<name<<endl<<" Institute: "<<institute<<endl<<" Age: "<<age<<endl;
}
void set_name(string name){
this->name=name;
}
void set_ins(string institute){
    this->institute=institute;
}
void set_age(int age){
    this->age=age;
}

};
class mathsteacher: public teacher{
string designation,course,department;
public:
mathsteacher(string designation="",string course="",string department="",string name="",string institute="",int age=0):teacher(name,institute,age),designation(designation),course(course),department(department){}

void display(){
    teacher::display();
    cout<<" Designation: "<<designation<<endl<<" Course: "<<course<<endl<<" Department: "<<department<<endl;
}
void set_des(string designation){
this->designation=designation;
}
void set_course(string course){
    this->course=course;
}
void set_dept(string department){
    this->department=department;
}

};
class scienceteacher: protected teacher{
    string designation;
    string const course,department;
    public:
    scienceteacher(string designation="",string course="",string department="",string name="",string institute="",int age=0):teacher(name,institute,age),designation(designation),course(course),department(department){}
    void display(){
        teacher::display();
        cout<<" Designation: "<<designation<<endl<<" Course: "<<course<<endl<<" Department: "<<department<<endl;
    }
    void set_des(string designation){
    this->designation=designation;
        }
    
    };
    class humanitiesteacher: private teacher{
        string designation;
        string const course,department;
        public:
        humanitiesteacher(string designation="",string course="",string department="",string name="",string institute="",int age=0):teacher(name,institute,age),designation(designation),course(course),department(department){}
        void display(){
            teacher::display();
            cout<<" Designation: "<<designation<<endl<<" Course: "<<course<<endl<<" Department: "<<department<<endl;
        }
    void set_des(string designation){
    this->designation=designation;
                }
        
        };
int main(){
    teacher c1;
    mathsteacher c2("professor","maths","maths deparment","afraz khan","ned",19);
    c2.display();
    scienceteacher c3("lecturer","science","csit","majid khan","ku",59);
    c3.display();
    humanitiesteacher c4("teacher","human","humanities department","shanzey khan","zabist",24);
    c4.display();
    cout<<" After changing humanities designation"<<endl;
    c4.set_des("phd");
    c4.display();

    return 0;
}