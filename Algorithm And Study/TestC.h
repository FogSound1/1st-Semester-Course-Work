#pragma once

class Matrix //���� �������
{
private:
	int Row; //ʳ������ ����� �������
	int Column; //ʳ������ �������� �������
	double** Arr; //������������� ���� �������

public:
	Matrix(int RowNumber, int ColumnNumber); //����������� �����
	~Matrix(); //���������� �����
	Matrix(const Matrix& matrix); //����������� ���������
	void ArrGenAuto(int RangeMin, int RangeMax); //��������� ������� ��������� �����
	void ArrgenMan(); //��������� ������� ���������
	int GetRow(); //����� �����
	int GetColumn(); //����� ��������
	double** GetArr(); //����� ������
	int Det(); //������� ����������� ���������� �������
    //������� ����������� ����� �� �������
	void GetMatr(Matrix CurrentMatrix, int IndRow, int IndCol);
	Matrix TranspMatrix(); //�������������� �������
	//�������������� ��������� ���������� ������
	friend std::ostream& operator << (std::ostream& out, const Matrix& MatrixA); 
	Matrix operator - (const Matrix& matrix); //�������������� ��������� ��������
	Matrix operator * (const Matrix& matrix); //�������������� ��������� ��� �������� ���� �������
	Matrix operator * (double number); //�������������� ��������� ��� �������� ������� �� ����� 
	void operator = (const Matrix &OtherMatrix); //�������������� ��������� ���������  
};

bool DoubleZero(double number); //�������� �� ������ ��� � �������
bool UnAcceptable(Matrix MainMatrix); //�������� ������� �� ���������� ����� �� ������
Matrix MachineZero(Matrix CurrentMatrix); //����� ��� �������� ����� �� �������
Matrix NormalReverse(Matrix CurrentMatrix); //����������� ��������� ������� ��� �����
Matrix Embordering(Matrix MainMatrix); //����� ����������
Matrix CellDivisionInitialization(Matrix MainMatrix); //�������� ������� �� �����
//����������� ������� ������� �������� �� �����
Matrix CellDivision(Matrix MainMatrix, Matrix MatrixCell11, Matrix MatrixCell12, Matrix MatrixCell21, Matrix MatrixCell22);