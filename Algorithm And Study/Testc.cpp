#include <iostream>
#include <iomanip>
#include "TestC.h"
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

//Не реализована проверка на готовые клетки, CellDivision иногда не работает

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
	this->Arr = new double*[matrix.Row];
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
					Arr[i][j] = RangeMin + rand() % RangeMax;
				}
			}
		}
		if (UnAcceptable(*this) && RangeMax != 0)
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void Matrix::ArrgenMan() //Створення матриці мануально
{
	for (int k = 0; ; k++)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Column; j++)
			{
				cout << "Enter the " << i + 1 << j + 1 << " element ";
				cin >> Arr[i][j];
			}
		}
		if (UnAcceptable(*this))
		{
			cout << "The matrix is unacceptable for these methods, please try again" << endl;
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

Matrix Matrix::TranspMatrix() //Транспонування матриці
{
	Matrix TempMatrix(Row, Column);
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			TempMatrix.Arr[j][i] = Arr[i][j];
		}
	}
	return TempMatrix;
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

//Перевантаження оператора потокового виводу
std::ostream& operator<< (std::ostream& out, const Matrix& MatrixA) 
{
	for (int i = 0; i < MatrixA.Row; i++)
	{
		for (int j = 0; j < MatrixA.Column; j++)
		{
			out << setw(10) << MatrixA.Arr[i][j];
		}
		cout << "\n";
	}

	return out;
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

void Matrix::operator = (const Matrix &OtherMatrix) //Перевантаження оператора присвоєння  
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

	this->Arr = new double*[OtherMatrix.Row];
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


bool UnAcceptable(Matrix MainMatrix) //Перевірка матриці на визначники різних її частин
{
	if (MainMatrix.Det() == 0)
	{
		return true;
	}
	for (int k = 2; k < MainMatrix.GetRow(); k++)
	{
		Matrix Temp(k, k);
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				Temp.GetArr()[i][j] = MainMatrix.GetArr()[i][j];
			}
		}
		if (Temp.Det() == 0)
		{
			return true;
		}
	}

	if (MainMatrix.GetRow() % 2 == 0)
	{
		Matrix MatrixCell(MainMatrix.GetRow() / 2, MainMatrix.GetRow() / 2);
		for (int i = MainMatrix.GetRow() / 2; i < MainMatrix.GetRow(); i++)
		{
			for (int j = MainMatrix.GetRow() / 2; j < MainMatrix.GetRow(); j++)
			{

				if (i >= MainMatrix.GetRow() / 2 && j >= MainMatrix.GetRow() / 2)
				{
					MatrixCell.GetArr()[i - (MainMatrix.GetRow() / 2)][j - (MainMatrix.GetRow() / 2)] = MainMatrix.GetArr()[i][j];
				}
			}
		}
		if (MatrixCell.Det() == 0)
		{
			return true;
		}
	}
	else
	{
		Matrix MatrixCell(MainMatrix.GetRow() / 2, MainMatrix.GetRow() / 2);
		for (int i = MainMatrix.GetRow() / 2 + 1; i < MainMatrix.GetRow(); i++)
		{
			for (int j = MainMatrix.GetRow() / 2 + 1; j < MainMatrix.GetRow(); j++)
			{

				if (i >= MainMatrix.GetRow() / 2 + 1 && j >= MainMatrix.GetRow() / 2 + 1)
				{
					MatrixCell.GetArr()[i - (MainMatrix.GetRow() / 2 + 1)][j - (MainMatrix.GetRow() / 2 + 1)] = MainMatrix.GetArr()[i][j];
				}
			}
		}
		if (MatrixCell.Det() == 0)
		{
			return true;
		}
	}
	return false;
}


Matrix NormalReverse(Matrix CurrentMatrix) //Знаходження оберненної матриці для кліток
{
	int det = CurrentMatrix.Det();
	Matrix ReverseMatrix(CurrentMatrix.GetRow(), CurrentMatrix.GetRow());
	for (int i = 0; i < CurrentMatrix.GetRow(); i++) 
	{
		for (int j = 0; j < CurrentMatrix.GetRow(); j++)
		{
			int m = CurrentMatrix.GetRow() - 1;
			Matrix TempMatrix(m, m);
			TempMatrix.GetMatr(CurrentMatrix, i, j);
			ReverseMatrix.GetArr()[i][j] = pow(-1.0, i + j + 2) * TempMatrix.Det() / det;
		}
	}
	return ReverseMatrix.TranspMatrix();
}

