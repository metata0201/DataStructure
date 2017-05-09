class Matrix
{
public:
	Matrix(float **ppMatrix, int nRow, int nCol);
	Matrix(int nRow, int nCol);
	~Matrix();

	// show matrix
	void ShowMatrix();

	float GetItem(int row, int col);
	void SetItem(float val, int row, int col);

	int GetRows();
	int GetCols();

	// transposition
	void Transpose(Matrix *matrixA);

private:
	float **ppArray;
	int Rows, Cols;
};