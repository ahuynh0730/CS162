/*******************************************************************************
** Author:       Anthony Huynh
** Date:         9/30/2018
** Description:  cpp file for reading matrix from user
*******************************************************************************/

#include "readMatrix.hpp"
#include <iostream>

//to get matrix from user
void readMatrix(int** matrix, int matrixDimension)
{
	std::cout << "Please enter " << matrixDimension * matrixDimension << " integers for the matrix." << std::endl;
	for (int i = 0; i < matrixDimension; i++)
	{
		for (int j = 0; j < matrixDimension; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}