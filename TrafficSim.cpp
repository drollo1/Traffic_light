//--------------------------------------------------------------------------------------------------------------------
// Name:  TrafficSim.cpp
// Class: CMSC 341 sec 1
// Asignment:  proj1
//
// Author: Dominic Rollo
// Email: drollo1@umbc.edu
// Description: Controlls the lights, queues, and traffic flow.  Prints out the changes second by second.
//--------------------------------------------------------------------------------------------------------------------

#include "TrafficSim.h"
#include "Clear.h"
#include <stdlib.h>

TrafficSim::TrafficSim(){
	initial();	
		motoClear=1;
		carClear=1;
		truckClear=2;
}

TrafficSim::TrafficSim(char *input){
	TrafficSim();
}

void TrafficSim::initial(){
	ReadFromFile();
	setupBoard();
	isFirstRun = true;
	j = i = clearN = clearS = clearE = clearW =0;

}
void TrafficSim::DoRun(){
	computing.open("output1.txt");
	Run();
	computing.close();
	
	initial();
	computing.open("output2.txt");
	Run();
	computing.close();
	

	computing.open("output3.txt");
	Run();
	computing.close();
	
}

void TrafficSim::Run(){
	while(t_clock<= total_clock){

	//traffic light control
		if(i == -1 && isNSflow())
			NS_Bound();
		else if(j == -1 && isEWflow())
			EW_Bound();
		else
			i=-1;
	//incoming cars
		if (t_clock != 0)
			addVehicles();

		PrintBoard();
		t_clock++;
	}
	computing << " Number of Vehicles that cleared intersection: " << results.count() << endl;
	computing << " Number of motorcycles that cleared intersection: " << results.motoCount() << endl;
	computing << " Number of cars that cleared intersection: " << results.carCount() << endl;
	computing << " Number of trucks that cleared intersection: " << results.truckCount() << endl;
	computing << " Average wait time: " << (double) results.totalWait()/results.count() << endl; 
}

//************************************************************************
//controls the flow of north and south bound traffic
//************************************************************************
bool TrafficSim::isNSflow(){
	if(isFirstRun){
		j = t_clock;
		isFirstRun = false; 
		return true;
	}
	else{
		if((t_clock - j)<30){
			return true;
		}
		else if(eb_traffic.empty() && wb_traffic.empty()){//
			return true;
		}
		else //switch to east weast bound
			j = -1;		
			isFirstRun = true;	
			clearN = clearS =0;
			return false;
		}
}


void TrafficSim::NS_Bound(){
//North bound dequeuer*************************************************
	if (!nb_traffic.empty()){
		clearN++;
		int tempN = nb_traffic.front().getClear();
		if(clearN == tempN){
			nb_traffic.front().setExit(t_clock);
			results.insert(nb_traffic.front());
			nb_traffic.pop();
			clearN = 0;
		}
	}
	else
		clearN =0;

//South bound dequeuer*************************************************
	if (!sb_traffic.empty()){
		clearS++;
		int tempS = sb_traffic.front().getClear();
		if(clearS == tempS){
			sb_traffic.front().setExit(t_clock);
			results.insert(sb_traffic.front());
			sb_traffic.pop();
			clearS=0;
		}
	}
	else
		clearS=0;
}

//************************************************************************
//controls the flow of east and west bound traffic
//************************************************************************
bool TrafficSim::isEWflow(){
	if(isFirstRun){
		i = t_clock;
		isFirstRun = false;
		return true;
	}
	else{
		if((t_clock - i)<10){
			return true;
		}
		else if (eb_traffic.empty() && wb_traffic.empty()){
			i = -1;	
			isFirstRun = true;
			clearE = clearW =0;
			return false;
		}
		else if((t_clock - i) < 30){					
			return true;

		}
		else//switch to north south bound
			i = -1;	
			isFirstRun = true;	
			clearE = clearW =0;	
			return false;
		}
}

