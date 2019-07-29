/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: header file for Person class

******************************************************/

#ifndef PERSON_hpp
#define PERSON_hpp

#include <string>
#include <iomanip>

class Person
{
protected:
	std::string name;
	int age;
	bool isStudent;
	bool isInstructor;
public:
	Person(std::string, int);
	std::string getName();
	int getAge();
	bool isAStudent();
	virtual float getGPA_orRating() = 0;
	virtual void do_work() = 0;
};

#endif // !PERSON_hpp

