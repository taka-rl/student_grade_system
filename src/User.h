#ifndef USER_H
#define USER_H

#include <string>

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

    virtual bool checkPassword(const std::string& input) const {
        return input == password;
    }

    // Pure virtual for polymorphism
    virtual void displayRole() const = 0;
};

#endif
