#include "Matrix.h"

void main()
{
	float mArray1[6][6] = { { 15, 0, 0, 22, 0, -15 }, { 0, 11, 3, 0, 0, 0 }, { 0, 0, 0, -6, 0, 0 },
	{ 0, 0, 0, 0, 0, 0 }, { 91, 0, 0, 0, 0, 0 }, { 0, 0, 28, 0, 0, 0 } };

	float mArray2[5][3] = { { -27, 3, 4 }, { 6, 82, -2 }, { 109, -64, 11 }, { 12, 8, 9 }, { 48, 27, 47 } };

	float *pArray1[6], *pArray2[5];
	for (int i = 0; i < 6; i++)
	{
		pArray1[i] = mArray1[i];
	}

	for (int i = 0; i < 5; i++)
	{
		pArray2[i] = mArray2[i];
	}

	Matrix matrixA(pArray1, 6, 6);
	matrixA.ShowMatrix();

	Matrix matrixTransposeA(6, 6);
	matrixTransposeA.Transpose(&matrixA);
	matrixTransposeA.ShowMatrix();

	Matrix matrixB(pArray2, 5, 3);
	matrixB.ShowMatrix();

	Matrix matrixTransposeB(3, 5);
	matrixTransposeB.Transpose(&matrixB);
	matrixTransposeB.ShowMatrix();
}