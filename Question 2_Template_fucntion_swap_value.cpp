#include<iostream>
using namespace std;

template <class T>
void swapValues(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 5, num2 = 10;
    cout << "Before swapping:\n";
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    swapValues(num1, num2);

    cout << "After swapping:\n";
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    float x = 2.3, y = 4.6;
    cout << "\nBefore swapping:\n";
    cout << "x = " << x << ", y = " << y << endl;

    swapValues(x, y);

    cout << "After swapping:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}