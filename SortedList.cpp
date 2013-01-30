///////////////////////////////////////////////////////////////////////////////
//                   ALL STUDENTS COMPLETE THESE SECTIONS
// Main Class File:  studentDB.cpp
// File:             SortedList.cpp
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
#include "SortedList.h"

using namespace std;

/*
 * SortedList class
 *
 * A SortedList is an ordered collection of Students.  The Students are ordered
 * from lowest numbered student ID to highest numbered student ID.
 */

// Constructs an empty list
SortedList::SortedList(){
    head = NULL; 
}

// Destructor. Deallocates the memory of the head
SortedList::~SortedList(){
    freeList(head);
}

// Creates a SortedList from the given SortedList
//
// @ param the address of the sorted list to copy
SortedList::SortedList(const SortedList & rhs){
head = (copyList(rhs.head));
}

// Equal operator overload constructor. Returns a new SortedList if the two are
// different
//
// @param the address of the Sorted list to compare
// @returns the address of the sorted list this one wants to be
const SortedList & SortedList::operator=(const SortedList & rhs){
    cout<<"HERE";
    if (this == &rhs){
        return *this;
    }
    else{
        delete head;
        head = copyList(rhs.head);
    }
    return *this;
}

// This function traverses the Linked List, returning each node to free storage
// (ie deallocating it's heap memory).  This function is used by the destructor
// and copy assignment operator.
//
// @param the pointer to the first node of the list to start deleting
void SortedList::freeList(Listnode *L){
    Listnode *tmp = L;
    while(tmp != NULL){
        Listnode *gone = tmp;
        tmp = tmp->next;
        delete gone;
    }
}

// This function returns a pointer to the first node of the copied LinkedList
// Function is used by the copy constructor and assignement overload operator
//
// @param The pointer to the first listnode to copy
// @returns the pointer to the first node of the new copy of the list
SortedList::Listnode* SortedList::copyList(Listnode *L){
    Listnode *head, *curr, *next;
    head = new Listnode();
    head->student = L->student;
    curr = head;
    next = L->next;
    L = L->next;
    while(next != NULL){
        curr->next = new Listnode();
        curr = curr->next;
        curr->student = next->student;
        next = L->next;
    L = L->next;
    }
    return head;
}

// If a student with the same ID is not already in the list, inserts
// the given student into the list in the appropriate place and returns
// true.  If there is already a student in the list with the same ID
// then the list is not changed and false is returned.
//
//  @param Student *s: pointer to a Student
//  @returns: true if the Student was added to the list, false otherwise
bool SortedList::insert(Student *s){
    //if this is the first student, perform ops to create the list
    if(head == NULL){
        head = new Listnode();
        head->student = s;
        return true;
    }
    
    //Listnode variables for use in manipulating the list
    Listnode *tmp = head;
    Listnode *found;
    Listnode *back = head;
    
    //check to see if the ID is in the list
    while (tmp != NULL){
        if(tmp->student->getID() == s->getID()){
            return false;
        }
        tmp = tmp->next;
    }

    //if it's not, add it to the correct location in the list
    tmp = head; //reset tmp to the node that head is pointing to
    int itr = 0; //to be used to see if the node we're intersted in is the first one
    bool done = false;
    while(tmp != NULL && !done){
        if(s->getID() < tmp->student->getID()){
            done = true;
            found = new Listnode(); //create new listnode with student data
            found->student = s;
            //if this is the first node in the chain, make sure head is updated
            if(itr == 0){
                found->next = head;
                head = found;
                return true;
            }
            found->next = tmp;
            back->next = found;
            
        }
        //if we're at the end, but have not done anything yet, the ID is larger than
        //anything in the chain, so add it there
        else if(tmp->next == NULL && s->getID() > tmp->student->getID()){
            done = true;
            found = new Listnode();
            found->student = s;
            tmp->next = new Listnode();
            tmp->next = found;
        }
        else{
            back = tmp;
            tmp = tmp->next;
            itr++;
        }
    }
    return true;
}


// Searches the list for a student with the given student ID.  If the
// student is found, it is returned; if it is not found, NULL is returned.
//
//  @param studentID: the 6-digit ID of the student to find
//  @returns a pointer to the found student, or NULL if the student wasn't found
Student* SortedList::find(int studentID){
    Listnode *curr = head;
    while(curr != NULL){
        //if the student is found, return it
        if(curr->student->getID() == studentID){
            return curr->student;
        }
        //otherwise continue traversing the chain
        curr = curr->next;
    }
    return NULL;
}

// Searches the list for a student with the given student ID.  If the
// student is found, the student is removed from the list and returned;
// if no student is found with the given ID, NULL is returned.
// Note that the Student is NOT deleted - it is returned - however,
// the removed list node should be deleted.
//
// @param studentID: the 6-digit ID of the student to be removed
// @returns a pointer to the student that's removed from the list, or NULL if not found
Student* SortedList::remove(int studentID){
    //Listnode variables to help with manipulation
    Listnode *curr = head;
    Listnode *tmp = head;
    Listnode *back = head;
    int itr = 0; //used to determine if node we want is the first in the chain
    bool found = false;
    while(curr != NULL && !found){
        //if we found the node we want, remove it
        if(curr->student->getID() == studentID){
            found = true;
            tmp = curr;
            curr = curr->next;
            //if it's the first in the chain, set head accordingly
            if(itr == 0){
                head = curr;
            }
            //otherwise, set the previous node accordingly
            else{
            back->next = curr;
            }
            tmp->next = NULL;
            Student *returned = tmp->student; //Student variable so we can delete the node
            delete tmp; //deallocate tmp's memory in the heap
            return returned;
        }
        //otherwise traverse and keep looking
        back = curr;
        curr = curr->next;
        itr++;
    }
    return NULL;
}

// Prints out the list of students to standard output.  The students are
// printed in order of student ID (from smallest to largest), one per line
void SortedList::print() const{
    Listnode *curr = head;
    if(head->student == NULL){
        cout << "Nothing in the list!" << endl;
    }
    while(curr != NULL){
        curr->student->print();
        cout << endl; // line inbetween each student
        curr = curr->next;
    }
}