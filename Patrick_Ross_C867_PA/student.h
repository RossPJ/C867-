#include <iostream>
#include <string>
#include "degree.h"

#ifndef STUDENT_H
#define STUDENT_H

using namespace std; 


class Student {
public:
    const static int numDaysArraySize = 3;

    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    string getAge();
    int* getNumDays();
    virtual Degree getDegree() = 0;

    virtual void print() = 0;

    void setStudentId(string studId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string emailAddress);
    void setAge(string studentAge);
    void setNumDays(int numDays[]);
    virtual void setDegree(Degree degrees) = 0;

    Student();
    Student(string studId, string firstName, string lastName, string emailAddress, string studentAge, int numDays[], Degree typeOfDegree);
    ~Student();

protected:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    string studentAge;
    int* numDays;
    Degree typeOfDegree;
};


#endif