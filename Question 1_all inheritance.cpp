#include <iostream>
using namespace std;

class Base {
private:
    int privateInt;

protected:
    int protectedInt;

public:
    int publicInt;

    Base(int pvt = 0, int prot = 0, int pub = 0) : privateInt(pvt), protectedInt(prot), publicInt(pub) {}

    // Getters and Setters
    void setPrivateInt(int value) { privateInt = value; }
    int getPrivateInt() { return privateInt; }

    void setProtectedInt(int value) { protectedInt = value; }
    int getProtectedInt() { return protectedInt; }

    void setPublicInt(int value) { publicInt = value; }
    int getPublicInt() { return publicInt; }
};

// Public Inheritance
class PublicChild : public Base {
public:
    PublicChild(int pvt, int prot, int pub) : Base(pvt, prot, pub) {}

    void display() {
        // privateInt is NOT accessible directly
        cout << "PublicChild - Accessing Members:\n";
        cout << "PrivateInt (via getter): " << getPrivateInt() << endl;
        cout << "ProtectedInt (direct): " << protectedInt << endl;
        cout << "PublicInt (direct): " << publicInt << endl;
    }
};

// Protected Inheritance
class ProtectedChild : protected Base {
public:
    ProtectedChild(int pvt, int prot, int pub) : Base(pvt, prot, pub) {}

    void display() {
        // privateInt is NOT accessible directly
        cout << "ProtectedChild - Accessing Members:\n";
        cout << "PrivateInt (via getter): " << getPrivateInt() << endl;
        cout << "ProtectedInt (direct): " << protectedInt << endl;
        cout << "PublicInt (direct): " << publicInt << endl;
    }
};

// Private Inheritance
class PrivateChild : private Base {
public:
    PrivateChild(int pvt, int prot, int pub) : Base(pvt, prot, pub) {}

    void display() {
        // privateInt is NOT accessible directly
        cout << "PrivateChild - Accessing Members:\n";
        cout << "PrivateInt (via getter): " << getPrivateInt() << endl;
        cout << "ProtectedInt (direct): " << protectedInt << endl;
        cout << "PublicInt (direct): " << publicInt << endl;
    }
};

int main() {
    PublicChild obj1(10, 20, 30);
    obj1.display();

    ProtectedChild obj2(40, 50, 60);
    obj2.display();

    PrivateChild obj3(70, 80, 90);
    obj3.display();

    return 0;
}