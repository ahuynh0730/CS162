/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: header file for University class

******************************************************/

#ifndef UNIVERSITY_hpp
#define UNIVERSITY_hpp
#include <string>
#include <vector>
#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"



class University
{
private:
	const std::string universityName = "Oregon State University";
	std::vector<Building> buildings;
	std::vector<Person*> people;
	Menu personMenu;
	Menu studentOrInstructor;

public:
	University();
	void startUniversity();
	void displayBuildings();
	void addBuilding();
	void displayPeopleInfo();
	void havePersonWork();
	void addPerson();
	void saveToFile();
	void readFromFile();
	~University();
};

#endif // !UNIVERSITY_hpp

