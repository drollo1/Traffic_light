//--------------------------------------------------------------------------------------------------------------------
// Name:  IntersectionFlowRate.cpp
// Class: CMSC 341 sec 1
// Asignment:  proj1
//
// Author: Dominic Rollo
// Email: drollo1@umbc.edu
// Description: stores flow rates with setters and getters
//--------------------------------------------------------------------------------------------------------------------

#include "IntersectionFlowRate.h"

IntersectionFlowRate::IntersectionFlowRate() {}

IntersectionFlowRate::IntersectionFlowRate(int fRMoto, int fRCar, int fRTruck)
{
	m_FRMoto = 60/fRMoto;
	m_FRCar = 60/fRCar;
	m_FRTruck = 60/fRTruck;
}

void IntersectionFlowRate::setFRMoto(int fRMoto)
{	m_FRMoto = fRMoto;	}

int IntersectionFlowRate::getFRMoto()
{	return m_FRMoto;	}

void IntersectionFlowRate::setFRCar(int fRCar)
{	m_FRCar = fRCar;	}

int IntersectionFlowRate::getFRCar()
{	return m_FRCar;	}

void IntersectionFlowRate::setFRTruck(int fRTruck)
{	m_FRTruck = fRTruck;	}

int IntersectionFlowRate::getFRTruck()
{	return m_FRTruck;	}