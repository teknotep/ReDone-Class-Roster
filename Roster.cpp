#include <iostream>
#include "roster.h"

using std::cout;

void Roster::addST(string studentID, string firstName, string lastName, string emailAddress, int age,
                   int numOfDays1, int numOfDays2, int numOfDays3, DegreeProgram degree)
     {
     int daysArray[] = {numOfDays1, numOfDays2, numOfDays3} ;
     classRosterArray[++addPosition] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degree);
    }

void Roster::removeStudent(string studentID)
{
    bool studentFound = false;
    for (int i = 0; i <= addPosition; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            studentFound = true;
            Student* temp = classRosterArray[i];
            classRosterArray[addPosition] = temp;
            cout << "Student: " << studentID << " has been removed.\n";
            addPosition --;
        }
    }
    if (!studentFound) cout << "Student: " << studentID << " not found.\n" ;
}

void Roster::printALL()
{
    cout<< "Showing All Student Data:\n";

    for (int i = 0; i <= addPosition; i++)
    {
      classRosterArray[i]->print(); // Student data prints for all instances
    }
    cout << "\n" ;
}

void Roster::printAvgNumOfDays(string studentID)
{
    cout << "Average days in courses for Student ID: " << studentID << ":\t";
    for (int i = 0; i <= Roster::addPosition; i++){
        if (classRosterArray[i]->getStudentID() == studentID){
            cout << ((double) classRosterArray[i]->getNumOfDays()[0]
                   + (double) classRosterArray[i]->getNumOfDays()[1]
                   + (double) classRosterArray[i]->getNumOfDays()[2]) / 3.0
                   << "\n"; // Sum, divided by 3 to print the average course days...
        }
    }
}

void Roster::printInvalidEmails()
{
    bool valid = true;
    for (int i = 0; i <= addPosition; i++)
    {
        string email = classRosterArray[i]->getEmailAddress();
        if ((email.find("@") == string::npos) || (email.find(".") == string::npos) || (email.find(" ") != string::npos))
        {
          cout << "Invalid Email Address: " << email << "\n";
          valid = false;
        }
    }   if (valid) cout << "All eMail addresses are valid!\n" << "\n";
}

void Roster::printByDegree(DegreeProgram degree)
{

    for (int i = 0; i <= addPosition; i++)
    {
        if (classRosterArray[i]->getDegree() == degree)
            classRosterArray[i]->print();
    }
      cout << "\n" << "\n";
}
Roster::~Roster()  //DESTROYED
{
    for (int i = 0; i < studentAmt; i++)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
