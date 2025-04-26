# About 
This note summarizes my hands-on experience in CMake. 

| Tool | Version |
|--------|----------------------|
| CMake      | 4.0.1               |
| Laptop      | Windows 10          |
| Code Editor  | Visual Studio Code |
| Compiler  | g++ (Rev6, Built by MSYS2 project) 13.1.0 | 


## What is CMake?
CMake is an open source that provides tools such as building, testing and packaging software. It enables you to control the software compilation process with simple independent configuration files. Unlike any other cross-platform systems, it can be used in conjunction with the native build environment. [^1]

Cmake contains the following three commnad-line tools: 
- cmake: to generate compiler-independent build instruction
- ctest: to detect and run tests
- cpack: to pack the software project into convenient installers
[^3]

## Merits about CMake
1. Single source builds on multiple platforms  
Developers are allowed to describe how to build simple and very complicated software systems with a single set of input files. This can be employed to build the software on multiple platforms from Android to iOS to Windows, macOS, and Linux, not needing to maintain a build script for each platform. It can generage a native build file for each platform. [^4] [^5]

2. Out-of-source builds  
CMake achieves out-of-source builds and gives the ability to have multiple build trees per source tree. [^5] This makes it possible to have another source file and makes developers organize a build folder more easily. [^4]

3. Target-centric approach  
Developers are allowed the build to be specified as a set of targets (executables, libraries, custom commands). Each target defines what other targets it depends on directly. After that, CMake performs the build in the correct order and includes transitive link targets. [^5]

4. Good combination with CI/CD  
CMake works well with CI/CD, providing a clean build environment where developer can build a project with CMake set files. This enables to build, test and deploy C++ application automatically. [^4]

5. Configurable build types  
CMake makes it easy to configure different build types such as debug and release. It allows compiler flags to be specified, facilitating debugging capabilities and performance optimisation. [^4]

6. Test support  
CMake is integrated with a testing tool called CTest, which helps manage test suites within the CMake configured build environment. This allows regression testing to be easily performed. [^4]

## Set up
1. Install CMake
Installer: https://cmake.org/download/  
Since I use windows 10, I chose Windows x64 ZIP.  
If you haven't installed a compiler(g++) and make.exe, please install them as well.

2. Extract the downloaed foder and move it to `Program Files`.

3. Set an environment path   
Path: C:\Program Files\cmake-4.0.1\bin

4. Install CMake Tools from Visual Studio Code extention.  

5. Add CMakeLists.txt
```
cmake_minimum_required(VERSION 3.10)
project(StudentGradeSystem VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files if you have any header files without this project
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

| Command | Description | Example usage |
|--------|----------------------| ----- |
| set(CMAKE_CXX_STANDARD 17)      | C++ 17 is used as standard              | set(CMAKE_CXX_STANDARD XX) |
| set(CMAKE_CXX_STANDARD_REQUIRED True)      | The standard becomes mandatory      | |
| include_directories(include)      | Add include directory              | |
| add_executable(StudentGradeSystem ${SOURCES})      | Adds the executable, the first argument is the name of the executable file    | |


6. Add CMakePresets.json
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

＊`generator` value is based on your compiler. In my case, `MSYS Makefiles` is set as I use "GCC 13.1.0 x86_64-w64-mingw32 (ucrt64)"


## Build and Execute the program
After configuring your project, you're ready to build. Open the Command Palette (Ctrl+Shift+P) and run the CMake: Build command, or select the Build button from the status bar.  
![image](https://github.com/user-attachments/assets/0702c9f4-a852-4d69-8d3e-1ee793745793)  



Reference:  
[^1]: about Software Development with CMake: https://cmake.org/about/  
[^2]: Why CMake?: https://cmake.org/cmake/help/book/mastering-cmake/chapter/Why%20CMake.html  
[^3]: Introduce to Cmake: https://dev.to/iamdeb25/introduction-to-cmake-26nk  
[^4]: CMakeとVisual Studio Code：C++開発のための強力なコンビ: https://note.com/codestudy_bymone/n/nb45dfc165335  
[^5]: CMake: The Standard Build System: https://cmake.org/features/  

