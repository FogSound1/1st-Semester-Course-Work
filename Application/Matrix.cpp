#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include "RevMat.h"
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

//Функції класу Matrix

Matrix::Matrix(int RowNumber, int ColumnNumber) //Конструктор класу
{
	Row = RowNumber;
	Column = ColumnNumber;
	Arr = new double* [Row];

	for (int i = 0; i < Row; i++)
	{
		Arr[i] = new double[Column];
	}
}

Matrix::~Matrix() //Деструктор класу
{
	for (int i = 0; i < Row; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}

Matrix::Matrix(const Matrix& matrix)  //Конструктор копіювання
{
	this->Row = matrix.Row;
	this->Column = matrix.Column;
	this->Arr = new double* [matrix.Row];
	for (int i = 0; i < matrix.Row; i++)
	{
		this->Arr[i] = new double[Column];
	}
	for (int i = 0; i < matrix.Row; i++)
	{
		for (int j = 0; j < matrix.Column; j++)
		{
			this->Arr[i][j] = matrix.Arr[i][j];
		}
	}
}

void Matrix::ArrGenAuto(int RangeMin, int RangeMax) //Генерація матриці випадковим чином
{
	srand(time(NULL));
	for (int k = 0; ; k++)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Column; j++)
			{
				if (RangeMax == 0)
				{
					Arr[i][j] = 0;
				}
				else
				{
					Arr[i][j] = rand() % (RangeMax - RangeMin + 1) + RangeMin;
				}
			}
		}
		if (UnAcceptable(*this, 3) && RangeMax != 0)
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

int Matrix::Det() //Функція знаходження визначника матриці
{
	int temp = 0;
	int k = 1;
	Matrix CurrentMatrix(*this);

	if (Row == 1)
	{
		temp = Arr[0][0];
	}
	else if (Row == 2)
	{
		temp = Arr[0][0] * Arr[1][1] - Arr[1][0] * Arr[0][1];
	}
	else
	{
		for (int i = 0; i < Row; i++)
		{
			int m = Row - 1;
			Matrix TempMatrix(m, m);
			TempMatrix.GetMatr(CurrentMatrix, 0, i);
			temp = temp + k * Arr[0][i] * TempMatrix.Det();
			k = -k;
		}
	}
	return temp;
}

//Функція викреслення рядка та стовпця
void Matrix::GetMatr(Matrix CurrentMatrix, int IndRow, int IndCol)
{
	int ki = 0;
	for (int i = 0; i < CurrentMatrix.Row; i++)
	{
		if (i != IndRow)
		{
			for (int j = 0, kj = 0; j < CurrentMatrix.Row; j++)
			{
				if (j != IndCol)
				{
					Arr[ki][kj] = CurrentMatrix.Arr[i][j];
					kj++;
				}
			}
			ki++;
		}
	}
}

int Matrix::GetRow() //Гетер рядків матриці
{
	return Row;
}

int Matrix::GetColumn() //Гетер стовпців матриці
{
	return Column;
}

double** Matrix::GetArr() //Гетер матрциі
{
	return Arr;
}

Matrix Matrix::operator - (const Matrix& matrix) //Перевантаження оператора віднімання
{
	Matrix NewMatrix(matrix.Row, matrix.Column);
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			NewMatrix.Arr[i][j] = this->Arr[i][j] - matrix.Arr[i][j];
		}
	}
	return NewMatrix;
}

Matrix Matrix::operator * (const Matrix& matrix) //Перевантаження оператора для множення двох матриць 
{
	Matrix NewMatrix(Row, matrix.Column);
	NewMatrix.ArrGenAuto(0, 0);
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < matrix.Column; j++)
		{
			for (int k = 0; k < matrix.Row; k++)
			{
				NewMatrix.Arr[i][j] += this->Arr[i][k] * matrix.Arr[k][j];
			}
		}
	}
	return NewMatrix;
}

Matrix Matrix::operator * (double number) //Перевантаження оператора для множення матриці на число  
{
	Matrix NewMatrix(Row, Column);
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			NewMatrix.Arr[i][j] = this->Arr[i][j] * number;
		}
	}
	return NewMatrix;
}

void Matrix::operator = (const Matrix& OtherMatrix) //Перевантаження оператора присвоєння  
{
	int OldRow = this->Row;
	this->Row = OtherMatrix.Row;
	this->Column = OtherMatrix.Column;

	if (this->Arr != nullptr)
	{
		for (int i = 0; i < OldRow; i++)
		{
			delete[] this->Arr[i];
		}
		delete[] this->Arr;
	}

	this->Arr = new double* [OtherMatrix.Row];
	for (int i = 0; i < OtherMatrix.Row; i++)
	{
		this->Arr[i] = new double[Column];
	}
	for (int i = 0; i < OtherMatrix.Row; i++)
	{
		for (int j = 0; j < OtherMatrix.Column; j++)
		{
			this->Arr[i][j] = OtherMatrix.Arr[i][j];
		}
	}
}