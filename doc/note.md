# Note
Everything that I have learned about C++ through this project is written here.

## Range-Based for loop
It constructs a for loop which must execute through a range defined as anything that you can iterate through, for example, std::vector, or any other C++ Standard Library sequence whose range is defined by a begin() and end().
https://learn.microsoft.com/en-us/cpp/cpp/range-based-for-statement-cpp?view=msvc-170

Since C++ 11
It executes a for loop over a range
https://en.cppreference.com/w/cpp/language/range-for

    for(range_declaration : range_expression ){
        Loop Statement
    }

Ex:
```
// the initializer may be a braced-init-list
for (int n : { 0, 1, 2, 3, 4, 5 })
    cout << n << ' ';
    cout << '\n';
    -> 0 1 2 3 4 5
// Iterating over array
int a[] = { 0, 1, 2, 3, 4, 5 };
for (int n : a)
    cout << n << ' ';
    cout << '\n';
    -> 0 1 2 3 4 5
    https://www.geeksforgeeks.org/range-based-loop-c/
```

Another Ex:  
 ```
for(const Student &student : students){
    studentRanks.emplace_back(student.getName(), student.calculateAverage());
}
```

const:  
    use if you don't intend to change the Student objects while Iterating. 
    If you want to return &student, you can't write like "for(const Student &student : students){" because this function returns non-const User*.
    This function returns pointer to actual object(student in this case).    
            
&(Reference):  
use if you want to avoid copying each Student object. 
without &, each iteration would involve creating a copy of the Student object, which is unnecessary overhead in this case.  
https://www.programiz.com/cpp-programming/ranged-for-loop
    
```
User* GradeSystem::authenticate(){
        for(Student &student : students){
            if(student.getName() == name){
                return &student;
            }
        }
    }
```

## auto
auto directly tells the compiler to use the initialization expression of a declared variable, or lambda expression parameter, to deduce its type.
It is recommneded to use auto for most situations decause of the following merits.
- Robustness: If the expression's type is changed including when a function return type is changed, It just works.
- Performance: This ensures that there's no conversion.
- Usability: Don't need to worry about type name spelling difficulties and typos.
- Efficiency: Your coding can be more efficient.  

https://learn.microsoft.com/en-us/cpp/cpp/auto-cpp?view=msvc-170


## push_back() and emplace_back()
push_back() and emplace_back() are two ways of inserting an element in a vector. 
push_back() is used to insert elements in a vector from the end of the container. 
emplace_back() uses parameterized constructor and allocates it into a different memory, then passing it to the copy constructor, which will insert it into the vector.  
https://www.geeksforgeeks.org/push_back-vs-emplace_back-in-cpp-stl-vectors/

Use push_back() when you have an exisiting temporary object that you want to move into your vector.
Use emplace_back() when you create a new temporary object. Instead of creating that temporary object, pass the object's constructor arguments directly to emplace_back().  
https://andreasfertig.com/blog/2023/04/push_back-vs-emplace_back-when-to-use-what/


## std::function
### std::pair
It is a class template that provides a way to store two heterogeneous objects as a single unit. A pair is a specific case of a std::tuple with two elements.  
https://en.cppreference.com/w/cpp/utility/pair

It is used to combine together two values that may be of different data types.
It is used if we want to store tuples.
The first element is referenced as 'first', and the second element as 'second' and the order is fixed. (first, second)
We use variable name followed by dot operator with the keyword such as 'first' or 'second'.  
https://www.geeksforgeeks.org/pair-in-cpp-stl/

```
std::pair<datatype1, datatypes2> variable name;
where: 
    datatype1: data type of the first element
    datatype2: data type of the second element
    variable name: Name assinged to the pair
```
Other link: https://www.programming-books.io/essential/cpp/stdpair-db03800f1091419fbb8be6357b79b0ee#15fe6e2e-86f8-45cb-8286-e05453907800

### std::map
Is is a class template provided by Standard Library, and is a sorted associative container that includes key-value pairs with unique keys.
To use it,  
```
define #include <map>
``` 
https://en.cppreference.com/w/cpp/container/map
https://learn.microsoft.com/en-us/cpp/standard-library/map-class?view=msvc-170
```
std::map<datatype, datatype> variable name;
```

