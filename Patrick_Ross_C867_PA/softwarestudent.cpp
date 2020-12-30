#include <iostream>
#include "softwarestudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent() {
    setDegree(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, string studentAge, int* numDays, Degree degreetype) {
    setDegree(SOFTWARE);
}

Degree SoftwareStudent::getDegree() {
    return SOFTWARE;
}

void SoftwareStudent::setDegree(Degree degrees) {
    this->typeOfDegree = SOFTWARE;
}

void SoftwareStudent::print() {
    this->Student::print();
    cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent() {
    Student::~Student();
}

