#include "User.h"

// Constructor
User::User(const std::string& name) : name(name) {}

// Getters and Setters
std::string User::getName() const { return name; }

// std::string Student::getName() const { return name; }
void User::setName(const std::string &newName) { name = newName; }
