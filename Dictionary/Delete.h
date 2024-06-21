#pragma once
#include "class.h" 
namespace DSProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Delete
	/// </summary>
	public ref class Delete : public System::Windows::Forms::Form
	{
	public:
		Trie* obj = Trie::getInstance();
		Delete(void)
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
		~Delete()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ DICTIONARY;
	private: System::Windows::Forms::TextBox^ input;





	private: System::Windows::Forms::Button^ delete_;
	private: System::Windows::Forms::Label^ word;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Delete::typeid));
			this->DICTIONARY = (gcnew System::Windows::Forms::Label());
			this->input = (gcnew System::Windows::Forms::TextBox());
			this->delete_ = (gcnew System::Windows::Forms::Button());
			this->word = (gcnew System::Windows::Forms::Label());
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
			this->DICTIONARY->Location = System::Drawing::Point(369, 46);
			this->DICTIONARY->Name = L"DICTIONARY";
			this->DICTIONARY->Size = System::Drawing::Size(279, 55);
			this->DICTIONARY->TabIndex = 4;
			this->DICTIONARY->Text = L"ZAT DICTIONARY";
			// 
			// input
			// 
			this->input->BackColor = System::Drawing::SystemColors::Info;
			this->input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input->Location = System::Drawing::Point(316, 182);
			this->input->Multiline = true;
			this->input->Name = L"input";
			this->input->Size = System::Drawing::Size(394, 83);
			this->input->TabIndex = 5;
			// 
			// delete_
			// 
			this->delete_->Cursor = System::Windows::Forms::Cursors::Hand;
			this->delete_->Location = System::Drawing::Point(421, 271);
			this->delete_->Name = L"delete_";
			this->delete_->Size = System::Drawing::Size(160, 61);
			this->delete_->TabIndex = 9;
			this->delete_->Text = L"DELETE";
			this->delete_->UseVisualStyleBackColor = true;
			this->delete_->Click += gcnew System::EventHandler(this, &Delete::button1_Click);
			// 
			// word
			// 
			this->word->AutoSize = true;
			this->word->BackColor = System::Drawing::SystemColors::Info;
			this->word->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->word->Location = System::Drawing::Point(328, 143);
			this->word->Name = L"word";
			this->word->Size = System::Drawing::Size(177, 36);
			this->word->TabIndex = 10;
			this->word->Text = L"Enter Word";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 523);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 61);
			this->button2->TabIndex = 18;
			this->button2->Text = L"EXIT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Delete::button2_Click);
			// 
			// Delete
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(969, 606);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->word);
			this->Controls->Add(this->delete_);
			this->Controls->Add(this->input);
			this->Controls->Add(this->DICTIONARY);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Delete";
			this->Text = L"Delete";
			this->Load += gcnew System::EventHandler(this, &Delete::Delete_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ word = input->Text;


		string St_word = msclr::interop::marshal_as<string>(word);
		if (MessageBox::Show("Do you want to delete"+word+"from dictionary","Delete Menu",MessageBoxButtons::YesNo,MessageBoxIcon::Warning)==System::Windows::Forms::DialogResult::Yes)
		{
			bool deleteWord = obj->deleteWord(St_word);
			if (deleteWord)
			{
				MessageBox::Show("Deletion Successful", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
				obj->saveToFile("Dictionary.txt");
			}
			else
			{
				MessageBox::Show("Word not found.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

			}
		}
		else
		{
			MessageBox::Show("Deletion Cancelled", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
private: System::Void Delete_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void output_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
