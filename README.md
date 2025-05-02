# student_grade_system
Currently under development to meet the requirements. 
The purpose of this project is to **build a strong foundation of C++ knowledge and skills and deepen them**.

## Requirements
### Functional requirements:
    Introduce roles such as admin and student, ensuring that common functionalities and specific functionalities for both admin and student    
    add/remove students and subjects
    modify students' grade
    calculate GPA, 
    display indivisual average grades
    display all students' grades
    display ranking by all students' average grades
    display grade distributions
    load thier grade on CSV file
    export their grade on CSV file 
    generate a report as csv for the selected student by the admin(teachers), including the selected student name, its grades, GPA, and average grade
    add a user login/logout system
    add error handings
    allows users such as admin(teachers and students) to use the system through CUI interface, not GUI interface
    add a menu for admin(teachers) and students to use the system

### Non-functional requirements:
    Scalability: 
        The system shall support at least 1000 students and 200 subjects without significant degradation in performance.

    Readability:
        All code shall follow the C++ Core Guidelines. 
        Each class and function shall be documented with meaningful comments.
    
    Maintainability:
        The system shall be designed with a modular architecture to allow the addition of new features with minimal code changes.

    Error Handling:
        If the following errors happen, the system shall display an appropriate error message.
            preventing invalid login, error loading grade csv, removing students or subjects that don't exist, and duplicate entries for students or subjects, invalid grade values

    Security:
        Students must not access admin features.
        Passwords shall be hashed with SHA-256.

### Use cases
    Commons for both students and admin(teachers):
        user login/logout system
        reset a password
        calculate GPA, average grades
        load thier grade on CSV file
        load user data on CSV file
        export their grade to CSV file
        export user data to CSV file
        add error handings, preventing invalid login, error loading grade csv, removing students or subjects that don't exist, and duplicate entries for students or subjects

    students:
        display only their own grades such as GPA and average grade
        
    admin(teachers):
        modify student's grades
        add/remove students and subjects
        display their all grades
        display ranking by average grades
        display grade distributions
        generate a report as csv, including the specific student name, its grades, GPA, and average grade

## Folder structure
    ├── data                    # 
    |   ├── users.csv           # user data
    │   └── grades.csv          # student grade data
    ├── src                     # codes for student grade system
    │   ├── GradeSystem.cpp     # GradeSystem class
    │   ├── GradeSystem.h       # 
    │   ├── main.cpp            # 
    │   ├── Student.cpp         # 
    │   ├── Student.h           # 
    │   ├── utilities.cpp       # 
    │   └── utilities.h         # 
    ├── .gitignore
    ├── CMakeLists.txt
    ├── CMakePresets.json       
    └── README.md

## How to compile and execute
- without CMake
1. compile the program with the following command in terminal
    g++ "./src/main.cpp" "./src/GradeSystem.cpp" "./src/User.cpp" "./src/Admin.cpp" "./src/Student.cpp" "./src/utilities.cpp" -o "program"

2. execute program.exe 

- with CMake
After configuring your project, you're ready to build. Open the Command Palette (Ctrl+Shift+P) and run the CMake: Build command, or select the Build button from the status bar.

After the build, if student_grade_system.exe hasn't been made, run the following command in the terminal.
```
cmake --build out/build/student_grade_system
```

## Future development plan
- Integrate unit testing
- Learn Smart Pointers and apply it
- Consider GUI/CLI menu to improve user experience
- 
