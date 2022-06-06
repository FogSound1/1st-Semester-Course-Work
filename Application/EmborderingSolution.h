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
	/// Сводка для EmborderingSolution
	/// </summary>
	public ref class EmborderingSolution : public System::Windows::Forms::Form
	{
	public:
		EmborderingSolution(Matrix MainMatrix)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Esolution(MainMatrix, 0);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EmborderingSolution()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ MatrixAView;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ UView;
	private: System::Windows::Forms::DataGridView^ VView;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ IterText;
	private: System::Windows::Forms::TextBox^ AkkText;
	private: System::Windows::Forms::TextBox^ AkText;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DataGridView^ qView;

	private: System::Windows::Forms::DataGridView^ rView;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::DataGridView^ BView;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::DataGridView^ AkGrid;

	private: System::Windows::Forms::Button^ IterButton;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::DataGridView^ MainMatrixE;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MatrixAView = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->UView = (gcnew System::Windows::Forms::DataGridView());
			this->VView = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->IterText = (gcnew System::Windows::Forms::TextBox());
			this->AkkText = (gcnew System::Windows::Forms::TextBox());
			this->AkText = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->qView = (gcnew System::Windows::Forms::DataGridView());
			this->rView = (gcnew System::Windows::Forms::DataGridView());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->BView = (gcnew System::Windows::Forms::DataGridView());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->AkGrid = (gcnew System::Windows::Forms::DataGridView());
			this->IterButton = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->MainMatrixE = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixAView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->qView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AkGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainMatrixE))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(45, 194);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 20);
			this->label1->TabIndex = 111;
			this->label1->Text = L"k = ";
			// 
			// MatrixAView
			// 
			this->MatrixAView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MatrixAView->ColumnHeadersVisible = false;
			this->MatrixAView->Location = System::Drawing::Point(84, 262);
			this->MatrixAView->Name = L"MatrixAView";
			this->MatrixAView->RowHeadersVisible = false;
			this->MatrixAView->RowHeadersWidth = 62;
			this->MatrixAView->RowTemplate->Height = 28;
			this->MatrixAView->Size = System::Drawing::Size(339, 310);
			this->MatrixAView->TabIndex = 112;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 392);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 20);
			this->label2->TabIndex = 113;
			this->label2->Text = L"A =";
			// 
			// UView
			// 
			this->UView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->UView->ColumnHeadersVisible = false;
			this->UView->Location = System::Drawing::Point(1044, 365);
			this->UView->Name = L"UView";
			this->UView->RowHeadersVisible = false;
			this->UView->RowHeadersWidth = 62;
			this->UView->RowTemplate->Height = 28;
			this->UView->Size = System::Drawing::Size(117, 336);
			this->UView->TabIndex = 114;
			// 
			// VView
			// 
			this->VView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->VView->ColumnHeadersVisible = false;
			this->VView->Location = System::Drawing::Point(468, 392);
			this->VView->Name = L"VView";
			this->VView->RowHeadersVisible = false;
			this->VView->RowHeadersWidth = 62;
			this->VView->RowTemplate->Height = 28;
			this->VView->Size = System::Drawing::Size(502, 111);
			this->VView->TabIndex = 115;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(987, 546);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 20);
			this->label3->TabIndex = 116;
			this->label3->Text = L"U =";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(429, 447);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 20);
			this->label4->TabIndex = 117;
			this->label4->Text = L"V =";
			// 
			// IterText
			// 
			this->IterText->Location = System::Drawing::Point(84, 194);
			this->IterText->Name = L"IterText";
			this->IterText->Size = System::Drawing::Size(100, 26);
			this->IterText->TabIndex = 118;
			// 
			// AkkText
			// 
			this->AkkText->Location = System::Drawing::Point(496, 546);
			this->AkkText->Name = L"AkkText";
			this->AkkText->Size = System::Drawing::Size(100, 26);
			this->AkkText->TabIndex = 119;
			// 
			// AkText
			// 
			this->AkText->Location = System::Drawing::Point(789, 546);
			this->AkText->Name = L"AkText";
			this->AkText->Size = System::Drawing::Size(100, 26);
			this->AkText->TabIndex = 120;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(441, 546);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 20);
			this->label5->TabIndex = 121;
			this->label5->Text = L"akk = ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(637, 546);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(136, 20);
			this->label6->TabIndex = 122;
			this->label6->Text = L"ak = akk - V A U =";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(26, 935);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(113, 20);
			this->label7->TabIndex = 126;
			this->label7->Text = L"q = -1/ak V A =";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(168, 726);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(110, 20);
			this->label8->TabIndex = 125;
			this->label8->Text = L"r = -1/ak A U =";
			// 
			// qView
			// 
			this->qView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->qView->ColumnHeadersVisible = false;
			this->qView->Location = System::Drawing::Point(145, 894);
			this->qView->Name = L"qView";
			this->qView->RowHeadersVisible = false;
			this->qView->RowHeadersWidth = 62;
			this->qView->RowTemplate->Height = 28;
			this->qView->Size = System::Drawing::Size(552, 106);
			this->qView->TabIndex = 124;
			// 
			// rView
			// 
			this->rView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->rView->ColumnHeadersVisible = false;
			this->rView->Location = System::Drawing::Point(296, 587);
			this->rView->Name = L"rView";
			this->rView->RowHeadersVisible = false;
			this->rView->RowHeadersWidth = 62;
			this->rView->RowTemplate->Height = 28;
			this->rView->Size = System::Drawing::Size(177, 301);
			this->rView->TabIndex = 123;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(589, 821);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(128, 20);
			this->label9->TabIndex = 128;
			this->label9->Text = L"B = A - (A U) q = ";
			// 
			// BView
			// 
			this->BView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->BView->ColumnHeadersVisible = false;
			this->BView->Location = System::Drawing::Point(723, 715);
			this->BView->Name = L"BView";
			this->BView->RowHeadersVisible = false;
			this->BView->RowHeadersWidth = 62;
			this->BView->RowTemplate->Height = 28;
			this->BView->Size = System::Drawing::Size(409, 285);
			this->BView->TabIndex = 127;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1161, 859);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 20);
			this->label10->TabIndex = 130;
			this->label10->Text = L"Ak =";
			// 
			// AkGrid
			// 
			this->AkGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->AkGrid->ColumnHeadersVisible = false;
			this->AkGrid->Location = System::Drawing::Point(1208, 671);
			this->AkGrid->Name = L"AkGrid";
			this->AkGrid->RowHeadersVisible = false;
			this->AkGrid->RowHeadersWidth = 62;
			this->AkGrid->RowTemplate->Height = 28;
			this->AkGrid->Size = System::Drawing::Size(432, 353);
			this->AkGrid->TabIndex = 129;
			// 
			// IterButton
			// 
			this->IterButton->Location = System::Drawing::Point(1568, 512);
			this->IterButton->Name = L"IterButton";
			this->IterButton->Size = System::Drawing::Size(127, 54);
			this->IterButton->TabIndex = 131;
			this->IterButton->Text = L"Далі";
			this->IterButton->UseVisualStyleBackColor = true;
			this->IterButton->Click += gcnew System::EventHandler(this, &EmborderingSolution::IterButton_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(575, 15);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(142, 20);
			this->label11->TabIndex = 133;
			this->label11->Text = L"Головна матриця";
			// 
			// MainMatrixE
			// 
			this->MainMatrixE->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MainMatrixE->ColumnHeadersVisible = false;
			this->MainMatrixE->Location = System::Drawing::Point(470, 38);
			this->MainMatrixE->Name = L"MainMatrixE";
			this->MainMatrixE->RowHeadersVisible = false;
			this->MainMatrixE->RowHeadersWidth = 62;
			this->MainMatrixE->RowTemplate->Height = 28;
			this->MainMatrixE->Size = System::Drawing::Size(388, 326);
			this->MainMatrixE->TabIndex = 132;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->вихідToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1707, 33);
			this->menuStrip1->TabIndex = 134;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// вихідToolStripMenuItem
			// 
			this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
			this->вихідToolStripMenuItem->Size = System::Drawing::Size(70, 29);
			this->вихідToolStripMenuItem->Text = L"Вихід";
			this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &EmborderingSolution::вихідToolStripMenuItem_Click);
			// 
			// EmborderingSolution
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1707, 1050);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->MainMatrixE);
			this->Controls->Add(this->IterButton);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->AkGrid);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->BView);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->qView);
			this->Controls->Add(this->rView);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->AkText);
			this->Controls->Add(this->AkkText);
			this->Controls->Add(this->IterText);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->VView);
			this->Controls->Add(this->UView);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->MatrixAView);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"EmborderingSolution";
			this->Text = L"EmborderingSolution";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixAView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->qView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AkGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainMatrixE))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: void Esolution(Matrix MainMatrix, int iter);
private: Matrix GetMain();
private: System::Void IterButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
