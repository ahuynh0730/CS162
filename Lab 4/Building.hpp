/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: header file for Building class

******************************************************/


#ifndef BUILDING_hpp
#define BUILDING_hpp

#include <string>

class Building
{
private:
	std::string buildingName;
	int buildingSize;
	std::string buildingAddress;

public:
	Building(std::string, int, std::string);
	std::string getBuildingName();
	int getBuildingSize();
	std::string getBuildingAddress();
};

#endif // !BUILDING_hpp

