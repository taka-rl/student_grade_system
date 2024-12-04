#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "utilities.h"
using namespace std;


void show_grades(const vector<vector<int>> &grades, const string *student_arr, const vector<string> &subjects_vec, size_t num_student, size_t num_subject){
    cout << "\nDisplaying all grades: " << endl;
    for(size_t i=0; i<num_student; i++){
        cout << student_arr[i] << ": ";
        for(size_t j=0; j<num_subject; j++){
            cout << subjects_vec[j] << "=" << grades[i][j] << " ";
        }
        cout << endl;
    }
}

void enter_grades(string *student_arr, size_t &num_student, size_t &num_subject, vector<string> &subjects_vec, vector<vector<int>> &grades){
    // Enter grades
    for(size_t  i=0; i<num_student; i++){
        for(size_t j=0; j<num_subject; j++){
            cout << "Enter grade between 1 and 5 for " << student_arr[i] << " in " << subjects_vec[j] << ":";
            cin >> grades[i][j];
        }
    }
}

void load_grades(string *student_arr, size_t &num_student, size_t &num_subject, std::vector<string> &subjects_vec, std::vector<std::vector<int>> &grades){
    // Prepare for reading grades from the csv file
    string file_path = create_csv_path();
    cout << "Attempting to open file at: " << file_path << endl;

    ifstream inFile(file_path);
    if(!inFile){
        cerr << "Error opening file for reading" << endl;
        return;
    }

    string line;
    size_t row = 0;

    // Read subjects (first row)
    if (getline(inFile, line)) {
        stringstream ss(line);
        string cell;
        subjects_vec.clear(); // Clear existing subjects
        getline(ss, cell, ','); // Skip the "Name" header
        while (getline(ss, cell, ',')) {
            subjects_vec.push_back(cell);
        }
    }

    // Read student names and grades
    while (getline(inFile, line) && row < num_student) {
        stringstream ss(line);
        string cell;

        // Read student name
        if (getline(ss, cell, ',')) {
            student_arr[row] = cell;
        }

        // Read grades
        size_t col = 0;
        while (getline(ss, cell, ',') && col < grades[row].size()) {
            grades[row][col] = stoi(cell); // Convert string to integer
            col++;
        }
        row++;
    }

    inFile.close();
}

void export_grades(const string *student_arr, size_t num_student, const vector<string> &subjects_vec, const vector<vector<int>> &grades) {
    string file_path = create_csv_path();

    cout << "Exporting grades to: " << file_path << endl;

    ofstream outFile(file_path);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    // Write header row (subjects)
    outFile << "Name";
    for (const string &subject : subjects_vec) {
        outFile << "," << subject;
    }
    outFile << endl;

    // Write each student's grades
    for (size_t i = 0; i < num_student; i++) {
        outFile << student_arr[i]; // Student name
        for (size_t j = 0; j < subjects_vec.size(); j++) {
            outFile << "," << grades[i][j]; // Grades
        }
        outFile << endl;
    }

    outFile.close();
    cout << "Grades successfully exported to grades.csv" << endl;
}

void update_grade(string *student_arr, size_t &num_student, size_t &num_subject, std::vector<string> &subjects_vec, std::vector<std::vector<int>> &grades){
    size_t select_student, select_subject;

    while (true){
        // Choose a student
        cout << "Enter a number cooresponding to the following students: " << endl;
        for(size_t i=0; i<num_student; i++){
            cout << "Student Number " << i  << ": " << student_arr[i] << endl;
        }
        cin >> select_student;
        
        // Choose a subject
        cout << "Enter a number cooresponding to the following subjects:  " << endl;
        for(size_t j=0; j<num_subject; j++){
            cout << "Subject Number " << j  << ": " << subjects_vec[j] << endl;
        }
        cin >> select_subject;

        // Make sure the input numbers
        if (select_student < num_student && select_subject < num_subject) {
            break;
        }
        cout << "Invalid selection, please try again." << endl;
    }

    // Update a grade
    int updated_grade;
    cout << "Enter the updated grade for " << student_arr[select_student] << " in " << subjects_vec[select_subject] << ": ";
    cin >> updated_grade;

    int *grade_ptr = &grades[select_student][select_subject];
    cout << "Grade before update: " << *grade_ptr << endl;
    *grade_ptr = updated_grade;
    cout << "Grade after update: " << *grade_ptr << endl;

}

