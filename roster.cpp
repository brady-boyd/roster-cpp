// roster.cpp
#pragma once
#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include <iomanip>
using namespace std;

// Roster class constructor
Roster::Roster() {
	lastIndex = -1;
	capacity = 5;
	for (int i = 0; i < capacity; i++) {
		classRosterArray[i] = nullptr;
	}
}

// Adds a student to the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	lastIndex++;
	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

// Prints all students in the roster
void Roster::print_all() {
	const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

	cout << "Student Roster:" << endl;
	for (int i = 0; i <= lastIndex; i++) {
		cout << classRosterArray[i]->getStudentID() << "\t"
			<< "First Name: " << setw(8) << left << classRosterArray[i]->getFirstName() << "\t"
			<< "Last Name: " << setw(8) << left << classRosterArray[i]->getLastName() << "\t"
			<< "Age: " << setw(3) << left << classRosterArray[i]->getAge() << "\t"
			<< "daysInCourse: {" << setw(2) << left << classRosterArray[i]->getDaysInCourse()[0] << ", "
			<< classRosterArray[i]->getDaysInCourse()[1] << ", "
			<< classRosterArray[i]->getDaysInCourse()[2] << "}\t"
			<< "Degree Program: " << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << endl;
	}


}

// Removes a student from the roster
void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (!found) {
		cout << "Student with ID " << studentID << " was not found." << endl;
	}
}

// Prints the average number of days in the three courses for a given student
void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			int* days = classRosterArray[i]->getDaysInCourse();
			cout << "The average number of days in the courses for student with ID " << studentID << " is " << (days[0] + days[1] + days[2]) / 3 << endl;
			break;
		}
	}
	if (!found) {
		cout << "Student with ID " << studentID << " was not found." << endl;
	}
}

// Prints invalid email addresses found in classRosterArray
void Roster::printInvalidEmails() {
	cout << "Invalid email addresses:" << endl;
	for (int i = 0; i <= lastIndex; i++) {
		string emailAddress = classRosterArray[i]->getEmailAddress();
		if (emailAddress.find("@") == string::npos ||
			emailAddress.find(".") == string::npos ||
			emailAddress.find(" ") != string::npos ||
			emailAddress.find("@.") != string::npos ||
			emailAddress.find(".@") != string::npos) {
			cout << emailAddress << endl;
		}
	}
}

// Prints students in a given degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Students in degree program " << degreeProgram << ":" << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

// Roster class destructor
Roster::~Roster() {
	for (int i = 0; i < lastIndex; i++) {
		delete classRosterArray[i];
	}
}