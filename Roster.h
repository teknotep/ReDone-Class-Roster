#pragma once
#include <vector>
#include "Student.h"

using std::vector;

class Roster{
public:
    static const int studentAmt = 5;
    Student* classRosterArray[studentAmt];
private:
    int addPosition = -1;
    vector<string> parsedStudentData;
public:
    void addST(string studentID, string firstName, string lastName, string emailAddress, int age,
             int numOfDays1, int numOfDays2, int numOfDays3, DegreeProgram degree);
	void removeStudent(string studentID);
	void printALL();
	void printAvgNumOfDays(string studentID);
	void printInvalidEmails();
	void printByDegree(DegreeProgram degree);

	~Roster();
};
