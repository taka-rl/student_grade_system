#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string name;

public:
    // Constructor
    User(const std::string& name);
    virtual ~User() = default;

    // Getters and Setters
    std::string getName() const;
    void setName(const std::string &newName);
   
    // Pure virtual for polymorphism
    virtual void displayRole() const = 0;
};

#endif
