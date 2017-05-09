#include "Matrix.h"
#include <cstdio>
#include <iostream>
#include <iomanip>

Matrix::Matrix(float **ppMatrix, int nRow, int nCol)
{
	if (nRow<=0 || nCol<=0)
	{
		return;
	}

	int i, j;
	// allocate memory for 'ppArray'
	ppArray = new float*[nRow];
	for (i = 0; i < nRow; i++)
	{
		ppArray[i] = new float[nCol];
	}

	// initialize
	for (i = 0; i < nRow; i++)
	{
		for (j = 0; j < nCol; j++)
		{
			ppArray[i][j] = ppMatrix[i][j];
		}
	}
	Rows = nRow;
	Cols = nCol;
}

Matrix::Matrix(int nRow, int nCol)
{
	if (nRow <= 0 || nCol <= 0)
	{
		return;
	}

	int i, j;
	// allocate memory for 'ppArray'
	ppArray = new float*[nRow];
	for (i = 0; i < nRow; i++)
	{
		ppArray[i] = new float[nCol];
	}

	// initialize
	for (i = 0; i < nRow; i++)
	{
		for (j = 0; j < nCol; j++)
		{
			ppArray[i][j] = 0;
		}
	}
	Rows = nRow;
	Cols = nCol;
}

Matrix::~Matrix()
{
	if (ppArray)
	{
		for (int i = 0; i < Rows; i++)
		{
			if (ppArray[i])
			{
				delete[] ppArray[i];
				ppArray[i] = NULL;
			}
		}
		delete[] ppArray;
		ppArray = NULL;
	}
}

// show matrix
void Matrix::ShowMatrix()
{
	std::cout << "Matrix:" << std::endl;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			std::cout << std::setw(4) << ppArray[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

float Matrix::GetItem(int row, int col)
{
	return ppArray[row][col];
}

void Matrix::SetItem(float val, int row, int col)
{
	ppArray[row][col] = val;
}

int Matrix::GetRows()
{
	return Rows;
}

int Matrix::GetCols()
{
	return Cols;
}

// transposition
void Matrix::Transpose(Matrix *matrixA)
{
	for (int i = 0; i < matrixA->GetRows(); i++)
	{
        for (int j = 0; j < matrixA->GetCols(); j++)
		{
            ppArray[j][i] = matrixA->GetItem(i, j);
		}
	}
}