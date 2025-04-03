#include "User.h"

// Constructor
User::User(const std::string &name, const std::string &password) : name(name), password(password){}

// Getters and Setters
std::string User::getName() const { return name; }
std::string User::getPassword() const { return password; }

void User::setName(const std::string &newName) { name = newName; }
void User::setPassword(const std::string &newPassword) { password = newPassword; }

