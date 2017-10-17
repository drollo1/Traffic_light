//--------------------------------------------------------------------------------------------------------------------
// Name:  Driver.cpp
// Class: CMSC 341 sec 1
// Asignment:  proj1
//
// Author: Dominic Rollo
// Email: drollo1@umbc.edu
// Description: Program Driver
//--------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include "TrafficSim.h"

using namespace std;

int main(int argc, char *argv[]) {
    //If there is an input file listed
    if (argc > 1) {
        TrafficSim *Sim = new TrafficSim(argv[1]);
        Sim->DoRun();
        delete Sim;
        Sim = NULL;

        //If no input file is specified.
    } else {
        TrafficSim *Sim = new TrafficSim();
        Sim->DoRun();
        delete Sim;
        Sim = NULL;
     }
    
    // endl(cout << clock() / (float)CLOCKS_PER_SEC);
    return 0;
}