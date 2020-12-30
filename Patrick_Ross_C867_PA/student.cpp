#include <iostream>
#include "student.h"
#include <string>
#include <iomanip>

using namespace std;


void Student::print() {
    cout << left << setw(8) << studentId;
    cout << left << setw(15) << firstName;
    cout << left << setw(15) << lastName;
    cout << left << setw(30) << emailAddress;
    cout << left << setw(10) << studentAge;
    cout << left << "|";
    cout << left << setw(5) << numDays[0];
    cout << left << setw(5) << numDays[1];
    cout << left << numDays[2] << "|";
    cout << setw(5) << "\t" << "Degree: ";
}

Student::Student() {
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->studentAge = "";
    this->numDays = new int[numDaysArraySize];
    for (int i = 0; i < numDaysArraySize; ++i) this->numDays[i] = 0;
}

Student::Student(string studId, string firstName, string lastName, string emailAddress, string studentAge, int numDays[], Degree typeOfDegree) {
    this->studentId = studId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->studentAge = studentAge;
    this->numDays = new int[numDaysArraySize];

    for (int i = 0; i < 3; ++i) this->numDays[i] = numDays[i];
}


void Student::setStudentId(string studId) {
    studentId = studId;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(string studentAge) {
    this->studentAge = studentAge;
}

void Student::setNumDays(int numDays[]) {
    if (this->numDays != nullptr) {
        delete[] this->numDays;
        this->numDays = nullptr;
    }

    this->numDays = new int[numDaysArraySize];
    for (int i = 0; i < 3; ++i)
        this->numDays[i] = numDays[i];
}




string Student::getStudentId() {
    return studentId;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

string Student::getAge() {
    return studentAge;
}

int* Student::getNumDays() {
    return numDays;
}

Student::~Student() {
    if (numDays != nullptr) {
        delete[] numDays;
        numDays = nullptr;
    }
}