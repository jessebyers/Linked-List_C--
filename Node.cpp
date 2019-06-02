//Mr Jesse Byers
//3162857
//SENG1120 - Assignment 1
//Node.cpp


#include <cstdlib> //NULL
#include <iostream>
#include "Node.h"

using namespace std;


	
	Node::Node(const data_type& initdata){

		data = initdata;
		next = NULL;
		previous = NULL;
	}

	Node::Node(){
		data = data_type();
		next = NULL;
		previous = NULL;

	}



	Node::~Node(){
			
	next = NULL;
	previous = NULL;

	}

	Node::data_type Node::getData() const{
		return data;
	}


	Node::data_type& Node::getData(){
		return data;
	}



	Node* Node::getNext(){
		return next;
	}


	
	Node* Node::getPrevious(){
		return previous;
	}
   

	void Node::setData(data_type& newData){
		data = newData;
	}


	
	void Node::setNext(Node* nextLink){
		next = nextLink;
	}


	
	void Node::setPrevious(Node* previousLink){
		previous = previousLink;
	}
