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
	int GetRow(); //����� �����
	int GetColumn(); //����� ��������
	double** GetArr(); //����� ������
	int Det(); //������� ����������� ���������� �������
	//������� ����������� ����� �� �������
	void GetMatr(Matrix CurrentMatrix, int IndRow, int IndCol);
	//�������������� ��������� ���������� ������
	Matrix operator - (const Matrix& matrix); //�������������� ��������� ��������
	Matrix operator * (const Matrix& matrix); //�������������� ��������� ��� �������� ���� �������
	Matrix operator * (double number); //�������������� ��������� ��� �������� ������� �� ����� 
	void operator = (const Matrix& OtherMatrix); //�������������� ��������� ���������  
};