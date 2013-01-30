///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Main Class File:  studentDB.cpp
// File:             SortedList.h
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
#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include "Student.h"

/*
 * SortedList class
 *
 * A SortedList is an ordered collection of Students.  The Students are ordered
 * from lowest numbered student ID to highest numbered student ID.
 */
class SortedList {
    
public:
    // Constructs an empty list.
    SortedList();
    
    // Destructor
    ~SortedList();
    
    // Copy Constructor
    SortedList(const SortedList & rhs);
    
    // Copy Assignment Operator
    const SortedList & operator=(const SortedList & rhs);
    
    bool insert(Student *s);
    // If a student with the same ID is not already in the list, inserts
    // the given student into the list in the appropriate place and returns
    // true.  If there is already a student in the list with the same ID
    // then the list is not changed and false is returned.
    
    Student *find(int studentID);
    // Searches the list for a student with the given student ID.  If the
    // student is found, it is returned; if it is not found, NULL is returned.
    
    Student *remove(int studentID);
    // Searches the list for a student with the given student ID.  If the
    // student is found, the student is removed from the list and returned;
    // if no student is found with the given ID, NULL is returned.
    // Note that the Student is NOT deleted - it is returned - however,
    // the removed list node should be deleted.
    
    void print() const;
    // Prints out the list of students to standard output.  The students are
    // printed in order of student ID (from smallest to largest), one per line
    
private:
    
    // Since Listnodes will only be used within the SortedList class,
    // we make it private.
    struct Listnode {
        Student *student;
        Listnode *next;
    };
    
    Listnode *head; // pointer to first node in the list
    
    static void freeList (Listnode *L);
    static Listnode *copyList (Listnode *L);
};

#endif