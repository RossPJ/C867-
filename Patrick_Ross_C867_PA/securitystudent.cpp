#include <iostream>
#include "securitystudent.h"

using namespace std; 

SecurityStudent::SecurityStudent() {
    setDegree(SECURITY);
}

SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, string studentAge, int* numDays, Degree degreetype) {
    setDegree(SECURITY);
}

Degree SecurityStudent::getDegree() {
    return SECURITY;
}

void SecurityStudent::setDegree(Degree degrees) {
    this->typeOfDegree = SECURITY;
}

void SecurityStudent::print() {
    this->Student::print();
    cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent() {
    Student::~Student();
}