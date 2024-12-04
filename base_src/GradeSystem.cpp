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

// Remove a subject
void GradeSystem::removeSubject(const std::string &subject){
    // Find the subject index in the subjects vector
    auto it = std::find(subjects.begin(), subjects.end(), subject);
    if(it == subjects.end()){
        std::cerr << "Subject " << subject << " not found.\n";
        return;
    }

    // Calculate the index of the subject to remove
    size_t subjectIdx = std::distance(subjects.begin(), it);

    // Remove the subject from the subjects vector
    subjects.erase(it);

    // Remove the corresponding grade from each student
    for(Student &student : students){
        std::vector<int> grades = student.getGrades();

        // Check if the student has grades for this subject
        if(subjectIdx < grades.size()){
            grades.erase(grades.begin() + subjectIdx);
        }

        // Update the student's grades
        student.setGrades(grades);
    }

    cout << "Subject " << subject << " and corresponding grades removed successfully.\n";
    
}

// Display all grades
void GradeSystem::showGrades() const {
    cout << "\nDisplaying all grades:\n";
    cout << "Name\t";
    for (const std::string &subject : subjects) {
        cout << subject << "\t";
    }
    cout << "\n";

    for (const Student &student : students) {
        cout << student.getName() << "\t";
        for (int grade : student.getGrades()) {
            cout << grade << "\t";
        }
        cout << "\n";
    }
}

// Calculate subject average grade
void GradeSystem::calculateSubjectAverage() const {
    for (size_t i = 0; i < subjects.size(); i++) {
        float sum = 0;
        for (const Student &student : students) {
            if (i < student.getGrades().size()) {
                sum += student.getGrades()[i];
            }
        }
        float average = students.empty() ? 0.0f : sum / students.size();
        cout << "Average for " << subjects[i] << ": " << average << "\n";
    }
}

// Calculate student average grade
void GradeSystem::calculateStudentAverages() const {
    cout << "\nStudent Averages: \n";
    for(const Student &student : students){
        cout << student.getName() << ": " << student.calculateAverage() << "\n";
    }
}

// Calculate GPA
void GradeSystem::calculateGpa(const int scale) const{
    /*
    Converted to any scales
    Converted GPA = Original grade points / Original scale * New scale
    In this grade systems, the original scale is 5.0
    Ex: if the new scale is 4
    Converted GPA = (Original grade points / 5) * 4
    */
    cout << "\nStudent GPA on scale of " << scale << std::endl;
    for(const Student &student : students){
        cout << student.getName() << ": " << (student.calculateAverage() / 5) * scale << "\n";
    }
} 

// Rank students by average grades
void GradeSystem::displayRank() const{
    // Define the pair vector
    std::vector<std::pair<std::string, float>> studentRanks;
    
    // Assign the student name and the calculated average grade
    for(const Student &student : students){
        studentRanks.emplace_back(student.getName(), student.calculateAverage());
    }

    // Sort students by average grades in descending order
    std::sort(studentRanks.begin(), studentRanks.end(), 
                [](const auto &a, const auto &b){
                    return a.second > b.second;
            });

    cout << "\nStudent Rankings:\n";
    for(size_t i=0; i<studentRanks.size(); ++i){
        cout << i + 1 << ". " << studentRanks[i].first << " - Average: " << studentRanks[i].second << "\n";
    }
}

// Load grades
void GradeSystem::loadGrades(){
    string file_path = create_csv_path();
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
            string studentName = cell;

        // Read grades
        std::vector<int> studentGrades;
        while(getline(ss, cell, ',')){
            studentGrades.push_back(std::stoi(cell)); // Convert string to int
        }
        
        // Create a Student object and add it to the students vector
        students.emplace_back(studentName, studentGrades);
    }

    inFile.close();
    cout << "Grades successfully loaded from: " << file_path << endl;
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
    cout << "Grades successfully exported to: " << file_path << endl;
}