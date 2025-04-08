#ifndef USER_H
#define USER_H

#include <string>


/*
User class represents indivisual user such as admin and student with their names, associated grades and login/logout method.
Attributes:
    std::string name: the name of the user
    std::string password: the password of the user

Functions: 
    Log-in
    reset a password
*/


class User {
protected:
    std::string name;
    std::string password; 

public:
    // Constructor
    User(const std::string &name, const std::string &password);
    virtual ~User() = default;

    // Getters and Setters
    std::string getName() const;
    void setName(const std::string &newName);

    std::string getPassword() const;
    void setPassword(const std::string &newPassword);

    void resetPassword();

    virtual bool checkPassword(const std::string& input) const {
        return input == password;
    }

    // Pure virtual for polymorphism
    virtual void displayRole() const = 0;
};

#endif
