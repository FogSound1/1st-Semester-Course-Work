#pragma once
#include <string>

bool DoubleZero(double number); //�������� �� ������ ��� � �������
bool UnAcceptable(Matrix MainMatrix, int type); //�������� ������� �� ���������� ����� �� ������
Matrix MachineZero(Matrix CurrentMatrix); //����� ��� �������� ����� �� �������
Matrix Embordering(Matrix MainMatrix); //����� ����������
Matrix CellDivisionInitialization(Matrix MainMatrix, int number); //�������� ������� �� �����
//ǳ������ ����� � ����
Matrix CellDivisionBuild(Matrix MainMatrix, Matrix MatrixR11, Matrix MatrixR12, Matrix MatrixR21, Matrix MatrixR22);
//����������� ������� ������� �������� �� �����
Matrix CellDivision(Matrix MainMatrix);
int WriteFile(Matrix ReverseMatrix, std::string FileName); //������� ������ � ����