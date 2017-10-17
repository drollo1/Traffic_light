//--------------------------------------------------------------------------------------------------------------------
// Name:  IntersectionFlowRate.h
// Class: CMSC 341 sec 1
// Asignment:  proj1
//
// Author: Dominic Rollo
// Email: drollo1@umbc.edu
// Description: Defines the InterSectionFlowRate class
//--------------------------------------------------------------------------------------------------------------------

#ifndef INTERSECTIONFLOWRATE_H_
#define INTERSECTIONFLOWRATE_H_

#include <iostream>
using namespace std;

class IntersectionFlowRate
{
  private:
	int m_FRMoto;
	int m_FRCar;
	int m_FRTruck;

  public:
	IntersectionFlowRate();
	IntersectionFlowRate(int fRMoto, int fRCar, int fRTruck);
	void setFRMoto(int fRMoto);
	void setFRCar(int fRCar);
	void setFRTruck(int fRTruck);
	int getFRMoto();
	int getFRCar();
	int getFRTruck();
};

#endif