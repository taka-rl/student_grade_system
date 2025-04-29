#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "GradeSystem.h"

/*
Admin class is inherited from the User class. 
Attributes:
    std::string name: the name of the admin
    std::string password: the password of the admin

Functions: the following functions are executed through GradeSystem class
    add/remove students and subjects
    modify students' grade
    display all students' grades
    display all students' average grades
    display all students' GPA
    display ranking by all students' average grades
*/


class GradeSystem; // Forward declaration

class Admin : public User {
public:
    // Constructor
    Admin(const std::string &name, const std::string &password);
    
    void displayRole() const override;

    void displayMenu() const;

    // Admin only operations
    void addStudent(GradeSystem &system, const Student &student);
    void removeStudent(GradeSystem &system, const std::string &name);
    void addSubject(GradeSystem &system, const std::string &subject);
    void removeSubject(GradeSystem &system, const std::string &subject);
    void showGrades(GradeSystem &system);
    void modifyGrade(GradeSystem &system, const std::string &studentName, const std::string &subjectName, const int &newGrade);
    void calculateSubjectAverage(GradeSystem &system);
    void calculateGpa(GradeSystem &system, const int scale);
    void displayRank(GradeSystem &system);
    void displayDistribution(GradeSystem &system);
    void exportGrades(GradeSystem &system);
};

#endif