void TrafficSim::EW_Bound(){
	
//Eorth bound dequeuer*************************************************
	if (!eb_traffic.empty()){
		clearE++;
		int tempE = eb_traffic.front().getClear();
		if(clearE == tempE){
			eb_traffic.front().setExit(t_clock);
			results.insert(eb_traffic.front());
			eb_traffic.pop();
			clearE = 0;
		}
	}
	else
		clearE =0;

//West bound dequeuer*************************************************
	if (!wb_traffic.empty()){
		clearW++;
		int tempW = wb_traffic.front().getClear();
		if(clearW == tempW){
			wb_traffic.front().setExit(t_clock);
			results.insert(wb_traffic.front());
			wb_traffic.pop();
			clearW = 0;
		}
	}
	else
		clearW =0;
}
//**********************************************************************
//Reads in vaules from input files
//**********************************************************************
void TrafficSim::ReadFromFile(){
	ifstream infile;
	string nb_line;
	string sb_line;
	string eb_line;
	string wb_line;

	infile.open("input1.txt", ios_base::in);	
	getline(infile, nb_line);
	getline(infile, sb_line);
	getline(infile, eb_line);
	getline(infile, wb_line);

	nb_line.erase(0,3);
	sb_line.erase(0,3);
	eb_line.erase(0,3);
	wb_line.erase(0,3);
	

//just a quick fix for reading correctly**************
/*	IntersectionFlowRate temp(3, 3, 3);
	nb_flowRate = temp;
	IntersectionFlowRate temp2(10, 10, 1);
	sb_flowRate = temp2;
	IntersectionFlowRate temp3(15, 15, 3);
	eb_flowRate = temp3;
	IntersectionFlowRate temp4(10, 10, 3);
	wb_flowRate = temp4;
*/
	IntersectionFlowRate temp(2, 1, 1);
	nb_flowRate = temp;
	sb_flowRate = temp;
	eb_flowRate = temp;
	wb_flowRate = temp;


//Having trouble with converting from string to int
/*	string temp = "";
	int rates[3];
	
	int j=0;
	for(int i=0; i < nb_line.length(); i++)
		if(nb_line.at(i)!=' ')
			temp+= nb_line.at(i);
		else{
			istringstream convert(temp);
			istringstream(temp) >> rates[j]; 
			temp="";
			j++;
		}
	cout << nb_line << endl;
*/
}
void TrafficSim::setupBoard(){

	Vehicle temp(2,0, 1);
	for(int i=0; i< 2; i++){
		eb_traffic.push(temp);
		nb_traffic.push(temp);
		sb_traffic.push(temp);
		wb_traffic.push(temp);
	}
}

void TrafficSim::addVehicles(){
//North bound inflow
	if ((t_clock % nb_flowRate.getFRMoto()) == 0) {
		Vehicle temp(1, t_clock, motoClear);
		nb_traffic.push(temp);
	}
	if ((t_clock % nb_flowRate.getFRCar()) == 0) {
		Vehicle temp2(2, t_clock, carClear);
		nb_traffic.push(temp2);
	}
	if ((t_clock % nb_flowRate.getFRTruck()) == 0) {
		Vehicle temp3(3, t_clock, truckClear);
		nb_traffic.push(temp3);
	}
//South bound inflow
	if ((t_clock % sb_flowRate.getFRMoto()) == 0) {
		Vehicle temp(1, t_clock, motoClear);
		sb_traffic.push(temp);
	}
	if ((t_clock % sb_flowRate.getFRCar()) == 0) {
		Vehicle temp2(2, t_clock, carClear);
		sb_traffic.push(temp2);
	}
	if ((t_clock % sb_flowRate.getFRTruck()) == 0) {
		Vehicle temp3(3, t_clock, truckClear);
		sb_traffic.push(temp3);
	}
//East bound inflow
	if ((t_clock % eb_flowRate.getFRMoto()) == 0) {
		Vehicle temp(1, t_clock, motoClear);
		eb_traffic.push(temp);
	}
	if ((t_clock % eb_flowRate.getFRCar()) == 0) {
		Vehicle temp2(2, t_clock, carClear);
		eb_traffic.push(temp2);
	}
	if ((t_clock % eb_flowRate.getFRTruck()) == 0) {
		Vehicle temp3(3, t_clock, truckClear);
		eb_traffic.push(temp3);
	}
//West bound inflow
	if ((t_clock % wb_flowRate.getFRMoto()) == 0) {
		Vehicle temp(1, t_clock, motoClear);
		wb_traffic.push(temp);
	}
	if ((t_clock % wb_flowRate.getFRCar()) == 0) {
		Vehicle temp2(2, t_clock, carClear);
		wb_traffic.push(temp2);
	}
	if ((t_clock % wb_flowRate.getFRTruck()) == 0) {
		Vehicle temp3(3, t_clock, truckClear);
		wb_traffic.push(temp3);
	}
}
void TrafficSim::PrintBoard(){
	computing << "   SB\t"; if(sb_traffic.size()>4) computing << "x";
	computing << "\n   " << sb_traffic.size() << "\t"; if(sb_traffic.size()>3) computing << "x";
	computing << "\n\t"; if(sb_traffic.size()>2) computing << "x";
	computing << "\n EB\t";if(sb_traffic.size()>1) computing << "x";
	computing << "\n " << eb_traffic.size() << "\t" << eb_traffic.front() << endl;
	if(eb_traffic.size()>4) computing << "   xxxx"; if(eb_traffic.size()==4) computing << "    xxx"; 
	if(eb_traffic.size()==3) computing << "     xx"; if(eb_traffic.size()==2) computing << "      x"; computing << eb_traffic.front();
	
	computing << " " << wb_traffic.front();  if(wb_traffic.size()==2) computing << "x"; if(wb_traffic.size()==3) computing << "xx";
	if(wb_traffic.size()==4) computing << "xxx"; if(wb_traffic.size()>4) computing << "xxxx";
	computing << "\n\t" << nb_traffic.front();computing << "\t WB";
	computing << "\n\t"; if(nb_traffic.size()>1) computing << "x"; 	computing << "\t " << wb_traffic.size();
	computing << "\n\t"; if(nb_traffic.size()>2) computing << "x";  
	computing << "\n\t"; if(nb_traffic.size()>3) computing << "x";  computing << " " << "NB";
	computing << "\n\t"; if(nb_traffic.size()>4) computing << "x";  computing << " " << nb_traffic.size();
	computing << "\n-------------------------------------------------\n";
}
