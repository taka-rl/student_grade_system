#ifndef GRADESYSTEM_H
#define GRADESYSTEM_H

#include <vector>
#include <string>
#include "Student.h"
#include "Admin.h"


/*
GradeSystem class manages all students, subjects, and grades.
Attributes
    std::vector<std::string> subjects: List of subjects.
    std::vector<Student> students: List of students.
Functions
    calculate GPA, average grades
    display all students' grades
    display ranking by all students' average grades
    display grade distributions
    load thier grade on CSV file
    export their grade on CSV file 
    generate a report as csv for the selected student by the admin(teachers), including the selected student name, its grades, GPA, and average grade

*/


class Admin;  // Forward declaration

class GradeSystem {
    friend class Admin;  // Only Admin can access private/protected parts.
private:
    std::vector<std::string> subjects;
    std::vector<Student> students;
    std::vector<Admin> admins;

public:
    // Constructor
    GradeSystem();

    // Add a student
    void addStudent(const Student &student);

    // Remove a student by name
    void removeStudent(const std::string &name);

    // Add a subject
    void addSubject(const std::string &subject);

    // Remove a subject
    void removeSubject(const std::string &subject);

    // Display all grades
    void showGrades() const;

    // Calculate subject average
    void calculateSubjectAverage() const;

    // Calculate student average
    void calculateStudentAverages() const;

    // Calculate GPA
    void calculateGpa(const int scale) const;

    // Display Ranking by average grades
    void displayRank() const;

    // Display grade distirbution
    void displayDistribution() const;

    // Load grades
    void loadGrades();

    // Export grades
    void exportGrades() const;

    // Login
    User* authenticate() const;
};

#endif // GRADESYSTEM_H
