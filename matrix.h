#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
private:
	int m_rows, m_cols;
	vector <vector <int>> m_array;

public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(vector <vector <int>> arr);

	unsigned getSize();
	int get_row();
	int get_col();

	friend Matrix& operator+	(const Matrix& arr1, const Matrix& arr2);
	friend Matrix& operator+=	(Matrix& arr1, const Matrix& arr2);
	friend Matrix& operator-	(const Matrix& arr1, const Matrix& arr2);
	friend Matrix& operator-=	(Matrix& arr1, const Matrix& arr2);
	friend Matrix& operator*	(const Matrix& arr1, const Matrix& arr2);
	friend Matrix& operator*=	(Matrix& arr1, const Matrix& arr2);

	friend ostream& operator<<	(std::ostream& os, const Matrix& arr);
	friend istream& operator>>	(std::istream& is, Matrix& arr);
};

Matrix::Matrix() {

	m_rows = m_cols = 0;
}

Matrix::Matrix(int rows, int cols) {

	m_cols = cols;
	m_rows = rows;
	m_array = *new vector <vector <int>>(m_rows, vector <int>(m_cols, 0));
}

Matrix::Matrix(vector <vector <int>> arr) {

	m_array = arr;
	m_rows = m_array.size();

	if (m_rows > 0) {
		m_cols = arr[0].size();
	}
	else {
		m_cols = 0;
	}
}

unsigned Matrix::getSize() {
	return m_array.size();
}

int Matrix::get_col() {
	return m_cols;
}

int Matrix::get_row() {
	return m_rows;
}

Matrix& operator+(const Matrix& arr1, const Matrix& arr2) {

	Matrix* result = new Matrix(arr1.m_rows, arr1.m_rows);
	for (int i = 0; i < arr1.m_rows; i++)
	{
		for (int j = 0; j < arr1.m_cols; j++) {
			result->m_array[i][j] = arr1.m_array[i][j] + arr2.m_array[i][j];
		}
	}
	return *result;

}

Matrix& operator+=(Matrix& arr1, const Matrix& arr2) {

	for (int i = 0; i < arr1.m_rows; i++)
	{
		for (int j = 0; j < arr1.m_cols; j++) {
			arr1.m_array[i][j] += arr2.m_array[i][j];
		}
	}

	return arr1;
}

Matrix& operator-(const Matrix& arr1, const Matrix& arr2) {

	Matrix* result = new Matrix(arr1.m_rows, arr1.m_rows);
	for (int i = 0; i < arr1.m_rows; i++)
	{
		for (int j = 0; j < arr1.m_cols; j++) {
			result->m_array[i][j] = arr1.m_array[i][j] - arr2.m_array[i][j];
		}
	}

	return *result;

}

Matrix& operator-=(Matrix& arr1, const Matrix& arr2) {

	for (int i = 0; i < arr1.m_rows; i++)
	{
		for (int j = 0; j < arr1.m_cols; j++) {
			arr1.m_array[i][j] -= arr2.m_array[i][j];
		}
	}

	return arr1;
}

Matrix& operator*(const Matrix& arr1, const Matrix& arr2) {

	Matrix* arrayR = new Matrix(arr1.m_rows, arr1.m_rows);
	for (int i = 0; i < arr1.m_rows; i++)
	{
		for (int j = 0; j < arr1.m_cols; j++) {
			arrayR->m_array[i][j] = arr1.m_array[i][j] * arr2.m_array[i][j];
		}
	}

	return *arrayR;

}

Matrix& operator*=(Matrix& arr1, const Matrix& arr2) {
	for (int i = 0; i < arr1.m_rows; i++)
	{
		for (int j = 0; j < arr1.m_cols; j++) {
			arr1.m_array[i][j] *= arr2.m_array[i][j];
		}
	}

	return arr1;
}


ostream& operator<<(ostream& os, const Matrix& arr) {

	for (int i = 0; i < arr.m_rows; i++)
	{
		for (int j = 0; j < arr.m_cols; j++)
		{
			os << arr.m_array[i][j] << "; ";
		}
		os << endl;
	}
	return os;
}

istream& operator>>(istream& is, Matrix& arr) {

	is >> arr.m_rows;
	is >> arr.m_cols;

	arr.m_array = *new vector <vector <int>>(arr.m_rows, vector <int>(arr.m_cols, 0));

	for (int i = 0; i < arr.m_rows; i++) {
		for (int j = 0; j < arr.m_cols; j++)
		{
			is >> arr.m_array[i][j];
		}
	}

	return is;
}
