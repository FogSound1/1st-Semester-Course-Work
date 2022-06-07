#include "EmborderingSolution.h"
#include "RevMat.h"

void ReverseMatrix::EmborderingSolution::Esolution(Matrix MainMatrix, int iter)
{
	int Disposal = MainMatrix.GetRow();
	Matrix OldA(1, 1);
	OldA.GetArr()[0][0] = 1 / MainMatrix.GetArr()[0][0];

	if (iter == 0)
	{
		MainMatrixE->RowCount = MainMatrix.GetRow();
		MainMatrixE->ColumnCount = MainMatrix.GetColumn();
		for (int i = 0; i < MainMatrix.GetRow(); i++)
		{
			for (int j = 0; j < MainMatrix.GetColumn(); j++)
			{
				//Значення матриці
				MainMatrixE->Rows[i]->Cells[j]->Value = MainMatrix.GetArr()[i][j];
			}
		}
		MainMatrixE->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		MainMatrixE->AutoResizeColumns();//Стовбці

		IterText->Text = Convert::ToString(1);

		AkGrid->RowCount = 1;
		AkGrid->ColumnCount = 1;

		MatrixAView->RowCount = OldA.GetRow();
		MatrixAView->ColumnCount = OldA.GetColumn();
		for (int i = 0; i < OldA.GetRow(); i++)
		{
			for (int j = 0; j < OldA.GetColumn(); j++)
			{
				//Значення матриці
				MatrixAView->Rows[i]->Cells[j]->Value = OldA.GetArr()[i][j];
			}
		}
		MatrixAView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		MatrixAView->AutoResizeColumns();//Стовбці
	}

	for (int k = 1; k < Disposal; k++)
	{
		Matrix A(k + 1, k + 1);
		for (int i = 0; i < k + 1; i++)
		{
			for (int j = 0; j < k + 1; j++)
			{
				A.GetArr()[i][j] = MainMatrix.GetArr()[i][j];
			}
		}
		if (k == iter)
		{
			MatrixAView->RowCount = A.GetRow();
			MatrixAView->ColumnCount = A.GetColumn();
			for (int i = 0; i < A.GetRow(); i++)
			{
				for (int j = 0; j < A.GetColumn(); j++)
				{
					//Значення матриці
					MatrixAView->Rows[i]->Cells[j]->Value = A.GetArr()[i][j];
				}
			}
			MatrixAView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			MatrixAView->AutoResizeColumns();//Стовбці
		}

		Matrix U(k, 1);
		Matrix V(1, k);
		double a = A.GetArr()[k][k];
		for (int i = 0; i < k; i++)
		{
			U.GetArr()[i][0] = A.GetArr()[i][k];
			V.GetArr()[0][i] = A.GetArr()[k][i];
		}
		double akk = a - (V * OldA * U).GetArr()[0][0];
		Matrix r = MachineZero(OldA * U * (-1 / akk));
		Matrix q = MachineZero(V * OldA * (-1 / akk));
		Matrix B = MachineZero(OldA - (OldA * U) * q);


		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				A.GetArr()[i][j] = B.GetArr()[i][j];
			}
		}
		for (int j = 0; j < k; j++)
		{
			A.GetArr()[j][k] = r.GetArr()[j][0];
			A.GetArr()[k][j] = q.GetArr()[0][j];
		}
		A.GetArr()[k][k] = (1 / akk);

		if (k == iter)
		{
			IterText->Text = Convert::ToString(iter + 1);
			UView->RowCount = U.GetRow();
			UView->ColumnCount = U.GetColumn();
			for (int i = 0; i < U.GetRow(); i++)
			{
				for (int j = 0; j < U.GetColumn(); j++)
				{
					//Значення матриці
					UView->Rows[i]->Cells[j]->Value = U.GetArr()[i][j];
				}
			}
			UView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			UView->AutoResizeColumns();//Стовбці

			AkkText->Text = Convert::ToString(a);
			AkText->Text = Convert::ToString(akk);

			VView->RowCount = V.GetRow();
			VView->ColumnCount = V.GetColumn();
			for (int i = 0; i < V.GetRow(); i++)
			{
				for (int j = 0; j < V.GetColumn(); j++)
				{
					//Значення матриці
					VView->Rows[i]->Cells[j]->Value = V.GetArr()[i][j];
				}
			}
			VView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			VView->AutoResizeColumns();//Стовбці

			rView->RowCount = r.GetRow();
			rView->ColumnCount = r.GetColumn();
			for (int i = 0; i < r.GetRow(); i++)
			{
				for (int j = 0; j < r.GetColumn(); j++)
				{
					//Значення матриці
					rView->Rows[i]->Cells[j]->Value = r.GetArr()[i][j];
				}
			}
			rView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			rView->AutoResizeColumns();//Стовбці

			qView->RowCount = q.GetRow();
			qView->ColumnCount = q.GetColumn();
			for (int i = 0; i < q.GetRow(); i++)
			{
				for (int j = 0; j < q.GetColumn(); j++)
				{
					//Значення матриці
					qView->Rows[i]->Cells[j]->Value = q.GetArr()[i][j];
				}
			}
			qView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			qView->AutoResizeColumns();//Стовбці

			BView->RowCount = B.GetRow();
			BView->ColumnCount = B.GetColumn();
			for (int i = 0; i < B.GetRow(); i++)
			{
				for (int j = 0; j < B.GetColumn(); j++)
				{
					//Значення матриці
					BView->Rows[i]->Cells[j]->Value = B.GetArr()[i][j];
				}
			}
			BView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			BView->AutoResizeColumns();//Стовбці

			AkGrid->RowCount = A.GetRow();
			AkGrid->ColumnCount = A.GetColumn();
			for (int i = 0; i < A.GetRow(); i++)
			{
				for (int j = 0; j < A.GetColumn(); j++)
				{
					//Значення матриці
					AkGrid->Rows[i]->Cells[j]->Value = A.GetArr()[i][j];
				}
			}
			AkGrid->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
			AkGrid->AutoResizeColumns();//Стовбці
		}

		OldA = A;
	}
}

Matrix ReverseMatrix::EmborderingSolution::GetMain()
{
	Matrix SomeMatrix(MainMatrixE->RowCount, MainMatrixE->ColumnCount);

	for (int i = 0; i < MainMatrixE->RowCount; i++)
	{
		for (int j = 0; j < MainMatrixE->ColumnCount; j++)
		{
			SomeMatrix.GetArr()[i][j] = Convert::ToDouble(MainMatrixE->Rows[i]->Cells[j]->Value);
		}
	}

	return SomeMatrix;
}


System::Void ReverseMatrix::EmborderingSolution::IterButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	Matrix MainMatrix = GetMain();
	int iter = Convert::ToInt32(IterText->Text);

	if (iter == MainMatrix.GetRow())
	{
		MessageBox::Show("Це була остання ітерація");
	}
	else
	{
		Esolution(MainMatrix, iter);
	}
	return System::Void();
}

System::Void ReverseMatrix::EmborderingSolution::вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
