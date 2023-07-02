// main.cpp
#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main() {
    // Student data from which populates the roster
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brady,Boyd,bboy102@wgu.edu,33,37,58,19,SOFTWARE"};
    // Creation of classRoster instance
    Roster classRoster;

    for (int i = 0; i < 5; i++) {
        string data = studentData[i];
        int nextComma = data.find(',');
        string studentID = data.substr(0, nextComma);
        data = data.substr(nextComma + 1);

        nextComma = data.find(',');
        string firstName = data.substr(0, nextComma);
        data = data.substr(nextComma + 1);

        nextComma = data.find(',');
        string lastName = data.substr(0, nextComma);
        data = data.substr(nextComma + 1);

        nextComma = data.find(',');
        string emailAddress = data.substr(0, nextComma);
        data = data.substr(nextComma + 1);

        nextComma = data.find(',');
        int age = stoi(data.substr(0, nextComma));
        data = data.substr(nextComma + 1);

        int daysInCourse[3];
        for (int j = 0; j < 3; j++) {
            nextComma = data.find(',');
            daysInCourse[j] = stoi(data.substr(0, nextComma));
            data = data.substr(nextComma + 1);
        }

        DegreeProgram degreeProgram;
        if (data == "SECURITY") {
            degreeProgram = SECURITY;
        }
        else if (data == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else {
            degreeProgram = SOFTWARE;
        }

        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
    }
    // Prints my course info, and the language used
    cout << "C867 Scripting and Programming Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 010912370 " << endl;
    cout << "Brady Boyd" << endl;
    cout << endl;
    // Prints all students in classRoster
    classRoster.print_all();
    cout << endl;
    // Prints invalid emails
    classRoster.printInvalidEmails();
    cout << endl;
    for (int i = 0; i <= classRoster.lastIndex; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
}
    cout << endl;
    // Prints all students in the SOFTWARE program
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    // Removes student A3 from classRoster
    classRoster.remove("A3");
    cout << "Student A3 has been removed via the remove() function." << endl;
    cout << endl;
    cout << "Here's the updated roster:" << endl;
    // Prints all students in classRoster after A3 is removed
    classRoster.print_all();
    cout << endl;
    // Removes student A3 from classRoster again but fails because A3 no longer exists
    classRoster.remove("A3");
    cout << endl;
    cout << "Desctructor has been implemented in the Roster class to free allocated memory." << endl;
    return 0;
}
