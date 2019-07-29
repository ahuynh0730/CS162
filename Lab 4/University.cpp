/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: implementation file for University class

******************************************************/


#include "University.hpp"
#include <iostream>
#include "inputValidation.hpp"
#include <iomanip>
#include <fstream>


//constructor with 0 parameters that places two buildings, one student, and one instructor in vector
University::University()
{

	studentOrInstructor.addOption("Student");
	studentOrInstructor.addOption("Instructor");


}

//to be called after initializing university, will ask for two buildings, one student, and one instructor
void University::startUniversity()
{
	//variables needed for new student and instructor
	std::string newName;
	int newAge;
	float GPA_orRating;

	//to add two buildings
	addBuilding();
	
	addBuilding();

	//to add student
	std::cout << "What is the student's name? ";
	std::getline(std::cin, newName);
	std::cout << "How old is the student? ";
	newAge = integerCheck(18, 100);
	std::cout << "What is the student's GPA? ";
	GPA_orRating = floatCheck(1, 4);
	people.push_back(new Student(newName, newAge, GPA_orRating));
	personMenu.addOption(newName);

	//to add instructor
	std::cout << "What is the instructor's name? ";
	std::getline(std::cin, newName);
	std::cout << "How old is the instructor? ";
	newAge = integerCheck(18, 100);
	std::cout << "What is the instructor's rating? ";
	GPA_orRating = floatCheck(1, 5);
	people.push_back(new Instructor(newName, newAge, GPA_orRating));
	personMenu.addOption(newName);
}

//to display all building info
void University::displayBuildings()
{
	for (int i = 0; i < buildings.size(); i++)
	{
		std::cout << buildings[i].getBuildingName() << " is at " << buildings[i].getBuildingAddress() << " and has "
			<< buildings[i].getBuildingSize() << " square feet." << std::endl;
	}
}

//to get all info from user and then push back a new building onto the vector
void University::addBuilding()
{
	std::string newName;
	int newSize;
	std::string newAddress;

	std::cout << "What is the name of the new building? ";
	std::getline(std::cin, newName);

	std::cout << "How many square feet does this building have? ";
	newSize = integerCheck(1, 100000);

	std::cout << "What is the address of the new building? ";
	std::getline(std::cin, newAddress);

	buildings.push_back(Building(newName, newSize, newAddress));
}


//to display information on everybody
void University::displayPeopleInfo()
{
	for (int i = 0; i < people.size(); i++)
	{
		//displays message for student
		if (people[i]->isAStudent())
		{
			std::cout << people[i]->getName() << " is a student " << people[i]->getAge() << " years old with "
				<< "a GPA of " << std::fixed << std::setprecision(2) << people[i]->getGPA_orRating() << "." << std::endl;
		}
		//displays message for instructor
		else
		{
			std::cout << people[i]->getName() << " is an instructor " << people[i]->getAge() << " years old with "
				<< "a rating of " << std::fixed << std::setprecision(2) << people[i]->getGPA_orRating() << "." << std::endl;
		}
	}
}

//to have a person work
void University::havePersonWork()
{
	std::cout << "Who would you like to do work?" << std::endl;
	int personChoice;
	personMenu.displayMenu();
	personChoice = integerCheck(1, personMenu.getVectorSize());
	people[personChoice - 1]->do_work();
}

//to add a person
void University::addPerson()
{
	int personChoice;
	std::cout << "What would you like to add?" << std::endl;
	studentOrInstructor.displayMenu();
	personChoice = integerCheck(1, 2);

	std::string newName;
	int newAge;
	switch (personChoice)
	{
	case 1:
		float newGPA;
		std::cout << "What is the student's name? ";
		std::getline(std::cin, newName);

		std::cout << "How old is the student? ";
		newAge = integerCheck(18, 100);

		std::cout << "What is the student's GPA? ";
		newGPA = floatCheck(0, 4);

		people.push_back(new Student(newName, newAge, newGPA));
		break;
	case 2:
		float newRating;
		std::cout << "What is the Instructor's name? ";
		
		std::getline(std::cin, newName);

		std::cout << "How old is the Instructor? ";
		newAge = integerCheck(18, 100);

		std::cout << "What is the Instructor's Rating? ";
		newGPA = floatCheck(0, 5);

		people.push_back(new Instructor(newName, newAge, newGPA));
		break;
	}
	personMenu.addOption(newName);
	
}

//to save information to a file
void University::saveToFile()
{
	std::ofstream outputFile;
	std::string fileName;
	std::cout << "What is the name of the file to save all the information to? Please include the file type(.txt) ";
	std::getline(std::cin, fileName);

	//if file does not open
	outputFile.open(fileName);
	if (!outputFile)
	{
		std::cout << "File Open Error! " << std::endl;
	}

	//starts writing all building data to file
	
	for (int i = 0; i < buildings.size(); i++)
	{
		outputFile << "Building:" << std::endl;
		outputFile << buildings[i].getBuildingName() << std::endl;
		outputFile << buildings[i].getBuildingSize() << std::endl;
		outputFile << buildings[i].getBuildingAddress() << std::endl;
		outputFile << std::endl;
	}

	//starts writing all people data to file
	
	for (int i = 0; i < people.size(); i++)
	{
		outputFile << "Person!" << std::endl;
		//will output whether the person is a student or instructor
		if (people[i]->isAStudent())
		{
			outputFile << "Student" << std::endl;
		}
		else
		{
			outputFile << "Instructor" << std::endl;
		}

		outputFile << people[i]->getName() << std::endl;
		outputFile << people[i]->getAge() << std::endl;
		outputFile << people[i]->getGPA_orRating() << std::endl;
		outputFile << std::endl;
	}
	outputFile.close();
}

//to start university by reading from a file

void University::readFromFile()
{
	//variables needed for building
	std::string buildingName;
	int buildingSize;
	std::string buildingAddress;

	//variables needed for people
	std::string personType;
	std::string personName;
	int personAge;
	float personGPA_orRank;

	std::string tempString;
	std::ifstream inputFile;
	std::string fileName;
	std::cout << "What is the name of the file you wish to open? Please include the file type(.txt for example) ";
	std::getline(std::cin, fileName);

	//if input file does not open
	inputFile.open(fileName);
	if (!inputFile)
	{
		std::cout << "File Open Error! " << std::endl;
	}

	char ch;
	while (!inputFile.fail())
	{
		ch = inputFile.get();
		//if char is a colon indicating building data
		if (ch == ':')
		{
			inputFile.ignore(256, '\n');
			std::getline(inputFile, buildingName);
			std::getline(inputFile, tempString);
			buildingSize = std::stoi(tempString);
			std::getline(inputFile, buildingAddress);
			buildings.push_back(Building(buildingName, buildingSize, buildingAddress));
		}
		//if char is an ! indicating person data
		else if (ch == '!')
		{
			inputFile.ignore(256, '\n');
			std::getline(inputFile, personType);
			std::getline(inputFile, personName);
			std::getline(inputFile, tempString);
			personAge = std::stoi(tempString);
			std::getline(inputFile, tempString);
			personGPA_orRank = std::stof(tempString);
			if (personType == "Student")
			{
				people.push_back(new Student(personName, personAge, personGPA_orRank));
			}
			else if (personType == "Instructor")
			{
				people.push_back(new Instructor(personName, personAge, personGPA_orRank));
			}
			personMenu.addOption(personName);
		}
	}
}


//destructor that will delete all people in people vector
University::~University()
{
	for (int i = 0; i < people.size(); i++)
	{
		delete people[i];
	}
}