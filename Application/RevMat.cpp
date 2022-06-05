#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include "RevMat.h"
#include <ctime>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

bool UnAcceptable(Matrix MainMatrix, int type) //�������� ������� �� ���������� ����� �� ������
{
	if (MainMatrix.GetRow() == 1 && MainMatrix.GetColumn() == 1 && MainMatrix.GetArr()[0][0] != 0)
	{
		return false;
	}
	if (MainMatrix.Det() == 0)
	{
		return true;
	}
	if (type == 1 || type == 3)
	{
		if (MainMatrix.GetArr()[0][0] == 0)
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
	}
	if (type == 2 || type == 3)
	{
		if (MainMatrix.GetArr()[MainMatrix.GetRow() - 1][MainMatrix.GetColumn() - 1] == 0)
		{
			return true;;
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
			if (MatrixCell.GetArr()[MatrixCell.GetRow() - 1][MatrixCell.GetColumn() - 1] == 0)
			{
				return true;;
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
			if (MatrixCell.GetArr()[MatrixCell.GetRow() - 1][MatrixCell.GetColumn() - 1] == 0)
			{
				return true;;
			}
		}
	}
}

Matrix MachineZero(Matrix CurrentMatrix) //����� ��� �������� ����� �� �������
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

bool DoubleZero(double number) //�������� �� ������ ��� � �������
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

Matrix Embordering(Matrix MainMatrix) //����� ����������
{
	int Disposal = MainMatrix.GetRow();

	Matrix OldA(1, 1);
	OldA.GetArr()[0][0] = 1 / MainMatrix.GetArr()[0][0];
	if (MainMatrix.GetRow() == 1)
	{
		return OldA;
	}

	for (int k = 1; k < Disposal; k++)
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
			return MachineZero(A);
		}
		OldA = A;
	}
}

Matrix CellDivisionInitialization(Matrix MainMatrix, int number) //�������� ������� �� �����
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
		if (number == 1)
		{
			return MatrixCell11;
		}
		else if (number == 2)
		{
			return MatrixCell12;
		}
		else if (number == 3)
		{
			return MatrixCell21;
		}
		else
		{
			return MatrixCell22;
		}
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
		if (number == 1)
		{
			return MatrixCell11;
		}
		else if (number == 2)
		{
			return MatrixCell12;
		}
		else if (number == 3)
		{
			return MatrixCell21;
		}
		else
		{
			return MatrixCell22;
		}
	}
}

//ǳ������ ����� � ����
Matrix CellDivisionBuild(Matrix MainMatrix, Matrix MatrixR11, Matrix MatrixR12, Matrix MatrixR21, Matrix MatrixR22)
{
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
					ReverseMatrix.GetArr()[i][j] = MatrixR12.GetArr()[i][j - Disposal / 2];
				}
				else if (i >= Disposal / 2 && j < Disposal / 2)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR21.GetArr()[i - Disposal / 2][j];
				}
				else if (i >= Disposal / 2 && j >= Disposal / 2)
				{
					ReverseMatrix.GetArr()[i][j] = MatrixR22.GetArr()[i - Disposal / 2][j - Disposal / 2];
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


//����������� ������� ������� �������� �� �����
Matrix CellDivision(Matrix MainMatrix)
{
	if (MainMatrix.GetRow() == 1)
	{
		MainMatrix.GetArr()[0][0] = 1 / MainMatrix.GetArr()[0][0];
		return MainMatrix;
	}

	Matrix MatrixCell11 = CellDivisionInitialization(MainMatrix, 1);
	Matrix MatrixCell12 = CellDivisionInitialization(MainMatrix, 2);
	Matrix MatrixCell21 = CellDivisionInitialization(MainMatrix, 3);
	Matrix MatrixCell22 = CellDivisionInitialization(MainMatrix, 4);
	Matrix MatrixCell22Inverse = CellDivision(MatrixCell22);

	Matrix MatrixR11 = CellDivision(MatrixCell11 - (MatrixCell12 * (MatrixCell22Inverse * MatrixCell21)));
	Matrix MatrixR12 = ((MatrixR11 * (-1)) * MatrixCell12) * MatrixCell22Inverse;
	Matrix MatrixR21 = (MatrixCell22Inverse * (-1)) * MatrixCell21 * MatrixR11;
	Matrix MatrixR22 = MatrixCell22Inverse - (MatrixCell22Inverse * MatrixCell21 * MatrixR12);

	Matrix ReverseMatrix = CellDivisionBuild(MainMatrix, MatrixR11, MatrixR12, MatrixR21, MatrixR22);
	return MachineZero(ReverseMatrix);
}

int WriteFile(Matrix ReverseMatrix, string FileName) //������� ������ � ����
{
	ofstream f1; //���������� f1 �������� �� ������ � ����
	f1.open(FileName); //��������� ���� ��� ������
	if (!f1.is_open()) //�������� �������� �����
	{
		return 1;
	}
	else //���������� ������ �����
	{
		f1 << ReverseMatrix.GetRow() << "\t";
		f1 << ReverseMatrix.GetColumn();

		for (int i = 0; i < ReverseMatrix.GetRow(); i++)
		{
			f1 << "\n";
			for (int j = 0; j < ReverseMatrix.GetColumn(); j++)
			{
				f1 << ReverseMatrix.GetArr()[i][j] << "\t";
			}
		}
	}
	f1.close();
	return 2;
}