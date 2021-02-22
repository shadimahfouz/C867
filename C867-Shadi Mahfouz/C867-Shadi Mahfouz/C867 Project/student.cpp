//
//  student.cpp
//  C867 Project
//
//  Created by Shadi Mahfouz on 12/25/20.
//

#include "student.h"
using std::endl;

Student::Student() { //Default constructor
    
    this->studentID = ""; //Empty string
    this->firstName = ""; //Empty string
    this->lastName = ""; //Empty string
    this->studentEmail = ""; //Empty string
    this->studentAge = 0; //Default 0
    for (i = 0; i < daysArraySize; ++i)
    this->daysToComplete[i] = 0; //Array of days to complete class
    this->degreeType = DegreeProgram::SOFTWARE; //Default degree program is SOFTWARE
    
}

Student::Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToComplete[], DegreeProgram degreeType) //Constructor
{
    
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->studentEmail = studentEmail;
    this->studentAge = studentAge;
    for (i = 0; i < daysArraySize; ++i) this->daysToComplete[i] = daysToComplete[i];
    this->degreeType = degreeType;
    
}

Student::~Student() {} //Dectructor

//Accessors
string Student::getID() {return this->studentID;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmail() {return this->studentEmail;}
int Student::getAge() {return this->studentAge;}
int* Student::getDays() {return this->daysToComplete;}
DegreeProgram Student::getDegree() {return this->degreeType;}

//Mutators
void Student::setID(string studentID) {this->studentID = studentID;}
void Student::setFirstName(string firstName) {this->firstName = firstName;}
void Student::setLastName(string lastName) {this->lastName = lastName;}
void Student::setStudentEmail(string studentEmail) {this->studentEmail = studentEmail;}
void Student::setStudentAge(int studentAge) {this->studentAge = studentAge;}
void Student::setDays(int daysToComplete[]) {
    for (i = 0; i < daysArraySize; ++i) this->daysToComplete[i] = daysToComplete[i];
}
void Student::setDegreeProgram(DegreeProgram degreeType) {this->degreeType = degreeType;}


//Table header defined
void Student::printTableHead() {cout << "ID | First Name | Last Name | Email | Age | Days in Course | Degree Program" << endl << endl;}

//Student data printer
void Student::print() {
        
    cout << this->getID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degreeNames[this->getDegree()] << endl;
}

