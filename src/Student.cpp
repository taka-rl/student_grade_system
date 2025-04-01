#include "Student.h"
#include "User.h"
#include <numeric>
#include <iostream>

// Constructor
Student::Student(const std::string &name, const std::vector<int> &grades) : User(name), grades(grades) {}

void Student::displayRole() const {
    std::cout << "Role: Student\n";
}

// Getters and Setters
std::vector<int> Student::getGrades() const { return grades; }
void Student::setGrades(const std::vector<int> &newGrades) { grades = newGrades; }

// Calculate average grade
float Student::calculateAverage() const {
    if (grades.empty()) return 0.0f;
    return static_cast<float>(std::accumulate(grades.begin(), grades.end(), 0)) / grades.size();
}