### std::find and std::find_if
std::find returns an iterator pointing to the first occurrence of a specified value in a data range. If the value is not found then it returns the iterator pointing to the end of the data range.
Syntax: std::find(iterator start, iterator end, target value);
https://www.w3schools.com/cpp/ref_algorithm_find.asp

std::find_if returns an iterator to the first element in the range [first, last) for which pred(Unary Function) returns true. If no such element is found, the function returns last.
Syntax: std::find_if(iterator start, iterator end, target value)
https://www.w3schools.com/cpp/ref_algorithm_find_if.asp


### lambda expression:
It is used often with algorithms like find_if.
```
Syntax: [capture-clause] (parameters) -> return-type{
    // definition
}
```
For example:
```
auto studentIt = std::find_if(students.begin(), students.end(), [&](const Student &s){
    return s.getName() == studentName;
});

Capture Clause:
    [&]: capture all external variables by reference.
    [=]: capture all external variables by value.
    [a, &b]: capture ‘a’ by value and ‘b’ by reference.
```

## Function
### Function argument
Function argument: https://www.quantstart.com/articles/Passing-By-Reference-To-Const-in-C/  
There are three different ways to pass to a function. They are respectively by value, by reference and by pointer.

Example function to be used.
``` 
Consider a norm function which calculates the Euclidean norm of a vector of double values. 
The function returns one double precision value ("the norm") and takes the vector as a parameter. The following code shows the vector being passed by value:

double euclid_norm(vector<double> my_vector);
```
#### Passing by Value:
Copies the object. Modification does not affect the original.

When a function receives an object (or built-in type) by value, the underlying object is copied using its copy constructor. 
The new object has additional memory allocated to it and all values and sub-objects are copied and stored separately. 
If the object passed is a built-in type such as an int or double value then the copying process is cheap and will often not impact performance. 
However if the passed object includes a lot of stored values, such as a vector or matrix then the copying process will be significant in terms of both storage and CPU cycles.

#### Passing by Reference:
No copy. It modifies the original object directly.

When a function reveives an object (or built-in type) by reference, the underlying object is not copied. The memory address of the object itself gives the function. 
This saves both memory and CPU cycles as no new memory is allocated and no (expensive) copy constructors are being called. It is a much more efficient operation.
If the function being passed the object now modifies the object in any way, the original object will reflect those modifications, rather than a copy of the object. 
In some instances this is exactly what is intended. In other situations this may not be the desired behaviour. Once again there is the possibility of bugs! 
In particular the vector norm function as described above should not be able to modify the passed vector object.
            
```
double euclid_norm(vector<double>& my_vector);
```

#### Passing by Reference to Const:
No copy and does not allow modification(safe and efficient). 

In order to solve the problem of not copying AND not modifying the underlying data a technique known as passing by reference to const is used. 
This is similar to passing by reference except that we mark the my_vector parameter as a const object. 
This tells euclid_norm not to modify my_vector within its own scope:
```            
double euclid_norm(const vector<double>& my_vector);
```
  
The const keyword marks my_vector as non-modifiable, while the reference symbol (&) states that it should not be copied. 
Nearly all instances of mathematical "read only" functions should be prefixed in this manner. 
Not only is the client interface clearer, but it is highly efficient and will not introduce data overwriting bugs. 
The only exception to this is when passing built-in types. The copying of such data is inexpensive and thus you can simply pass by value.

## OOP
OOP(Object-Oriented Programming): https://www.w3schools.com/cpp/cpp_oop.asp
The purpose of OOP is to create objects that contain both data and functions.
These are advantages over procedure programming.
- OOP is faster and easier to execute
- OOP provides a clear structure for the programs
- OOP keeps the C++ code DRY "Don't Repeat Yourself", and makes the code easier to maintain, modify and debug.
- It is possible that OOP creates full reusable applications with less code and shorter development time.
The two main aspects of OOP are classes and objects.
Example:
    class: Fruit
    object: Apple, Banana, Mango
So a class is a template for objects and an object is an instance of a class.

