#include "RevMatForm.h"
#include "Matrix.h"
#include "RevMat.h"
#include <string>
#include <msclr/marshal_cppstd.h>

using namespace std;
using namespace msclr::interop;
using namespace ReverseMatrix;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew RevMatForm);
    return 0;
}

//Створення матриці
System::Void ReverseMatrix::RevMatForm::CreateMatrixButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    int SizeMatrix;
    SizeMatrix = Convert::ToInt32(MatrixSizeUpDown->Value);
    Matrix MainMatrix(SizeMatrix, SizeMatrix);
    MainMatrix.ArrGenAuto(0, 0);

    MainMatrixGridView->RowCount = SizeMatrix;
    MainMatrixGridView->ColumnCount = SizeMatrix;

    ShowMatrix(SizeMatrix, MainMatrix, 1); //Виводим матрицю
    //Ячейки
    MainMatrixGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);


    return System::Void();
}

//Генерація матриці випадковим чином
System::Void ReverseMatrix::RevMatForm::ArrGenAutoButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MainMatrixGridView->RowCount == 0)
    {
        MessageBox::Show("Матриця не створена");
        return;
    }

    int MaxNumber, MinNumber;
    MaxNumber = Convert::ToInt32(MaxNumberUpDown->Value);
    MinNumber = Convert::ToInt32(MinNumberUpDown->Value);

    if (MinNumber == MaxNumber || MinNumber > MaxNumber)
    {
        MessageBox::Show("Заданий діапазон не може згенерувати невироджену матрицю");
        return;
    }

    Matrix MainMatrix(MainMatrixGridView->RowCount, MainMatrixGridView->ColumnCount);
    MainMatrix.ArrGenAuto(MinNumber, MaxNumber);

    ShowMatrix(MainMatrix.GetRow(), MainMatrix, 1); //Виводим матрицю
    //Ячейки
    MainMatrixGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    MainMatrixGridView->AutoResizeColumns();//Стовбці
    return System::Void();
}

//Обернення матриці методом окаймлення
System::Void ReverseMatrix::RevMatForm::EmborderingButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (BannedSymbols())
    {
        MessageBox::Show("Задана матриця містить некоректний символ");
        return;
    }

    Matrix  MainMatrix = GetMatrix(1);
    if (UnAcceptable(MainMatrix, 1))
    {
        MessageBox::Show("Задана матриця не підходить для даного методу");
        return;
    }

    if (SolutionCheck->Checked)
    {
        EmborderingSolution^ Form = gcnew EmborderingSolution(MainMatrix);
        Form->Show();
    }

    Matrix ReverseMatrix = Embordering(MainMatrix);
    ReverseMatrixGridView->RowCount = ReverseMatrix.GetRow();
    ReverseMatrixGridView->ColumnCount = ReverseMatrix.GetRow();

    ShowMatrix(ReverseMatrix.GetRow(), ReverseMatrix, 2);
    //Ячейки
    ReverseMatrixGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    ReverseMatrixGridView->AutoResizeColumns();//Стовбці

    return System::Void();
}

//Знаходженн матриці методом робиття на клітки
System::Void ReverseMatrix::RevMatForm::CellDivisionButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    int count = 0;
    bool ZeroDiv = false;
    if (BannedSymbols())
    {
        MessageBox::Show("Задана матриця містить некоректний символ");
        return;
    }

    Matrix  MainMatrix = GetMatrix(1);

    if (UnAcceptable(MainMatrix, 2))
    {
        MessageBox::Show("Задана матриця не підходить для даного методу");
        return;
    }

    if (SolutionCheck->Checked)
    {
        if (MainMatrix.GetRow() == 1)
        {
            MessageBox::Show("Для матриці розмірності 1х1 детальне рішення непотрібне");
        }
        else
        {
            CellDivisionSolution^ Form = gcnew CellDivisionSolution(MainMatrix);
            Form->Show();
        }

    }

    Matrix ReverseMatrix = CellDivision(MainMatrix, &count, &ZeroDiv);
    ReverseMatrixGridView->RowCount = ReverseMatrix.GetRow();
    ReverseMatrixGridView->ColumnCount = ReverseMatrix.GetRow();

    ShowMatrix(ReverseMatrix.GetRow(), ReverseMatrix, 2);
    //Ячейки
    ReverseMatrixGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    ReverseMatrixGridView->AutoResizeColumns();//Стовбці

    return System::Void();
}

