#pragma once
#include <iostream>
#include <string>

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"


using namespace std; 

class SoftwareStudent : public Student {
public:

   
    SoftwareStudent(string studentId, string firstName, string lastName, string emailAddressAddress, string studentstudentAge, int* numDaysInCourse, Degree degreetype);
    Degree getDegree();
    void setDegree(Degree degrees);
    void print();

    SoftwareStudent();
    ~SoftwareStudent();
};

#endif