/*****************************************************

	By: Anthony Huynh
	Date: 11/18/2018
	Description: implemenetation file for functions related to searching/sorting a vector of ints

*******************************************************/

#include "Sorting.hpp"
#include <fstream>
#include <iostream>


//to fill a vector of ints given a fileName
void fillVectorFromFile(std::vector<int>& vectorIn, std::string fileName)
{
	std::ifstream inputFile;
	inputFile.open(fileName);
	if (!inputFile)
	{
		std::cout << "File Open Error! " << std::endl;
	}

	int temp;
	while (inputFile >> temp)
	{
		vectorIn.push_back(temp);
	}

	inputFile.close();
}

//simple linear search, will return position + 1 that value was found at,
//the additional one is to account for zero indexing
int linearSearch(const std::vector<int>& vectorIn, int value)
{
	for (unsigned int i = 0; i < vectorIn.size(); i++)
	{
		if (vectorIn[i] == value)
		{
			return i+1;
		}
	}

	return -1;
}

//if positionFound is -1, then value is not in vector
//else will display where first found value is at
void displayFound(std::string fileName, int positionFound)
{
	
	std::cout << fileName << ": ";
	if (positionFound == -1)
	{
		std::cout << "Target value not found";
	}
	else
	{
		std::cout << "Target value found at position " << positionFound;
	}
	std::cout << std::endl;
}

//sorts a vector using selection sort
//credit: http://www.algolist.net/algorithms/sorting/selection_sort
void selectionSort(std::vector<int>& vectorIn)
{
	int minIndex, tmp;
	for (unsigned int i = 0; i < vectorIn.size() - 1; i++) {
		minIndex = i;
		for (unsigned int j = i + 1; j < vectorIn.size(); j++)
		{
			if (vectorIn[j] < vectorIn[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i) 
		{
			tmp = vectorIn[i];
			vectorIn[i] = vectorIn[minIndex];
			vectorIn[minIndex] = tmp;
		}

	}
	
}

//displays vector contents
void displayVector(const std::vector<int>& vectorIn, std::string fileName)
{
	std::cout << fileName << " sorted: ";
	for (unsigned int i = 0; i < vectorIn.size(); i++)
	{
		std::cout << vectorIn[i] << "   ";
	}
	std::cout << std::endl;
}

//asks user for output file name and writes vector to that file
void writeVector(const std::vector<int>& vectorIn, std::string origFileName)
{
	std::string newFileName;
	std::ofstream outputFile;
	
	std::cout << "Please enter the file to save the sorted vector of " << origFileName << std::endl;
	std::getline(std::cin, newFileName);
	outputFile.open(newFileName);
	if (!outputFile)
	{
		std::cout << "File Open Error! " << std::endl;
	}
	for (unsigned int i = 0; i < vectorIn.size(); i++)
	{
		outputFile << vectorIn[i] << " ";
	}

	outputFile.close();

}

//credit: http://www.algolist.net/Algorithms/Binary_search
//performs a binary search on a vector
//will return position or -1 if not found
int binarySearch(const std::vector<int>& vectorIn, int searchValue) {
	int left = 0;
	int right = vectorIn.size();
	while (left <= right) 
	{
		int middle = (left + right) / 2;
		if (vectorIn[middle] == searchValue)
		{
			return middle;
		}
		else if (vectorIn[middle] > searchValue)
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}

	return -1;

}

