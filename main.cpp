#include <iostream>
#include "Student.h"
#include "GradeSystem.h"

int main() {
    GradeSystem gradeSystem;

    // Load grades from CSV
    gradeSystem.loadGrades();

    // Display grades
    gradeSystem.showGrades();

    // Example: Add a new subject
    std::cout << "\nAdding a new subject: Biology\n";
    gradeSystem.addSubject("Biology");

    // Display grades after adding a new subject
    gradeSystem.showGrades();

    // Export grades back to CSV
    gradeSystem.exportGrades();

    return 0;
}
