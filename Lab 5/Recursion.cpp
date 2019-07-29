/*****************************************************

Name: Anthony Huynh
Date: 10/21/18
Description: implentation file for recursion

******************************************************/

#include "Recursion.hpp"
#include <iostream>

//recursively reversing a string
//c is last letter of string
//will display c, then call itself
//if there is one character in the length, will output an endl
void stringReverse(std::string stringIn)
{
	char c = stringIn[stringIn.length()-1];
	std::cout << c;
	if (stringIn.length() > 1)
	{
		stringReverse(stringIn.substr(0, stringIn.length()-1));
	}
	if (stringIn.length() == 1)
	{
		std::cout << std::endl;
	}

}


//starts with back of array then relies on recursion to add in back of array until array size is 1
//when array size is 1, it returns index 0 of that array
int arraySum(int* array, int arraySize)
{
	if (arraySize > 1)
	{
		return array[arraySize - 1] + arraySum(array, arraySize - 1);
	}

	if (arraySize == 1)
	{
		return array[0];
	}
}


//starts with the highest number(n) and adds the second highest number through recursion since n will be
//decreased by 1 each call
//will return 1 when n = 1
int calcTriangNumber(int n)
{
	if (n > 1)
	{
		return n + calcTriangNumber(n - 1);
	}

	if (n == 1)
	{
		return 1;
	}
}