#pragma once
#include "System.h"
#include "Map.h"
#include "Cell.h"
#include "Player.h"
#include <msclr\marshal_cppstd.h>

typedef System::Drawing::Rectangle R;
namespace BoardGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm1에 대한 요약입니다.
	/// </summary>
	public ref class Board : public System::Windows::Forms::Form
	{
	public:
		Board(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Board()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ button1;
	private: Graphics^ g;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ Guide1;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ Guide2;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ PlayerPanel1;
	private: System::Windows::Forms::Panel^ PlayerPanel4;




	private: System::Windows::Forms::Panel^ PlayerPanel3;

	private: System::Windows::Forms::Panel^ PlayerPanel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ Player1;

	private: System::Windows::Forms::Label^ Player3;
	private: System::Windows::Forms::Label^ Player2;
	private: System::Windows::Forms::Label^ Information1;
	private: System::Windows::Forms::Label^ Information4;
	private: System::Windows::Forms::Label^ Player4;
	private: System::Windows::Forms::Label^ Information3;
	private: System::Windows::Forms::Label^ Information2;
	private: System::Windows::Forms::Panel^ AllPlayers;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button4;





	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Guide2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Guide1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->PlayerPanel1 = (gcnew System::Windows::Forms::Panel());
			this->Information1 = (gcnew System::Windows::Forms::Label());
			this->Player1 = (gcnew System::Windows::Forms::Label());
			this->PlayerPanel4 = (gcnew System::Windows::Forms::Panel());
			this->Information4 = (gcnew System::Windows::Forms::Label());
			this->Player4 = (gcnew System::Windows::Forms::Label());
			this->PlayerPanel3 = (gcnew System::Windows::Forms::Panel());
			this->Information3 = (gcnew System::Windows::Forms::Label());
			this->Player3 = (gcnew System::Windows::Forms::Label());
			this->PlayerPanel2 = (gcnew System::Windows::Forms::Panel());
			this->Information2 = (gcnew System::Windows::Forms::Label());
			this->Player2 = (gcnew System::Windows::Forms::Label());
			this->AllPlayers = (gcnew System::Windows::Forms::Panel());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->PlayerPanel1->SuspendLayout();
			this->PlayerPanel4->SuspendLayout();
			this->PlayerPanel3->SuspendLayout();
			this->PlayerPanel2->SuspendLayout();
			this->AllPlayers->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"종료";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Board::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->label2);
			this->panel1->ForeColor = System::Drawing::Color::Cornsilk;
			this->panel1->Location = System::Drawing::Point(173, 36);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(831, 500);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Board::panel1_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(269, 446);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 12);
			this->label2->TabIndex = 0;
			this->label2->Text = L"label2";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(852, 555);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(244, 62);
			this->button2->TabIndex = 2;
			this->button2->Text = L"RollDice!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Board::button2_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->Guide2);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->Guide1);
			this->panel2->Location = System::Drawing::Point(173, 555);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(640, 115);
			this->panel2->TabIndex = 3;
			// 
			// Guide2
			// 
			this->Guide2->AutoSize = true;
			this->Guide2->Location = System::Drawing::Point(17, 41);
			this->Guide2->Name = L"Guide2";
			this->Guide2->Size = System::Drawing::Size(38, 12);
			this->Guide2->TabIndex = 2;
			this->Guide2->Text = L"label2";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(19, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(209, 21);
			this->textBox1->TabIndex = 1;
			// 
			// Guide1
			// 
			this->Guide1->AutoSize = true;
			this->Guide1->Location = System::Drawing::Point(17, 13);
			this->Guide1->Name = L"Guide1";
			this->Guide1->Size = System::Drawing::Size(38, 12);
			this->Guide1->TabIndex = 0;
			this->Guide1->Text = L"label1";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Cambria", 20));
			this->button3->Location = System::Drawing::Point(852, 647);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(244, 62);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Skip!";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Board::button3_Click);
			// 
			// PlayerPanel1
			// 
			this->PlayerPanel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PlayerPanel1->Controls->Add(this->Information1);
			this->PlayerPanel1->Controls->Add(this->Player1);
			this->PlayerPanel1->Location = System::Drawing::Point(1, 14);
			this->PlayerPanel1->Name = L"PlayerPanel1";
			this->PlayerPanel1->Size = System::Drawing::Size(200, 260);
			this->PlayerPanel1->TabIndex = 5;
			// 
			// Information1
			// 
			this->Information1->AutoSize = true;
			this->Information1->Font = (gcnew System::Drawing::Font(L"Cambria", 15));
			this->Information1->Location = System::Drawing::Point(5, 83);
			this->Information1->Name = L"Information1";
			this->Information1->Size = System::Drawing::Size(71, 23);
			this->Information1->TabIndex = 1;
			this->Information1->Text = L"Score : ";
			// 
			// Player1
			// 
			this->Player1->AutoSize = true;
			this->Player1->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Player1->Location = System::Drawing::Point(3, 11);
			this->Player1->Name = L"Player1";
			this->Player1->Size = System::Drawing::Size(101, 32);
			this->Player1->TabIndex = 0;
			this->Player1->Text = L"Player1";
			// 
			// PlayerPanel4
			// 
			this->PlayerPanel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PlayerPanel4->Controls->Add(this->Information4);
			this->PlayerPanel4->Controls->Add(this->Player4);
			this->PlayerPanel4->Location = System::Drawing::Point(618, 14);
			this->PlayerPanel4->Name = L"PlayerPanel4";
			this->PlayerPanel4->Size = System::Drawing::Size(200, 260);
			this->PlayerPanel4->TabIndex = 6;
			// 
			// Information4
			// 
			this->Information4->AutoSize = true;
			this->Information4->Font = (gcnew System::Drawing::Font(L"Cambria", 15));
			this->Information4->Location = System::Drawing::Point(3, 83);
			this->Information4->Name = L"Information4";
			this->Information4->Size = System::Drawing::Size(71, 23);
			this->Information4->TabIndex = 4;
			this->Information4->Text = L"Score : ";
			// 
			// Player4
			// 
			this->Player4->AutoSize = true;
			this->Player4->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Player4->Location = System::Drawing::Point(3, 11);
			this->Player4->Name = L"Player4";
			this->Player4->Size = System::Drawing::Size(101, 32);
			this->Player4->TabIndex = 3;
			this->Player4->Text = L"Player4";
			// 
			// PlayerPanel3
			// 
			this->PlayerPanel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PlayerPanel3->Controls->Add(this->Information3);
			this->PlayerPanel3->Controls->Add(this->Player3);
			this->PlayerPanel3->Location = System::Drawing::Point(412, 14);
			this->PlayerPanel3->Name = L"PlayerPanel3";
			this->PlayerPanel3->Size = System::Drawing::Size(200, 260);
			this->PlayerPanel3->TabIndex = 7;
			// 
			// Information3
			// 
			this->Information3->AutoSize = true;
			this->Information3->Font = (gcnew System::Drawing::Font(L"Cambria", 15));
			this->Information3->Location = System::Drawing::Point(3, 83);
			this->Information3->Name = L"Information3";
			this->Information3->Size = System::Drawing::Size(71, 23);
			this->Information3->TabIndex = 3;
			this->Information3->Text = L"Score : ";
			// 
			// Player3
			// 
			this->Player3->AutoSize = true;
			this->Player3->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Player3->Location = System::Drawing::Point(3, 11);
			this->Player3->Name = L"Player3";
			this->Player3->Size = System::Drawing::Size(101, 32);
			this->Player3->TabIndex = 2;
			this->Player3->Text = L"Player3";
			// 
			// PlayerPanel2
			// 
			this->PlayerPanel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PlayerPanel2->Controls->Add(this->Information2);
			this->PlayerPanel2->Controls->Add(this->Player2);
			this->PlayerPanel2->Location = System::Drawing::Point(206, 14);
			this->PlayerPanel2->Name = L"PlayerPanel2";
			this->PlayerPanel2->Size = System::Drawing::Size(200, 260);
			this->PlayerPanel2->TabIndex = 7;
			// 
			// Information2
			// 
			this->Information2->AutoSize = true;
			this->Information2->Font = (gcnew System::Drawing::Font(L"Cambria", 15));
			this->Information2->Location = System::Drawing::Point(3, 83);
			this->Information2->Name = L"Information2";
			this->Information2->Size = System::Drawing::Size(71, 23);
			this->Information2->TabIndex = 2;
			this->Information2->Text = L"Score : ";
			// 
			// Player2
			// 
			this->Player2->AutoSize = true;
			this->Player2->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Player2->Location = System::Drawing::Point(3, 11);
			this->Player2->Name = L"Player2";
			this->Player2->Size = System::Drawing::Size(101, 32);
			this->Player2->TabIndex = 1;
			this->Player2->Text = L"Player2";
			// 
			// AllPlayers
			// 
			this->AllPlayers->Controls->Add(this->PlayerPanel4);
			this->AllPlayers->Controls->Add(this->PlayerPanel3);
			this->AllPlayers->Controls->Add(this->PlayerPanel2);
			this->AllPlayers->Controls->Add(this->PlayerPanel1);
			this->AllPlayers->Location = System::Drawing::Point(3, 676);
			this->AllPlayers->Name = L"AllPlayers";
			this->AllPlayers->Size = System::Drawing::Size(827, 283);
			this->AllPlayers->TabIndex = 8;
			this->AllPlayers->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Board::AllPlayers_Paint);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Location = System::Drawing::Point(14, 87);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 88);
			this->listBox1->TabIndex = 9;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Board::listBox1_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(34, 191);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"ReStart";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Board::button4_Click);
			// 
			// Board
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1184, 961);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->AllPlayers);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Name = L"Board";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &Board::MyForm1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Board::Board_Paint);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->PlayerPanel1->ResumeLayout(false);
			this->PlayerPanel1->PerformLayout();
			this->PlayerPanel4->ResumeLayout(false);
			this->PlayerPanel4->PerformLayout();
			this->PlayerPanel3->ResumeLayout(false);
			this->PlayerPanel3->PerformLayout();
			this->PlayerPanel2->ResumeLayout(false);
			this->PlayerPanel2->PerformLayout();
			this->AllPlayers->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Visible = false;
		this->Guide1->Text = "Player " + BS.turn + "의 차례입니다.";
		this->Guide2->Visible = false; 
		this->PlayerPanel1->Visible = false;
		this->PlayerPanel2->Visible = false; 
		this->PlayerPanel3->Visible = false;
		this->PlayerPanel4->Visible = false;
		this->button3->Text = "Skip";
		this->button2->Text = "Roll Dice!";
		this->button2->Visible = true;
		this->button3->Visible = true;
		for (int i = 0; i < BS.files.size(); i++) {
			String^ str = msclr::interop::marshal_as<String^>(BS.files[i]);
			if(!this->listBox1->Items->Contains(str))
				this->listBox1->Items->Add(str);
		}


	}
	private: System::Void Board_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (BS.Operation == 0) {
			this->button3->Visible = false;
			BS.PlayerSet[BS.turn - 1].SelectState = true;
			BS.PlayerSet[BS.turn - 1].RollingDice();
			if (BS.PlayerSet[BS.turn - 1].GetMoveCount() != 0) {
				this->Guide1->Text = "Player " + BS.turn + "이(가) 움직일 수 있는 칸 수는 " + BS.PlayerSet[BS.turn - 1].GetMoveCount() + "입니다.";
				this->Guide2->Text = "움직일 경로를 아래 TextBox에 입력해주세요. (U, D, R, L or u, d, r, l)";
				this->button2->Text = "Insert Position";
				this->textBox1->Visible = true;
			}
			else {
				this->Guide1->Text = "Player " + BS.turn + "이(가) 움직일 수 없습니다!.";
				this->Guide2->Text = "";
				this->textBox1->Visible = false;
				this->button2->Text = "OK!";
			}
			this->Guide2->Visible = true;
		}
		else if (BS.Operation == 1) {
			System::String^ managed = this->textBox1->Text;
			std::string unmanaged = msclr::interop::marshal_as<std::string>(managed);
			if (BS.PlayerSet[BS.turn - 1].Move(unmanaged)) {
				BS.PlayerSet[BS.turn - 1].CountingBridgeCard();
				this->textBox1->Text = "";
				this->textBox1->Visible = false;

				if (BS.PlayerSet[BS.turn - 1].GetPlayerState() == Idle) {
					this->Guide1->Text = "Player " + BS.turn + "의 위치는 " + BS.PlayerSet[BS.turn - 1].CurrentCell.GetCellNumber() + "입니다";

					if (BS.PlayerSet[BS.turn - 1].GetMoveCount() != 0) {
						BS.PlayerSet[BS.turn - 1].GettingCard();
					}
					if (BS.PlayerSet[BS.turn - 1].str == "No") {
						this->Guide2->Text = "Player " + BS.turn + "은 점수카드를 얻지 못했습니다.";
					}
					else {
						String^ str = gcnew String(BS.PlayerSet[BS.turn - 1].str.c_str());
						this->Guide2->Text = "Player " + BS.turn + "은 점수카드 " + str + "을 얻었습니다.";
						BS.PlayerSet[BS.turn - 1].str = "No";
					}

				}
				else if(BS.PlayerSet[BS.turn - 1].GetPlayerState() == OnBridge){
					this->Guide1->Text = "Player " + BS.turn + "의 위치는 " + "다리 위 입니다";
					this->Guide2->Text = "";
				}
				else if(BS.PlayerSet[BS.turn - 1].GetPlayerState() == Ended) {
					this->Guide1->Text = "Player " + BS.turn + "이(가) 끝났습니다!";
					this->Guide2->Text = "Player" + BS.turn + " 은(는) " + BS.EndScore() + "점을 얻었습니다." ;
				}
				this->button2->Text = "OK!";
				g->Clear(Color::WhiteSmoke);
				panel1_Paint(sender, gcnew PaintEventArgs(g, panel1->DisplayRectangle));
				Graphics^ gr = this->AllPlayers->CreateGraphics();
				AllPlayers_Paint(sender, gcnew PaintEventArgs(gr, AllPlayers->DisplayRectangle));
			}
			else {
				this->Guide2->Text = "잘못 입력하셨습니다. 다시 입력해주세요 (U, D, R, L or u, d, r, l)";
				this->textBox1->Text = "";
			}
		}
		else {
			if (BS.GameEnd()) {
				this->Guide1->Text = "승자는 Player " + BS.WinnerPlayer() + "이고, 점수는 " + BS.PlayerSet[BS.WinnerPlayer() - 1 ].GetScore() + "입니다.";
				this->Guide2->Text = "종료 버튼을 눌러 게임을 종료하십시오!";
			}
			else {
				BS.ChangeTurn();
				this->Guide2->Visible = false;
				this->Guide1->Text = "Player " + BS.turn + "의 차례입니다.";
				this->button2->Text = "Roll Dice!";
				this->button3->Visible = true;
			}
		}
	}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	R rect = R(200, 100, 50, 50);
	System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 14);
	int IncreaseCount = 0;
	g = this->panel1->CreateGraphics();
	g->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
	//Drawing Map
	for (int i = 0; i < BS.map.GetCellCount(); i++) {
		if (i == 0) {
			g->FillRectangle(Brushes::LightYellow, rect);
			g->DrawString("Start", f, Brushes::Black, rect);
			g->DrawRectangle(Pens::Black, rect);
			IncreaseCount = 50;
		}
		else {
			if (i == BS.map.GetCellCount() - 1) {
				rect.Height = 50;
				rect.Width = 50;
				IncreaseCount = 50;
			}
			else {
				rect.Height = 25;
				rect.Width = 25;
			}
			if (BS.map.CellSet[i - 1].GetNextDirection() == Direction::Right) {
				rect.X = rect.X + IncreaseCount;
			}
			else if (BS.map.CellSet[i - 1].GetNextDirection() == Up) {
				rect.Y = rect.Y - IncreaseCount;
			}
			else if (BS.map.CellSet[i - 1].GetNextDirection() == Down) {
				rect.Y = rect.Y + IncreaseCount;
			}
			g->FillRectangle(Brushes::LightYellow, rect);
			if (i == BS.map.GetCellCount() - 1) {
				g->DrawString("End", f, Brushes::Black, rect);
			}
			if (BS.map.CellSet[i].GetState() == Bridge) {
				g->DrawImage(Image::FromFile("Cross.PNG", true), rect);
			}
			else if (BS.map.CellSet[i].GetState() == CardS) {
				if (BS.map.CellSet[i].returnCard().GetCardState() == Hammer) {
					g->DrawImage(Image::FromFile("Hammer.PNG", true), rect);
				}
				else if (BS.map.CellSet[i].returnCard().GetCardState() == Saw) {
					g->DrawImage(Image::FromFile("Saw.PNG", true), rect);
				}
				else if (BS.map.CellSet[i].returnCard().GetCardState() == PhilipsDriver) {
					g->DrawImage(Image::FromFile("PhilipsDriver.PNG", true), rect);
				}
			}
			g->DrawRectangle(Pens::Black, rect);
			if (BS.map.CellSet[i].GetState() == Bridge) {
				R BridgeRect = R(rect.X + IncreaseCount, rect.Y, rect.Width, rect.Height);
				g->DrawImage(Image::FromFile("Bridge.PNG", true), BridgeRect);
			}
			IncreaseCount = 25;

		}
	}
	for (int i = 0; i < BS.playerNumber; i++) {
		R PlyerRect = R(200 + (5 * i), 112, 10, 10);
		int IncreaseCount = 0;
		//위치의 기준은
		int CellCount = BS.PlayerSet[i].CurrentCell.GetCellNumber();
		for (int j = 0; j < CellCount; j++) {
			if (j == 0) {
				IncreaseCount = 50;

			}
			else {

				IncreaseCount = 25;
			}
			if (BS.map.CellSet[j].GetNextDirection() == Direction::Right) {
				PlyerRect.X = PlyerRect.X + IncreaseCount;
			}
			else if (BS.map.CellSet[j].GetNextDirection() == Up) {
				PlyerRect.Y = PlyerRect.Y - IncreaseCount;
			}
			else if (BS.map.CellSet[j].GetNextDirection() == Down) {
				PlyerRect.Y = PlyerRect.Y + IncreaseCount;
			}
		}
		if (BS.PlayerSet[i].GetPlayerState() == OnBridge) {
			if (BS.PlayerSet[i].CurrentCell.GetState() == Bridge) {
				PlyerRect.X = PlyerRect.X + IncreaseCount;
			}
			else if (BS.PlayerSet[i].CurrentCell.GetState() == AfterBridge) {
				PlyerRect.X = PlyerRect.X - IncreaseCount;
			}
		}
		if (i == 0) {
			g->FillEllipse(Brushes::Red, PlyerRect);
			g->DrawEllipse(Pens::Black, PlyerRect);
		}
		else if (i == 1) {
			g->FillEllipse(Brushes::Blue, PlyerRect);
			g->DrawEllipse(Pens::Black, PlyerRect);
		}
		else if (i == 2) {
			g->FillEllipse(Brushes::Yellow, PlyerRect);
			g->DrawEllipse(Pens::Black, PlyerRect);
		}
		else {
			g->FillEllipse(Brushes::Green, PlyerRect);
			g->DrawEllipse(Pens::Black, PlyerRect);
		}
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (BS.Operation == 0) {
		BS.PlayerSet[BS.turn - 1].Rest();
		BS.PlayerSet[BS.turn - 1].CountingBridgeCard();
		this->Guide1->Text = "Player " + BS.turn + "가 턴을 넘겼습니다.";
		this->button2->Visible = false;
		this->button3->Text = "OK!";
		Graphics^ gr = this->AllPlayers->CreateGraphics();
		AllPlayers_Paint(sender, gcnew PaintEventArgs(gr, AllPlayers->DisplayRectangle));
	}
	else if (BS.Operation == 1) {
		BS.ChangeTurn();
		BS.Operation = 0;
		this->button2->Visible = true;
		this->button3->Text = "Skip";
		this->Guide1->Text = "Player " + BS.turn + "의 차례입니다.";
	}
}
private: System::Void AllPlayers_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ Panel;
	for (int i = 0; i < BS.playerNumber; i++) {
		if (i == 0) {
			PlayerPanel1->Visible = true;
			Panel = PlayerPanel1->CreateGraphics();
			Panel->FillRectangle(Brushes::Red, 170, 20, 10, 10);
			Information1->Text = "Score :" + BS.PlayerSet[i].GetScore() + "\n" + "BridgeCard :" + BS.PlayerSet[i].GetBridgeCount();
		}
		else if (i == 1) {
			PlayerPanel2->Visible = true;
			Panel = PlayerPanel2->CreateGraphics();
			Panel->FillRectangle(Brushes::Blue, 170, 20, 10, 10);
			Information2->Text = "Score :" + BS.PlayerSet[i].GetScore() + "\n" + "BridgeCard :" + BS.PlayerSet[i].GetBridgeCount();
		}
		else if (i == 2) {
			PlayerPanel3->Visible = true;
			Panel = PlayerPanel3->CreateGraphics();
			Panel->FillRectangle(Brushes::Yellow, 170, 20, 10, 10);
			Information3->Text = "Score :" + BS.PlayerSet[i].GetScore() + "\n" + "BridgeCard :" + BS.PlayerSet[i].GetBridgeCount();
		}
		else {
			PlayerPanel4->Visible = true;
			Panel = PlayerPanel4->CreateGraphics();
			Panel->FillRectangle(Brushes::Green, 170, 20, 10, 10);
			Information4->Text = "Score :" + BS.PlayerSet[i].GetScore() + "\n" + "BridgeCard :" + BS.PlayerSet[i].GetBridgeCount();
		}
	}
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	BS.ReInitialize("Resource/" + msclr::interop::marshal_as<string>(this->listBox1->SelectedItem->ToString()));
	MyForm1_Load(sender, e);
	g->Clear(Color::WhiteSmoke);
	panel1_Paint(sender, gcnew PaintEventArgs(g, panel1->DisplayRectangle));
	Graphics^ gr = this->AllPlayers->CreateGraphics();
	AllPlayers_Paint(sender, gcnew PaintEventArgs(gr, AllPlayers->DisplayRectangle));
}
};
}
