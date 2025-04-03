#include <iostream>
#include <string>
#include <direct.h> 
using namespace std;


string get_current_path(){
    // Define a buffer 
    const size_t size = 1024;
    // Allocate a character array to store the directory path
    char buffer[size];
    string current_path;  
    // Call _getcwd to get the current working directory and store it in buffer
    if (getcwd(buffer, size) != NULL) {
        // print the current working directory
        cout << "Current working directory: " << buffer << endl;
    } 
    else {
        // If _getcwd returns NULL, print an error message
        cerr << "Error getting current working directory" << endl;
    }
    current_path = buffer;
    return current_path; 
}

string create_csv_path(const string filename){
    if(filename != "grades.csv" && filename != "users.csv"){
        cerr << "Set either grades.csv or users.csv as a filenmae" << endl;
        return "";
    }

    const string path = get_current_path();
    return path + "/data/" + filename;
}

