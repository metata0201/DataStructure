#include "Polynomial.h"
#include <cstdio>
#include <iostream>

Polynomial::Polynomial(float *coeff, int size)
{
	// Initialize
	pCoeff = NULL;
	nCoeffSize = 0;
	iLeadExp = 0;

	if (size <= 0)	{ return; }

	pCoeff = new float[size];
	if (pCoeff)
	{
		for (int i = 0; i < size; i++)
		{
			*(pCoeff + i) = coeff[i];
		}
		nCoeffSize = size;
		iLeadExp   = size - 1;
	}
}

Polynomial::Polynomial(int size)
{
	// Initialize
	pCoeff = NULL;
	nCoeffSize = 0;
	iLeadExp = 0;

	if (size <= 0)	{ return; }

	pCoeff = new float[size];
	if (pCoeff)
	{
		for (int i = 0; i < size; i++)
		{
			*(pCoeff + i) = 0;
		}
		nCoeffSize = size;
	}
}

Polynomial::~Polynomial()
{

}

void Polynomial::expression()
{
	int count = 0;
	for (int i = iLeadExp; i >= 0; i--)
	{
		if (*(pCoeff+i))
		{
			count++;
			if (1 == count)
			{
				std::cout << *(pCoeff + i) << "X^" << i;
			}
			else
			{
				std::cout << " + " << *(pCoeff + i) << "X^" << i;
			}
		}
	}
	std::cout << std::endl;
}

// return the largest exponent
int Polynomial::LeadExp()
{
	for (int i = nCoeffSize-1; i >= 0; i--)
	{
		if (*(pCoeff + i))
		{
			iLeadExp = i;
			break;
		}
	}
	return iLeadExp;
}

// return the coefficient of e
float Polynomial::Coef(unsigned int exp)
{
	return *(pCoeff + exp);
}

// if *this is a zero polynomial return true, else return false;
bool Polynomial::IsZero()
{
	for (int i = 0; i < nCoeffSize; i++)
	{
		if (*(pCoeff + i) != 0)
			return false;
	}

	return true;
}

// compare exponent between A and B
int Polynomial::Compare(int expA, int expB)
{
	int status = 0;

	if (expA < expB) { status = -1; }
	else if (expA == expB) { status = 0; }
	else { status = 1; }

	return status;
}

// remove the exponent
void Polynomial::Remove(unsigned int exp)
{
	if (exp >= nCoeffSize || exp < 0)
		return;

	*(pCoeff + exp) = 0;
}

// attach the exponent
void Polynomial::Attach(float coeff, unsigned int exp)
{
	if (exp >= nCoeffSize || exp < 0)
		return;

	*(pCoeff + exp) = coeff;
}

void Polynomial::Attach(Polynomial poly)
{
	for (int i = 0; i <= poly.iLeadExp; i++)
	{
		*(pCoeff + i) = poly.Coef(i);
	}
}

// return the sum of the polynomials *this and poly
void Polynomial::Add(Polynomial polyA, Polynomial polyB)
{
	float coefSum = 0;
	int exp = 0;
	
	iLeadExp = (polyA.iLeadExp >= polyB.iLeadExp) ? polyA.iLeadExp : polyB.iLeadExp;
	while (!polyA.IsZero() && !polyB.IsZero())
	{
		switch(Compare(polyA.LeadExp(), polyB.LeadExp()))
		{
			case -1:
			{
				exp = polyB.LeadExp();
				coefSum = polyB.Coef(exp);
				polyB.Remove(exp);
				break;
			}
			case 0:
			{
				exp = polyA.LeadExp();
				coefSum = polyA.Coef(exp) + polyB.Coef(exp);				
				polyA.Remove(exp);
				polyB.Remove(exp);
				break;
			}
			case 1:
			{
				exp = polyA.LeadExp();
				coefSum = polyA.Coef(exp);
				polyA.Remove(exp);
				break;
			}
		}
		*(pCoeff + exp) = coefSum;
	}

	// add the remaining polyA
	if (!polyA.IsZero())
	{
		exp = polyA.LeadExp();
		for (int i = 0; i <= exp; i++)
		{
			*(pCoeff + i) = polyA.Coef(i);
		}
	}

	// add the remaining polyB
	if (!polyB.IsZero())
	{
		exp = polyB.LeadExp();
		for (int i = 0; i <= exp; i++)
		{
			*(pCoeff + i) = polyB.Coef(i);
		}
	}
}