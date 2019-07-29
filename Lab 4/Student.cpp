/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: implementation file for Student class

******************************************************/

#include "Student.hpp"
#include <iostream>

//constructor that uses the person constructor and the float to set gpa
Student::Student(std::string nameIn, int ageIn, float GPA_in) : Person(nameIn,ageIn)
{
	GPA = GPA_in;
	isStudent = true;
	isInstructor = false;
}

//to have a student do work
void Student::do_work()
{
	int hwHours = rand() % 25;
	std::cout << name << " did " << hwHours << " hours of homework." << std::endl;
}

float Student::getGPA_orRating()
{
	return GPA;
}

