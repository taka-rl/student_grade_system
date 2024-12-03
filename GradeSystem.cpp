#include "GradeSystem.h"
#include "utilities.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;


// Constructor
GradeSystem::GradeSystem() : subjects(), students() {}

// Add a student
void GradeSystem::addStudent(const Student &student) {
    students.push_back(student);
}

// Remove a student by name
void GradeSystem::removeStudent(const std::string &name) {
    students.erase(std::remove_if(students.begin(), students.end(),
                                  [&](const Student &s) { return s.getName() == name; }),
                   students.end());
}

// Add a subject
void GradeSystem::addSubject(const std::string &subject) {
    subjects.push_back(subject);
    for (Student &student : students) {
        std::vector<int> grades = student.getGrades();
        grades.push_back(0); // Default grade for new subject
        student.setGrades(grades);
    }
}

// Display all grades
void GradeSystem::showGrades() const {
    std::cout << "\nDisplaying all grades:\n";
    std::cout << "Name\t";
    for (const std::string &subject : subjects) {
        std::cout << subject << "\t";
    }
    std::cout << "\n";

    for (const Student &student : students) {
        std::cout << student.getName() << "\t";
        for (int grade : student.getGrades()) {
            std::cout << grade << "\t";
        }
        std::cout << "\n";
    }
}

// Calculate subject average
void GradeSystem::calculateSubjectAverage() const {
    for (size_t i = 0; i < subjects.size(); i++) {
        float sum = 0;
        for (const Student &student : students) {
            if (i < student.getGrades().size()) {
                sum += student.getGrades()[i];
            }
        }
        float average = students.empty() ? 0.0f : sum / students.size();
        std::cout << "Average for " << subjects[i] << ": " << average << "\n";
    }
}

// Load grades
void GradeSystem::loadGrades(){
    std::string file_path = create_csv_path();
    cout << "Attempting to open file at: " << file_path << endl;

    ifstream inFile(file_path);
    if(!inFile){
        cerr << "Error opening file for reading" << endl;
        return;
    }

    
    string line;
    size_t row = 0;

    subjects.clear();
    students.clear();

    // Read subjects (first row)
    if(getline(inFile, line)){
        stringstream ss(line);
        string cell;

        // Skip the "Name" header
        getline(ss, cell, ','); 
        while(getline(ss, cell, ',')){
            subjects.push_back(cell);
        }
    }

    // Read student names and grades
    while(getline(inFile, line)){
        stringstream ss(line);
        string cell;

        // Read student name
        if(!getline(ss, cell, ',')) continue;
            std::string studentName = cell;

        // Read grades
        std::vector<int> studentGrades;
        while(getline(ss, cell, ',')){
            studentGrades.push_back(std::stoi(cell)); // Convert string to int
        }
        
        // Create a Student object and add it to the students vector
        students.emplace_back(studentName, studentGrades);
    }

    inFile.close();
    std::cout << "Grades successfully loaded from: " << file_path << std::endl;
}
// Export grades
void GradeSystem::exportGrades() const{
    string file_path = create_csv_path();
    cout << "Exporting grades to: " << file_path << endl;

    ofstream outFile(file_path);
    if(!outFile){
        cerr << "Error opening file for writing." << endl;
        return;
    }

    // Write header row (subjects)
    outFile << "Name";
    for(const string &subject : subjects){
        outFile << "," << subject;
    }
    outFile << endl;

    // Write student names and their grades
    for(const Student &student : students){
        outFile << student.getName(); // Student name
        for (int grade : student.getGrades()){
            outFile << "," << grade; // Grades
        }
        outFile << endl;
    }

    outFile.close();
    std::cout << "Grades successfully exported to: " << file_path << std::endl;
}



