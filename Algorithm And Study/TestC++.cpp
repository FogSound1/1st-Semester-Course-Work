#include <iostream>
#include "TestC.h"
using namespace std;

int main()
{
	int Method;
	cout << "Enter 1 to automatically generate a matrix\nEnter 2 to manually fill the matrix ";
	cin >> Method;
	int SizeNumber;
	do
	{
		cout << "Enter the size of a matrix ";
		cin >> SizeNumber;
	} while (SizeNumber <= 1);
	Matrix MainMatrix(SizeNumber, SizeNumber);
	if (Method == 1)
	{
		MainMatrix.ArrGenAuto(1, 4);
	}
	else
	{
		MainMatrix.ArrgenMan();
	}
	cout << "Enter 1 to use emborder method\nEnter 2 to use cell division method ";
	cin >> Method;
	cout << endl << MainMatrix;
	cout << endl << NormalReverse(MainMatrix);
	cout << "___________________________________________________________" << endl;
	if (Method == 1)
	{
		Matrix ReverseMatrix = MachineZero(Embordering(MainMatrix));
		cout << ReverseMatrix;
	}
	else
	{
		Matrix ReverseMatrix = MachineZero(CellDivisionInitialization(MainMatrix));
		cout << ReverseMatrix;
	}
	return 0;
}