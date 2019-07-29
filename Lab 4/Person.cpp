/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: implementation file for Person class

******************************************************/

#include "Person.hpp"

//constructor with two parameters for name and age
Person::Person(std::string nameIn, int ageIn)
{
	name = nameIn;
	age = ageIn;
}

std::string Person::getName()
{
	return name;
}

int Person::getAge()
{
	return age;
}

//will return true if person object is student, will return false if person object is an instructor
bool Person::isAStudent()
{
	switch (isStudent)
	{
	case true:
		return true;
		break;
	case false: 
		return false;
		break;
	default:
		return true;
		break;
	}
}