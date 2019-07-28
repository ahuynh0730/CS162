/*******************************************************************************
** Author:       Anthony Huynh
** Date:         10/07/2018
** Description:  implementation file for counting letters in a file
*******************************************************************************/

#include "count_letters.hpp"
#include <iostream>
#include <cctype>
#include <string>

void count_letters(std::ifstream & file, int* array)
{
	char c;
	while (file.get(c))
	{
		//to change upper case letters to lower case, ASCII values are used
		if (c >= 65 && c <= 90)
		{
			c = tolower(c);
		}
		
		//to incremement proper array index for letter, a will be index 0 and z will be index 25
		if (c >= 97 && c <= 122)
		{
			array[c - 97] = array [c-97] + 1;
		}

		//if character is \n or end of line, program will break and return to main
		if (c == '\n')
		{
			break;
		}
	}
}