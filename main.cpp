///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Title:            main.cpp
// Files:            Student.h, SortedList.h, Student.cpp, SortedList.cpp
// Semester:         CS368 Fall 2012
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
#include "SortedList.h"

using namespace std;

// Very simple and repetitive main program to demons-
// trate the functionality of the destructor, copy constructor, and copy assign-
// ment operators of the Student and SortedList classes.
int main()
{
    Student *s = new Student (987654,32,2.3);
    Student *y = new Student (231231,12,3.2);
    Student *k = new Student (123456,69,3.4);
    Student *c  = new Student(412452,98,4.3);
    Student *w = new Student(112124,0,0);
    Student *b = new Student(325125, 34, 4.0);
    SortedList *list = new SortedList();
    list->insert(s);
    list->insert(y);
    list->insert(k); 
    cout<< "The original list from P2: " << endl;
    list->print();
    cout<<endl;
    // calls the destructor for the sorted list
    delete list;
    // If list were to be printed, there would be a runtime error because the pointers
    // are NULL
    list = new SortedList();
    list->insert(c);
    list->insert(w);
    cout << "the new list after it has been destructed, and created again: " << endl;
    list->print();
    cout<<endl;
    w->update('D', 4);
    s->update('F', 5);
    // make a copy of the list, and remove one elem of it, but not of the copy
    SortedList *copy = new SortedList(*list);
    list->remove(412452);
    list->insert(b);
    cout<<"The orignial list after removing 412452: " << endl;
    list->print();
    cout<<"The copied list after removing 412452: " <<endl;
    copy->print();
    cout<<endl;
    // assign copy to list
    SortedList *secCop;
    secCop = list;
    cout<<"After assigning copy to list, copy looks like original list: " << endl;
    secCop->print();
    delete list;
    delete w;
    delete y;
    delete c;
    delete s;
    delete k;
    delete b;
    
}

