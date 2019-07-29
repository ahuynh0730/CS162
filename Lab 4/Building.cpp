/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: implementation file for Building class

******************************************************/

#include "Building.hpp"

//constructor with 3 parameters to set building name, size, and address
Building::Building(std::string name, int size, std::string address)
{
	buildingName = name;
	buildingSize = size;
	buildingAddress = address;
}

std::string Building::getBuildingName()
{
	return buildingName;
}

int Building::getBuildingSize()
{
	return buildingSize;
}

std::string Building::getBuildingAddress()
{
	return buildingAddress;
}
