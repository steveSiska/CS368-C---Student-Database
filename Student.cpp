///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Main Class File:  studentDB.cpp
// File:             Student.cpp
// Semester:         CS368-1 Fall 2012
//
// Author:           Steve Siska ssiska@wisc.edu
// CS Login:         siska
// Lecturer's Name:  Skrentny
// Lab Section:      NA
//
//                   PAIR PROGRAMMERS COMPLETE THIS SECTION
// Pair Partner:     (name of your pair programming partner)
// CS Login:         (partner's login name)
// Lecturer's Name:  (name of your partner's lecturer)
// Lab Section:      (your partner's lab section number)
//
//                   STUDENTS WHO GET HELP FROM ANYONE OTHER THAN THEIR PARTNER
// Credits:          (list anyone who helped you write your program)
//////////////////////////// 80 columns wide //////////////////////////////////
#include <iostream>
#include "Student.h"

using namespace std;

/*
 * Student class
 *
 * A Student object contains a student ID, the number of credits, and an
 * overall GPA.
 */


// Constructs a default student with an ID of 0, 0 credits, and 0.0 GPA
Student::Student(){
    studentID = 0;
    credits = 0;
    GPA = 0.0;
}

// Constructs a student with the given ID, 0 credits, and 0.0 GPA
//
// @param ID: the 6-digit ID to give this student
Student::Student(int ID){
    studentID = ID;
    credits = 0;
    GPA = 0.0;
}

// Constructs a student with the given ID, credits, and GPA
//
// @param ID: the 6-digit ID to give this student
// @param cr: the amount of credits to give this student
// @grPtAv: the 0.0-4.0 floating point value to give this student's GPA
Student::Student(int ID, int cr, double grPtAv){
    studentID = ID;
    credits = cr;
    GPA = grPtAv;
}

// Destructs a Student object by deleting it's dynamically allocated members
// Since a student has no variables stored in the heap, this statement does
// nothing to the memory management aspcet of the program
Student::~Student(){
}

// Creates a Student from the given Student
//
// @param the address of the Student to copy
Student::Student(const Student & rhs) : studentID(rhs.studentID), credits(rhs.credits), GPA(rhs.GPA){
}

// Overloads the equals operator, and returns a new Student if the two are different
//
// @param the address of the student to change
// @returns the address of the Student this one wants to be
const Student & Student::operator=(const Student & rhs){
    if (this == &rhs){
        return *this;
    }
    else{
        studentID = rhs.studentID;
        credits = rhs.credits;
        GPA = rhs.GPA;
    }
    return *this;
}

// Returns the student ID of the student
//
// @returns the ID of this student
int Student::getID() const{
    return studentID;
}

// Returns the number of credits of the student
//
// @returns the credits of this student
int Student::getCredits() const{
    return credits;
}

// Returns the GPA of the student
//
//  @returns the GPA of this student
double Student::getGPA() const{
    return GPA;
}

// Updates the total credits and overall GPA to take into account the
// additions of the given letter grade in a course with the given number
// of credits.  The update is done by first converting the letter grade
// into a numeric value (A = 4.0, B = 3.0, etc.).  The new GPA is
// calculated using the formula:
//
//            (oldGPA * old_total_credits) + (numeric_grade * cr)
//   newGPA = ---------------------------------------------------
//                        old_total_credits + cr
//
// Finally, the total credits is updated (to old_total_credits + cr)
//
// @param grade: the char value of the grade A-D, F
// @param cr: the amount of credits to give the student
void Student::update(char grade, int cr){
    double gradePoints, newGPA;
    grade = tolower(grade);
    switch(grade) {
        case 'a':
            gradePoints = 4;
            break;
        case 'b':
            gradePoints = 3;
            break;
        case 'c':
            gradePoints = 2;
            break;
        case 'd':
            gradePoints = 1;
            break;
        case 'f':
            gradePoints = 0;
            break;
    }
    newGPA = ((GPA*credits) + (gradePoints*cr))/(credits+cr);
    GPA = newGPA;
    credits = credits + cr;
}

// Prints out the student to standard output in the format:
//   ID,credits,GPA
// Note: the end-of-line is NOT printed after the student information
void Student::print() const{
    cout << studentID << "," << credits << "," << GPA;
}

