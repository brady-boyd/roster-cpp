// student.cpp
#pragma once
#include "student.h"
#include <iostream>
#include "degree.h"
#include "roster.h"

// constructor for Student class
Student::Student(
    std::string studentID,
    std::string firstName,
    std::string lastName,
    std::string emailAddress,
    int age,
    int daysInCourse[],
    DegreeProgram degreeProgram
) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

// getters
std::string Student::getStudentID() {
    return studentID;
}

std::string Student::getFirstName() {
    return firstName;
}

std::string Student::getLastName() {
    return lastName;
}

std::string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int* Student::getDaysInCourse() {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

// setters
void Student::setStudentID(std::string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// prints specified student's data
void Student::print() {
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Email Address: " << emailAddress << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Days In Course: " << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << std::endl;
    std::cout << "Degree Program: ";
    switch (degreeProgram) {
    case SECURITY:
        std::cout << "SECURITY" << std::endl;
        break;
    case NETWORK:
        std::cout << "NETWORK" << std::endl;
        break;
    case SOFTWARE:
        std::cout << "SOFTWARE" << std::endl;
        break;
    default:
        std::cout << "Invalid Degree Program" << std::endl;
    }
}