### C++ Classes/Objects: https://www.w3schools.com/cpp/cpp_classes.asp
C++ is associated with classes and objects as well as its attributes and methods.
Example:
Car: object
The car has attributes such as weight, color, brand and so on.
The car has methods like drive, brake and so on.
Attributes and methods are fundamentally variables and functions, belonging to the class. They are referred to as "class members".

### Constructors: https://www.w3schools.com/cpp/cpp_constructors.asp
A constructor in C++ is a special method. It is automatically called when an object of a class is created.

### private/protected/public: https://www.w3schools.com/cpp/cpp_access_specifiers.asp  

| specifiers | description |
|--------|----------------------|
| public      | members are accessible from outside the class               |
| private      | members cannot be accessed (or viewed) from outside the class. Members can be accessed from friend classes.          |
| protected  | members cannot be accessed from outside the class, however, they can be accessed in inherited classes. |

It is considered good practice to declare your class attributes as private (as often as you can). This will reduce the possibility of yourself (or others) to mess up the code.  

The difference between private and protected:
| specifiers | Who can access it? | Use case | 
|--------|----------------------|-----|
| private   | Only the class itself and friend classes | Hide internal implementation details |
| protected | The class itself and any derived(inherited) classes | Share core data with subclasses while still hiding it from the outside |

Example1:  
`Admin` and `Student` class need to access members of User directly using getter and setter.  
You don't want unrelated external code to access them directly.  
-> So `protected` makes sense.  
You should use `protected` when:
- You know inheriting classes need access.
- But you still want to hide from non-related classes.

```
class User {
protected:
    std::string name;
    std::string password; 
public:    
    // Getters and Setters
    std::string getName() const;
    void setName(const std::string &newName);

class Admin : public User {
public:

class Student : public User {
private:
    std::vector<int> grades;
```
Exampe2:  
`grades` should only be accessed/modified through public methods like `getGrades()` and `setGrades()`. Even derived class shouldn't access grades directly. This enforce tight encapsulation.
Use `private` when:
- You want to fully control access via public interfaces.
- The data is internal to the class only.


```
class Student : public User {
private:
    std::vector<int> grades;
// Getters and Setters
    std::vector<int> Student::getGrades() const { return grades; }
    void Student::setGrades(const std::vector<int> &newGrades) { grades = newGrades; }
```

Example3:  
These are internal structures -> No class(except Admin) should touch them directly.  
You give `Admin` selective access using `friend class Admin;` which is fine for controlled privilege elevation.  
Use `private + friend` when  
- You want to restrict access to one or two trusted classes
- You're exposing internals intentionally in a controlled way.


```        
class GradeSystem {
    friend class Admin;  // Only Admin can access private/protected parts.
private:
    std::vector<std::string> subjects;
    std::vector<Student> students;
    std::vector<Admin> admins;    
```

### Encapsulation: https://www.w3schools.com/cpp/cpp_encapsulation.asp
Encapsulation ensures that "sensitive" data is hidden from users. In order to achieve this, you must declare class variables/attributes as private(cannot be accessed from outside the class).
If you want others to read or modify the value of a private member, you can provide public get and set methods.
Example:
```
class Student : public User {
private:
    std::vector<int> grades;

public:
    // Getters and Setters
    std::vector<int> Student::getGrades() const { return grades; }
    void Student::setGrades(const std::vector<int> &newGrades) { grades = newGrades; }
```
It is deemed good practice to define your class attributes as private. Encapsulation makes sure better control of your data as you(or others) can change one part of the code without affecting other parts.
Encapsulation increases security of data.


### Inheritance: https://www.w3schools.com/cpp/cpp_inheritance.asp
It is possible to inherit attributes and methods from one class to another in C++. 
Inheritance is useful for code reusability: reuse attributes and methods of an exisiting class when you create a new class.

- base class(parent class): the class being inherited from  
- derived class(child class): the class that inherits from another   class  

Example:
```
- parent class
class User {
protected:
    std::string name;
    std::string password; 
public:

- child class
class Admin : public User {
public:
```

