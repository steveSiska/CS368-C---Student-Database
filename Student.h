///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Main Class File:  studentDB.cpp
// File:             Student.h
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
#ifndef STUDENT_H
#define STUDENT_H

/*
 * Student class
 *
 * A Student object contains a student ID, the number of credits, and an
 * overall GPA.
 */
class Student {
    
public:
    // Constructs a default student with an ID of 0, 0 credits, and 0.0 GPA.
    Student();
    
    // Constructs a student with the given ID, 0 credits, and 0.0 GPA.
    Student(int ID);
    
    // Constructs a student with the given ID, number of credits, and GPA.
    Student(int ID, int cr, double grPtAv);
    
    // Destructor
    ~Student();
    
    // Copy Constructor
    Student(const Student & rhs);
    
    // Copy Assignement Operator
    const Student & operator= (const Student & rhs);
    
    // Accessors
    int getID() const;       // returns the student ID
    int getCredits() const;  // returns the number of credits
    double getGPA() const;   // returns the GPA
    
    // Other methods
    
    void update(char grade, int cr);
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
    
    void print() const;
    // Prints out the student to standard output in the format:
    //   ID,credits,GPA
    // Note: the end-of-line is NOT printed after the student information
    
private:
    int studentID;
    int credits;
    double GPA;
};

#endif