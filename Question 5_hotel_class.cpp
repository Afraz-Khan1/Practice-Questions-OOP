#include<iostream>
#include<string>
using namespace std;

class HotelMercato {
private:
    string customerName; // Customer name
    int days;            // Number of days stayed
    const double dailyCharge = 1000.85; // Fixed daily charge

public:
    // Constructor to initialize customer name and days stayed
    HotelMercato(string name, int days) : customerName(name), days(days) {}

    // Function to calculate the rent
    double calculateRent() const {
        int effectiveDays = days; // Effective days for rent calculation
        if (days > 7) {
            effectiveDays = days - 1; // Apply discount for stays longer than a week
        }
        return effectiveDays * dailyCharge;
    }

    // Function to display customer details (const function)
    void displayDetails() const {
        cout << "Customer Name: " << customerName << endl;
        cout << "Days Stayed: " << days << endl;
        cout << "Total Rent: " << calculateRent() << endl;
    }
};

int main() {
    string name;
    int days;

    // Input customer details
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter number of days stayed: ";
    cin >> days;

    // Create HotelMercato object
    HotelMercato customer(name, days);

    // Display customer details
    customer.displayDetails();

    return 0;
}