Matrix MachineZero(Matrix CurrentMatrix) //Заміна усіх машинних нулей на звичайні
{
	for (int i = 0; i < CurrentMatrix.GetRow(); i++)
	{
		for (int j = 0; j < CurrentMatrix.GetColumn(); j++)
		{
			if (DoubleZero(CurrentMatrix.GetArr()[i][j]))
			{
				CurrentMatrix.GetArr()[i][j] = 0;
			}
		}
	}
	return CurrentMatrix;
}

bool DoubleZero(double number) //Перевірка на машинні нулі у матриці
{
	string ZeroCheck = to_string(number);
	string ZeroMinus = "-0.000000";
	string ZeroPlus = "0.000000";
	if (ZeroCheck == ZeroMinus)
	{
		return true;
	}
	if (ZeroCheck == ZeroPlus)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Matrix Embordering(Matrix MainMatrix) //Метод окаймлення
{
	int Disposal = MainMatrix.GetRow();

	double A10 = 1/MainMatrix.GetArr()[0][0];
	double U2 = MainMatrix.GetArr()[0][1];
	double V2 = MainMatrix.GetArr()[1][0];
	double a2 = MainMatrix.GetArr()[1][1] - V2 * A10 * U2;
	double r2 = (-1 / a2) * A10 * U2;
	double q2 = (-1 / a2) * V2 * A10;
	double B2 = A10 - (A10 * U2) * q2;

	Matrix OldA(2, 2);
	OldA.GetArr()[0][0] = B2;
	OldA.GetArr()[0][1] = r2;
	OldA.GetArr()[1][0] = q2;
	OldA.GetArr()[1][1] = 1/a2;

	if (MainMatrix.GetRow() > 2)
	{

		for (int k = 2; k < Disposal; k++)
		{
			Matrix A(k + 1, k + 1);
			for (int i = 0; i < k + 1; i++)
			{
				for (int j = 0; j < k + 1; j++)
				{
					A.GetArr()[i][j] = MainMatrix.GetArr()[i][j];
				}
			}

			Matrix U(k, 1);
			Matrix V(1, k);
			double a = A.GetArr()[k][k];
			for (int i = 0; i < k; i++)
			{
				U.GetArr()[i][0] = A.GetArr()[i][k];
				V.GetArr()[0][i] = A.GetArr()[k][i];
			}
			double akk = a - (V * OldA * U).GetArr()[0][0];
			Matrix r = OldA * U * (-1 / akk);
			Matrix q = V * OldA * (-1 / akk);
			Matrix B = OldA - (OldA * U) * q;


			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					A.GetArr()[i][j] = B.GetArr()[i][j];
				}
			}
			for (int j = 0; j < k; j++)
			{
				A.GetArr()[j][k] = r.GetArr()[j][0];
				A.GetArr()[k][j] = q.GetArr()[0][j];
			}
			A.GetArr()[k][k] = (1 / akk);
			if (k == Disposal - 1)
			{
				return A;
			}
			OldA = A;
		}
	}
	else
	{
		return OldA;
	}
}

