#pragma once
#include <string>
#include "degree.h"

using std::string;

class Student {
public:
    const static int daysArraySize = 3;
private:
    string studentID = "";
	string firstName = "";
	string lastName = "";
	string emailAddress = "";
	int age;
	int numOfDays[3] = {0, 0, 0};
	DegreeProgram degree = DegreeProgram::NETWORK;

public:
    Student(string studentID, string firstName, string lastName, string emailAddress,
            int age, int numOfDays[daysArraySize], DegreeProgram degree);
    ~Student();
    //  ACCESSORS - GETTERS  //
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge() ;
    int* getNumOfDays();
    DegreeProgram getDegree();

    //  MUTATORS - SETTERS  //
    void setStudentID(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmailAddress(string);
    void setAge(int);
    void setNumOfDays(int[daysArraySize]);
    void setDegree(DegreeProgram);

    void print();
};
