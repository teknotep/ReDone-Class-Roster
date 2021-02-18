#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;


int main()
{
cout << "Manny Colondres _ Student 001233220" << endl;
cout << "Scripting and Programming - Applications C867" << endl;
cout << "C++ Programming Language" << endl;
cout << "Performance Assessment" << endl;

    Roster classRoster;
    const string studentData[] =
       {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",   //4
        "A5,Manny,Colondres,teknotep@yahoo.com,36,20,30,40,SOFTWARE"
       };
for (int i = 0; i < 5; i++)
{
    string studentString = studentData[i];
    vector<string> sTokens;
    stringstream studentStream(studentString);
    while (studentStream.good())
    {
        string substr;
        getline(studentStream,substr, ','); //Comma Delineation
        sTokens.push_back(substr);
    }
    DegreeProgram degree = DegreeProgram::NETWORK;
    if (sTokens.at(8).back() == 'E')//software degree program
        degree = DegreeProgram::SOFTWARE;
    if (sTokens.at(8).back() == 'Y')//security degree program
        degree = DegreeProgram::SECURITY;
    int* tmpArray = new int[3];
    tmpArray[0] = stoi(sTokens.at(5));
    tmpArray[1] = stoi(sTokens.at(6));
    tmpArray[2] = stoi(sTokens.at(7));
    tmpArray[3] = stoi(sTokens.at(4));

classRoster.addST(sTokens.at(0), sTokens.at(1), sTokens.at(2), sTokens.at(3), stoi(sTokens.at(4)),
                       stoi(sTokens.at(5)), stoi(sTokens.at(6)), stoi(sTokens.at(7)), degree);
}

classRoster.printALL();

classRoster.printInvalidEmails();

cout << endl;
for(int i = 0; i < 5; i++)
{
    classRoster.printAvgNumOfDays(classRoster.classRosterArray[i]->getStudentID());
}
cout << "\nDisplaying SOFTWARE students:" << endl;
classRoster.printByDegree(DegreeProgram::SOFTWARE);

classRoster.removeStudent("A3");

return 0;
}
