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
		MainMatrix.ArrGenAuto(5, 64);
	}
	else
	{
		MainMatrix.ArrgenMan();
	}
	int count = 0;
	int elcount = 0;
	int elcountc = 0;
	int countc = 0;
	bool ZeroDiv;
	CellDivision(MainMatrix, &countc, &ZeroDiv, &elcountc);
	Embordering(MainMatrix, &count, &elcount);
	cout << endl << countc << " recourse " << elcountc << " el oper";
	cout << endl << count << " iter " << elcount << " el oper";
	return 0;
}
