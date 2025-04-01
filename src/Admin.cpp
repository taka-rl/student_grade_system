#include "Admin.h"
#include "GradeSystem.h"
#include <iostream>
using namespace std;


// Constructor
Admin::Admin(const std::string& name) : User(name) {}

void Admin::displayRole() const {
    std::cout << "Role: Admin\n";
}

void Admin::displayMenu() const {
    cout << "\nAdmin Menu:\n"
         << "1. Add Student\n"
         << "2. Remove Student\n"
         << "3. Add Subject\n"
         << "4. Remove Subject\n"
         << "5. Show Grades\n";
}

// Admin only operations
// Add a student
void Admin::addStudent(GradeSystem& system, const Student& student) {
    system.addStudent(student);
}

// Remove a student by name
void Admin::removeStudent(GradeSystem& system, const std::string& name) {
    system.removeStudent(name);
}

// Add a subject
void Admin::addSubject(GradeSystem& system, const std::string& subject) {
    system.addSubject(subject);
}

// Remove a subject
void Admin::removeSubject(GradeSystem& system, const std::string& subject) {
    system.removeSubject(subject);
}

// Display all grades
void Admin::showGrades(GradeSystem& system) {
    system.showGrades();
}

// Calculate subject average
void Admin::calculateSubjectAverage(GradeSystem& system) {
    system.calculateSubjectAverage();
}

// Calculate GPA
void Admin::calculateGpa(GradeSystem& system, const int scale) {
    system.calculateGpa(scale);
}

// Display Ranking by average grades
void Admin::displayRank(GradeSystem& system) {
    system.displayRank();
}

// Display grade distirbution
void Admin::displayDistribution(GradeSystem& system) {
    system.displayDistribution();
}

// Export grades
void Admin::exportGrades(GradeSystem& system) {
    system.exportGrades();
}

