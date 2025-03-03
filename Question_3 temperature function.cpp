#include <iostream>
using namespace std;

float convertToCelsius(float F) {
    return (F - 32) / 1.8;
}

int main() {
    float F;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> F;
    cout << "Temperature in Celsius: " << convertToCelsius(F) << endl;
    return 0;
}