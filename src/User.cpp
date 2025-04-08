#include "User.h"
#include <iostream>
using namespace std;


// Constructor
User::User(const std::string &name, const std::string &password) : name(name), password(password){}

// Getters and Setters
std::string User::getName() const { return name; }
std::string User::getPassword() const { return password; }

void User::setName(const std::string &newName) { name = newName; }
void User::setPassword(const std::string &newPassword) { password = newPassword; }
void User::resetPassword(){
    std::string current, newPass;
    cout << "Enter current password: ";
    cin >> current;

    if(!checkPassword(current)){
        cout << "Incorrect password.\n";
        return;
    }
    cout << "Enter new password: ";
    cin >> newPass;
    setPassword(newPass);
    cout << "Password reset successfully.\n";
}
