//--------------------------------------------------------------------------------------------------------------------
// Name:  LinkedList.h
// Class: CMSC 341 sec 1
// Asignment:  proj1
//
// Author: Dominic Rollo
// Email: drollo1@umbc.edu
// Description: Defines the LinkedList class
//--------------------------------------------------------------------------------------------------------------------

#ifndef LINKEDLINKED_H_
#define LINKEDLINKED_H_

#include "Vehicle.h"

struct NODE
{
	Vehicle carNode;
	NODE * link;
};


class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void insert(Vehicle  dequeued);
	Vehicle last();
	int count();
	int motoCount();
	int carCount();
	int truckCount();
	int totalWait();
	double averageWait();
	bool isEmpty();
private:
	NODE *FRONT_ptr, *REAR_ptr, *CURSOR, *INSERT, *PREVIOUS_ptr;
};


#endif