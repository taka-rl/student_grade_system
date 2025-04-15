# About 
This note summarizes my hands-on experience in CMake. 

| Tool | Version |
|--------|----------------------|
| CMake      | 4.0.1               |
| Laptop      | Windows 10          |
| Code Editor  | Visual Studio Code |
| Compiler  | g++ (Rev6, Built by MSYS2 project) 13.1.0 | 


## What is CMake?

## Pros and Cons about CMake

## Set up
1. Install CMake
Installer: https://cmake.org/download/  
Since I use windows 10, I chose Windows x64 ZIP.

2. Extract the downloaed foder and move it to Program Files.

3. Set an environment path   
Path: C:\Program Files\cmake-4.0.1\bin

4. Install CMake Tools from Visual Studio Code extention.  

4. Add CMakeLists.txt
```
cmake_minimum_required(VERSION 3.10)
project(StudentGradeSystem VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(include)

# Add source files
set(SOURCES
    ./src/main.cpp
    ./src/GradeSystem.cpp
    ./src/Student.cpp
    ./src/Admin.cpp
    ./src/User.cpp
    ./src/utilities.cpp
)

# Create executable
add_executable(StudentGradeSystem ${SOURCES})

# Enable testing (optional)
include(CTest)
enable_testing()

```


5. Add CMakePresets.json
```
{
    "version": 8,
    "configurePresets": [
        {
            "name": "student_grade_system",
            "displayName": "GCC 13.1.0 x86_64-w64-mingw32 (ucrt64)",
            "generator": "MSYS Makefiles",
            "binaryDir": "${sourceDir}/out/build/${presetName}",
            "cacheVariables": {
                "CMAKE_INSTALL_PREFIX": "${sourceDir}/out/install/${presetName}",
                "CMAKE_C_COMPILER": "Set the compile path for C",
                "CMAKE_MAKE_PROGRAM": "Set the compile path for make.exe",
                "CMAKE_CXX_COMPILER": "Set the compile path for C++",
                "CMAKE_BUILD_TYPE": "Debug"
            }
        }
    ]
}
```


## Build and Execute the program
After configuring your project, you're ready to build. Open the Command Palette (Ctrl+Shift+P) and run the CMake: Build command, or select the Build button from the status bar.


Reference:
C++ in VS Code: Building your Code with CMake: https://youtu.be/_BWU5mWqVA4?feature=shared
CMake Tutorial: https://cmake.org/cmake/help/latest/guide/tutorial/index.html#
Create a CMake hello world project with CMake Quick Start: https://code.visualstudio.com/docs/cpp/cmake-quickstart
