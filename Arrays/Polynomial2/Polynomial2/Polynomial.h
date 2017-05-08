#define MAX_SIZE 100

class Item
{
	friend class Polynomial;
public:
	float coeff;
	int exp;
};

class Polynomial
{
public:
	Polynomial(float *pCoeff, int *pExp, int size);
	Polynomial();
	~Polynomial();

	int GetStart();
	int GetEnd();

	// Show the polynomial expression
	void ShowExpression();

	// compare the exponent between A and B
	char Compare(int indexA, int indexB);

	// add new item to 'itemArray'
	void NewItem(float coeff, int exp);

	// addition function
	void Add(Polynomial polyA, Polynomial polyB);
private:
	static Item itemArray[MAX_SIZE];
	static int free;
	int start;
	int end;
};