Matrix CellDivisionInitialization(Matrix MainMatrix) //Розбиття матриці на клітки
{
	int Disposal = MainMatrix.GetRow();

	if (Disposal % 2 == 0)
	{
		Matrix MatrixCell11(Disposal / 2, Disposal / 2);
		Matrix MatrixCell12(Disposal / 2, Disposal / 2);
		Matrix MatrixCell21(Disposal / 2, Disposal / 2);
		Matrix MatrixCell22(Disposal / 2, Disposal / 2);

		for (int i = 0; i < Disposal; i++)
		{
			for (int j = 0; j < Disposal; j++)
			{
				if (i < Disposal / 2 && j < Disposal / 2)
				{
					MatrixCell11.GetArr()[i][j] = MainMatrix.GetArr()[i][j];
				}
				else if (i < Disposal / 2 && j >= Disposal / 2)
				{
					MatrixCell12.GetArr()[i][j - Disposal / 2] = MainMatrix.GetArr()[i][j];
				}
				else if (i >= Disposal / 2 && j < Disposal / 2)
				{
					MatrixCell21.GetArr()[i - Disposal / 2][j] = MainMatrix.GetArr()[i][j];
				}
				else if (i >= Disposal / 2 && j >= Disposal / 2)
				{
					MatrixCell22.GetArr()[i - Disposal / 2][j - Disposal / 2] = MainMatrix.GetArr()[i][j];
				}
			}
		}
		Matrix ReverseMatrix = CellDivision(MainMatrix, MatrixCell11, MatrixCell12, MatrixCell21, MatrixCell22);
		return ReverseMatrix;
	}
	else
	{
		Matrix MatrixCell11(Disposal / 2 + 1, Disposal / 2 + 1);
		Matrix MatrixCell12(Disposal / 2 + 1, Disposal / 2);
		Matrix MatrixCell21(Disposal / 2, Disposal / 2 + 1);
		Matrix MatrixCell22(Disposal / 2, Disposal / 2);

		for (int i = 0; i < Disposal; i++)
		{
			for (int j = 0; j < Disposal; j++)
			{
				if (i < Disposal / 2 + 1 && j < Disposal / 2 + 1)
				{
					MatrixCell11.GetArr()[i][j] = MainMatrix.GetArr()[i][j];
				}
				else if (i < Disposal / 2 + 1 && j >= Disposal / 2 + 1)
				{
					MatrixCell12.GetArr()[i][j - (Disposal / 2 + 1)] = MainMatrix.GetArr()[i][j];
				}
				else if (i >= Disposal / 2 + 1 && j < Disposal / 2 + 1)
				{
					MatrixCell21.GetArr()[i - (Disposal / 2 + 1)][j] = MainMatrix.GetArr()[i][j];
				}
				else if (i >= Disposal / 2 + 1 && j >= Disposal / 2 + 1)
				{
					MatrixCell22.GetArr()[i - (Disposal / 2 + 1)][j - (Disposal / 2 + 1)] = MainMatrix.GetArr()[i][j];
				}
			}
		}
		Matrix ReverseMatrix = CellDivision(MainMatrix, MatrixCell11, MatrixCell12, MatrixCell21, MatrixCell22);
		return ReverseMatrix;
	}
}

//Знаходження матриці методом розбиття на клітки
Matrix CellDivision(Matrix MainMatrix, Matrix MatrixCell11, Matrix MatrixCell12, Matrix MatrixCell21, Matrix MatrixCell22)
{
	Matrix MatrixR11 = Embordering(MatrixCell11 - (MatrixCell12 * (Embordering(MatrixCell22) * MatrixCell21)));
	Matrix MatrixR12 = ((MatrixR11 * (-1)) * MatrixCell12) * Embordering(MatrixCell22);
	Matrix MatrixR21 = (Embordering(MatrixCell22) * (-1)) * MatrixCell21 * MatrixR11;
	Matrix MatrixR22 = Embordering(MatrixCell22) - (NormalReverse(MatrixCell22) * MatrixCell21 * MatrixR12);
	Matrix ReverseMatrix(MainMatrix.GetRow(), MainMatrix.GetColumn());
	int Disposal = ReverseMatrix.GetRow();
	if (Disposal % 2 == 0)
	{
		for (int i = 0; i < Disposal; i++)
		{
			for (int j = 0; j < Disposal; j++)
			{
				if (i < Disposal / 2 && j < Disposal / 2)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR11.GetArr()[i][j];
				}
				else if (i < Disposal / 2 && j >= Disposal / 2)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR12.GetArr()[i][j - Disposal/2];
				}
				else if (i >= Disposal / 2 && j < Disposal / 2)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR21.GetArr()[i - Disposal/2][j];
				}
				else if (i >= Disposal / 2 && j >= Disposal / 2)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR22.GetArr()[i - Disposal/2][j - Disposal/2];
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < Disposal; i++)
		{
			for (int j = 0; j < Disposal; j++)
			{
				if (i < Disposal / 2 + 1 && j < Disposal / 2 + 1)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR11.GetArr()[i][j];
				}
				else if (i < Disposal / 2 + 1 && j >= Disposal / 2 + 1)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR12.GetArr()[i][j - (Disposal / 2 + 1)];
				}
				else if (i >= Disposal / 2 + 1 && j < Disposal / 2 + 1)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR21.GetArr()[i - (Disposal / 2 + 1)][j];
				}
				else if (i >= Disposal / 2 + 1 && j >= Disposal / 2 + 1)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR22.GetArr()[i - (Disposal / 2 + 1)][j - (Disposal / 2 + 1)];
				}
			}
		}
	}
	return ReverseMatrix;
}