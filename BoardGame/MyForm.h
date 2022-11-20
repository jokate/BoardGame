#pragma once
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "System.h"
#include "Card.h"
#include "Cell.h"
#include "Map.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "Board.h"
typedef System::Drawing::Rectangle R;
namespace BoardGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm�� ���� ����Դϴ�.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	protected:

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(191, 280);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(203, 317);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 30));
			this->label1->Location = System::Drawing::Point(145, 167);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 40);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Welcome!";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"����", 18));
			this->label2->Location = System::Drawing::Point(115, 228);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(258, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"�����ڸ� �Է����ּ���";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(484, 461);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text->Length == 0) {
			this->label2->Text = "�ٽ� �Է����ּ���!";
		}
		else {
			String^ str = textBox1->Text;
			std::string unmanaged = msclr::interop::marshal_as<std::string>(str);
			if (BoardSystem::Check(unmanaged) == 0) {
				this->label2->Text = "������ �Ұ��� �մϴ�!";
			}
			else {
				this->label2->Text = "������ ����մϴ�!";
				BS.Initialize("Resource/default.map",BoardSystem::Check(unmanaged));
				BS.ReadMaps("Resource/*.map");
				this->Hide();
				Board^ GC = gcnew Board();
				Graphics^ g = GC->CreateGraphics();
				GC->ShowDialog();
			}
		}
	}
	};
}