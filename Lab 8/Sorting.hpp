/*****************************************************

	By: Anthony Huynh
	Date: 11/18/2018
	Description: header file for functions related to searching/sorting a vector of ints

*******************************************************/



#ifndef SORTING_hpp
#define SORTING_hpp

#include <string>
#include <vector>

void fillVectorFromFile(std::vector<int>&, std::string);
int linearSearch(const std::vector<int>&, int);
void displayFound(std::string, int);
void selectionSort(std::vector<int>&);
void displayVector(const std::vector<int>&, std::string);
void writeVector(const std::vector<int>&, std::string);
int binarySearch(const std::vector<int>&, int);

#endif // !SORTING_hpp

