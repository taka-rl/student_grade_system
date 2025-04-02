#include "Student.h"
#include "User.h"
#include <numeric>
#include <iostream>
using namespace std;

// Constructor
Student::Student(const std::string &name, const std::vector<int> &grades) : User(name), grades(grades) {}

void Student::displayRole() const {
    std::cout << "Role: Student\n";
}

void Student::displayMenu() const {
    cout << "\nStudent Menu:\n";
    cout << "Choose one of the following actions\n";
    cout << "1. Display the own grade\n";
    cout << "2. Calculate the average grade\n";
    cout << "3. Calculate GPA\n";
    cout << "4. Reset password\n";
    cout << "5. End this program\n";
}

// Getters and Setters
std::vector<int> Student::getGrades() const { return grades; }
void Student::setGrades(const std::vector<int> &newGrades) { grades = newGrades; }

// Calculate average grade
float Student::calculateAverage() const {
    if (grades.empty()) return 0.0f;
    return static_cast<float>(std::accumulate(grades.begin(), grades.end(), 0)) / grades.size();
}
