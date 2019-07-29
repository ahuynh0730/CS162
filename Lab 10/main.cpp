/****************************************

	By: Anthony Huynh
	Date: 12/2/2018
	Description: This program will compare efficeiency of iteration vs recursion of fibonacci numbers

******************************************/

#include <iostream>
#include <time.h>
#include "inputValidation.hpp"

//recursive fibonacci function obtained from https://www.thecrazyprogrammer.com/2014/12/c-cpp-program-for-fibonacci-series-using-recursion.html
int fibonacci(int n);

int main()
{
	int t1 = 1, t2 = 1, nextTerm = 0;
	clock_t iterationTime;
	clock_t recursionTime;
	int numbFibonacci;
	std::cout << "Which fibonacci number would you like the program to calculate? (between 3 and 40) ";
	numbFibonacci = integerCheck(3, 40);



	//fibonacci algorithm modified from https://www.programiz.com/cpp-programming/examples/fibonacci-series
	iterationTime = clock();
	for (int i = 3; i <= numbFibonacci; i++)
	{
		nextTerm = t1 + t2;
		t1 = t2;
		t2 = nextTerm;
	}
	iterationTime = clock() - iterationTime;

	recursionTime = clock();
	nextTerm = fibonacci(numbFibonacci);
	recursionTime = clock() - recursionTime;

	std::cout << "The " << numbFibonacci << "th fibonacci term is: " << nextTerm << std::endl;
	std::cout << "Iteration took " << iterationTime << " clicks." << std::endl;
	std::cout << "Recursion took " << recursionTime << " clicks." << std::endl;

	

	return 0;
}

int fibonacci(int n)
{
	if ((n == 1) || (n == 0))
	{
		return(n);
	}
	else
	{
		return(fibonacci(n - 1) + fibonacci(n - 2));
	}
}