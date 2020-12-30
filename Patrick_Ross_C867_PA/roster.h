#pragma once 

#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;


const static int numStudents{ 5 };

const static string studentData[numStudents]{
    
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Patrick,Ross,Pross17@wgu.edu,38,12,59,22,SOFTWARE"
};

class Roster {
public:
    int lastArrayIndex;
    int maxSize;
    void parseAdd(string dataRow);
    void printAll();
    bool removeStudent(string studentId);
    void printAvgNumDays(string studentId);
    void printInvalidEmail();
    void printByDegreeProgram(Degree degrees);

    Student** classRosterArray;
    Roster();
    Roster(int maxSize);
    ~Roster();

    //Adds Formating Inbetween Data Output
    void format() {
        cout << "__________________________________________________________";
        cout << "__________________________________________________________" << endl;
        cout << endl;
    }
};

#endif