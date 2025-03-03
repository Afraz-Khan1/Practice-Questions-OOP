#include <iostream>
using namespace std;
void swapNumbers(int *a, int *b, int *c) {// int *a refer to num1 you can also do like miss (int& a,int& b,int& c) and in main (num1,num2,num3)
    int temp;
    
    // Swap the values
    temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

int main() {
    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    cout << "Before swapping:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << ", num3 = " << num3 << endl;
    swapNumbers(&num1, &num2, &num3);

    cout << "After swapping:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << ", num3 = " << num3 << endl;

    return 0;
}