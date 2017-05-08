#include "Polynomial.h"
#include <iostream>

void main()
{
	float CoeffA[3] = { 3, 2, 4 }, CoeffB[4] = { 1, 10, 3, 1 };
	int expA[3] = { 20, 5, 0 }, expB[4] = {4, 3, 2, 0};
	Polynomial polyA(CoeffA, expA, 3), polyB(CoeffB, expB, 4), polyC;

	std::cout << "polyA : ";
	polyA.ShowExpression();
	std::cout << "polyB : ";
	polyB.ShowExpression();

	polyC.Add(polyA, polyB);
	std::cout << "polyC =  polyA + polyB = "; 
	polyC.ShowExpression();
}