#pragma once
#include <string>

bool DoubleZero(double number); //Перевірка на машинні нулі у матриці
bool UnAcceptable(Matrix MainMatrix, int type); //Перевірка матриці на визначники різних її частин
Matrix MachineZero(Matrix CurrentMatrix); //Заміна усіх машинних нулей на звичайні
Matrix Embordering(Matrix MainMatrix); //Метод окаймлення
Matrix CellDivisionInitialization(Matrix MainMatrix, int number); //Розбиття матриці на клітки
//Зібрання кліток в одну
Matrix CellDivisionBuild(Matrix MainMatrix, Matrix MatrixR11, Matrix MatrixR12, Matrix MatrixR21, Matrix MatrixR22);
//Знаходження матриці методом розбиття на клітки
Matrix CellDivision(Matrix MainMatrix, int* count);
int WriteFile(Matrix ReverseMatrix, std::string FileName); //Функція запису у файл
