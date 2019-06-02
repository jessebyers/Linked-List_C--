//Mr Jesse Byers
//3162857
//SENG1120 - Assignment 1
//LinkedList.cpp

#include "LinkedList.h"

#include <cstdlib> //NULL
#include <iostream>
using namespace std;

ostream& operator << (ostream& outs, LinkedList& input) 
{
	Node* current = input.getTail();


	while (current != NULL) {
		outs << current->getData() << " ";
		current = current->getPrevious();

	}  

	return outs;

}

void LinkedList::operator += (LinkedList& rhs)
{	

	Node* current = rhs.getTail();

	while (current != NULL){

		addToHead(current->getData());

		current = current->getPrevious();
	}


}

	/////////////////////CONSTRUCTOR/DESTRUCTOR/////////////////////////////////


LinkedList::LinkedList(){

	head = NULL;
	tail = NULL;
	current = NULL;
	list_length = 0;

}

LinkedList::LinkedList(const data_type& data){ 

	int stringLength = 0;
	int spaceIndex = 0;

	data_type* inputString = new data_type;
	*inputString = data;

	data_type* tempString = new data_type;

	stringLength  = inputString->length();

	//list fill out		
	spaceIndex = inputString->find(" ", 0); // first space index location
	*tempString = inputString->substr (0,spaceIndex); //seperate the word

	head = new Node(*tempString);
	tail = head;
	current = tail;
	list_length = 1;

	*inputString = inputString->substr(spaceIndex + 1, stringLength); //adjust word by starting at space index
	stringLength  = inputString->length(); //set length



	while (stringLength > 0 && spaceIndex != -1){
			

		spaceIndex = inputString->find(" ", 0); // first space index location
			
		*tempString = inputString->substr (0,spaceIndex); //seperate the word
			
		addToHead(*tempString); // add the word to the list
				
		*inputString = inputString->substr(spaceIndex + 1, stringLength); //adjust word by starting at space index
				
		stringLength  = inputString->length(); //set length
				
				
	} 

	spaceIndex = 0; //reset


	}

LinkedList::~LinkedList(){ //Destructor

	while(head != NULL){
		removeHead();
		tail = NULL;

	}

}

	/////////////////////GET FUNCTIONS//////////////////////////////////

		Node* LinkedList::getTail(){

			return tail;
		}

		Node* LinkedList::getHead(){

			return head;
		}


	/////////////////////MUTATOR FUNCTIONS//////////////////////////////////


		void LinkedList::addToHead(data_type& data){


			if (list_length==0){

				head = new Node(data);
				tail = head;
				current = tail;
				list_length = 1;

			} else {

				Node* headinsert = new Node(data);
				head->setPrevious(headinsert);
				headinsert->setNext(head);
				head = headinsert;
				list_length++;
				headinsert = NULL;


			}

		}


		void LinkedList::addToTail(data_type& data){

			if (list_length==0){

				head = new Node(data);
				tail = head;
				current = tail;
				list_length = 1;

			} else {

				Node* tailinsert = new Node(data);

				tail->setNext(tailinsert);
				tailinsert->setPrevious(tail);
				tail = tailinsert;
				list_length++;
				tailinsert = NULL;


			}


		}

	////////////////////////REMOVE FUNCTIONS///////////////////////////////////

		void LinkedList::removeHead(){

			if (list_length==0){




			} 	else if (list_length==1){

				delete head;
				head = NULL;
				tail = NULL;
				list_length--;


			} else {

				Node* temphead = head;

				head = temphead->getNext();	
				head->setPrevious(NULL);

				temphead = NULL;
				delete temphead;
				list_length--;
				
				

			}

		}


		void LinkedList::removeTail(){

			if (list_length==0){


			} 	else if (list_length==1){

				delete head;
				head = NULL;
				tail = NULL;
				list_length--;

			} else {

				Node* temptail = tail;
				tail = temptail->getPrevious();

				temptail = NULL;
				delete temptail;
				list_length--;
				



			}


		}

		void LinkedList::remove(const data_type& input){ //removes a specific word in the list

		bool msgcount = 0; //0 is not found, 1 is found

		
		if (input == tail->getData()){

			removeTail();
			msgcount = 1;
		} 

		if (input == head->getData()) {

			removeHead();
			msgcount = 1;
		} 


		for (current = head->getNext(); current != tail; current = current->getNext()){

			if (input == current->getData() && input != head->getData() && input != tail->getData()){

				Node* temp;
				temp = current->getPrevious();
				temp->setNext(current->getNext());
				temp = current->getNext();
				temp->setPrevious(current->getPrevious());
				delete current;
				current = temp;
				list_length--;
				msgcount = 1;


			} 
		}

		

		if (msgcount == 0) {
			cout << "NOTICE: Word was not found in LinkedList" << endl;

		}

	}

	///////////////////////CURRENT FUNCTIONS//////////////////////////////////////

	Node* LinkedList::getCurrent(){

		return current;


	}


	void LinkedList::currentForward(){

		current = current->getNext();

	}

	void LinkedList::currentBack(){

		current = current->getPrevious();

	}

	void LinkedList::currentMoveToHead(){

		current = head;

	}

	void LinkedList::currentMoveToTail(){

		current = tail;

	}


	///////////////////////SIZE FUNCTIONS//////////////////////////////////////

	std::size_t LinkedList::size(){

		return list_length;
	}




