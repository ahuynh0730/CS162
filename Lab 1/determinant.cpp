/*******************************************************************************
** Author:       Anthony Huynh
** Date:         9/30/2018
** Description:  cpp file for calculating determinant of a matrix
*******************************************************************************/

#include "determinant.hpp"



int determinant(int** matrix, int matrixDimension)
{
	int determinant;
	//if matrix is 2x2
	if (matrixDimension == 2)
		determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

	//if matrix is 3x3
	if (matrixDimension == 3)
		determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
						- matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
						+ matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
	return determinant;
}