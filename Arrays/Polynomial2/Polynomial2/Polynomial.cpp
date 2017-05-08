#include "Polynomial.h"
#include <iostream>

// static member initialization
Item Polynomial::itemArray[MAX_SIZE];
int Polynomial::free = 0;

Polynomial::Polynomial(float *pCoeff, int *pExp, int size)
{
	start = free;
	end = free;

	for (int i = 0; i < size; i++)
	{
		itemArray[free].coeff = pCoeff[i];
		itemArray[free].exp = pExp[i];
		free++;
	}

	if (free)
	{
		end = free - 1;
	}
}

Polynomial::Polynomial()
{
	start = free;
	end = free;
}


Polynomial::~Polynomial()
{

}

int Polynomial::GetStart()
{
	return start;
}
int Polynomial::GetEnd()
{
	return end;
}

// Show the polynomial expression
void Polynomial::ShowExpression()
{
	for (int i = start; i <= end; i++)
	{
		if (i == start)
		{
			std::cout << itemArray[i].coeff << "X^" << itemArray[i].exp;
		}
		else
		{
			std::cout << "+" << itemArray[i].coeff << "X^" << itemArray[i].exp;
		}
	}
	std::cout << std::endl;
}

// compare the exponent between A and B
char Polynomial::Compare(int indexA, int indexB)
{
	if (itemArray[indexA].exp > itemArray[indexB].exp)
	{
		return '>';
	}
	else if (itemArray[indexA].exp == itemArray[indexB].exp)
	{
		return '=';
	}
	else
	{
		return '<';
	}
}

// add new item to 'itemArray'
void Polynomial::NewItem(float coeff, int exp)
{
	if (free >= MAX_SIZE)
	{
		std::cout << "Exceed the array size" << std::endl;
		return;
	}

	itemArray[free].coeff = coeff;
	itemArray[free].exp = exp;
	free++;
}

// addition function
void Polynomial::Add(Polynomial polyA, Polynomial polyB)
{
	int i = polyA.GetStart(), j = polyB.GetStart();
	int endA = polyA.GetEnd(), endB = polyB.GetEnd();
	start = free;
	end = free;

	while (i<=endA && j<=endB)
	{
		switch (Compare(i, j))
		{
			case '>':
			{
				NewItem(itemArray[i].coeff, itemArray[i].exp);
				i++;
				break;
			}
			case '=':
			{
				NewItem(itemArray[i].coeff + itemArray[j].coeff, itemArray[i].exp);
				i++;
				j++;
				break;
			}
			case '<':
			{
				NewItem(itemArray[j].coeff, itemArray[j].exp);
				j++;
				break;
			}
			default:
				break;
		}
	}

	for (; i <= endA; i++)
	{
		NewItem(itemArray[i].coeff, itemArray[i].exp);
	}
	for (; j <= endB; j++)
	{
		NewItem(itemArray[j].coeff, itemArray[j].exp);
	}
	end = free - 1;
}