#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "GradeSystem.h"

class GradeSystem; // Forward declaration

class Admin : public User {
public:
    // Constructor
    Admin(const std::string &name);
    
    void displayRole() const override;

    void displayMenu() const;

    // Admin only operations
    void addStudent(GradeSystem &system, const Student &student);
    void removeStudent(GradeSystem &system, const std::string &name);
    void addSubject(GradeSystem &system, const std::string &subject);
    void removeSubject(GradeSystem &system, const std::string &subject);
    void showGrades(GradeSystem &system);
    void calculateSubjectAverage(GradeSystem &system);
    void calculateGpa(GradeSystem &system, const int scale);
    void displayRank(GradeSystem &system);
    void displayDistribution(GradeSystem &system);
    void exportGrades(GradeSystem &system);
};

#endif
