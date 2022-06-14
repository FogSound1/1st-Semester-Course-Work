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
	void ArrgenMan(); //Створення матриці мануально
	int GetRow(); //Гетер рядків
	int GetColumn(); //Гетер стовпців
	double** GetArr(); //Гетер матрциі
	int Det(); //Функція знаходження визначника матриці
    //Функція викреслення рядка та стовпця
	void GetMatr(Matrix CurrentMatrix, int IndRow, int IndCol);
	Matrix TranspMatrix(); //Транспонування матриці
	//Перевантаження оператора потокового виводу
	friend std::ostream& operator << (std::ostream& out, const Matrix& MatrixA); 
	Matrix operator - (const Matrix& matrix); //Перевантаження оператора віднімання
	Matrix operator * (const Matrix& matrix); //Перевантаження оператора для множення двох матриць
	Matrix operator * (double number); //Перевантаження оператора для множення матриці на число 
	void operator = (const Matrix &OtherMatrix); //Перевантаження оператора присвоєння  
};

bool DoubleZero(double number); //Перевірка на машинні нулі у матриці
bool UnAcceptable(Matrix MainMatrix, int type); //Перевірка матриці на визначники різних її частин
Matrix MachineZero(Matrix CurrentMatrix); //Заміна усіх машинних нулей на звичайні
Matrix NormalReverse(Matrix CurrentMatrix); //Знаходження оберненної матриці для кліток
Matrix Embordering(Matrix MainMatrix, int* count, int* elcount); //Метод окаймлення
Matrix CellDivisionInitialization(Matrix MainMatrix, int number); //Розбиття матриці на клітки
//Знаходження матриці методом розбиття на клітки
Matrix CellDivision(Matrix MainMatrix, int* count, bool* ZeroDiv, int* elcount);
Matrix CellDivisionBuild(Matrix MainMatrix, Matrix MatrixR11, Matrix MatrixR12, Matrix MatrixR21, Matrix MatrixR22);
