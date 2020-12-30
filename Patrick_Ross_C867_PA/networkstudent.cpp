#include <iostream>
#include "networkstudent.h"

using namespace std; 

NetworkStudent::NetworkStudent() {
    setDegree(NETWORK);
}

NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, string studentAge, int* numDays, Degree degreetype) {
    setDegree(NETWORK);
}

Degree NetworkStudent::getDegree() {
    return NETWORK;
}

void NetworkStudent::setDegree(Degree degrees) {
    this->typeOfDegree = NETWORK;
}

void NetworkStudent::print() {
    this->Student::print();
    cout << "NETWORK" << endl;
}

NetworkStudent::~NetworkStudent() {
    Student::~Student();
}