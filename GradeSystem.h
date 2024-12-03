#ifndef GRADESYSTEM_H
#define GRADESYSTEM_H

#include <vector>
#include <string>
#include "Student.h"  // Include the Student class


/*
GradeSystem class manages all students, subjects, and grades.
Attributes
    std::vector<std::string> subjects: List of subjects.
    std::vector<Student> students: List of students.
Functions

*/


class GradeSystem {
private:
    std::vector<std::string> subjects;
    std::vector<Student> students;

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

    // Load grades
    void loadGrades();

    // Export grades
    void exportGrades() const;

};

#endif // GRADESYSTEM_H
