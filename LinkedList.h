//Mr Jesse Byers
//3162857
//SENG1120 - Assignment 1
//LinkedList.h

#ifndef JESSE_ASSIGNMENT1LL
#define JESSE_ASSIGNMENT1LL

#include <cstdlib> //NULL
#include <iostream>
#include "Node.h"

using namespace std;


class LinkedList
{


public:

	typedef string data_type;

	// Constructors
	// Precondition: none
    // Postcondition: Sets head, tail current to null and list length to 0
	LinkedList();

	// Precondition: none 
    // Postcondition: data is passed through and each token is stored seperately in each node
	LinkedList(const data_type& data);

	//Destructor
	// Precondition: linked list has been initialized 
    // Postcondition: the linked list is deleted
	~LinkedList(); 

	//Mutators
	// Precondition: linked list has been initialized 
    // Postcondition: data is added to the head
	void addToHead(data_type& data);

	// Precondition: linked list has been initialized 
    // Postcondition: data is added to the tail
	void addToTail(data_type& data);

	// Precondition: head has been initialized with data
    // Postcondition: head is removed and is replaced by the next node
	void removeHead();

	// Precondition: tail has been initialized with data
    // Postcondition: tail is removed and is replaced by the previous node
	void removeTail();

	// Precondition: current has been initialized with data
    // Postcondition: returns the current node
	Node* getCurrent();

	// Precondition: current has been initialized with data
    // Postcondition: current is changed to the next node in the linked list
	void currentForward();

	// Precondition: current has been initialized with data
    // Postcondition: current is changed to the previous node in the linked list
	void currentBack();	

	// Precondition: current has been initialized with data
    // Postcondition: current is changed to the head node in the linked list
	void currentMoveToHead();

	// Precondition: current has been initialized with data
    // Postcondition: current is changed to the tail node in the linked list
	void currentMoveToTail();

	// Precondition: 
    // Postcondition: all nodes that match the input are removed from the linked list 
	void remove(const data_type& input);

	// Precondition: linked list has been initialized with data
    // Postcondition: copys the contents of one linked list to the end of another. Original list is not deleted.
	void operator += (LinkedList& rhs); 
	
	// Precondition: tail has been initialized with data
    // Postcondition: tail is returned
	Node* getTail();

	// Precondition: head has been initialized with data
    // Postcondition: head is returned
	Node* getHead();

	// Precondition: linked list has been initialized
    // Postcondition: size is returned
	size_t size();



private:

	Node* head;
	Node* tail;
	Node* current;

	size_t list_length;

};

// Precondition: linked list has been initialized with data
// Postcondition: outputs the sequence of nodes in order as they are added
ostream& operator <<(ostream& outs, LinkedList& input); 


#endif