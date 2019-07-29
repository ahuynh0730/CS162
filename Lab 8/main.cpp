/*****************************************************

	By: Anthony Huynh
	Date: 11/18/2018
	Description: This will read in a list of integers in a file and store them in a vector.
		Then all vectors will be searched and see if user's input was found.

*******************************************************/

#include <iostream>

#include <vector>
#include <string>
#include "Sorting.hpp"
#include "inputValidation.hpp"

int main()
{
	std::vector<int> originalVector;
	std::vector<int> earlyVector;
	std::vector<int> middleVector;
	std::vector<int> endVector;
	const std::string originalText = "Original.txt";
	const std::string earlyText = "Early.txt";
	const std::string middleText = "Middle.txt";
	const std::string endText = "End.txt";

	//to fill the four vectors using files
	fillVectorFromFile(originalVector, originalText);
	fillVectorFromFile(earlyVector, earlyText);
	fillVectorFromFile(middleVector, middleText);
	fillVectorFromFile(endVector, endText);

	//requests value to be searched for between 0 and 10000
	int searchValue;
	std::cout << "What is the value to be searched for? ";
	searchValue = integerCheck(0, 10000);
	std::cout << std::endl;

	//searches 4 vectors and displays location found if in vector
	int positionFound = linearSearch(originalVector, searchValue);
	displayFound(originalText, positionFound);
	positionFound = linearSearch(earlyVector, searchValue);
	displayFound(earlyText, positionFound);
	positionFound = linearSearch(middleVector, searchValue);
	displayFound(middleText, positionFound);
	positionFound = linearSearch(endVector, searchValue);
	displayFound(endText, positionFound);

	//sorts the four vectors
	selectionSort(originalVector);
	selectionSort(earlyVector);
	selectionSort(middleVector);
	selectionSort(endVector);

	//shows and outputs sorted vectors
	std::cout << std::endl;
	writeVector(originalVector, originalText);
	displayVector(originalVector, originalText);

	writeVector(earlyVector, earlyText);
	displayVector(earlyVector, earlyText);

	writeVector(middleVector, middleText);
	displayVector(middleVector, middleText);

	writeVector(endVector, endText);
	displayVector(endVector, endText);

	//requests value for a binary search between 0 and 10000
	searchValue;
	std::cout << "What is the value to be searched (using binary search) for? ";
	searchValue = integerCheck(0, 10000);
	std::cout << std::endl;

	//searches 4 vectors and displays location found if in vector
	positionFound = binarySearch(originalVector, searchValue);
	displayFound(originalText, positionFound);
	positionFound = binarySearch(earlyVector, searchValue);
	displayFound(earlyText, positionFound);
	positionFound = binarySearch(middleVector, searchValue);
	displayFound(middleText, positionFound);
	positionFound = binarySearch(endVector, searchValue);
	displayFound(endText, positionFound);


	return 0;

}