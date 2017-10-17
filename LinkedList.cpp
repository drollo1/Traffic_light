//--------------------------------------------------------------------------------------------------------------------
// Name:  LinkedList.cpp
// Class: CMSC 341 sec 1
// Asignment:  proj1
//
// Author: Dominic Rollo
// Email: drollo1@umbc.edu
// Description: Manages links in the list and can store vehicle objects in each node
//--------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "LinkedList.h"

LinkedList::LinkedList()
{
	FRONT_ptr = NULL;
	REAR_ptr = NULL;
	PREVIOUS_ptr = NULL;
}

LinkedList::~LinkedList()
{
  while(FRONT_ptr != NULL)
  {
      CURSOR = FRONT_ptr;
      FRONT_ptr = FRONT_ptr -> link; // moves FRONT_ptr up one node
	  delete CURSOR; // deletes and return NODE back to free memory!!!
  }
}

void LinkedList::insert(Vehicle  dequeued){
	INSERT = new NODE;	
	if(isEmpty()){
		INSERT->  carNode = dequeued;	
		INSERT -> link = NULL;
		FRONT_ptr = INSERT;
		REAR_ptr = INSERT;
	}
	else{
		INSERT->  carNode = dequeued;	
		REAR_ptr -> link = INSERT;
		INSERT -> link = NULL;
		REAR_ptr = INSERT;
	}
}

Vehicle LinkedList::last(){
	Vehicle temp = REAR_ptr -> carNode;
	return temp;
}

int LinkedList::count(){
	int result=0;
	CURSOR = FRONT_ptr;
	for(CURSOR = FRONT_ptr; CURSOR; CURSOR = CURSOR-> link){
		result++;
	}
	return result;
}

int LinkedList::motoCount(){
	int result=0;
	CURSOR = FRONT_ptr;
	for(CURSOR = FRONT_ptr; CURSOR; CURSOR = CURSOR-> link){
		int temp = CURSOR->carNode.getType();
		if(temp==1)
			result++;
	}
	return result;
}

int LinkedList::carCount(){
	int result=0;
	CURSOR = FRONT_ptr;
	for(CURSOR = FRONT_ptr; CURSOR; CURSOR = CURSOR-> link){
		int temp = CURSOR->carNode.getType();
		if(temp ==2)
			result++;
	}
	return result;
}

int LinkedList::truckCount(){
	int result=0;
	CURSOR = FRONT_ptr;
	for(CURSOR = FRONT_ptr; CURSOR; CURSOR = CURSOR-> link){
		int temp = CURSOR->carNode.getType();
		if(temp ==3)
			result++;
	}
	return result;
}


int LinkedList::totalWait(){
	int result =0;
	CURSOR = FRONT_ptr;
	for(CURSOR = FRONT_ptr; CURSOR; CURSOR = CURSOR-> link){
		Vehicle temp = CURSOR-> carNode;
		result+= temp.getExit() - temp.getEnter();		
	}
	return result;
}

double LinkedList::averageWait() {
	double result;
	result = 5 / 2;
	return result;
}

bool LinkedList::isEmpty()
{
	if ((FRONT_ptr == NULL) && (REAR_ptr == NULL))	{ return true; }
	else { return false;}
}