#include<iostream>
using namespace std;
class character{
float *health,*attack_power,*defence_ratio;
string *special_ability;
public:
character(){  // default constructor
health=new float(20.0);
attack_power=new float(30.0);
defence_ratio=new float(10.0);
special_ability=new string("default");
}

character(float heal,float attack,float defence,string ability){ // Parametrized constructor
health=new float(heal);
attack_power=new float(attack);
defence_ratio=new float(defence);
special_ability=new string(ability);
}
character(const character& C){
health=new float(*C.health);
attack_power=new float(*C.attack_power);
defence_ratio=new float(*C.defence_ratio);
special_ability=new string(*C.special_ability);
}
void set_attributes(float heal,float attack,float defence,string ability){
*health=heal;
*attack_power=attack;
*defence_ratio=defence;
*special_ability=ability;
}
float get_health(){
    return *health;
}
float get_attack(){
    return *attack_power;
}
float get_defence(){
    return *defence_ratio;
}
string get_ability(){
    return *special_ability;
}

~character() {
    delete health;
    delete attack_power;
    delete defence_ratio;
    delete special_ability;
}

};
int main(){
    float health,attack,defence;
    string ability;

    cout<<" Enter Health of character "<<endl;
    cin>>health;
    cout<<" Enter Attack power of character "<<endl;
    cin>>attack;
    cout<<" Enter Defence ratio of character "<<endl;
    cin>>defence;
    cout<<" Enter Special ability of character "<<endl;
    cin.ignore();
    getline(cin,ability);
    character c1(health,attack,defence,ability);
    character c2(c1);

    cout<<" Character 1 Health: "<<c1.get_health()<<endl;
    cout<<" Character 1 Attack Power: "<<c1.get_attack()<<endl;
    cout<<" Character 1 Defence: "<<c1.get_defence()<<endl;
    cout<<" Character 1 Special Ability: "<<c1.get_ability()<<endl;

    cout<<" \nCharacter 2 Health: "<<c2.get_health()<<endl;
    cout<<" Character 2 Attack Power: "<<c2.get_attack()<<endl;
    cout<<" Character 2 Defence: "<<c2.get_defence()<<endl;
    cout<<" Character 2 Special Ability: "<<c2.get_ability()<<endl;

    char ch;
    cout<<" Modify character: A) Character 1 , B) character 2 , C) Exist"<<endl;
    cin>>ch;
    
    if(ch=='A'|| ch=='a'){
    cout<<" Enter Health of character "<<endl;
    cin>>health;
    cout<<" Enter Attack power of character "<<endl;
    cin>>attack;
    cout<<" Enter Defence ratio of character "<<endl;
    cin>>defence;
    cout<<" Enter Special ability of character "<<endl;
    cin.ignore();
    getline(cin,ability);
    c1.set_attributes(health,attack,defence,ability);   
    }
    else if(ch=='B'|| ch=='b'){
    cout<<" Enter Health of character "<<endl;
    cin>>health;
    cout<<" Enter Attack power of character "<<endl;
    cin>>attack;
    cout<<" Enter Defence ratio of character "<<endl;
    cin>>defence;
    cout<<" Enter Special ability of character "<<endl;
    cin.ignore();
    getline(cin,ability);
    c2.set_attributes(health,attack,defence,ability);   
    }
    else{
    cout<<" Okay"<<endl;
    }
    
    cout<<" Character 1 Health: "<<c1.get_health()<<endl;
    cout<<" Character 1 Attack Power: "<<c1.get_attack()<<endl;
    cout<<" Character 1 Defence: "<<c1.get_defence()<<endl;
    cout<<" Character 1 Special Ability: "<<c1.get_ability()<<endl;

    cout<<" \nCharacter 2 Health: "<<c2.get_health()<<endl;
    cout<<" Character 2 Attack Power: "<<c2.get_attack()<<endl;
    cout<<" Character 2 Defence: "<<c2.get_defence()<<endl;
    cout<<" Character 2 Special Ability: "<<c2.get_ability()<<endl;
    
    return 0;
}