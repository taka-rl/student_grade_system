#include "Student.h"
#include <numeric>

// Constructor
Student::Student(const std::string &name, const std::vector<int> &grades) : name(name), grades(grades) {}

// Getters and Setters
std::string Student::getName() const { return name; }
void Student::setName(const std::string &newName) { name = newName; }

std::vector<int> Student::getGrades() const { return grades; }
void Student::setGrades(const std::vector<int> &newGrades) { grades = newGrades; }

// Calculate average grade
float Student::calculateAverage() const {
    if (grades.empty()) return 0.0f;
    return static_cast<float>(std::accumulate(grades.begin(), grades.end(), 0)) / grades.size();
}