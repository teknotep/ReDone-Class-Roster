#include <iostream>
#include "Student.h"
#include "degree.h"
#include "degree.h"

using std::cout;


// CONSTRUCTOR //
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
                 int age, int numOfDays[daysArraySize], DegreeProgram degree){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->numOfDays[0] = numOfDays[0];
    this->numOfDays[1] = numOfDays[1];
    this->numOfDays[2] = numOfDays[2];
    this->degree = degree;
}

Student::~Student() {
    };

//ACCESSORS - GETTERS//
string Student::getStudentID()  {
    return studentID;
};
string Student::getFirstName()  {
    return firstName;
};
string Student::getLastName()  {
    return lastName;
};
string Student::getEmailAddress()  {
    return emailAddress;
};
int  Student::getAge()  {
    return age;
};
int* Student::getNumOfDays() {
    return numOfDays;
};
DegreeProgram Student::getDegree(){
    return degree;
};
//MUTATORS - SETTERS//
void Student::setStudentID(string studentID) {
            this->studentID = studentID;
    };
void Student::setFirstName(string firstName) {
            this->firstName = firstName;
    };
void Student::setLastName(string lastName) {
            this->lastName = lastName;
    };
void Student::setEmailAddress(string emailAddress) {
            this->emailAddress = emailAddress;
    };
void Student::setAge(int age) {
            this->age = age;
    };
void Student::setNumOfDays(int numOfDays[daysArraySize]){
            this->numOfDays[0] = numOfDays[0];
            this->numOfDays[1] = numOfDays[1];
            this->numOfDays[2] = numOfDays[2];
    };
void Student::setDegree(DegreeProgram degree){
            this->degree = degree;
    };

void Student::print()
{
    cout << studentID << '\t';
    cout << "First Name: " << firstName << '\t';
    cout << "Last Name: " << lastName << '\t';
    cout << "Email: " << emailAddress << '\t';
    cout << "Age:" << age << '\t';
    cout << "Days In Course: ";
    cout << numOfDays[0] << ',';
    cout << numOfDays[1] << ',';
    cout << numOfDays[2] << '\t';
    cout << "Degree Program: " << DegreeProgramStrings[(int)degree] << '\n';
}
