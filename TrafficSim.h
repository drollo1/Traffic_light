//--------------------------------------------------------------------------------------------------------------------
// Name:  TrafficSim.h
// Class: CMSC 341 sec 1
// Asignment:  proj1
//
// Author: Dominic Rollo
// Email: drollo1@umbc.edu
// Description: Defines the TrafficSim class
//--------------------------------------------------------------------------------------------------------------------

#ifndef TRAFFICSIM_H_
#define TRAFFICSIM_H_

#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Vehicle.h"
#include "IntersectionFlowRate.h"
#include "LinkedList.h"

class TrafficSim
{
  private:
	ofstream output1, output2, output3, computing;
	queue <Vehicle> nb_traffic;
	queue <Vehicle> sb_traffic;
	queue <Vehicle> eb_traffic;
	queue <Vehicle> wb_traffic;
	LinkedList results;
	IntersectionFlowRate nb_flowRate;
	IntersectionFlowRate sb_flowRate;
	IntersectionFlowRate eb_flowRate;
	IntersectionFlowRate wb_flowRate;
//Clock control variables
	int t_clock;
	static int const total_clock = 120;
	int j;
	int i;
//Clearing variables
	int motoClear;
	int carClear;
	int truckClear;
//switch case variables
	bool isFirstRun;
//clearing control clocks
	int clearN;
	int clearS;
	int clearE;
	int clearW;
  public:
//constructor
	TrafficSim();
	TrafficSim(char *input);
//runs sim
	void initial();
	void DoRun();
	void ReadFromFile();
	void PrintBoard();
//adds vehicles to board
	void setupBoard();
	void addVehicles();
//direction of traffic
	void NS_Bound();
	void EW_Bound();
//traffic flow control
	bool isNSflow();
	bool isEWflow();
	void Run();
};

#endif