#include <iostream>
#include <string>
#include <iomanip>


#include "degree.h"
#include "roster.h"
#include "securitystudent.h"
#include "networkstudent.h"
#include "softwarestudent.h"
#include "student.h"

using namespace std;

//Constructor------------------------------------------------------------------------------------------------------------
Roster::Roster() {
    this->classRosterArray = nullptr;
    this->maxSize = 5;
    this->lastArrayIndex = -1;
}

Roster::Roster(int maxSize) {
    this->classRosterArray = new Student * [maxSize];
    this->maxSize = maxSize;
    this->lastArrayIndex = -1;
}

//Parse Student Data and Add to Class Roster----------------------------------------------------------------------------
void Roster::parseAdd(string dataRow) {
    if (lastArrayIndex < maxSize) {
        ++lastArrayIndex;
        int tempArrayHolder[Student::numDaysArraySize];

        if (dataRow[6] == 'n') {

            this->classRosterArray[lastArrayIndex] = new SecurityStudent();
            classRosterArray[lastArrayIndex]->setDegree(SECURITY);
        }

        else if (dataRow[4] == 'a') {

            this->classRosterArray[lastArrayIndex] = new SoftwareStudent();
            classRosterArray[lastArrayIndex]->setDegree(SOFTWARE);
        }

        else {

            this->classRosterArray[lastArrayIndex] = new NetworkStudent();
            classRosterArray[lastArrayIndex]->setDegree(NETWORK);
        }

        int rightHand = studentData[lastArrayIndex].find(",");
        classRosterArray[lastArrayIndex]->setStudentId(studentData[lastArrayIndex].substr(0, rightHand));

        int leftHand = rightHand + 1;
        rightHand = studentData[lastArrayIndex].find(",", leftHand);
        classRosterArray[lastArrayIndex]->setFirstName(studentData[lastArrayIndex].substr(leftHand, rightHand - leftHand));

        leftHand = rightHand + 1;
        rightHand = studentData[lastArrayIndex].find(",", leftHand);
        classRosterArray[lastArrayIndex]->setLastName(studentData[lastArrayIndex].substr(leftHand, rightHand - leftHand));

        leftHand = rightHand + 1;
        rightHand = studentData[lastArrayIndex].find(",", leftHand);
        classRosterArray[lastArrayIndex]->setEmail(studentData[lastArrayIndex].substr(leftHand, rightHand - leftHand));

        leftHand = rightHand + 1;
        rightHand = studentData[lastArrayIndex].find(",", leftHand);
        classRosterArray[lastArrayIndex]->setAge(studentData[lastArrayIndex].substr(leftHand, rightHand - leftHand));

        leftHand = rightHand + 1;
        rightHand = studentData[lastArrayIndex].find(",", leftHand);
        tempArrayHolder[0] = stod(studentData[lastArrayIndex].substr(leftHand, rightHand - leftHand));

        leftHand = rightHand + 1;
        rightHand = studentData[lastArrayIndex].find(",", leftHand);
        tempArrayHolder[1] = stod(studentData[lastArrayIndex].substr(leftHand, rightHand - leftHand));

        leftHand = rightHand + 1;
        rightHand = studentData[lastArrayIndex].find(",", leftHand);
        tempArrayHolder[2] = stod(studentData[lastArrayIndex].substr(leftHand, rightHand - leftHand));

        classRosterArray[lastArrayIndex]->setNumDays(tempArrayHolder);
    }
}

//Print All in Class Roster Array----------------------------------------------------
void Roster::printAll() {
    for (int i = 0; i <= this->lastArrayIndex; ++i) (this->classRosterArray)[i]->print();
}

//Remove a Student ID------------------------------------------------------------------
bool Roster::removeStudent(string studentId) {
    bool isFound = false;
    for (int i = 0; i <= lastArrayIndex; ++i) {
        if (this->classRosterArray[i]->getStudentId() == studentId) {
            isFound = true;
            Student* studentTemp = classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[lastArrayIndex];
            (classRosterArray[lastArrayIndex]) = studentTemp;
            lastArrayIndex--;
        }
    }
    cout << endl;

    if (!isFound) cout << "**Student with ID [" << studentId << "] was not found!**" << endl;

    return isFound;
}

//Remove Invalid Email Addresses ---------------------------------------------------------------
void Roster::printInvalidEmail() {
    cout << "Invalid Student Email Addresses: ";

    for (int i = 0; i < numStudents; ++i) {

        bool symbolSpace = false;
        bool symbolAt = false;
        bool symbolPeriod = false;

        string emailAddress = (*classRosterArray[i]).getEmailAddress();

        for (auto& x : emailAddress) {

            if (x == '@') { symbolAt = true; }
            if (x == '.') { symbolPeriod = true; }
            if (x == ' ') { symbolSpace = true; }
        }

        if (symbolAt == false) { cout << "[" << (*classRosterArray[i]).getEmailAddress() << "] "; }
        if (symbolPeriod == false) { cout << "[" << (*classRosterArray[i]).getEmailAddress() << "] "; }
        if (symbolSpace == true) { cout << "[" << (*classRosterArray[i]).getEmailAddress() << "] "; }
    }
}

//Print by the Degree-------------------------------------------------------------------------------
void Roster::printByDegreeProgram(Degree degrees) {
    cout << degreeString[degrees] << " Degree Students: " << endl;
    cout << endl;
    for (int i = 0; i <= lastArrayIndex; ++i) {
        if (this->classRosterArray[i]->getDegree() == degrees) this->classRosterArray[i]->print();

    }
}
//Print the Average Number of Days------------------------------------------------------------------
void Roster::printAvgNumDays(string studentId) {
    bool found = false;
    for (int i = 0; i <= lastArrayIndex; ++i) {
        if (this->classRosterArray[i]->getStudentId() == studentId) {
            found = true;
            int* avgNumDays = classRosterArray[i]->getNumDays();
            cout << "Student ID: " << "[" << studentId << "] " << (avgNumDays[0] + avgNumDays[1] + avgNumDays[2]) / 3 << " average days in a course.";
            cout << endl;
        }
    }
    
}

//Destructor --------------------------------------------------------------------------------------
Roster::~Roster() {
    for (int i = 0; i < numStudents; ++i) {
        delete this->classRosterArray[i];
    }
    delete this;
}


//Main Function-------------------------------------------------------------------------------------
int main() {

    Roster* classRoster = new Roster(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        classRoster->parseAdd(studentData[i]);
    }

    cout << endl;

    cout << "C867 / Scripting and Programming - Applications" << endl;;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 001133263" << endl;
    cout << "Name: Patrick Ross" << endl;
    cout << endl;
    classRoster->format();

    cout << left << setw(8) << "ID: ";
    cout << left << setw(15) << "First: ";
    cout << left << setw(15) << "Last: ";
    cout << left << setw(30) << "Email: ";
    cout << left << setw(10) << "Age: ";
    cout << left << "Days in Courses: ";
    cout << setw(5) << "\t" << "DEGREE: " << endl;
    classRoster->format();


    classRoster->printAll();
    classRoster->format();

    classRoster->printInvalidEmail();
    cout << endl;
    classRoster->format();

    classRoster->printAvgNumDays("A5");
    classRoster->format();

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;
    classRoster->format();

    classRoster->removeStudent("A3");

    classRoster->printAll();
   
    classRoster->removeStudent("A3");
    cout << endl;


    return 0;

    
}