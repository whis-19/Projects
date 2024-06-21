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
	/// Summary for findword
	/// </summary>
	public ref class findword : public System::Windows::Forms::Form
	{
	public:
		Trie* obj = Trie::getInstance();

		findword(void)
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
		~findword()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ search;
	protected:




	private: System::Windows::Forms::Label^ DICTIONARY;
	private: System::Windows::Forms::TextBox^ input;
	private: System::Windows::Forms::TextBox^ output;



	private: System::Windows::Forms::Label^ word;
	private: System::Windows::Forms::Button^ suggest;
	private: System::Windows::Forms::Button^ button2;





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(findword::typeid));
			this->search = (gcnew System::Windows::Forms::Button());
			this->DICTIONARY = (gcnew System::Windows::Forms::Label());
			this->input = (gcnew System::Windows::Forms::TextBox());
			this->output = (gcnew System::Windows::Forms::TextBox());
			this->word = (gcnew System::Windows::Forms::Label());
			this->suggest = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// search
			// 
			this->search->Location = System::Drawing::Point(530, 381);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(160, 61);
			this->search->TabIndex = 2;
			this->search->Text = L"SEARCH";
			this->search->UseVisualStyleBackColor = true;
			this->search->Click += gcnew System::EventHandler(this, &findword::button1_Click);
			// 
			// DICTIONARY
			// 
			this->DICTIONARY->AutoSize = true;
			this->DICTIONARY->BackColor = System::Drawing::SystemColors::HighlightText;
			this->DICTIONARY->Font = (gcnew System::Drawing::Font(L"Gloucester MT Extra Condensed", 28.2F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DICTIONARY->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->DICTIONARY->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DICTIONARY.Image")));
			this->DICTIONARY->Location = System::Drawing::Point(356, 26);
			this->DICTIONARY->Name = L"DICTIONARY";
			this->DICTIONARY->Size = System::Drawing::Size(279, 55);
			this->DICTIONARY->TabIndex = 3;
			this->DICTIONARY->Text = L"ZAT DICTIONARY";
			this->DICTIONARY->Click += gcnew System::EventHandler(this, &findword::label2_Click);
			// 
			// input
			// 
			this->input->BackColor = System::Drawing::SystemColors::Info;
			this->input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input->Location = System::Drawing::Point(296, 136);
			this->input->Multiline = true;
			this->input->Name = L"input";
			this->input->Size = System::Drawing::Size(394, 83);
			this->input->TabIndex = 4;
			// 
			// output
			// 
			this->output->BackColor = System::Drawing::SystemColors::Info;
			this->output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->output->Location = System::Drawing::Point(296, 243);
			this->output->Multiline = true;
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(394, 132);
			this->output->TabIndex = 5;
			this->output->TextChanged += gcnew System::EventHandler(this, &findword::input_TextChanged);
			// 
			// word
			// 
			this->word->AutoSize = true;
			this->word->BackColor = System::Drawing::SystemColors::Info;
			this->word->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->word->Location = System::Drawing::Point(303, 97);
			this->word->Name = L"word";
			this->word->Size = System::Drawing::Size(177, 36);
			this->word->TabIndex = 6;
			this->word->Text = L"Enter Word";
			this->word->Click += gcnew System::EventHandler(this, &findword::word_Click);
			// 
			// suggest
			// 
			this->suggest->Location = System::Drawing::Point(296, 381);
			this->suggest->Name = L"suggest";
			this->suggest->Size = System::Drawing::Size(160, 61);
			this->suggest->TabIndex = 7;
			this->suggest->Text = L"Suggest words";
			this->suggest->UseVisualStyleBackColor = true;
			this->suggest->Click += gcnew System::EventHandler(this, &findword::suggest_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 483);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 61);
			this->button2->TabIndex = 19;
			this->button2->Text = L"EXIT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &findword::button2_Click);
			// 
			// findword
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(969, 574);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->suggest);
			this->Controls->Add(this->word);
			this->Controls->Add(this->output);
			this->Controls->Add(this->input);
			this->Controls->Add(this->DICTIONARY);
			this->Controls->Add(this->search);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"findword";
			this->Text = L"Search";
			this->Load += gcnew System::EventHandler(this, &findword::findword_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ word = input->Text;


		string St_word = msclr::interop::marshal_as<string>(word);
		string meaning= obj->searchMeaning(St_word);
		
		if (meaning!="")
		{

			output->Text=gcnew String(meaning.c_str());

		}
		else
		{
			MessageBox::Show("Word Not Found", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
			output->Text = "Word Not Founds";
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void findword_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void word_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void suggest_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ word = input->Text;


		string input = msclr::interop::marshal_as<std::string>(word);


		vector<string> suggestions = obj->suggestWords(input);
		

		if (!suggestions.empty()) {
			string suggestionStr = "Suggestions:\n\t";
			int i = 1;
			
			for (const auto& suggestion : suggestions) {
				
				suggestionStr += to_string(i) + ": " + suggestion + "\t\n\t";
				if (i == 10) { break; }
				i++;
			}
			MessageBox::Show(gcnew String(suggestionStr.c_str()), "Suggestions");

		}
		else {
			MessageBox::Show("No suggestions found.", "Suggestions");
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
};
}
