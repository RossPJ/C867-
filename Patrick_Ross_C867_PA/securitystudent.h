#pragma once
#include <iostream>
#include <string>

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"


using namespace std;

class SecurityStudent : public Student {
public:

    SecurityStudent(string studentId, string firstName, string lastName, string emailAddressAddress, string studentstudentAge, int* numDaysInCourse, Degree degreetype);
    Degree getDegree();
    void setDegree(Degree degrees);
    void print();

    SecurityStudent();
    ~SecurityStudent();
};

#endif