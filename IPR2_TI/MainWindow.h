#pragma once

namespace IPR2TI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct key {
		long int n = 0;
		long int e = 0;
		long int d = 0;
	} key;

	struct secret_values {
		long int p = 0;
		long int q = 0;
		long int fn = 0;
	} confidential;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_menu_encrypt;
	protected:
	private: System::Windows::Forms::Button^ btn_menu_decrypt;
	private: System::Windows::Forms::Button^ btn_menu_generate;
	private: System::Windows::Forms::Button^ btn_upload_input_file;
	private: System::Windows::Forms::Button^ btn_upload_key_public;


	private: System::Windows::Forms::Button^ btn_encrypt;
	private: System::Windows::Forms::Button^ btn_upload_input_file_binary;

	private: System::Windows::Forms::Button^ btn_upload_key_private;
	private: System::Windows::Forms::Button^ btn_decrypt;
	private: System::Windows::Forms::TextBox^ input_p;
	private: System::Windows::Forms::Label^ label_p;
	private: System::Windows::Forms::Label^ label_q;
	private: System::Windows::Forms::TextBox^ input_q;
	private: System::Windows::Forms::Label^ label_e;
	private: System::Windows::Forms::TextBox^ input_e;
	private: System::Windows::Forms::Button^ btn_generate;
	private: System::Windows::Forms::TextBox^ tb_view_input_file;
	private: System::Windows::Forms::TextBox^ tb_view_output_file;
	private: System::Windows::Forms::Button^ btn_save_key_public;




	private: System::Windows::Forms::Button^ btn_save_key_private;
	private: System::Windows::Forms::Button^ btn_clean;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;



	private:

		String^ FilePublicKey = "";
		String^ FilePrivateKey = "";
		String^ FileInput = "";
		String^ FileOutput = "";
		int file_size = 0;
		array<int>^ encrypted;
		array<Byte>^ decrypted;
	private: System::Windows::Forms::Button^ btn_save_encrypted_file;
	private: System::Windows::Forms::Button^ btn_save_decrypted_file;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->btn_menu_encrypt = (gcnew System::Windows::Forms::Button());
			this->btn_menu_decrypt = (gcnew System::Windows::Forms::Button());
			this->btn_menu_generate = (gcnew System::Windows::Forms::Button());
			this->btn_upload_input_file = (gcnew System::Windows::Forms::Button());
			this->btn_upload_key_public = (gcnew System::Windows::Forms::Button());
			this->btn_encrypt = (gcnew System::Windows::Forms::Button());
			this->btn_upload_input_file_binary = (gcnew System::Windows::Forms::Button());
			this->btn_upload_key_private = (gcnew System::Windows::Forms::Button());
			this->btn_decrypt = (gcnew System::Windows::Forms::Button());
			this->input_p = (gcnew System::Windows::Forms::TextBox());
			this->label_p = (gcnew System::Windows::Forms::Label());
			this->label_q = (gcnew System::Windows::Forms::Label());
			this->input_q = (gcnew System::Windows::Forms::TextBox());
			this->label_e = (gcnew System::Windows::Forms::Label());
			this->input_e = (gcnew System::Windows::Forms::TextBox());
			this->btn_generate = (gcnew System::Windows::Forms::Button());
			this->tb_view_input_file = (gcnew System::Windows::Forms::TextBox());
			this->tb_view_output_file = (gcnew System::Windows::Forms::TextBox());
			this->btn_save_key_public = (gcnew System::Windows::Forms::Button());
			this->btn_save_key_private = (gcnew System::Windows::Forms::Button());
			this->btn_clean = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->btn_save_encrypted_file = (gcnew System::Windows::Forms::Button());
			this->btn_save_decrypted_file = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_menu_encrypt
			// 
			this->btn_menu_encrypt->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_menu_encrypt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_menu_encrypt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_menu_encrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_menu_encrypt->ForeColor = System::Drawing::Color::White;
			this->btn_menu_encrypt->Location = System::Drawing::Point(12, 23);
			this->btn_menu_encrypt->Name = L"btn_menu_encrypt";
			this->btn_menu_encrypt->Size = System::Drawing::Size(300, 23);
			this->btn_menu_encrypt->TabIndex = 0;
			this->btn_menu_encrypt->Text = L"Зашифровка файла";
			this->btn_menu_encrypt->UseVisualStyleBackColor = false;
			this->btn_menu_encrypt->Click += gcnew System::EventHandler(this, &MainWindow::btn_menu_encrypt_Click);
			// 
			// btn_menu_decrypt
			// 
			this->btn_menu_decrypt->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_menu_decrypt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_menu_decrypt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_menu_decrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_menu_decrypt->ForeColor = System::Drawing::Color::White;
			this->btn_menu_decrypt->Location = System::Drawing::Point(350, 23);
			this->btn_menu_decrypt->Name = L"btn_menu_decrypt";
			this->btn_menu_decrypt->Size = System::Drawing::Size(300, 23);
			this->btn_menu_decrypt->TabIndex = 1;
			this->btn_menu_decrypt->Text = L"Расшифровка файла";
			this->btn_menu_decrypt->UseVisualStyleBackColor = false;
			this->btn_menu_decrypt->Click += gcnew System::EventHandler(this, &MainWindow::btn_menu_decrypt_Click);
			// 
			// btn_menu_generate
			// 
			this->btn_menu_generate->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_menu_generate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_menu_generate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_menu_generate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_menu_generate->ForeColor = System::Drawing::Color::White;
			this->btn_menu_generate->Location = System::Drawing::Point(688, 23);
			this->btn_menu_generate->Name = L"btn_menu_generate";
			this->btn_menu_generate->Size = System::Drawing::Size(300, 23);
			this->btn_menu_generate->TabIndex = 2;
			this->btn_menu_generate->Text = L"Генерация ключей";
			this->btn_menu_generate->UseVisualStyleBackColor = false;
			this->btn_menu_generate->Click += gcnew System::EventHandler(this, &MainWindow::btn_menu_generate_Click);
			// 
			// btn_upload_input_file
			// 
			this->btn_upload_input_file->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_upload_input_file->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_upload_input_file->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_upload_input_file->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btn_upload_input_file->ForeColor = System::Drawing::Color::White;
			this->btn_upload_input_file->Location = System::Drawing::Point(12, 69);
			this->btn_upload_input_file->Name = L"btn_upload_input_file";
			this->btn_upload_input_file->Size = System::Drawing::Size(115, 23);
			this->btn_upload_input_file->TabIndex = 3;
			this->btn_upload_input_file->Text = L"Загрузить файл";
			this->btn_upload_input_file->UseVisualStyleBackColor = false;
			this->btn_upload_input_file->Visible = false;
			this->btn_upload_input_file->Click += gcnew System::EventHandler(this, &MainWindow::btn_upload_input_file_Click);
			// 
			// btn_upload_key_public
			// 
			this->btn_upload_key_public->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_upload_key_public->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_upload_key_public->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_upload_key_public->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btn_upload_key_public->ForeColor = System::Drawing::Color::White;
			this->btn_upload_key_public->Location = System::Drawing::Point(12, 115);
			this->btn_upload_key_public->Name = L"btn_upload_key_public";
			this->btn_upload_key_public->Size = System::Drawing::Size(115, 23);
			this->btn_upload_key_public->TabIndex = 4;
			this->btn_upload_key_public->Text = L"Загрузить ключ";
			this->btn_upload_key_public->UseVisualStyleBackColor = false;
			this->btn_upload_key_public->Visible = false;
			this->btn_upload_key_public->Click += gcnew System::EventHandler(this, &MainWindow::btn_upload_key_public_Click);
			// 
			// btn_encrypt
			// 
			this->btn_encrypt->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_encrypt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_encrypt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_encrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_encrypt->ForeColor = System::Drawing::Color::White;
			this->btn_encrypt->Location = System::Drawing::Point(197, 111);
			this->btn_encrypt->Name = L"btn_encrypt";
			this->btn_encrypt->Size = System::Drawing::Size(115, 23);
			this->btn_encrypt->TabIndex = 5;
			this->btn_encrypt->Text = L"Зашифровать";
			this->btn_encrypt->UseVisualStyleBackColor = false;
			this->btn_encrypt->Visible = false;
			this->btn_encrypt->Click += gcnew System::EventHandler(this, &MainWindow::btn_encrypt_Click);
			// 
			// btn_upload_input_file_binary
			// 
			this->btn_upload_input_file_binary->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_upload_input_file_binary->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_upload_input_file_binary->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_upload_input_file_binary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btn_upload_input_file_binary->ForeColor = System::Drawing::Color::White;
			this->btn_upload_input_file_binary->Location = System::Drawing::Point(350, 69);
			this->btn_upload_input_file_binary->Name = L"btn_upload_input_file_binary";
			this->btn_upload_input_file_binary->Size = System::Drawing::Size(115, 23);
			this->btn_upload_input_file_binary->TabIndex = 6;
			this->btn_upload_input_file_binary->Text = L"Загрузить файл";
			this->btn_upload_input_file_binary->UseVisualStyleBackColor = false;
			this->btn_upload_input_file_binary->Visible = false;
			this->btn_upload_input_file_binary->Click += gcnew System::EventHandler(this, &MainWindow::btn_upload_input_file_binary_Click);
			// 
			// btn_upload_key_private
			// 
			this->btn_upload_key_private->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_upload_key_private->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_upload_key_private->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_upload_key_private->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btn_upload_key_private->ForeColor = System::Drawing::Color::White;
			this->btn_upload_key_private->Location = System::Drawing::Point(350, 115);
			this->btn_upload_key_private->Name = L"btn_upload_key_private";
			this->btn_upload_key_private->Size = System::Drawing::Size(115, 23);
			this->btn_upload_key_private->TabIndex = 7;
			this->btn_upload_key_private->Text = L"Загрузить ключ";
			this->btn_upload_key_private->UseVisualStyleBackColor = false;
			this->btn_upload_key_private->Visible = false;
			this->btn_upload_key_private->Click += gcnew System::EventHandler(this, &MainWindow::btn_upload_key_private_Click);
			// 
			// btn_decrypt
			// 
			this->btn_decrypt->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_decrypt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_decrypt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_decrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_decrypt->ForeColor = System::Drawing::Color::White;
			this->btn_decrypt->Location = System::Drawing::Point(535, 111);
			this->btn_decrypt->Name = L"btn_decrypt";
			this->btn_decrypt->Size = System::Drawing::Size(115, 23);
			this->btn_decrypt->TabIndex = 8;
			this->btn_decrypt->Text = L"Расшифровать";
			this->btn_decrypt->UseVisualStyleBackColor = false;
			this->btn_decrypt->Visible = false;
			this->btn_decrypt->Click += gcnew System::EventHandler(this, &MainWindow::btn_decrypt_Click);
			// 
			// input_p
			// 
			this->input_p->Location = System::Drawing::Point(788, 69);
			this->input_p->Name = L"input_p";
			this->input_p->Size = System::Drawing::Size(200, 20);
			this->input_p->TabIndex = 9;
			this->input_p->Visible = false;
			this->input_p->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::input_KeyPress);
			// 
			// label_p
			// 
			this->label_p->AutoSize = true;
			this->label_p->BackColor = System::Drawing::Color::White;
			this->label_p->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_p->Font = (gcnew System::Drawing::Font(L"News701 BT", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_p->ForeColor = System::Drawing::Color::SteelBlue;
			this->label_p->Location = System::Drawing::Point(685, 72);
			this->label_p->Name = L"label_p";
			this->label_p->Size = System::Drawing::Size(97, 16);
			this->label_p->TabIndex = 10;
			this->label_p->Text = L"Введите \"p\":";
			this->label_p->Visible = false;
			// 
			// label_q
			// 
			this->label_q->AutoSize = true;
			this->label_q->BackColor = System::Drawing::Color::White;
			this->label_q->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_q->Font = (gcnew System::Drawing::Font(L"News701 BT", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_q->ForeColor = System::Drawing::Color::SteelBlue;
			this->label_q->Location = System::Drawing::Point(686, 95);
			this->label_q->Name = L"label_q";
			this->label_q->Size = System::Drawing::Size(96, 16);
			this->label_q->TabIndex = 11;
			this->label_q->Text = L"Введите \"q\":";
			this->label_q->Visible = false;
			// 
			// input_q
			// 
			this->input_q->Location = System::Drawing::Point(788, 92);
			this->input_q->Name = L"input_q";
			this->input_q->Size = System::Drawing::Size(200, 20);
			this->input_q->TabIndex = 12;
			this->input_q->Visible = false;
			this->input_q->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::input_KeyPress);
			// 
			// label_e
			// 
			this->label_e->AutoSize = true;
			this->label_e->BackColor = System::Drawing::Color::White;
			this->label_e->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_e->Font = (gcnew System::Drawing::Font(L"News701 BT", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_e->ForeColor = System::Drawing::Color::SteelBlue;
			this->label_e->Location = System::Drawing::Point(687, 118);
			this->label_e->Name = L"label_e";
			this->label_e->Size = System::Drawing::Size(95, 16);
			this->label_e->TabIndex = 13;
			this->label_e->Text = L"Введите \"e\":";
			this->label_e->Visible = false;
			// 
			// input_e
			// 
			this->input_e->Location = System::Drawing::Point(788, 115);
			this->input_e->Name = L"input_e";
			this->input_e->Size = System::Drawing::Size(200, 20);
			this->input_e->TabIndex = 14;
			this->input_e->Visible = false;
			this->input_e->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::input_KeyPress);
			// 
			// btn_generate
			// 
			this->btn_generate->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_generate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_generate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_generate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_generate->ForeColor = System::Drawing::Color::White;
			this->btn_generate->Location = System::Drawing::Point(873, 147);
			this->btn_generate->Name = L"btn_generate";
			this->btn_generate->Size = System::Drawing::Size(115, 23);
			this->btn_generate->TabIndex = 15;
			this->btn_generate->Text = L"Генерировать";
			this->btn_generate->UseVisualStyleBackColor = false;
			this->btn_generate->Visible = false;
			this->btn_generate->Click += gcnew System::EventHandler(this, &MainWindow::btn_generate_Click);
			// 
			// tb_view_input_file
			// 
			this->tb_view_input_file->Location = System::Drawing::Point(12, 147);
			this->tb_view_input_file->Multiline = true;
			this->tb_view_input_file->Name = L"tb_view_input_file";
			this->tb_view_input_file->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tb_view_input_file->Size = System::Drawing::Size(300, 400);
			this->tb_view_input_file->TabIndex = 16;
			this->tb_view_input_file->Visible = false;
			// 
			// tb_view_output_file
			// 
			this->tb_view_output_file->Location = System::Drawing::Point(350, 147);
			this->tb_view_output_file->Multiline = true;
			this->tb_view_output_file->Name = L"tb_view_output_file";
			this->tb_view_output_file->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tb_view_output_file->Size = System::Drawing::Size(300, 400);
			this->tb_view_output_file->TabIndex = 17;
			this->tb_view_output_file->Visible = false;
			// 
			// btn_save_key_public
			// 
			this->btn_save_key_public->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_save_key_public->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_save_key_public->Enabled = false;
			this->btn_save_key_public->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_save_key_public->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btn_save_key_public->ForeColor = System::Drawing::Color::White;
			this->btn_save_key_public->Location = System::Drawing::Point(688, 190);
			this->btn_save_key_public->Name = L"btn_save_key_public";
			this->btn_save_key_public->Size = System::Drawing::Size(180, 23);
			this->btn_save_key_public->TabIndex = 18;
			this->btn_save_key_public->Text = L"Сохранить открытый ключ";
			this->btn_save_key_public->UseVisualStyleBackColor = false;
			this->btn_save_key_public->Visible = false;
			this->btn_save_key_public->Click += gcnew System::EventHandler(this, &MainWindow::btn_save_key_public_Click);
			// 
			// btn_save_key_private
			// 
			this->btn_save_key_private->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_save_key_private->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_save_key_private->Enabled = false;
			this->btn_save_key_private->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_save_key_private->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btn_save_key_private->ForeColor = System::Drawing::Color::White;
			this->btn_save_key_private->Location = System::Drawing::Point(690, 236);
			this->btn_save_key_private->Name = L"btn_save_key_private";
			this->btn_save_key_private->Size = System::Drawing::Size(180, 23);
			this->btn_save_key_private->TabIndex = 19;
			this->btn_save_key_private->Text = L"Сохранить закрытый ключ";
			this->btn_save_key_private->UseVisualStyleBackColor = false;
			this->btn_save_key_private->Visible = false;
			this->btn_save_key_private->Click += gcnew System::EventHandler(this, &MainWindow::btn_save_key_private_Click);
			// 
			// btn_clean
			// 
			this->btn_clean->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_clean->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_clean->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_clean->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_clean->ForeColor = System::Drawing::Color::White;
			this->btn_clean->Location = System::Drawing::Point(690, 503);
			this->btn_clean->Name = L"btn_clean";
			this->btn_clean->Size = System::Drawing::Size(298, 46);
			this->btn_clean->TabIndex = 20;
			this->btn_clean->Text = L"Очистить всё / В начало";
			this->btn_clean->UseVisualStyleBackColor = false;
			this->btn_clean->Visible = false;
			this->btn_clean->Click += gcnew System::EventHandler(this, &MainWindow::btn_clean_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			// 
			// btn_save_encrypted_file
			// 
			this->btn_save_encrypted_file->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_save_encrypted_file->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_save_encrypted_file->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_save_encrypted_file->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btn_save_encrypted_file->ForeColor = System::Drawing::Color::White;
			this->btn_save_encrypted_file->Location = System::Drawing::Point(689, 413);
			this->btn_save_encrypted_file->Name = L"btn_save_encrypted_file";
			this->btn_save_encrypted_file->Size = System::Drawing::Size(115, 23);
			this->btn_save_encrypted_file->TabIndex = 21;
			this->btn_save_encrypted_file->Text = L"Сохранить файл";
			this->btn_save_encrypted_file->UseVisualStyleBackColor = false;
			this->btn_save_encrypted_file->Visible = false;
			this->btn_save_encrypted_file->Click += gcnew System::EventHandler(this, &MainWindow::save_encrypted_file_Click);
			// 
			// btn_save_decrypted_file
			// 
			this->btn_save_decrypted_file->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btn_save_decrypted_file->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_save_decrypted_file->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_save_decrypted_file->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btn_save_decrypted_file->ForeColor = System::Drawing::Color::White;
			this->btn_save_decrypted_file->Location = System::Drawing::Point(690, 455);
			this->btn_save_decrypted_file->Name = L"btn_save_decrypted_file";
			this->btn_save_decrypted_file->Size = System::Drawing::Size(115, 23);
			this->btn_save_decrypted_file->TabIndex = 22;
			this->btn_save_decrypted_file->Text = L"Сохранить файл";
			this->btn_save_decrypted_file->UseVisualStyleBackColor = false;
			this->btn_save_decrypted_file->Visible = false;
			this->btn_save_decrypted_file->Click += gcnew System::EventHandler(this, &MainWindow::btn_save_decrypted_file_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1024, 561);
			this->Controls->Add(this->btn_save_decrypted_file);
			this->Controls->Add(this->btn_save_encrypted_file);
			this->Controls->Add(this->btn_clean);
			this->Controls->Add(this->btn_save_key_private);
			this->Controls->Add(this->btn_save_key_public);
			this->Controls->Add(this->tb_view_output_file);
			this->Controls->Add(this->tb_view_input_file);
			this->Controls->Add(this->btn_generate);
			this->Controls->Add(this->input_e);
			this->Controls->Add(this->label_e);
			this->Controls->Add(this->input_q);
			this->Controls->Add(this->label_q);
			this->Controls->Add(this->label_p);
			this->Controls->Add(this->input_p);
			this->Controls->Add(this->btn_decrypt);
			this->Controls->Add(this->btn_upload_key_private);
			this->Controls->Add(this->btn_upload_input_file_binary);
			this->Controls->Add(this->btn_encrypt);
			this->Controls->Add(this->btn_upload_key_public);
			this->Controls->Add(this->btn_upload_input_file);
			this->Controls->Add(this->btn_menu_generate);
			this->Controls->Add(this->btn_menu_decrypt);
			this->Controls->Add(this->btn_menu_encrypt);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1040, 600);
			this->MinimumSize = System::Drawing::Size(1040, 600);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_menu_encrypt_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_menu_decrypt_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_menu_generate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_clean_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void input_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void btn_generate_Click(System::Object^ sender, System::EventArgs^ e);



	private: int values_input_check();
	private: unsigned int generate_private_key();
	private: long int extended_gcd(long int a, long int b, long int &x, long int &y);
	private: System::Void btn_save_key_public_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_save_key_private_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_upload_input_file_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_upload_key_public_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_encrypt_Click(System::Object^ sender, System::EventArgs^ e);
	private: void encrypt_file();
	private: int mod_power(int number, int power, int mod);
	private: System::Void save_encrypted_file_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_upload_input_file_binary_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_upload_key_private_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_decrypt_Click(System::Object^ sender, System::EventArgs^ e);
	private: void decrypt_file();
	private: System::Void btn_save_decrypted_file_Click(System::Object^ sender, System::EventArgs^ e);
};
}
