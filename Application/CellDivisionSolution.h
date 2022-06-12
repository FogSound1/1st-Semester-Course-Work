#pragma once
#include "Matrix.h"

namespace ReverseMatrix {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CellDivisionSolution
	/// </summary>

	public ref class CellDivisionSolution : public System::Windows::Forms::Form
	{

	public:
		CellDivisionSolution(Matrix MainMatrix)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			CDResult(MainMatrix);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CellDivisionSolution()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ IntroductionLabel;
	private: System::Windows::Forms::DataGridView^ MatrixCell11View;
	private: System::Windows::Forms::DataGridView^ MatrixCell12View;
	private: System::Windows::Forms::DataGridView^ MatrixCell21View;
	private: System::Windows::Forms::DataGridView^ MatrixCell22View;




	private: System::Windows::Forms::Label^ SecondPhase;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridView^ R11View;
	private: System::Windows::Forms::DataGridView^ R12View;




	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::DataGridView^ R21View;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::DataGridView^ R22View;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::DataGridView^ ReverseMatrixCD;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ RecCount;
	private: System::Windows::Forms::Label^ label16;
	protected:

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
			this->IntroductionLabel = (gcnew System::Windows::Forms::Label());
			this->MatrixCell11View = (gcnew System::Windows::Forms::DataGridView());
			this->MatrixCell12View = (gcnew System::Windows::Forms::DataGridView());
			this->MatrixCell21View = (gcnew System::Windows::Forms::DataGridView());
			this->MatrixCell22View = (gcnew System::Windows::Forms::DataGridView());
			this->SecondPhase = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->R11View = (gcnew System::Windows::Forms::DataGridView());
			this->R12View = (gcnew System::Windows::Forms::DataGridView());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->R21View = (gcnew System::Windows::Forms::DataGridView());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->R22View = (gcnew System::Windows::Forms::DataGridView());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->ReverseMatrixCD = (gcnew System::Windows::Forms::DataGridView());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RecCount = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixCell11View))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixCell12View))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixCell21View))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixCell22View))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R11View))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R12View))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R21View))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R22View))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ReverseMatrixCD))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// IntroductionLabel
			// 
			this->IntroductionLabel->AutoSize = true;
			this->IntroductionLabel->Location = System::Drawing::Point(511, 9);
			this->IntroductionLabel->Name = L"IntroductionLabel";
			this->IntroductionLabel->Size = System::Drawing::Size(482, 20);
			this->IntroductionLabel->TabIndex = 0;
			this->IntroductionLabel->Text = L"Спочатку розіб\'ємо основну матрицю на 4 підматриці (клітини)";
			// 
			// MatrixCell11View
			// 
			this->MatrixCell11View->AllowUserToAddRows = false;
			this->MatrixCell11View->AllowUserToDeleteRows = false;
			this->MatrixCell11View->AllowUserToResizeColumns = false;
			this->MatrixCell11View->AllowUserToResizeRows = false;
			this->MatrixCell11View->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MatrixCell11View->ColumnHeadersVisible = false;
			this->MatrixCell11View->Location = System::Drawing::Point(105, 80);
			this->MatrixCell11View->Name = L"MatrixCell11View";
			this->MatrixCell11View->ReadOnly = true;
			this->MatrixCell11View->RowHeadersVisible = false;
			this->MatrixCell11View->RowHeadersWidth = 62;
			this->MatrixCell11View->RowTemplate->Height = 28;
			this->MatrixCell11View->Size = System::Drawing::Size(267, 189);
			this->MatrixCell11View->TabIndex = 1;
			// 
			// MatrixCell12View
			// 
			this->MatrixCell12View->AllowUserToAddRows = false;
			this->MatrixCell12View->AllowUserToDeleteRows = false;
			this->MatrixCell12View->AllowUserToResizeColumns = false;
			this->MatrixCell12View->AllowUserToResizeRows = false;
			this->MatrixCell12View->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MatrixCell12View->ColumnHeadersVisible = false;
			this->MatrixCell12View->Location = System::Drawing::Point(430, 80);
			this->MatrixCell12View->Name = L"MatrixCell12View";
			this->MatrixCell12View->ReadOnly = true;
			this->MatrixCell12View->RowHeadersVisible = false;
			this->MatrixCell12View->RowHeadersWidth = 62;
			this->MatrixCell12View->RowTemplate->Height = 28;
			this->MatrixCell12View->Size = System::Drawing::Size(267, 189);
			this->MatrixCell12View->TabIndex = 2;
			// 
			// MatrixCell21View
			// 
			this->MatrixCell21View->AllowUserToAddRows = false;
			this->MatrixCell21View->AllowUserToDeleteRows = false;
			this->MatrixCell21View->AllowUserToResizeColumns = false;
			this->MatrixCell21View->AllowUserToResizeRows = false;
			this->MatrixCell21View->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MatrixCell21View->ColumnHeadersVisible = false;
			this->MatrixCell21View->Location = System::Drawing::Point(752, 80);
			this->MatrixCell21View->Name = L"MatrixCell21View";
			this->MatrixCell21View->ReadOnly = true;
			this->MatrixCell21View->RowHeadersVisible = false;
			this->MatrixCell21View->RowHeadersWidth = 62;
			this->MatrixCell21View->RowTemplate->Height = 28;
			this->MatrixCell21View->Size = System::Drawing::Size(267, 189);
			this->MatrixCell21View->TabIndex = 3;
			// 
			// MatrixCell22View
			// 
			this->MatrixCell22View->AllowUserToAddRows = false;
			this->MatrixCell22View->AllowUserToDeleteRows = false;
			this->MatrixCell22View->AllowUserToResizeColumns = false;
			this->MatrixCell22View->AllowUserToResizeRows = false;
			this->MatrixCell22View->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MatrixCell22View->ColumnHeadersVisible = false;
			this->MatrixCell22View->Location = System::Drawing::Point(1074, 80);
			this->MatrixCell22View->Name = L"MatrixCell22View";
			this->MatrixCell22View->ReadOnly = true;
			this->MatrixCell22View->RowHeadersVisible = false;
			this->MatrixCell22View->RowHeadersWidth = 62;
			this->MatrixCell22View->RowTemplate->Height = 28;
			this->MatrixCell22View->Size = System::Drawing::Size(267, 189);
			this->MatrixCell22View->TabIndex = 4;
			// 
			// SecondPhase
			// 
			this->SecondPhase->AutoSize = true;
			this->SecondPhase->Location = System::Drawing::Point(511, 296);
			this->SecondPhase->Name = L"SecondPhase";
			this->SecondPhase->Size = System::Drawing::Size(463, 20);
			this->SecondPhase->TabIndex = 5;
			this->SecondPhase->Text = L"Далі знаходимо клітини до оберненої матриці по формулам";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(226, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"A11";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(539, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"A12";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1184, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"A22";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(869, 57);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"A21";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label5->Location = System::Drawing::Point(12, 414);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(386, 32);
			this->label5->TabIndex = 10;
			this->label5->Text = L"R11 = (A11 - A12 A22 A21) = ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(230, 394);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"-1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(349, 394);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(23, 20);
			this->label7->TabIndex = 12;
			this->label7->Text = L"-1";
			// 
			// R11View
			// 
			this->R11View->AllowUserToAddRows = false;
			this->R11View->AllowUserToDeleteRows = false;
			this->R11View->AllowUserToResizeColumns = false;
			this->R11View->AllowUserToResizeRows = false;
			this->R11View->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->R11View->ColumnHeadersVisible = false;
			this->R11View->Location = System::Drawing::Point(395, 344);
			this->R11View->Name = L"R11View";
			this->R11View->ReadOnly = true;
			this->R11View->RowHeadersVisible = false;
			this->R11View->RowHeadersWidth = 62;
			this->R11View->RowTemplate->Height = 28;
			this->R11View->Size = System::Drawing::Size(267, 189);
			this->R11View->TabIndex = 13;
			// 
			// R12View
			// 
			this->R12View->AllowUserToAddRows = false;
			this->R12View->AllowUserToDeleteRows = false;
			this->R12View->AllowUserToResizeColumns = false;
			this->R12View->AllowUserToResizeRows = false;
			this->R12View->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->R12View->ColumnHeadersVisible = false;
			this->R12View->Location = System::Drawing::Point(1074, 344);
			this->R12View->Name = L"R12View";
			this->R12View->ReadOnly = true;
			this->R12View->RowHeadersVisible = false;
			this->R12View->RowHeadersWidth = 62;
			this->R12View->RowTemplate->Height = 28;
			this->R12View->Size = System::Drawing::Size(267, 189);
			this->R12View->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(992, 394);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(23, 20);
			this->label9->TabIndex = 15;
			this->label9->Text = L"-1";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label10->Location = System::Drawing::Point(739, 414);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(297, 32);
			this->label10->TabIndex = 14;
			this->label10->Text = L"R12 = -R11 A12 A22 =";
			// 
			// R21View
			// 
			this->R21View->AllowUserToAddRows = false;
			this->R21View->AllowUserToDeleteRows = false;
			this->R21View->AllowUserToResizeColumns = false;
			this->R21View->AllowUserToResizeRows = false;
			this->R21View->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->R21View->ColumnHeadersVisible = false;
			this->R21View->Location = System::Drawing::Point(395, 565);
			this->R21View->Name = L"R21View";
			this->R21View->ReadOnly = true;
			this->R21View->RowHeadersVisible = false;
			this->R21View->RowHeadersWidth = 62;
			this->R21View->RowTemplate->Height = 28;
			this->R21View->Size = System::Drawing::Size(267, 189);
			this->R21View->TabIndex = 21;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(217, 615);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(23, 20);
			this->label11->TabIndex = 19;
			this->label11->Text = L"-1";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label12->Location = System::Drawing::Point(75, 635);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(297, 32);
			this->label12->TabIndex = 18;
			this->label12->Text = L"R21 = -A22 A21 R21 =";
			// 
			// R22View
			// 
			this->R22View->AllowUserToAddRows = false;
			this->R22View->AllowUserToDeleteRows = false;
			this->R22View->AllowUserToResizeColumns = false;
			this->R22View->AllowUserToResizeRows = false;
			this->R22View->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->R22View->ColumnHeadersVisible = false;
			this->R22View->Location = System::Drawing::Point(1074, 582);
			this->R22View->Name = L"R22View";
			this->R22View->ReadOnly = true;
			this->R22View->RowHeadersVisible = false;
			this->R22View->RowHeadersWidth = 62;
			this->R22View->RowTemplate->Height = 28;
			this->R22View->Size = System::Drawing::Size(267, 189);
			this->R22View->TabIndex = 25;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(907, 615);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(23, 20);
			this->label13->TabIndex = 24;
			this->label13->Text = L"-1";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(828, 615);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(23, 20);
			this->label14->TabIndex = 23;
			this->label14->Text = L"-1";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label15->Location = System::Drawing::Point(700, 635);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(368, 32);
			this->label15->TabIndex = 22;
			this->label15->Text = L"R22 = A22 - A22 A21 B12 = ";
			// 
			// ReverseMatrixCD
			// 
			this->ReverseMatrixCD->AllowUserToAddRows = false;
			this->ReverseMatrixCD->AllowUserToDeleteRows = false;
			this->ReverseMatrixCD->AllowUserToResizeColumns = false;
			this->ReverseMatrixCD->AllowUserToResizeRows = false;
			this->ReverseMatrixCD->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ReverseMatrixCD->ColumnHeadersVisible = false;
			this->ReverseMatrixCD->Location = System::Drawing::Point(558, 769);
			this->ReverseMatrixCD->Name = L"ReverseMatrixCD";
			this->ReverseMatrixCD->ReadOnly = true;
			this->ReverseMatrixCD->RowHeadersVisible = false;
			this->ReverseMatrixCD->RowHeadersWidth = 62;
			this->ReverseMatrixCD->RowTemplate->Height = 28;
			this->ReverseMatrixCD->Size = System::Drawing::Size(372, 269);
			this->ReverseMatrixCD->TabIndex = 26;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(113, 889);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(401, 20);
			this->label8->TabIndex = 27;
			this->label8->Text = L"Збираємо клітини та отримуємо обернену матрицю";
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->вихідToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1395, 33);
			this->menuStrip1->TabIndex = 28;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// вихідToolStripMenuItem
			// 
			this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
			this->вихідToolStripMenuItem->Size = System::Drawing::Size(70, 29);
			this->вихідToolStripMenuItem->Text = L"Вихід";
			this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &CellDivisionSolution::вихідToolStripMenuItem_Click);
			// 
			// RecCount
			// 
			this->RecCount->Location = System::Drawing::Point(1036, 930);
			this->RecCount->Name = L"RecCount";
			this->RecCount->ReadOnly = true;
			this->RecCount->Size = System::Drawing::Size(100, 26);
			this->RecCount->TabIndex = 29;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(956, 889);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(253, 20);
			this->label16->TabIndex = 30;
			this->label16->Text = L"Кількість рекурсивних входжень";
			// 
			// CellDivisionSolution
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1395, 1050);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->RecCount);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->ReverseMatrixCD);
			this->Controls->Add(this->R22View);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->R21View);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->R12View);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->R11View);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->SecondPhase);
			this->Controls->Add(this->MatrixCell22View);
			this->Controls->Add(this->MatrixCell21View);
			this->Controls->Add(this->MatrixCell12View);
			this->Controls->Add(this->MatrixCell11View);
			this->Controls->Add(this->IntroductionLabel);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"CellDivisionSolution";
			this->Text = L"CellDivisionSolution";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixCell11View))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixCell12View))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixCell21View))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixCell22View))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R11View))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R12View))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R21View))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->R22View))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ReverseMatrixCD))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: void CDResult(Matrix MainMatrix);
};
}
