//
//  main.cpp
//  C867 Project
//
//  Created by Shadi Mahfouz on 12/25/20.
//


#include "roster.h"
using std::endl;

int main() {
    
    int i = 0;
    //My information
    cout << "Scripting and Programming - Applications - C867 " << "Language used: C++ " << "Name: Shadi Mahfouz " << "ID# 001423923" << endl;
    
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Shadi,Mahfouz,mahfouzshadi@gmail.com,26,20,25,30,SOFTWARE"
    };
    
    const int numStudents = 5;
    Roster roster;
    
    for (i = 0; i < numStudents; ++i) {
        roster.parse(studentData[i]);
        cout << endl;
        cout << "Displaying all students: " << endl << endl;;
        roster.printAll();
        cout << endl;
    }
    
    for (i = 0; i < 3; ++i) {
        
        cout << endl;
        cout << "Displaying student by degree type: " << degreeNames[i] << endl << endl;
        roster.printByDegreeType((DegreeProgram)i);
        
    }
    
    cout << endl;
    cout << "Displaying students with invalid emails: " << endl << endl;
    roster.printInvalidEmails();
    cout << endl;
    
    cout << "Average number of days to finish courses: " << endl << endl;
    roster.printAverageDays("A1");
    
    cout << "Removing student with ID A3: " << endl << endl;
    roster.removeStudent("A3");
    cout << endl;
    
    cout << "Removing student with ID A3: " << endl << endl;
    roster.removeStudent("A3");
    cout << endl;
    
    return 0;
}
