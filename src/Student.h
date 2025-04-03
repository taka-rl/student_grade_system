#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <vector>

/*
Student class represents individual students with their names and associated grades.
Attributes
    std::string name: the name of the student
    std::vector<int> grades: stores the grades for each subject
Functions

*/

class Student : public User {
private:
    std::vector<int> grades;

public:
    // Constructor
    Student(const std::string &name, const std::string &password, const std::vector<int> &grades = {}) : User(name, password), grades(grades) {}
    
    void displayRole() const override;

    void displayMenu() const;

    // Getters and Setters
    std::vector<int> getGrades() const;
    void setGrades(const std::vector<int> &newGrades);

    // Function to calculate average grade
    float calculateAverage() const;
};

#endif // STUDENT_H