#pragma once

class Matrix //Клас матриці
{
private:
	int Row; //Кількість рядків матриці
	int Column; //Кількість стовпців матриці
	double** Arr; //Представлення самої матриці

public:
	Matrix(int RowNumber, int ColumnNumber); //Конструктор класу
	~Matrix(); //Деструктор класу
	Matrix(const Matrix& matrix); //Конструктор копіювання
	void ArrGenAuto(int RangeMin, int RangeMax); //Генерація матриці випаковим чином
	int GetRow(); //Гетер рядків
	int GetColumn(); //Гетер стовпців
	double** GetArr(); //Гетер матрциі
	int Det(); //Функція знаходження визначника матриці
	//Функція викреслення рядка та стовпця
	void GetMatr(Matrix CurrentMatrix, int IndRow, int IndCol);
	//Перевантаження оператора потокового виводу
	Matrix operator - (const Matrix& matrix); //Перевантаження оператора віднімання
	Matrix operator * (const Matrix& matrix); //Перевантаження оператора для множення двох матриць
	Matrix operator * (double number); //Перевантаження оператора для множення матриці на число 
	void operator = (const Matrix& OtherMatrix); //Перевантаження оператора присвоєння  
};