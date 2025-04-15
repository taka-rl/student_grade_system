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
