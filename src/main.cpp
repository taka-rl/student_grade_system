#include <iostream>
#include "Student.h"
#include "Admin.h"
#include "GradeSystem.h"
using namespace std;


int main(){
    GradeSystem gradeSystem;
    string newSubject, newStudentName, newPassword, removeSubject, removeStudent;
    std::vector<int> newGrades;
    Student newStudent = {newStudentName, newPassword, newGrades};
    int scale;
    int action = 0;
    User* loggedInUser = nullptr;

    // Load grades from CSV
    gradeSystem.loadGrades();

    // Login
    while (!loggedInUser) {
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> action;

        if (action == 1) {
            loggedInUser = gradeSystem.authenticate();
            if (!loggedInUser) {
                cout << "Invalid credentials. Try again.\n";
            } else {
                cout << "Login successful!\n";
                loggedInUser->displayRole();
            }
        } else if (action == 2) {
            cout << "Exiting program.\n";
            return 0;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    if(Admin* admin = dynamic_cast<Admin*>(loggedInUser)){
        // Admin logic
        int choice = 0;
        while (true){
            admin->displayMenu();
            cout << "Enter: ";
            cin >> choice;
            if(choice == 10) break;

            switch(choice){
                case 1:
                    cout << "Add a new student" << endl;
                    cout << "Write a studen name: ";
                    cin >> newStudentName;

                    // Temporal password
                    newPassword = "012345";

                    newStudent = {newStudentName, newPassword, newGrades};
                    cout << "\nAdding a new student: " << newStudentName << endl;;
                    admin->addStudent(gradeSystem, newStudent);
                    break;
                case 2:
                    cout << "Add a new subject" << endl;                
                    cout << "\nEnter a new subject: ";
                    cin >> newSubject;
                    admin->addSubject(gradeSystem, newSubject);
                    break;
                case 3:
                    cout << "Remove a student" << endl;
                    cout << "\nEnter a student name to remove: ";
                    cin >> removeStudent;
                    admin->removeStudent(gradeSystem, removeStudent);
                    break;
                case 4:
                    cout << "Remove a subject" << endl;                
                    cout << "\nEnter a subject to remove: ";
                    cin >> removeSubject;
                    admin->removeSubject(gradeSystem, removeSubject);
                    break;
                case 5:
                    cout << "show grades" << endl;
                    gradeSystem.showGrades();
                    break;    
                case 6:
                    cout << "calculate the subject average grade" << endl;
                    gradeSystem.calculateSubjectAverage();
    
                    cout << "calculate the student average grade" << endl;
                    gradeSystem.calculateStudentAverages();
                    break;
                case 7:
                    cout << "calculate GPA" << endl;
                    cout << "Enter a scale for GPA: ";
                    cin >> scale;
                    gradeSystem.calculateGpa(scale);
                    break;
                case 8:
                    cout << "Display ranking by average grades" << endl;
                    gradeSystem.displayRank();
                    break;
                case 9:
                    cout << "Display grade distributions" << endl;
                    gradeSystem.displayDistribution();
                    break;                
                default:
                    cout << "Select from 1 to 9" << endl;
                    break;
            }
        }

    }else if(Student* student = dynamic_cast<Student*>(loggedInUser)){
        // Student logic
        int choice = 0;
        while (true){
            student->displayMenu();
            cout << "Enter: ";
            cin >> choice;

            if (choice == 5) break;

            switch(choice){
                case 1:
                cout << "Display the own grade\n" << endl;
                student->getGrades();
                break;
            case 2:
                cout << "Calculate the average grade\n" << endl;
                student->calculateAverage();
                break;
            case 3:
                cout << "Calculate GPA\n" << endl;
                cout << "Enter a scale for GPA: ";
                cin >> scale;
                gradeSystem.calculateGpa(scale);
                break;
            case 4:
                cout << "Reset password" << endl;
                student->resetPassword();
                break;
            default:
                cout << "Select from 1 to 4" << endl;
                break;
        }
    }
}

    // Display grades before the program ends
    gradeSystem.showGrades();

    // Export grades back to CSV
    gradeSystem.exportGrades();

    // Export Users back to CSV
    gradeSystem.exportUsers();

    return 0;
}
