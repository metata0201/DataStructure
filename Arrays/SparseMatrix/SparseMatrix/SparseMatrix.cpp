#include "SparseMatrix.h"
#include <iostream>
#include <iomanip> 

SparseMatrix::SparseMatrix(float **ppMatrix, int nRow, int nCol)
{
	if (nRow <= 0 || nCol <= 0)
		return;

    memset(itemArray, 0, sizeof(Item)*MAX_SIZE);

	Rows = nRow;
	Cols = nCol;
	Items= 0;
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			if (ppMatrix[i][j])
			{
				itemArray[Items].val = ppMatrix[i][j];
				itemArray[Items].row = i;
				itemArray[Items].col = j;
				Items++;
			}
		}
	}
}

SparseMatrix::SparseMatrix()
{
    memset(itemArray, 0, sizeof(Item)*MAX_SIZE);

    Rows = 0;
    Cols = 0;
    Items= 0;
}

// show matrix
void SparseMatrix::ShowMatrix()
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			std::cout << std::setw(4) << ItemVal(i, j);
		}
		std::cout << std::endl;
	}
}

float SparseMatrix::ItemVal(int row, int col)
{
	for (int i = 0; i < Items; i++)
	{
		if (itemArray[i].row==row && itemArray[i].col==col)
		{
			return itemArray[i].val;
		}
	}

	return 0;
}

// transpose
void SparseMatrix::Transpose(SparseMatrix matrixA)
{
    int current = 0;
    Rows = matrixA.Cols;
    Cols = matrixA.Rows;
    Items= matrixA.Items;

    if (Items)
    {
        for (int c= 0; c < matrixA.Cols; c++)
        {
            for (int i = 0; i < Items; i++)
            {
                if (matrixA.itemArray[i].col == c)
                {
                    itemArray[current].row = c;
                    itemArray[current].col = matrixA.itemArray[i].row;
                    itemArray[current].val = matrixA.itemArray[i].val;
                    current++;
                }
            }
        }
    }
}

// fast matrix transpose
void SparseMatrix::FastTranspose(SparseMatrix matrixA)
{
    Rows = matrixA.Cols;
    Cols = matrixA.Rows;
    Items= matrixA.Items;

    int *RowSize = new int[matrixA.Cols];   // RowSize indicate the number of items in row i of the transposed matrix
    int *RowStart= new int[matrixA.Cols];   // RowStart indicate the starting item's index in row i of the transposed matrix
    memset(RowSize, 0, sizeof(int)*matrixA.Cols);
    memset(RowStart,0, sizeof(int)*matrixA.Cols);

    int i, j;
    if (Items)
    {
        for (i = 0; i < matrixA.Items; i++)
        {
            RowSize[matrixA.itemArray[i].col]++;
        }

        RowStart[0] = 0;
        for (i = 1; i < matrixA.Cols; i++)
        {
            RowStart[i] = RowStart[i - 1] + RowSize[i - 1];
        }

        // transpose the matrix
        for (i = 0; i < matrixA.Items; i++)
        {
            j = RowStart[matrixA.itemArray[i].col];
            itemArray[j].col = matrixA.itemArray[i].row;
            itemArray[j].row = matrixA.itemArray[i].col;
            itemArray[j].val = matrixA.itemArray[i].val;
            RowStart[matrixA.itemArray[i].col]++;
        }
    }

    if (RowSize)
    {
        delete []RowSize;
        RowSize = NULL;
    }
    if (RowStart)
    {
        delete []RowStart;
        RowStart = NULL;
    }
}