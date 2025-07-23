#include<iostream>
using namespace std;

template <class T> // here we should not send string data type as we can't increment it.
class mycontainer {
    T element;
public:
    mycontainer(T arg) {
        element = arg;
    }

    T increase() {
        return ++element;
    }
};

// Specialization for char
template <>
class mycontainer<char> {
    char element;
public:
    mycontainer(char arg) {
        element = arg;
    }

    char uppercase() {
        if (element >= 'a' && element <= 'z')
            element = element - 32;
        return element;
    }
};

int main() {
    mycontainer<int> obj1(7);
    cout << "Increased int: " << obj1.increase() << endl;

    mycontainer<char> obj2('b');
    cout << "Uppercased char: " << obj2.uppercase() << endl;

    return 0;
}