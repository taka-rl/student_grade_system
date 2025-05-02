#include "Admin.h"
#include "GradeSystem.h"
#include <iostream>
using namespace std;


// Constructor
Admin::Admin(const std::string &name, const std::string &password) : User(name, password) {}

void Admin::displayRole() const {
    std::cout << "Role: Admin\n";
}

void Admin::displayMenu() const {
    cout << "\nAdmin Menu:\n";
    cout << "Choose one of the following actions\n";
    cout << "1. Add a new student\n";
    cout << "2. Add a new subject\n"; 
    cout << "3. Remove a student\n";
    cout << "4. Remove a subject\n";
    cout << "5. Show grades\n";
    cout << "6. Modify a grade\n";
    cout << "7. Calculate the average grades\n";
    cout << "8. Calculate GPA\n";
    cout << "9. Display ranking by average grades\n";
    cout << "10. Display grade distributions\n";        
    cout << "11. End this program\n";
}

// Admin only operations
// Add a student
void Admin::addStudent(GradeSystem &system, const Student &student) {
    system.addStudent(student);
}

// Remove a student by name
void Admin::removeStudent(GradeSystem &system, const std::string &name) {
    system.removeStudent(name);
}

// Add a subject
void Admin::addSubject(GradeSystem &system, const std::string &subject) {
    system.addSubject(subject);
}

// Remove a subject
void Admin::removeSubject(GradeSystem &system, const std::string &subject) {
    system.removeSubject(subject);
}

// Display all grades
void Admin::showGrades(GradeSystem &system) {
    system.showGrades();
}

// Modify a grade
void Admin::modifyGrade(GradeSystem &system, const std::string &studentName, const std::string &subjectName, const int &newGrade){
    system.modifyGrade(studentName, subjectName, newGrade);
}

// Calculate subject average
void Admin::calculateSubjectAverage(GradeSystem &system) {
    system.calculateSubjectAverage();
}

// Calculate GPA
void Admin::calculateGpa(GradeSystem &system, const int scale) {
    system.calculateGpa(scale);
}

// Display Ranking by average grades
void Admin::displayRank(GradeSystem &system) {
    system.displayRank();
}

// Display grade distirbution
void Admin::displayDistribution(GradeSystem &system) {
    system.displayDistribution();
}

// Export grades
void Admin::exportGrades(GradeSystem &system) {
    system.exportGrades();
}

