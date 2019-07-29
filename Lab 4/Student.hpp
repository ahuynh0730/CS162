/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: header file for Student class

******************************************************/


#ifndef STUDENT_hpp
#define STUDENT_hpp

#include "Person.hpp"


class Student : public Person
{
private:
	float GPA;

public:
	Student(std::string, int, float);
	void do_work();
	float getGPA_orRating();
};

#endif // !STUDENT_hpp

