#include <iostream>
#include "Polynomial.h"

void main()
{
	float CoeffA[21] = { 0 }, CoeffB[5] = { 0 };
	// initialize CoeffA
	CoeffA[0] = 4;
	CoeffA[5] = 2;
	CoeffA[20] = 3;
	// initialize CoeffB
	CoeffB[0] = 1;
	CoeffB[2] = 3;
	CoeffB[3] = 10;
	CoeffB[4] = 1;

	Polynomial polyA(CoeffA, 21), polyB(CoeffB, 5);
	std::cout << "polyA : ";
	polyA.expression();
	std::cout << "polyB : ";
	polyB.expression();

	int maxExp = 0; 
	if (polyA.LeadExp() >= polyB.LeadExp())
	{
		maxExp = polyA.LeadExp();
	}
	else
	{
		maxExp = polyB.LeadExp();
	}

	Polynomial polyC(maxExp + 1);
	polyC.Add(polyA, polyB);
	std::cout << "polyC : ";
	polyC.expression();
}