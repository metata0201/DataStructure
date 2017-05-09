#include "SparseMatrix.h"
#include <iostream>

void main()
{
	float mArray1[6][6] = { { 15, 0, 0, 22, 0, -15 }, { 0, 11, 3, 0, 0, 0 }, { 0, 0, 0, -6, 0, 0 },
                            { 0, 0, 0, 0, 0, 0 }, { 91, 0, 0, 0, 0, 0 }, { 0, 0, 28, 0, 0, 0 } };

    float *pArray1[6];
    for (int i = 0; i < 6; i++)
    {
        pArray1[i] = mArray1[i];
    }

    SparseMatrix matrixA(pArray1, 6, 6);
    std::cout << "Matrix A:" << std::endl;
    matrixA.ShowMatrix();

    //SparseMatrix matrixTransposeA;
    //matrixTransposeA.Transpose(matrixA);
    //std::cout << "Transpose matrix A:" << std::endl;
    //matrixTransposeA.ShowMatrix();

    SparseMatrix matrixTransposeA;
    matrixTransposeA.FastTranspose(matrixA);
    std::cout << "Transpose matrix A:" << std::endl;
    matrixTransposeA.ShowMatrix();
}