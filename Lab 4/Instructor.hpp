/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: header file for Instructor class

******************************************************/

#ifndef INSTRUCTOR_hpp
#define INSTRUCTOR_hpp

#include "Person.hpp"
#include <string>

class Instructor : public Person
{
private:
	float rating;

public:
	Instructor(std::string, int, float);
	void do_work();
	float getRating();
	bool isAnInstructor();
	float getGPA_orRating();
};

#endif // !INSTRUCTOR_hpp

