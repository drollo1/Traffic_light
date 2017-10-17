//--------------------------------------------------------------------------------------------------------------------
// Name:  Vehicl.cpp
// Class: CMSC 341 sec 1
// Asignment:  proj1
//
// Author: Dominic Rollo
// Email: drollo1@umbc.edu
// Description: Vehicles store data about how long they take in queues and to exit intersection
//--------------------------------------------------------------------------------------------------------------------

#include "Vehicle.h"

Vehicle::Vehicle(){}


Vehicle::Vehicle(int type, int enter, int clear)
{
	m_type = type;
	m_enter = enter;
	m_clear = clear;
}

void Vehicle::setType(int type)
{
	m_type = type;
}

int Vehicle::getType()
{
	return m_type;
}

void Vehicle::setEnter(int enter)
{
	m_enter = enter;
}

int Vehicle::getEnter()
{
	return m_enter;
}


void Vehicle::setExit(int exit)
{
	m_exit = exit;
}

int Vehicle::getExit(){
	return m_exit;
}

void Vehicle::setClear(int clear)
{
	m_clear = clear;
}

int Vehicle::getClear()
{
	return m_clear;
}

ostream& operator <<(ostream& os, const Vehicle& obj){
	if (obj.m_type == 1)
		os << "M";
	else if (obj.m_type == 2)
		os << "C";
	else if (obj.m_type == 3)
		os << "T";
	else
		os << " ";
	return os;
}