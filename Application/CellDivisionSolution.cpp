#include "CellDivisionSolution.h"
#include "RevMat.h"

System::Void ReverseMatrix::CellDivisionSolution::вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
	return System::Void();
}

void ReverseMatrix::CellDivisionSolution::CDResult(Matrix MainMatrix)
{
	int count = 0;
	Matrix MatrixCell11 = CellDivisionInitialization(MainMatrix, 1);
	Matrix MatrixCell12 = CellDivisionInitialization(MainMatrix, 2);
	Matrix MatrixCell21 = CellDivisionInitialization(MainMatrix, 3);
	Matrix MatrixCell22 = CellDivisionInitialization(MainMatrix, 4);
	count++;
	Matrix MatrixCell22Inverse = CellDivision(MatrixCell22, &count);

	count++;
	Matrix MatrixR11 = MachineZero(CellDivision(MatrixCell11 - (MatrixCell12 * (MatrixCell22Inverse * MatrixCell21)), &count));
	Matrix MatrixR12 = MachineZero(((MatrixR11 * (-1)) * MatrixCell12) * MatrixCell22Inverse);
	Matrix MatrixR21 = MachineZero((MatrixCell22Inverse * (-1)) * MatrixCell21 * MatrixR11);
	Matrix MatrixR22 = MachineZero(MatrixCell22Inverse - (MatrixCell22Inverse * MatrixCell21 * MatrixR12));

	Matrix ReverseMatrix = CellDivisionBuild(MainMatrix, MatrixR11, MatrixR12, MatrixR21, MatrixR22);
	
	RecCount->Text = Convert::ToString(count);
	MatrixCell11View->RowCount = MatrixCell11.GetRow();
	MatrixCell11View->ColumnCount = MatrixCell11.GetColumn();
	for (int i = 0; i < MatrixCell11.GetRow(); i++)
	{
		for (int j = 0; j < MatrixCell11.GetColumn(); j++)
		{
			//Назва таблиці у лівому кутку
			MatrixCell11View->TopLeftHeaderCell->Value = "A11";
			//Номери столбців
			MatrixCell11View->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//Номери рядків
			MatrixCell11View->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//Значення матриці
			MatrixCell11View->Rows[i]->Cells[j]->Value = MatrixCell11.GetArr()[i][j];
		}
	}
	MatrixCell11View->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	MatrixCell11View->AutoResizeColumns();//Стовбці


	MatrixCell12View->RowCount = MatrixCell12.GetRow();
	MatrixCell12View->ColumnCount = MatrixCell12.GetColumn();
	for (int i = 0; i < MatrixCell12.GetRow(); i++)
	{
		for (int j = 0; j < MatrixCell12.GetColumn(); j++)
		{
			//Назва таблиці у лівому кутку
			MatrixCell12View->TopLeftHeaderCell->Value = "A12";
			//Номери столбців
			MatrixCell12View->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//Номери рядків
			MatrixCell12View->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//Значення матриці
			MatrixCell12View->Rows[i]->Cells[j]->Value = MatrixCell12.GetArr()[i][j];
		}
	}
	MatrixCell12View->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	MatrixCell12View->AutoResizeColumns();//Стовбці

	MatrixCell21View->RowCount = MatrixCell21.GetRow();
	MatrixCell21View->ColumnCount = MatrixCell21.GetColumn();
	for (int i = 0; i < MatrixCell21.GetRow(); i++)
	{
		for (int j = 0; j < MatrixCell21.GetColumn(); j++)
		{
			//Назва таблиці у лівому кутку
			MatrixCell21View->TopLeftHeaderCell->Value = "A21";
			//Номери столбців
			MatrixCell21View->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//Номери рядків
			MatrixCell21View->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//Значення матриці
			MatrixCell21View->Rows[i]->Cells[j]->Value = MatrixCell21.GetArr()[i][j];
		}
	}
	MatrixCell21View->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	MatrixCell21View->AutoResizeColumns();//Стовбці

	MatrixCell22View->RowCount = MatrixCell22.GetRow();
	MatrixCell22View->ColumnCount = MatrixCell22.GetColumn();
	for (int i = 0; i < MatrixCell22.GetRow(); i++)
	{
		for (int j = 0; j < MatrixCell22.GetColumn(); j++)
		{
			//Назва таблиці у лівому кутку
			MatrixCell22View->TopLeftHeaderCell->Value = "A22";
			//Номери столбців
			MatrixCell22View->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//Номери рядків
			MatrixCell22View->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//Значення матриці
			MatrixCell22View->Rows[i]->Cells[j]->Value = MatrixCell22.GetArr()[i][j];
		}
	}
	MatrixCell22View->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	MatrixCell22View->AutoResizeColumns();//Стовбці

	R11View->RowCount = MatrixR11.GetRow();
	R11View->ColumnCount = MatrixR11.GetColumn();
	for (int i = 0; i < MatrixR11.GetRow(); i++)
	{
		for (int j = 0; j < MatrixR11.GetColumn(); j++)
		{
			//Назва таблиці у лівому кутку
			R11View->TopLeftHeaderCell->Value = "R11";
			//Номери столбців
			R11View->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//Номери рядків
			R11View->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//Значення матриці
			R11View->Rows[i]->Cells[j]->Value = MatrixR11.GetArr()[i][j];
		}
	}
	R11View->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	R11View->AutoResizeColumns();//Стовбці

	R12View->RowCount = MatrixR12.GetRow();
	R12View->ColumnCount = MatrixR12.GetColumn();
	for (int i = 0; i < MatrixR12.GetRow(); i++)
	{
		for (int j = 0; j < MatrixR12.GetColumn(); j++)
		{
			//Назва таблиці у лівому кутку
			R12View->TopLeftHeaderCell->Value = "R12";
			//Номери столбців
			R12View->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//Номери рядків
			R12View->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//Значення матриці
			R12View->Rows[i]->Cells[j]->Value = MatrixR12.GetArr()[i][j];
		}
	}
	R12View->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	R12View->AutoResizeColumns();//Стовбці

	R21View->RowCount = MatrixR21.GetRow();
	R21View->ColumnCount = MatrixR21.GetColumn();
	for (int i = 0; i < MatrixR21.GetRow(); i++)
	{
		for (int j = 0; j < MatrixR21.GetColumn(); j++)
		{
			//Назва таблиці у лівому кутку
			R21View->TopLeftHeaderCell->Value = "R21";
			//Номери столбців
			R21View->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//Номери рядків
			R21View->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//Значення матриці
			R21View->Rows[i]->Cells[j]->Value = MatrixR21.GetArr()[i][j];
		}
	}
	R21View->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	R21View->AutoResizeColumns();//Стовбці

	R22View->RowCount = MatrixR22.GetRow();
	R22View->ColumnCount = MatrixR22.GetColumn();
	for (int i = 0; i < MatrixR22.GetRow(); i++)
	{
		for (int j = 0; j < MatrixR22.GetColumn(); j++)
		{
			//Назва таблиці у лівому кутку
			R22View->TopLeftHeaderCell->Value = "R22";
			//Номери столбців
			R22View->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//Номери рядків
			R22View->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//Значення матриці
			R22View->Rows[i]->Cells[j]->Value = MatrixR22.GetArr()[i][j];
		}
	}
	R22View->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	R22View->AutoResizeColumns();//Стовбці

	ReverseMatrixCD->RowCount = ReverseMatrix.GetRow();
	ReverseMatrixCD->ColumnCount = ReverseMatrix.GetColumn();
	for (int i = 0; i < ReverseMatrix.GetRow(); i++)
	{
		for (int j = 0; j < ReverseMatrix.GetColumn(); j++)
		{
			//Назва таблиці у лівому кутку
			ReverseMatrixCD->TopLeftHeaderCell->Value = "Обернена матриця";
			//Номери столбців
			ReverseMatrixCD->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//Номери рядків
			ReverseMatrixCD->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//Значення матриці
			ReverseMatrixCD->Rows[i]->Cells[j]->Value = ReverseMatrix.GetArr()[i][j];
		}
	}
	ReverseMatrixCD->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	ReverseMatrixCD->AutoResizeColumns();//Стовбці
}
