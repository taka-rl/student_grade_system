#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

/*
Student class represents individual students with their names and associated grades.
Attributes
    std::string name: the name of the student
    std::vector<int> grades: stores the grades for each subject
Functions

*/

class Student {
private:
    std::string name;
    std::vector<int> grades;

public:
    // Constructor
    Student(const std::string &name, const std::vector<int> &grades = {});

    // Getters and Setters
    std::string getName() const;
    void setName(const std::string &newName);

    std::vector<int> getGrades() const;
    void setGrades(const std::vector<int> &newGrades);

    // Function to calculate average grade
    float calculateAverage() const;
};

#endif // STUDENT_H