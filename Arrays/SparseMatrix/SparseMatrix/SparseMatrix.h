#define MAX_SIZE 50

class Item
{
	friend class SparseMatrix;

public:
	int row, col;
	float val;
};

class SparseMatrix
{
public:
	SparseMatrix(float **ppMatrix, int nRow, int nCol);
    SparseMatrix();
	// show matrix
	void ShowMatrix();

	float ItemVal(int row, int col);

    // matrix transpose
    void Transpose(SparseMatrix matrixA);
    // fast matrix transpose
    void FastTranspose(SparseMatrix matrixA);

public:
	int Rows, Cols, Items;
	Item itemArray[MAX_SIZE];
};