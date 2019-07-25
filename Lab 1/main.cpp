/*******************************************************************************
** Author:       Anthony Huynh
** Date:         9/30/2018
** Description:  main file for matrix calculator
*******************************************************************************/

#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cin;
using std::cout;
using std::endl;

void displayMatrix(int **, int);

int main()
{
	int matrixSizeChoice = 0, matrixDimension;
	cout << "Please choose the size of the matrix." << endl
		<< "1. 2x2" << endl << "2. 3x3" << endl;

	//will keep looping until user chooses 1 or 2
	cin >> matrixSizeChoice;
	while (matrixSizeChoice != 1 && matrixSizeChoice != 2)
	{
		cout << "Invalid option, please try again." << endl;
		cin >> matrixSizeChoice;
	}

	//sets matrix dimension based on users option
	if (matrixSizeChoice == 1)
		matrixDimension = 2;
	else if (matrixSizeChoice == 2)
		matrixDimension = 3;


	int ** matrix = new int*[matrixDimension];
	for (int i = 0; i < matrixDimension; i++)
	{
		matrix[i] = new int[matrixDimension];
	}

	
	readMatrix(matrix, matrixDimension);
	

	displayMatrix(matrix, matrixDimension);
	cout << "Determinant: " << determinant(matrix, matrixDimension) << endl;
	for (int i = 0; i < matrixDimension; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	

	
	return 0;
}

void displayMatrix(int** matrix, int matrixDimension)
{
	for (int i = 0; i < matrixDimension; i++)
	{
		for (int j = 0; j < matrixDimension; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}