void calculate_grade_average(string *student_arr, size_t &num_student, size_t &num_subject, vector<vector<int>> &grades){
    float ave = 0.0;
    cout << "\nDisplaying all average grades per student: " << endl;
    for(size_t i=0; i<num_student; i++){
        cout << student_arr[i] << ": ";
        for(size_t j=0; j<num_subject; j++){
            ave += grades[i][j];
        }
        ave = ave / num_subject;
        cout << "Average grade: " << ave << endl;
        ave = 0.0;
    }
}

void calculate_subject_average(size_t &num_student, size_t &num_subject, std::vector<string> &subjects_vec, std::vector<std::vector<int>> &grades){
    float ave = 0.0;
    cout << "\nDisplaying all average grades per subject: " << endl;
    for(size_t j=0; j<num_subject; j++){
        cout << subjects_vec[j] << ": ";
        for(size_t i=0; i<num_student; i++){
            ave += grades[i][j];
        }
        ave = ave / num_student;
        cout << "Average grade: " << ave << endl;
        ave = 0.0;
    }
}

void find_high_low_grades(){

}

void add_subject(){

}


int main(){
    // define the number of students and subjects
    size_t num_student = 5, num_subject = 6;

    // Dynamic array for students using pointer
    string *student_arr = new string[num_student]{"Tom", "Ken", "Marry", "Jesus", "Taka"};

    // define subjects in vector
    vector<string> subjects_vec{"Math", "English", "History", "Japanese", "Physics", "Chemistry"};
    vector<vector<int>> grades(num_student, vector<int>(num_subject, 0));


    // Enter grades or Load grades
    int select;
    std::cout << "Enter a number: 1: enter grades, 2: load grades, Default is 1: ";
    std::cin >> select;
    switch(select){
        case 1:
            enter_grades(student_arr, num_student, num_subject, subjects_vec, grades);
            break;
        case 2:
            load_grades(student_arr, num_student, num_subject, subjects_vec, grades);
            break;
        default: 
            enter_grades(student_arr, num_student, num_subject, subjects_vec, grades);
            break;
    }

    int act;
    while (true){
        cout << "Choose the action from 1 to 4: 1 to update an exisiting grade, 2 to calculate the average grade, 3 to find the highest and lowest grades, 4 to add a new subject, 5 to show grades, 6 to end: \n";
        cin >> act;

        switch(act){
            case 1:
                cout << "update an exisiting grade" << endl;
                update_grade(student_arr, num_student, num_subject, subjects_vec, grades);
                break;
            case 2:
                cout << "calculate the average grade" << endl;
                calculate_grade_average(student_arr, num_student, num_subject, grades);
                calculate_subject_average(num_student, num_subject, subjects_vec, grades);
                break;
            case 3:
                cout << "find the highest and lowest grades" << endl;
                find_high_low_grades();
                break;
            case 4:
                cout << "add a new subject" << endl;
                add_subject();
                break;
            case 5:
                cout << "show grades" << endl;
                show_grades(grades, student_arr, subjects_vec, num_student, num_subject);
                break;    
            case 6:
                cout << "end this program" << endl;
                break;
            default:
                cout << "Select from 1 to 4 " << endl;
                break;
        }
        if(act == 6){
            break;
        }
    }

    // export grades
    std::cout << "Would you like to update the grades? Enter a number: 1: Yes,  2: No, Default is 1: ";
    std::cin >> select;
    if(select == 1){
        export_grades(student_arr, num_student, subjects_vec, grades);
    }else{

    }

    // Free the dynamically allocated memory
    delete[] student_arr;
        
    return 0;
}