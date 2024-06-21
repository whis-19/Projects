#pragma once
#include"class.h"
namespace DSProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for update
	/// </summary>
	public ref class update : public System::Windows::Forms::Form
	{
	public:
		Trie* obj = Trie::getInstance();
		update(void)
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
		~update()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ DICTIONARY;
	private: System::Windows::Forms::Label^ word;
	private: System::Windows::Forms::TextBox^ input;
	private: System::Windows::Forms::TextBox^ output;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ delete_;
	private: System::Windows::Forms::Button^ button2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(update::typeid));
			this->DICTIONARY = (gcnew System::Windows::Forms::Label());
			this->word = (gcnew System::Windows::Forms::Label());
			this->input = (gcnew System::Windows::Forms::TextBox());
			this->output = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->delete_ = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// DICTIONARY
			// 
			this->DICTIONARY->AutoSize = true;
			this->DICTIONARY->BackColor = System::Drawing::SystemColors::HighlightText;
			this->DICTIONARY->Font = (gcnew System::Drawing::Font(L"Gloucester MT Extra Condensed", 28.2F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DICTIONARY->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->DICTIONARY->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DICTIONARY.Image")));
			this->DICTIONARY->Location = System::Drawing::Point(343, 45);
			this->DICTIONARY->Name = L"DICTIONARY";
			this->DICTIONARY->Size = System::Drawing::Size(279, 55);
			this->DICTIONARY->TabIndex = 5;
			this->DICTIONARY->Text = L"ZAT DICTIONARY";
			// 
			// word
			// 
			this->word->AutoSize = true;
			this->word->BackColor = System::Drawing::SystemColors::Info;
			this->word->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->word->Location = System::Drawing::Point(303, 126);
			this->word->Name = L"word";
			this->word->Size = System::Drawing::Size(177, 36);
			this->word->TabIndex = 11;
			this->word->Text = L"Enter Word";
			// 
			// input
			// 
			this->input->BackColor = System::Drawing::SystemColors::Info;
			this->input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input->Location = System::Drawing::Point(293, 165);
			this->input->Multiline = true;
			this->input->Name = L"input";
			this->input->Size = System::Drawing::Size(394, 83);
			this->input->TabIndex = 12;
			// 
			// output
			// 
			this->output->BackColor = System::Drawing::SystemColors::Info;
			this->output->Cursor = System::Windows::Forms::Cursors::Hand;
			this->output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output->Location = System::Drawing::Point(293, 326);
			this->output->Multiline = true;
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(394, 95);
			this->output->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Info;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(303, 287);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(303, 36);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Enter  New Meaning";
			this->label1->Click += gcnew System::EventHandler(this, &update::label1_Click);
			// 
			// delete_
			// 
			this->delete_->Cursor = System::Windows::Forms::Cursors::Hand;
			this->delete_->Location = System::Drawing::Point(410, 427);
			this->delete_->Name = L"delete_";
			this->delete_->Size = System::Drawing::Size(160, 61);
			this->delete_->TabIndex = 15;
			this->delete_->Text = L"UPDATE";
			this->delete_->UseVisualStyleBackColor = true;
			this->delete_->Click += gcnew System::EventHandler(this, &update::delete__Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 517);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 61);
			this->button2->TabIndex = 19;
			this->button2->Text = L"EXIT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &update::button2_Click);
			// 
			// update
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(966, 606);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->delete_);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->output);
			this->Controls->Add(this->input);
			this->Controls->Add(this->word);
			this->Controls->Add(this->DICTIONARY);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"update";
			this->Text = L"update";
			this->Load += gcnew System::EventHandler(this, &update::update_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void update_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void delete__Click(System::Object^ sender, System::EventArgs^ e) {
	String^ Word = input->Text;
	String^ meaning = output->Text;

	string St_Word = msclr::interop::marshal_as<string>(Word);
	string St_meaning = msclr::interop::marshal_as<string>(meaning);

	if (MessageBox::Show("Do you want to update '" + Word + "' to '" + meaning + "' in the dictionary?", "Update Menu", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
	{
		bool updateWord = obj->updateWord(St_Word, St_meaning);

		if (updateWord)
		{
			MessageBox::Show("Word Updated Successfully", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
			output->Text = "Word Updated Successfully";
			obj->saveToFile("Dictionary.txt");
		}
		else
		{
			output->Text = "Word not found for update.";
		}
	}
	else
	{
		MessageBox::Show("Update Cancelled", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
};
}
