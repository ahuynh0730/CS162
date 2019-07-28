/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  main file for program that counts frequency of each letter
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "count_letters.hpp"
#include "output_letters.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;


int main()
{
	//creating array where index 0 represents a and filling with 0
	int* letterArray = new int[26];
	for (int i = 0; i < 26; i++)
	{
		letterArray[i] = 0;
	}

	//getting file name from user
	string fileName;
	cout << "Please enter the file name to be opened." << endl;
	getline(cin, fileName);

	//creating fstream object and opening file
	ifstream inFile;
	inFile.open(fileName);

	//creating ostream object
	ofstream outFile;

	//to let user know file was not able to be opened and quits program
	if (inFile.fail())
	{
		cout << "The file was not found." << endl;
		return 1;
	}
	
	//will keep loop running as long as inFile is open
	while (inFile)
	{
		count_letters(inFile, letterArray);
		output_letters(outFile, letterArray);
		//to reset array to all 0 after each line
		for (int i = 0; i < 26; i++)
		{
			letterArray[i] = 0;
		}
	}

	

	inFile.close();

	delete [] letterArray;

	return 0;
}