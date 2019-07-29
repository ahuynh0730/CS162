/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: implementation file for Instructor class

******************************************************/

#include "Instructor.hpp"
#include <iostream>

//constructor that uses the person constructor and the float to set rating
Instructor::Instructor(std::string nameIn, int ageIn, float ratingIn) : Person(nameIn, ageIn)
{
	rating = ratingIn;
	isStudent = false;
	isInstructor = true;
}

//to have an instructor do work
void Instructor::do_work()
{
	int gradeHours = rand() % 25;
	std::cout << name << " graded papers for " << gradeHours << " hours." << std::endl;
}

//returns rating of professor
float Instructor::getGPA_orRating()
{
	return rating;
}

