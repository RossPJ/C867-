#pragma once
#include <iostream>
#include <string>

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"


using namespace std;

class NetworkStudent : public Student {
public:
    
    NetworkStudent(string studentId, string firstName, string lastName, string emailAddressAddress, string studentstudentAge, int* numDaysInCourse, Degree degreetype);
    Degree getDegree();
    void setDegree(Degree degrees);
    void print();


    NetworkStudent();
    ~NetworkStudent();
};

#endif