#include "matrix.h"

int matrix_test()
{
	Matrix test1, test2;
	cout << "1. Enter row, column and values for matrixes:" << endl;
	cin >> test1;
	cout << endl;
	cin >> test2;
	cout << endl;

	if (test1.getSize() > 0 && test2.getSize() > 0 && test1.get_col() == test2.get_col() && test1.get_row() == test2.get_row()) {

		cout << "Matrix 1: " << endl << test1 << endl;
		cout << "Matrix 2: " << endl << test2 << endl;

		cout << "matrix1 + matrix2 =" << endl;
		Matrix MatrixAdding = test1 + test2;
		cout << MatrixAdding << endl;

		cout << "matrix1 += matrix2 =" << endl;
		test1 += test2;
		cout << test1 << endl;

		cout << "matrix1 - matrix2 =" << endl;
		Matrix SubMatrix = test1 - test2;
		cout << SubMatrix << endl;

		cout << "matrix1 -= matrix2 =" << endl;
		test1 -= test2;
		cout << test1 << endl;

		cout << "matrix1 8 matrix2 =" << endl;
		Matrix MultiMatrix = test1 * test2;
		cout << MultiMatrix << endl;

		
		cout << "matrix1 *= matrix2 =" << endl;
		test1 *= test2;
		cout << "Result: " << test1 << endl;
	}
	else {
		cout << "Error";
	}

	return 0;
}