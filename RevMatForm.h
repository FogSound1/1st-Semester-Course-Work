#pragma once
#include "Matrix.h"
#include "CellDivisionSolution.h"
#include "EmborderingSolution.h"

namespace ReverseMatrix 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RevMatForm
	/// </summary>
	public ref class RevMatForm : public System::Windows::Forms::Form
	{
	public:
		RevMatForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RevMatForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ ReverseMatrixGridView;

	private: System::Windows::Forms::DataGridView^ MainMatrixGridView;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ MatrixSizeUpDown;
	private: System::Windows::Forms::Button^ CreateMatrixButton;
	private: System::Windows::Forms::Button^ ArrGenAutoButton;




	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ EmborderingButton;
	private: System::Windows::Forms::Button^ CellDivisionButton;
	private: System::Windows::Forms::NumericUpDown^ MinNumberUpDown;
	private: System::Windows::Forms::NumericUpDown^ MaxNumberUpDown;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ FileNameTextBox;
	private: System::Windows::Forms::Button^ WriteFileButton;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^ SolutionCheck;















	protected:












	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ReverseMatrixGridView = (gcnew System::Windows::Forms::DataGridView());
			this->MainMatrixGridView = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MatrixSizeUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->CreateMatrixButton = (gcnew System::Windows::Forms::Button());
			this->ArrGenAutoButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->CellDivisionButton = (gcnew System::Windows::Forms::Button());
			this->EmborderingButton = (gcnew System::Windows::Forms::Button());
			this->MinNumberUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->MaxNumberUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->FileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->WriteFileButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SolutionCheck = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ReverseMatrixGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainMatrixGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixSizeUpDown))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MinNumberUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxNumberUpDown))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(544, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Обернена матриця";
			// 
			// ReverseMatrixGridView
			// 
			this->ReverseMatrixGridView->AllowUserToAddRows = false;
			this->ReverseMatrixGridView->AllowUserToDeleteRows = false;
			this->ReverseMatrixGridView->AllowUserToResizeColumns = false;
			this->ReverseMatrixGridView->AllowUserToResizeRows = false;
			this->ReverseMatrixGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ReverseMatrixGridView->ColumnHeadersVisible = false;
			this->ReverseMatrixGridView->Location = System::Drawing::Point(434, 78);
			this->ReverseMatrixGridView->Name = L"ReverseMatrixGridView";
			this->ReverseMatrixGridView->ReadOnly = true;
			this->ReverseMatrixGridView->RowHeadersVisible = false;
			this->ReverseMatrixGridView->RowHeadersWidth = 62;
			this->ReverseMatrixGridView->RowTemplate->Height = 28;
			this->ReverseMatrixGridView->Size = System::Drawing::Size(372, 269);
			this->ReverseMatrixGridView->TabIndex = 1;
			// 
			// MainMatrixGridView
			// 
			this->MainMatrixGridView->AllowUserToAddRows = false;
			this->MainMatrixGridView->AllowUserToDeleteRows = false;
			this->MainMatrixGridView->AllowUserToResizeColumns = false;
			this->MainMatrixGridView->AllowUserToResizeRows = false;
			this->MainMatrixGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MainMatrixGridView->Location = System::Drawing::Point(12, 78);
			this->MainMatrixGridView->Name = L"MainMatrixGridView";
			this->MainMatrixGridView->RowHeadersWidth = 62;
			this->MainMatrixGridView->RowTemplate->Height = 28;
			this->MainMatrixGridView->Size = System::Drawing::Size(372, 269);
			this->MainMatrixGridView->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(128, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Основна матриця";
			// 
			// MatrixSizeUpDown
			// 
			this->MatrixSizeUpDown->Location = System::Drawing::Point(12, 387);
			this->MatrixSizeUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->MatrixSizeUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->MatrixSizeUpDown->Name = L"MatrixSizeUpDown";
			this->MatrixSizeUpDown->Size = System::Drawing::Size(120, 31);
			this->MatrixSizeUpDown->TabIndex = 4;
			this->MatrixSizeUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// CreateMatrixButton
			// 
			this->CreateMatrixButton->Location = System::Drawing::Point(138, 385);
			this->CreateMatrixButton->Name = L"CreateMatrixButton";
			this->CreateMatrixButton->Size = System::Drawing::Size(101, 33);
			this->CreateMatrixButton->TabIndex = 5;
			this->CreateMatrixButton->Text = L"Створити";
			this->CreateMatrixButton->UseVisualStyleBackColor = true;
			this->CreateMatrixButton->Click += gcnew System::EventHandler(this, &RevMatForm::CreateMatrixButton_Click);
			// 
			// ArrGenAutoButton
			// 
			this->ArrGenAutoButton->Location = System::Drawing::Point(12, 443);
			this->ArrGenAutoButton->Name = L"ArrGenAutoButton";
			this->ArrGenAutoButton->Size = System::Drawing::Size(139, 33);
			this->ArrGenAutoButton->TabIndex = 6;
			this->ArrGenAutoButton->Text = L"Згенерувати";
			this->ArrGenAutoButton->UseVisualStyleBackColor = true;
			this->ArrGenAutoButton->Click += gcnew System::EventHandler(this, &RevMatForm::ArrGenAutoButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->CellDivisionButton);
			this->groupBox1->Controls->Add(this->EmborderingButton);
			this->groupBox1->Location = System::Drawing::Point(435, 361);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(371, 118);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Методи обернення";
			// 
			// CellDivisionButton
			// 
			this->CellDivisionButton->Location = System::Drawing::Point(56, 74);
			this->CellDivisionButton->Name = L"CellDivisionButton";
			this->CellDivisionButton->Size = System::Drawing::Size(274, 38);
			this->CellDivisionButton->TabIndex = 1;
			this->CellDivisionButton->Text = L"Метод розбиття на клітини";
			this->CellDivisionButton->UseVisualStyleBackColor = true;
			this->CellDivisionButton->Click += gcnew System::EventHandler(this, &RevMatForm::CellDivisionButton_Click);
			// 
			// EmborderingButton
			// 
			this->EmborderingButton->Location = System::Drawing::Point(56, 30);
			this->EmborderingButton->Name = L"EmborderingButton";
			this->EmborderingButton->Size = System::Drawing::Size(274, 38);
			this->EmborderingButton->TabIndex = 0;
			this->EmborderingButton->Text = L"Метод окаймлення";
			this->EmborderingButton->UseVisualStyleBackColor = true;
			this->EmborderingButton->Click += gcnew System::EventHandler(this, &RevMatForm::EmborderingButton_Click);
			// 
			// MinNumberUpDown
			// 
			this->MinNumberUpDown->Location = System::Drawing::Point(179, 443);
			this->MinNumberUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->MinNumberUpDown->Name = L"MinNumberUpDown";
			this->MinNumberUpDown->Size = System::Drawing::Size(88, 31);
			this->MinNumberUpDown->TabIndex = 10;
			this->MinNumberUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// MaxNumberUpDown
			// 
			this->MaxNumberUpDown->Location = System::Drawing::Point(291, 443);
			this->MaxNumberUpDown->Name = L"MaxNumberUpDown";
			this->MaxNumberUpDown->Size = System::Drawing::Size(93, 31);
			this->MaxNumberUpDown->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(245, 417);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 23);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Діапазон";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(32, 361);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 23);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Розмір";
			// 
			// FileNameTextBox
			// 
			this->FileNameTextBox->Location = System::Drawing::Point(619, 504);
			this->FileNameTextBox->Name = L"FileNameTextBox";
			this->FileNameTextBox->Size = System::Drawing::Size(187, 31);
			this->FileNameTextBox->TabIndex = 14;
			// 
			// WriteFileButton
			// 
			this->WriteFileButton->Location = System::Drawing::Point(435, 499);
			this->WriteFileButton->Name = L"WriteFileButton";
			this->WriteFileButton->Size = System::Drawing::Size(168, 38);
			this->WriteFileButton->TabIndex = 15;
			this->WriteFileButton->Text = L"Записати у";
			this->WriteFileButton->UseVisualStyleBackColor = true;
			this->WriteFileButton->Click += gcnew System::EventHandler(this, &RevMatForm::WriteFileButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->вихідToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(818, 33);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// вихідToolStripMenuItem
			// 
			this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
			this->вихідToolStripMenuItem->Size = System::Drawing::Size(70, 29);
			this->вихідToolStripMenuItem->Text = L"Вихід";
			this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &RevMatForm::вихідToolStripMenuItem_Click);
			// 
			// SolutionCheck
			// 
			this->SolutionCheck->AutoSize = true;
			this->SolutionCheck->Location = System::Drawing::Point(12, 506);
			this->SolutionCheck->Name = L"SolutionCheck";
			this->SolutionCheck->Size = System::Drawing::Size(193, 27);
			this->SolutionCheck->TabIndex = 17;
			this->SolutionCheck->Text = L"Детальне рішення";
			this->SolutionCheck->UseVisualStyleBackColor = true;
			// 
			// RevMatForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(818, 571);
			this->Controls->Add(this->SolutionCheck);
			this->Controls->Add(this->WriteFileButton);
			this->Controls->Add(this->FileNameTextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->MaxNumberUpDown);
			this->Controls->Add(this->MinNumberUpDown);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ArrGenAutoButton);
			this->Controls->Add(this->ReverseMatrixGridView);
			this->Controls->Add(this->CreateMatrixButton);
			this->Controls->Add(this->MainMatrixGridView);
			this->Controls->Add(this->MatrixSizeUpDown);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"RevMatForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ReverseMatrix";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ReverseMatrixGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainMatrixGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixSizeUpDown))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MinNumberUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxNumberUpDown))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void CreateMatrixButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ArrGenAutoButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void EmborderingButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CellDivisionButton_Click(System::Object^ sender, System::EventArgs^ e);
private: void ShowMatrix(int SizeMatrix, Matrix MainMatrix, int type);
private: Matrix GetMatrix(int type);
private: System::Void WriteFileButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
