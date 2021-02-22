//
//  roster.cpp
//  C867 Project
//
//  Created by Shadi Mahfouz on 12/25/20.
//

#include "roster.h"
#include "iomanip"
using std::endl;

void Roster::parse(string studentdata) {
    
    DegreeProgram degree = SOFTWARE; //Default value
    //Calling from enumerator based on student ID numbers since they are already known
    if (studentdata.at(0) == 'A' && studentdata.at(1) == '1') {
        degree = SECURITY;
    }
    else if (studentdata.at(0) == 'A' && studentdata.at(1) == '2') {
        degree = NETWORK;
    }
    else if (studentdata.at(0) == 'A' && studentdata.at(1) == '3') {
        degree = SOFTWARE;
    }
    else if (studentdata.at(0) == 'A' && studentdata.at(1) == '4') {
        degree = SECURITY;
    }
    else if (studentdata.at(0) == 'A' && studentdata.at(1) == '5') {
        degree = SOFTWARE;
    }
    
    //size_t avoids a complier warning since it does not accept negative integers
    //This allows us to parse through the data and extract strings and integers
    size_t rhs = studentdata.find(","); //This will find commas in the string
    string ID = studentdata.substr(0, rhs); //This will extract the student ID from the string
    
    //The following will allow us to continue to parse through the string, beginning at where we left off up until the next comma
    
    size_t lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string first = studentdata.substr(lhs, rhs - lhs); //This will extract the student's first name
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string last = studentdata.substr(lhs, rhs - lhs); //This will extract the student's last name
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string email = studentdata.substr(lhs, rhs - lhs); //This will extract the student's email
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int age = stoi(studentdata.substr(lhs, rhs - lhs)); //This will extract student age from the string and convert it to an integer
    
    //The following will search for and extract all three instances of number of days to complete classes and convert them to integers
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int day1 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int day2 = stoi(studentdata.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int day3 = stoi(studentdata.substr(lhs, rhs - lhs));
    
    add(ID, first, last, email, age, day1, day2, day3, degree);
}

void Roster::add(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int day1, int day2, int day3, DegreeProgram degreeType)
{
    int daysArray[3] = {day1, day2, day3}; //Array to store all three entries for days to complete courses
    
    classRosterArray[++finalIndex] = new Student(studentID, firstName, lastName, studentEmail, studentAge, daysArray, degreeType);
}

void Roster::printAll() {
    
    Student::printTableHead(); //Prints the table head above student data
    
    //Gets student information and stores it in array, then prints
    //Edit- Uses print() function from Student class to print the contents of the array once it is filled
    for(i = 0; i <= finalIndex; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
        /*cout << classRosterArray[i]->getID(); cout << '\t';
        cout << classRosterArray[i]->getFirstName(); cout << '\t';
        cout << classRosterArray[i]->getLastName(); cout << '\t';
        cout << classRosterArray[i]->getEmail(); cout << '\t';
        cout << classRosterArray[i]->getAge(); cout << '\t';
        cout << classRosterArray[i]->getDays()[0]; cout << ", ";
        cout << classRosterArray[i]->getDays()[1]; cout << ", ";
        cout << classRosterArray[i]->getDays()[2]; cout << '\t';
        cout << degreeNames[classRosterArray[i]->getDegree()] << endl;*/
    }
}
    
//Only prints students info of a certain degree type
void Roster::printByDegreeType(DegreeProgram degree) {
        
        Student::printTableHead();
        for(i = 0; i <= Roster::finalIndex; ++i) {
            if (Roster::classRosterArray[i]->getDegree() == degree) {
                classRosterArray[i]->print();
        }
        
    }
    
}

void Roster::printInvalidEmails() {
    
    //The below will search for and find emails containing a space, missing the '@' symbol, or missing a period
    bool invalid = false;
    
    for (i = 0; i < numStudents; ++i) {
        string email = (classRosterArray[i]->getEmail());
        string at = "@";
        string dot = ".";
        string space = " ";
        size_t foundat = email.find(at);
        size_t founddot = email.find(dot);
        size_t foundspace = email.find(space);
        if (foundspace != string::npos || foundat == string::npos || founddot == string::npos) {
            invalid = true;
            cout << "Invalid email: " << email << endl;
        }
    }
}
   
void Roster::printAverageDays(string studentID) {
    
    //Prints the average number of days it takes each student to finish a class based on the 3 entries in the array for number of days
    //Edit- Modofied function to output average number of days for one student only
    bool any = false;
    for (i = 0; i <= Roster::finalIndex; ++i) {
        if (classRosterArray[i]->getID() == studentID) {
            any = true;
            cout << classRosterArray[i]->getID() << ": ";
            cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3 << endl;
        }
    }
    
    cout << endl;
    
}

void Roster::removeStudent(string studentID) {
    
    //Removes student by ID number
    bool success = false;
    for (i = 0; i <= Roster::finalIndex; ++i) {
        if (classRosterArray[i]->getID() == studentID){
            success = true;
            if (i < numStudents - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::finalIndex--; //This allows the array to be decremented after switching deleted student into the last index, not fully deleting the student from the program but making the student data inaccessible to the user
        }
    }
    
    if (success) {
        cout << studentID << " has been removed from the roster" << endl << endl;
        this->printAll();
    }
    
    else cout << studentID << " not found." << endl << endl;
    
}

Roster::~Roster() {
    
    //Roster destructor
    cout << "Destructor called" << endl << endl;
    for (i = 0; i < numStudents; ++i) {
        cout << "Destroying student number " << i + 1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }

}
