#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <locale.h>

namespace KarcherLottery {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for KarcherLottery
	/// </summary>
	public ref class KarcherLottery : public System::Windows::Forms::Form
	{
	public:
		KarcherLottery(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			CreateInputFile();
		}

		void CreateInputFile();
		std::vector<std::wstring> PrepareParticipants();
		std::vector<std::wstring> GenerateWinners(std::vector<std::wstring> participants);
		System::String^ ConvertToSystemString(std::wstring string);

	private: System::Windows::Forms::Button^ generate_button;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ first_winner;
	private: System::Windows::Forms::Label^ second_winner;
	private: System::Windows::Forms::Label^ third_winner;
	private: System::Windows::Forms::Label^ fourth_winner;
	private: System::Windows::Forms::Label^ fifth_winner;



	public:

		int winner_number = 0;
		bool first_generating = true;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~KarcherLottery()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(KarcherLottery::typeid));
			this->generate_button = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->first_winner = (gcnew System::Windows::Forms::Label());
			this->second_winner = (gcnew System::Windows::Forms::Label());
			this->third_winner = (gcnew System::Windows::Forms::Label());
			this->fourth_winner = (gcnew System::Windows::Forms::Label());
			this->fifth_winner = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// generate_button
			// 
			this->generate_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->generate_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"generate_button.Image")));
			this->generate_button->Location = System::Drawing::Point(619, 429);
			this->generate_button->Name = L"generate_button";
			this->generate_button->Size = System::Drawing::Size(200, 53);
			this->generate_button->TabIndex = 0;
			this->generate_button->UseVisualStyleBackColor = true;
			this->generate_button->Click += gcnew System::EventHandler(this, &KarcherLottery::generate_button_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(844, 504);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// first_winner
			// 
			this->first_winner->AutoSize = true;
			this->first_winner->BackColor = System::Drawing::SystemColors::Window;
			this->first_winner->Font = (gcnew System::Drawing::Font(L"Clan Pro", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->first_winner->Location = System::Drawing::Point(46, 175);
			this->first_winner->Name = L"first_winner";
			this->first_winner->Size = System::Drawing::Size(276, 61);
			this->first_winner->TabIndex = 2;
			this->first_winner->Text = L"1. vyherce";
			this->first_winner->Visible = false;
			// 
			// second_winner
			// 
			this->second_winner->AutoSize = true;
			this->second_winner->BackColor = System::Drawing::SystemColors::Window;
			this->second_winner->Font = (gcnew System::Drawing::Font(L"Clan Pro", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->second_winner->Location = System::Drawing::Point(46, 235);
			this->second_winner->Name = L"second_winner";
			this->second_winner->Size = System::Drawing::Size(276, 61);
			this->second_winner->TabIndex = 3;
			this->second_winner->Text = L"2. vyherce";
			this->second_winner->Visible = false;
			// 
			// third_winner
			// 
			this->third_winner->AutoSize = true;
			this->third_winner->BackColor = System::Drawing::SystemColors::Window;
			this->third_winner->Font = (gcnew System::Drawing::Font(L"Clan Pro", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->third_winner->Location = System::Drawing::Point(46, 295);
			this->third_winner->Name = L"third_winner";
			this->third_winner->Size = System::Drawing::Size(276, 61);
			this->third_winner->TabIndex = 4;
			this->third_winner->Text = L"3. vyherce";
			this->third_winner->Visible = false;
			// 
			// fourth_winner
			// 
			this->fourth_winner->AutoSize = true;
			this->fourth_winner->BackColor = System::Drawing::SystemColors::Window;
			this->fourth_winner->Font = (gcnew System::Drawing::Font(L"Clan Pro", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fourth_winner->Location = System::Drawing::Point(46, 355);
			this->fourth_winner->Name = L"fourth_winner";
			this->fourth_winner->Size = System::Drawing::Size(276, 61);
			this->fourth_winner->TabIndex = 5;
			this->fourth_winner->Text = L"4. vyherce";
			this->fourth_winner->Visible = false;
			// 
			// fifth_winner
			// 
			this->fifth_winner->AutoSize = true;
			this->fifth_winner->BackColor = System::Drawing::SystemColors::Window;
			this->fifth_winner->Font = (gcnew System::Drawing::Font(L"Clan Pro", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fifth_winner->Location = System::Drawing::Point(46, 415);
			this->fifth_winner->Name = L"fifth_winner";
			this->fifth_winner->Size = System::Drawing::Size(276, 61);
			this->fifth_winner->TabIndex = 6;
			this->fifth_winner->Text = L"5. vyherce";
			this->fifth_winner->Visible = false;
			// 
			// KarcherLottery
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(842, 501);
			this->Controls->Add(this->fifth_winner);
			this->Controls->Add(this->fourth_winner);
			this->Controls->Add(this->third_winner);
			this->Controls->Add(this->second_winner);
			this->Controls->Add(this->first_winner);
			this->Controls->Add(this->generate_button);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"KarcherLottery";
			this->Text = L"KarcherLottery";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void generate_button_Click(System::Object^ sender, System::EventArgs^ e)
	{

		if (first_generating == true)
		{
			std::vector<std::wstring> participants;
			participants = PrepareParticipants();
			std::vector<std::wstring> winners = GenerateWinners(participants);

			first_winner->Text = ConvertToSystemString(L"1.   " + winners.at(0));
			first_winner->Visible = true;

			second_winner->Text = ConvertToSystemString(L"2.   " + winners.at(1));
			third_winner->Text = ConvertToSystemString(L"3.   " + winners.at(2));
			fourth_winner->Text = ConvertToSystemString(L"4.   " + winners.at(3));
			fifth_winner->Text = ConvertToSystemString(L"5.   " + winners.at(4));

			first_generating = false;
		}

		switch (winner_number)
		{
		case 1:
			second_winner->Visible = true;
			break;
		case 2:
			third_winner->Visible = true;
			break;
		case 3:
			fourth_winner->Visible = true;
			break;
		case 4:
			fifth_winner->Visible = true;
			break;
		default:
			break;
		}

		winner_number++;
	}
};
}