### Polymorphism: https://www.w3schools.com/cpp/cpp_polymorphism.asp
Polymorphism means "many forms". It happens when we have many classes that are related to each other by inheritance.
Inheritance allows us to inherit attributes and methods from another class.
Polymorphism uses those methods to perform different tasks, allowing us to perform a single action in different ways.  
Example:  
Think about a base class called Animal and it has a method called animalSound().
Derived classes of Animals could be Cats, Dogs, and so on. They also have thier own implementation of an animal sound(the cat meows etc.).   
```
// Base class
class Animal {
public:
    void animalSound() {
        cout << "The animal makes a sound \n";
        }
};

// Derived class
class Cat : public Animal {
public:
    void animalSound() {
        cout << "The cat says: meows \n";
    }
};

// Derived class
class Dog : public Animal {
public:
    void animalSound() {
        cout << "The dog says: bow wow \n";
    }
};

int main() {
    Animal myAnimal;
    Cat myCat;
    Dog myDog;

    myAnimal.animalSound(); -> "The animal makes a sound \n"
     // Cat and Dog objects override the animalSound() method. 
    myCat.animalSound(); -> "The cat says: meows \n"
    myDog.animalSound(); -> "The dog says: bow wow \n"
    return 0;
}
```

### forward declarations: https://www.geeksforgeeks.org/what-are-forward-declarations-in-c/
It refers to the beforehand declaration of the class, variable, function, etc prior to its usage.
 In this example, class Admin is defined beforehand, and it's used for `std::vector<Admin> admins;`.
Example:  
```
class Admin;  // Forward declaration

class GradeSystem {
    friend class Admin;  // Only Admin can access private/protected parts.
private:
    std::vector<std::string> subjects;
    std::vector<Student> students;
    std::vector<Admin> admins;
```

### friend class: https://www.geeksforgeeks.org/friend-class-function-cpp/
It can access private and protected memobers of other classes in which it is declared as a friend. 
In this example, Admin class can access private/protected of GradeSystem.  
Example:  
```
class Admin;  // Forward declaration

class GradeSystem {
    friend class Admin;  // Only Admin can access private/protected parts.
private:
    std::vector<std::string> subjects;
    std::vector<Student> students;
    std::vector<Admin> admins;
```

## virtual function: https://www.geeksforgeeks.org/virtual-function-cpp/
Virtual function (virtual methods) is a member function that is declared within a base class and is re-defined(overriden) by a derived class.
Referring to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the method.
- Virtual functions make sure that the correct function is called for an object, regarding the type of reference (or pointer) used for the function call.
- They are mainly used to achieve Runtime polymorphism.
- Functions are declared with a virtual keyword in a base class.
- The resolving of a function call is done at runtime.

## Pure Virtual Function
A virtual function is called a pure virtual function if it does not have any implementation and is assigned = 0. A class that includes a pure virtual function is called an abstract class.



Example:  
```
class User {
public:
    // Constructor
    User(const std::string &name, const std::string &password);
    virtual ~User() = default;

    virtual bool checkPassword(const std::string& input) const {
        return input == password;
    }

    // Pure virtual for polymorphism
    virtual void displayRole() const = 0;
};

class Admin : public User {
public:
    // Constructor
    Admin(const std::string &name, const std::string &password);
    
    void Student::displayRole() const {
        std::cout << "Role: Student\n";
    }

class Student : public User {
public:
void Student::displayRole() const {
    std::cout << "Role: Student\n";
}


```

`virtual void displayRole() const = 0;`
- Every subclass (Admin and Student) must implement it.  
- The User class become an abstract base class(you can't instantiate `User` directly).
- This enforce interface-based design.


```
virtual bool checkPassword(const std::string& input) const {
    return input == password;
}
```
This is a regular virtual function with a default implementation. This allows derived classes to: 
- Use it as-is
- Override it with custom logic. 

Use virtual when: 
- You expect subclasses to override a behavior.
- You want to call methods via base class pointers like `User* user = new Student(...))`  

Use = 0 (pure virtual) when:
- You want to force subclasses to implement the method.


| Keyword | Description |
|--------|----------------------|
| `virtual`      | Enables runtime polymorphism (can override in child classes) |
| `virtual ... = 0`      | Pure virtual = abstract class; must be implemented in derived classes  |
| `~User() = default;`  | Declares a virtual destructor to ensure correct cleanup of derived classes via base pointer (important) |
