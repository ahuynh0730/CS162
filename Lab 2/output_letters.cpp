/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  implementation file for outputting frequencies of letters in a file
*******************************************************************************/


#include "output_letters.hpp"
#include <iostream>
#include <string>

void output_letters(ofstream & file, int* array)
{
	//to get file name from user
	std::string outFileName;
	std::cout << "What is the name of the file to output to?" << std::endl;
	std::getline(std::cin, outFileName);

	//to open an output file
	file.open(outFileName);
	for (int i = 0; i < 26; i++)
	{
		//changes an int+97 to the ASCII chars and then displays frequencies
		file << static_cast<char>(i + 97) << ": " << array[i] << std::endl;
	}
	file.close();

}