class Polynomial
{
public:
	float *pCoeff;
	int nCoeffSize;
	int iLeadExp;

public:
	Polynomial(float *coeff, int size);
	Polynomial(int size);
	~Polynomial();
	// show expression, such as 3X^20+2X^5+4
	void expression();

	// return the largest exponent
	int LeadExp();	

	// return the coefficient of e
	float Coef(unsigned int exp);

	// if *this is a zero polynomial return TRUE, else return FALSE;
	bool IsZero();

	// compare exponent between A and B
	int Compare(int expA, int expB);

	// remove the exponent
	void Remove(unsigned int exp);

	// attach the exponent
	void Attach(float coeff, unsigned int exp);
	void Attach(Polynomial poly);

	// return the sum of the polynomials *this and poly
	void Add(Polynomial polyA, Polynomial polyB);
};