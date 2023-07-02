// roster.h
#pragma once
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

// Roster class declaration
class Roster {
public:
	Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	void print_all();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	int lastIndex;
	int capacity;
	Student* classRosterArray[5];
	~Roster();
};