//Вивод матриці
void ReverseMatrix::RevMatForm::ShowMatrix(int SizeMatrix, Matrix MainMatrix, int type)
{
    if (type == 1)
    {
        for (int i = 0; i < SizeMatrix; i++)
        {
            for (int j = 0; j < SizeMatrix; j++)
            {
                //Значення матриці
                MainMatrixGridView->Rows[i]->Cells[j]->Value = MainMatrix.GetArr()[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < SizeMatrix; i++)
        {
            for (int j = 0; j < SizeMatrix; j++)
            {
                //Значення матриці
                ReverseMatrixGridView->Rows[i]->Cells[j]->Value = MainMatrix.GetArr()[i][j];
            }
        }
    }
}

//Зчитування матриці з DataGridView
Matrix ReverseMatrix::RevMatForm::GetMatrix(int type)
{
    Matrix SomeMatrix(MainMatrixGridView->RowCount, MainMatrixGridView->ColumnCount);

    if (type == 1)
    {
        for (int i = 0; i < MainMatrixGridView->RowCount; i++)
        {
            for (int j = 0; j < MainMatrixGridView->ColumnCount; j++)
            {
                SomeMatrix.GetArr()[i][j] = Convert::ToDouble(MainMatrixGridView->Rows[i]->Cells[j]->Value);
            }
        }
    }
    else
    {
        for (int i = 0; i < ReverseMatrixGridView->RowCount; i++)
        {
            for (int j = 0; j < ReverseMatrixGridView->ColumnCount; j++)
            {
                SomeMatrix.GetArr()[i][j] = Convert::ToDouble(ReverseMatrixGridView->Rows[i]->Cells[j]->Value);
            }
        }
    }

    return SomeMatrix;
}

//Запис оберненої матриці у файл
System::Void ReverseMatrix::RevMatForm::WriteFileButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Matrix ReverseMatrix = GetMatrix(2);
    string FileName = marshal_as<string>(FileNameTextBox->Text);

    int result = WriteFile(ReverseMatrix, FileName);
    if (result == 1)
    {
        MessageBox::Show("Файл не знайдений");
        return;
    }
    else
    {
        MessageBox::Show("Матриця успішно записана у файл ", FileNameTextBox->Text);
        return;
    }
    return System::Void();
}


//Вихід
System::Void ReverseMatrix::RevMatForm::вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

//Перевірка матриці на некоректні символи
bool ReverseMatrix::RevMatForm::BannedSymbols()
{
    string TrueSymbols = "0 1 2 3 4 5 6 7 8 9";
    string minus = "-";
    string comma = ",";
    string zero = "0";
    string Check;

    for (int i = 0; i < MainMatrixGridView->RowCount; i++)
    {
        for (int j = 0; j < MainMatrixGridView->ColumnCount; j++)
        {
            bool OneComma = false;
            Check = marshal_as<string>(Convert::ToString(MainMatrixGridView->Rows[i]->Cells[j]->Value));
            for (int k = 0; k < Check.length(); k++)
            {
                if (TrueSymbols.find(Check[k]) == string::npos)
                {
                    //Якщо перший символ -
                    if (k == 0 && minus.find(Check[k]) != string::npos)
                    {
                        //Якщо перший символ -, а другий ,
                        if (comma.find(Check[k + 1]) != string::npos)
                        {
                            return true;
                        }
                        continue;
                    }
                    //Якщо перший символ ,
                    if (k == 0 && comma.find(Check[k]) != string::npos)
                    {
                        return true;
                    }
                    //Якщо це не перша ,
                    if (k > 0 && comma.find(Check[k]) != string::npos && OneComma == false)
                    {
                        OneComma = true;
                        continue;
                    }
                    return true;
                }
            }
        }
    }
}
