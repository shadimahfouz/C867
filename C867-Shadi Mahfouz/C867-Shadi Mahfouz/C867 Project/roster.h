//
//  roster.h
//  C867 Project
//
//  Created by Shadi Mahfouz on 12/25/20.
//

#pragma once
#include "student.h"

class Roster {
private:
    
    int finalIndex = -1; //Last spot in array
    const static int numStudents = 5;
    Student* classRosterArray[numStudents]; //Array of students
    
public:
    int i = 0;
    void parse(string row);
    void add(string ID, string first, string last, string email, int age, int day1, int day2, int day3, DegreeProgram degree);
    void printAll();
    void printByDegreeType(DegreeProgram degree); //Prints students by degree program
    void printInvalidEmails(); //Prints invalid emails tht contain a space or do not contain a '@' and '.'
    void printAverageDays(string studentID); //Prints average number of days it takes to complete a class for a student
    void removeStudent(string studentID); //Delete a student by ID
    ~Roster(); //Destructor
    
};
