// student.h
#pragma once
#include <string>
#include "degree.h"

// Student class declaration
class Student {
public:
    // constructor
    Student(
        std::string studentID,
        std::string firstName,
        std::string lastName,
        std::string emailAddress,
        int age,
        int daysInCourse[],
        DegreeProgram degreeProgram
    );

    // getters
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();

    // setters
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // print method for individual student
    void print();

private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
};
