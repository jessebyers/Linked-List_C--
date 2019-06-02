//Mr Jesse Byers
//3162857
//SENG1120 - Assignment 1
//Node.h


#ifndef JESSE_ASSIGNMENT1N
#define JESSE_ASSIGNMENT1N

#include <cstdlib> //NULL
#include <iostream>


using namespace std;


class Node
{


	typedef string data_type; 


	public:

	//Constructor
	// Precondition: none
    // Postcondition: node is initialized with data.
		Node(const data_type& initdata);


	// Precondition: none
    // Postcondition: next previous and data is set to NULL
		Node();
		
//Destructor
	// Precondition: node is initialized with data.
    // Postcondition: nodes data is set to NULL.
		~Node();


//Gets
    // Precondition: data has been initialized
    // Postcondition: data is returned
		data_type getData() const;

		// Precondition: data has been initialized
    // Postcondition: data is returned
		data_type& getData();

		// Precondition: next has been initialized
    // Postcondition: next is returned
		Node* getNext();

		// Precondition: previous has been initialized
    // Postcondition: previous is returned
		Node* getPrevious();


  //Sets
	// Precondition: node has been initialized
    // Postcondition: data is set with new data
		void setData(data_type& newData);

		// Precondition: node has been initialized
    // Postcondition: next is set to a new node
		void setNext(Node* nextLink);

		// Precondition: node has been initialized
    // Postcondition: previous is set to a new node
		void setPrevious(Node* previousLink);





	private:
		data_type data;
		Node* next;
		Node* previous;




};


#endif

