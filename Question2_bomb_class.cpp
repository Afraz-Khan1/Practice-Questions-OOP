#include<iostream>
using namespace std;

class weapons {
    string description;
public:
    weapons(string description = "") : description(description) {}

    void weaponsDescription() {
        cout << " Description: " << description << endl;
    }

    void set_des(string description = "") {
        this->description = description;
    }
};

class hotweapons : public weapons {
    string weapon_types[4];
public:
    hotweapons(string description = "", string weapon_types[] ={}) : weapons(description) {
        for (int i = 0; i < 4; i++) {
            this->weapon_types[i] = (weapon_types) ? weapon_types[i] : "default";
        }
    }

    void hotweaponsDescription() {
        weapons::weaponsDescription();
        for (int i = 0; i < 4; i++) {
            cout << " Weapons type: " << i + 1 << " " << weapon_types[i] << endl;
        }
    }
};

class bomb : public weapons {
    string bomb_type[4];
public:
    bomb(string description = "", string bomb_type[] ={}) : weapons(description) {
        for (int i = 0; i < 4; i++) {
            this->bomb_type[i] = (bomb_type) ? bomb_type[i] : "default";
        }
    }

    void bombsDescription() {
        for (int i = 0; i < 4; i++) {
            cout << " Bomb type: " << i + 1 << " " << bomb_type[i] << endl;
        }
    }
};

class nuclearbomb : public weapons {
    string nuclearbob;
public:
    nuclearbomb(string description = "", string nuclearbob = "") : weapons(description), nuclearbob(nuclearbob) {}

    void nuclearbombsDescription() {
        weapons::weaponsDescription();
        cout << " Nuclear bomb name: " << nuclearbob << endl;
    }
};

int main() {
    string weapon_types[4], bomb_type[4];
    for (int i = 0; i < 4; i++) {
        cout << " Enter weapon type " << i + 1 << endl;
        getline(cin, weapon_types[i]);
    }
    hotweapons c2("Uses bullets to fire", weapon_types); // remove weapon_type to see if default come auto
    c2.hotweaponsDescription();

    for (int i = 0; i < 4; i++) {
        cout << " Enter bomb type " << i + 1 << endl;
        getline(cin, bomb_type[i]);
    }
    bomb c3("uses explosive powder and materials that multiply on giving power", bomb_type);
    c3.weaponsDescription();
    c3.bombsDescription();

    cout << " After changing bomb description: " << endl;
    c3.set_des(" uses powder to explode");
    c3.weaponsDescription(); // access the base display as it is public inheritance
    c3.bombsDescription();

    nuclearbomb c4("bomb explodes using radium most dangerous chemical", "atom bomb");
    c4.nuclearbombsDescription();

    return 0;
}