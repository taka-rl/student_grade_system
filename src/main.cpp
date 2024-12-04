#include <iostream>
#include "Student.h"
#include "GradeSystem.h"
using namespace std;


int main() {
    GradeSystem gradeSystem;
    string newSubject, newStudentName, removeSubject, removeStudent;
    std::vector<int> newGrades;
    Student newStudent = {newStudentName, newGrades};
    int scale;

    // Load grades from CSV
    gradeSystem.loadGrades();

    int act;
    while (true){
        cout << "Choose the action from 1 to 10\n";
        cout << "1 to add a new student\n";
        cout << "2 to add a new subject\n"; 
        cout << "3 to remove a student\n";
        cout << "4 to remove a subject\n";
        cout << "5 to show grades\n";
        cout << "6 to calculate the average grades\n";
        cout << "7 to calculate GPA\n";
        cout << "8 to display ranking by average grades\n";
        cout << "9 to display grade distributions\n";        
        cout << "10 to end\n";
        cout << "Enter: ";
        cin >> act;

        switch(act){
            case 1:
                cout << "Add a new student" << endl;
                cout << "Write a studen name: ";
                cin >> newStudentName;
                // cout << "Write grades: ";
                // cin >> newGrades;

                newStudent = {newStudentName, newGrades};
                cout << "\nAdding a new student: " << newStudentName << endl;;
                gradeSystem.addStudent(newStudent);
                break;
            case 2:
                cout << "Add a new subject" << endl;                
                cout << "\nEnter a new subject: ";
                cin >> newSubject;
                gradeSystem.addSubject(newSubject);
                break;
            case 3:
                cout << "Remove a student" << endl;
                cout << "\nEnter a student name to remove: ";
                cin >> removeStudent;
                gradeSystem.removeStudent(removeStudent);
                break;
            case 4:
                cout << "Remove a subject" << endl;                
                cout << "\nEnter a subject to remove: ";
                cin >> removeSubject;
                gradeSystem.removeSubject(removeSubject);
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
            case 10:
                cout << "end this program" << endl;
                break;
            default:
                cout << "Select from 1 to 8 " << endl;
                break;
        }
        if(act == 10){
            break;
        }
    }    

    // Display grades before the program ends
    gradeSystem.showGrades();

    // Export grades back to CSV
    gradeSystem.exportGrades();

    return 0;
}
