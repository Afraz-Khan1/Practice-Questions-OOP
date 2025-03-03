#include <iostream>
#include <string>
using namespace std;
// Function to calculate percentage (using reference for percentage)
void calculatePercentage(float totalMarks, int totalSubjects, float &percentage) {
    percentage = (totalMarks / (totalSubjects * 100)) * 100;
}
int main() {
    int rollNumber, totalSubjects;
    
    cout << "Enter your roll number: ";
    cin >> rollNumber;
    
    cout << "Enter the number of subjects: ";
    cin >> totalSubjects;

    string subjects[totalSubjects];
    float marks[totalSubjects], totalMarks = 0, percentage;

   
    for (int i = 0; i < totalSubjects; i++) {
        cout << "Enter name of subject " << i + 1 << ": ";
        cin >> subjects[i];
        cout << "Enter marks for " << subjects[i] << ": ";
        cin >> marks[i];
        totalMarks += marks[i];
    }
    
    calculatePercentage(totalMarks, totalSubjects, percentage);

    
    cout << "\nRoll Number: " << rollNumber << endl;
    cout << "Total Marks Obtained: " << totalMarks << endl;
    cout << "Percentage: " << percentage << "%" << endl;

    return 0;
}