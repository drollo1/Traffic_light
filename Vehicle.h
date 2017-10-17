//--------------------------------------------------------------------------------------------------------------------
// Name:  Vehicle.h
// Class: CMSC 341 sec 1
// Asignment:  proj1
//
// Author: Dominic Rollo
// Email: drollo1@umbc.edu
// Description: Defines the Vehicle class
//--------------------------------------------------------------------------------------------------------------------

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include <string>
using namespace std;

struct Vehicle
{
  private:
	int m_type;
	int m_enter;
	int m_exit;
	int m_clear;

  public:
	Vehicle * link;


	Vehicle();
	Vehicle(int type, int enter, int clear);
	void setType(int type);
	void setEnter(int enter);
	void setExit(int exit);
	void setClear(int clear);
	int getType();
	int getEnter();
	int getExit();
	int getClear();	
	friend ostream& operator <<(ostream& os, const Vehicle& obj);


};

#endif