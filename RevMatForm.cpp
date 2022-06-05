#include "RevMatForm.h"
#include "Matrix.h"
#include "RevMat.h"
#include <string>
#include <Windows.h>
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

//��������� �������
System::Void ReverseMatrix::RevMatForm::CreateMatrixButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    int SizeMatrix;
    SizeMatrix = Convert::ToInt32(MatrixSizeUpDown->Value);
    Matrix MainMatrix(SizeMatrix, SizeMatrix);
    MainMatrix.ArrGenAuto(0, 0);

    MainMatrixGridView->RowCount = SizeMatrix;
    MainMatrixGridView->ColumnCount = SizeMatrix;

    ShowMatrix(SizeMatrix, MainMatrix, 1); //������� �������
    //������
    MainMatrixGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    MainMatrixGridView->AutoResizeColumns();//�������
    
    return System::Void();
}

//��������� ������� ���������� �����
System::Void ReverseMatrix::RevMatForm::ArrGenAutoButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    int MaxNumber, MinNumber;
    MaxNumber = Convert::ToInt32(MaxNumberUpDown->Value);
    MinNumber = Convert::ToInt32(MinNumberUpDown->Value);

    Matrix MainMatrix = GetMatrix(1);
    MainMatrix.ArrGenAuto(MinNumber, MaxNumber);

    ShowMatrix(MainMatrix.GetRow(), MainMatrix, 1); //������� �������
    //������
    MainMatrixGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
    MainMatrixGridView->AutoResizeColumns();//�������
    return System::Void();
}

//��������� ������� ������� ����������
System::Void ReverseMatrix::RevMatForm::EmborderingButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Matrix  MainMatrix = GetMatrix(1);
    if (SolutionCheck->Checked)
    {
        EmborderingSolution^ Form = gcnew EmborderingSolution(MainMatrix);
        Form->Show();
    }

    if (UnAcceptable(MainMatrix, 1))
    {
        MessageBox::Show("������ ������� �� �������� ��� ������ ������");
        return;
    }
    else
    {
        Matrix ReverseMatrix = Embordering(MainMatrix);
        ReverseMatrixGridView->RowCount = ReverseMatrix.GetRow();
        ReverseMatrixGridView->ColumnCount = ReverseMatrix.GetRow();

        ShowMatrix(ReverseMatrix.GetRow(), ReverseMatrix, 2);
        //������
        MainMatrixGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
        MainMatrixGridView->AutoResizeColumns();//�������
    }

    return System::Void();
}

System::Void ReverseMatrix::RevMatForm::CellDivisionButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Matrix  MainMatrix = GetMatrix(1);
    if (SolutionCheck->Checked)
    {
        CellDivisionSolution^ Form = gcnew CellDivisionSolution(MainMatrix);
        Form->Show();
    }

    if (UnAcceptable(MainMatrix, 2))
    {
        MessageBox::Show("������ ������� �� �������� ��� ������ ������");
        return;
    }
    else
    {
        Matrix ReverseMatrix = CellDivision(MainMatrix);
        ReverseMatrixGridView->RowCount = ReverseMatrix.GetRow();
        ReverseMatrixGridView->ColumnCount = ReverseMatrix.GetRow();

        ShowMatrix(ReverseMatrix.GetRow(), ReverseMatrix, 2);
        //������
        ReverseMatrixGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
        ReverseMatrixGridView->AutoResizeColumns();//�������
    }
    return System::Void();
}

//����� �������
void ReverseMatrix::RevMatForm::ShowMatrix(int SizeMatrix, Matrix MainMatrix, int type)
{
    if (type == 1)
    {
        for (int i = 0; i < SizeMatrix; i++)
        {
            for (int j = 0; j < SizeMatrix; j++)
            {
                //����� ������� � ����� �����
                MainMatrixGridView->TopLeftHeaderCell->Value = "������� �������";
                //������ ��������
                MainMatrixGridView->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
                //������ �����
                MainMatrixGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
                //�������� �������
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
                //����� ������� � ����� �����
                ReverseMatrixGridView->TopLeftHeaderCell->Value = "������� �������";
                //������ ��������
                ReverseMatrixGridView->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
                //������ �����
                ReverseMatrixGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
                //�������� �������
                ReverseMatrixGridView->Rows[i]->Cells[j]->Value = MainMatrix.GetArr()[i][j];
            }
        }
    }
}

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

System::Void ReverseMatrix::RevMatForm::WriteFileButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    Matrix ReverseMatrix = GetMatrix(2);
    string FileName = marshal_as<string>(FileNameTextBox->Text);
    
    int result = WriteFile(ReverseMatrix, FileName);
    if (result == 1)
    {
        MessageBox::Show("���� �� ���������");
        return;
    }
    else
    {
        MessageBox::Show("������� ������ �������� � ���� ", FileNameTextBox->Text);
        return;
    }
    return System::Void();
}

System::Void ReverseMatrix::RevMatForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}
