//
//  student.h
//  C867 Project
//
//  Created by Shadi Mahfouz on 12/25/20.
//


#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
using std::endl;
using std::setw;

class Student

{
    
public:
    
    const static int daysArraySize = 4;
    
private:
    
    string studentID;
    string firstName;
    string lastName;
    string studentEmail;
    int studentAge;
    int i = 0;
    int daysToComplete[daysArraySize];
    DegreeProgram degreeType;
    
public:
    
    Student(); //Default Constructor
    Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToComplete[], DegreeProgram degreeType); //Full constructor
    ~Student(); //Destructor
    
    //Accessors
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegree();
    
    //Mutators
    void setID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setStudentEmail(string studentEmail);
    void setStudentAge(int studentAge);
    void setDays(int daysToComplete[]);
    void setDegreeProgram(DegreeProgram degreeType);
    
    static void printTableHead(); //Prints static table head for format
    
    void print(); //Prints each student's information separately
    
};
