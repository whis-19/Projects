#pragma once
#include "findword.h"
#include "Delete.h"
#include "update.h"
#include "Add_word.h"
#include"TEAM_.h"
namespace DSProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HOME
	/// </summary>
	public ref class HOME : public System::Windows::Forms::Form
	{
	public:
		HOME(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HOME()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ delete_;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ search;
	private: System::Windows::Forms::Button^ addWord;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ DICTIONARY;
	private: System::Windows::Forms::Button^ button3;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HOME::typeid));
			this->delete_ = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->search = (gcnew System::Windows::Forms::Button());
			this->addWord = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->DICTIONARY = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// delete_
			// 
			this->delete_->Location = System::Drawing::Point(294, 280);
			this->delete_->Name = L"delete_";
			this->delete_->Size = System::Drawing::Size(160, 61);
			this->delete_->TabIndex = 13;
			this->delete_->Text = L"UPDATE";
			this->delete_->UseVisualStyleBackColor = true;
			this->delete_->Click += gcnew System::EventHandler(this, &HOME::delete__Click);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(502, 177);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 61);
			this->button1->TabIndex = 14;
			this->button1->Text = L"DELETE";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &HOME::button1_Click);
			// 
			// search
			// 
			this->search->Location = System::Drawing::Point(294, 177);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(160, 61);
			this->search->TabIndex = 15;
			this->search->Text = L"SEARCH";
			this->search->UseVisualStyleBackColor = true;
			this->search->Click += gcnew System::EventHandler(this, &HOME::search_Click);
			// 
			// addWord
			// 
			this->addWord->Location = System::Drawing::Point(502, 280);
			this->addWord->Name = L"addWord";
			this->addWord->Size = System::Drawing::Size(160, 61);
			this->addWord->TabIndex = 16;
			this->addWord->Text = L"ADD WORD";
			this->addWord->UseVisualStyleBackColor = true;
			this->addWord->Click += gcnew System::EventHandler(this, &HOME::addWord_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(294, 377);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 61);
			this->button2->TabIndex = 17;
			this->button2->Text = L"EXIT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &HOME::button2_Click);
			// 
			// DICTIONARY
			// 
			this->DICTIONARY->AutoSize = true;
			this->DICTIONARY->BackColor = System::Drawing::SystemColors::HighlightText;
			this->DICTIONARY->Font = (gcnew System::Drawing::Font(L"Gloucester MT Extra Condensed", 28.2F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DICTIONARY->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->DICTIONARY->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DICTIONARY.Image")));
			this->DICTIONARY->Location = System::Drawing::Point(347, 29);
			this->DICTIONARY->Name = L"DICTIONARY";
			this->DICTIONARY->Size = System::Drawing::Size(279, 55);
			this->DICTIONARY->TabIndex = 18;
			this->DICTIONARY->Text = L"ZAT DICTIONARY";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(502, 377);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(160, 61);
			this->button3->TabIndex = 19;
			this->button3->Text = L"TEAM";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &HOME::button3_Click);
			// 
			// HOME
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(969, 606);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->DICTIONARY);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->addWord);
			this->Controls->Add(this->search);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->delete_);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"HOME";
			this->Text = L"HOME";
			this->Load += gcnew System::EventHandler(this, &HOME::HOME_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void HOME_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Delete obj;
	obj.ShowDialog();
}
private: System::Void search_Click(System::Object^ sender, System::EventArgs^ e) {
	findword obj;
	obj.ShowDialog();

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}

private: System::Void addWord_Click(System::Object^ sender, System::EventArgs^ e) {
	Add_word obj;
	obj.ShowDialog();

}
private: System::Void delete__Click(System::Object^ sender, System::EventArgs^ e) {
	update obj;
	obj.ShowDialog();

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	TEAM_ obj;
	obj.ShowDialog();
}
};
}
