---
title: "Computer Information Systems 23 - Homework 3"
author:  Cody Vig # Name and Email
output:
  pdf_document:
    toc: yes
    toc_depth: 3
---

# Problem 1

Consider the class `studentType`:

```cpp
class sutdentType: public personType
{ 
public:
    void print();
    void calculateGPA();
    void setID(long id);
    void setCourses(const string c[]);
    void setGrades(const char cG[], int noOfC);

    void getID();
    void getCourses(string c[], int noOfC);
    studentType(
        string fNmae = "", string lName = "", long id = -1, 
        sting *c = nullptr, char *cG = nullptr, int noOfC = 0
    )
}
```

## 1. Is this a concrete class? 

As writtes, yes, `studentType` is a concrete class. It does not have virtual functions, and as such there are no issues with instantiation. 

## 2. How would you change the definition of the class student so that the functions print and calculateGPA are pure virtual functions?

To make them virtual functions, we would need to add the `virtaul` modifier to their prototypes. To make them *pure* virtual functions, we need to remove all declarations of those functions and end their prototypes with `= 0`:
```cpp
virtual void print() = 0;
virtual void calculateGPA() = 0;
```

## 3. With this change, is studentType a concrete class? Can you create studentType objects?

By definition, the existence of at least one pure virtual function makes this class an abstract class, not a concrete one. As such, we cannot instantiate `studentType`, so we cannot create `studentType` objects.