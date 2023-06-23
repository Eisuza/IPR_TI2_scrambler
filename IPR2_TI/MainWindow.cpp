#include "MainWindow.h"
#include <cmath>
#include <numeric>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	IPR2TI::MainWindow mainWindow;
	Application::Run(% mainWindow);
}

System::Void IPR2TI::MainWindow::btn_menu_encrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	btn_upload_input_file->Visible = true;
	btn_upload_key_public->Visible = true;
	btn_encrypt->Visible = true;
	btn_menu_encrypt->Enabled = false;
	btn_menu_decrypt->Visible = false;
	btn_menu_generate->Visible = false;
	btn_clean->Visible = true;
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_menu_decrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	btn_upload_input_file_binary->Visible = true;
	btn_upload_key_private->Visible = true;
	btn_decrypt->Visible = true;
	btn_menu_encrypt->Visible = false;
	btn_menu_decrypt->Enabled = false;
	btn_menu_generate->Visible = false;
	btn_clean->Visible = true;
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_menu_generate_Click(System::Object^ sender, System::EventArgs^ e)
{
	label_p->Visible = true;
	label_q->Visible = true;
	label_e->Visible = true;
	input_p->Visible = true;
	input_q->Visible = true;
	input_e->Visible = true;
	btn_generate->Visible = true;
	btn_save_key_public->Visible = true;
	btn_save_key_private->Visible = true;
	btn_clean->Visible = true;
	btn_menu_encrypt->Visible = false;
	btn_menu_decrypt->Visible = false;
	btn_menu_generate->Enabled = false;
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_clean_Click(System::Object^ sender, System::EventArgs^ e)
{
	btn_upload_input_file->Visible = false;
	btn_upload_key_public->Visible = false;
	btn_encrypt->Visible = false;
	btn_upload_input_file_binary->Visible = false;
	btn_upload_key_private->Visible = false;
	btn_decrypt->Visible = false;
	label_p->Visible = false;
	label_q->Visible = false;
	label_e->Visible = false;
	input_p->Visible = false;
	input_p->Text = "";
	input_q->Text = "";
	input_e->Text = "";
	input_q->Visible = false;
	input_e->Visible = false;
	btn_generate->Visible = false;
	btn_save_key_public->Visible = false;
	btn_save_key_private->Visible = false;
	btn_save_key_public->Enabled = false;
	btn_save_key_private->Enabled = false;
	btn_save_encrypted_file->Visible = false;
	btn_save_decrypted_file->Visible = false;
	btn_menu_encrypt->Enabled = true;
	btn_menu_decrypt->Enabled = true;
	btn_menu_generate->Enabled = true;
	btn_menu_encrypt->Visible = true;
	btn_menu_decrypt->Visible = true;
	btn_menu_generate->Visible = true;
	tb_view_input_file->Visible = false;
	tb_view_output_file->Visible = false;
	btn_clean->Visible = false;
	FilePublicKey = "";
	FilePrivateKey = "";
	FileInput = "";
	FileOutput = "";
	file_size = 0;
	return System::Void();
}

System::Void IPR2TI::MainWindow::input_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	char ch = e->KeyChar;
	if (!((ch >= 48 && ch <=57) || ch == 8)){
		e->Handled = true;
	}	
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_generate_Click(System::Object^ sender, System::EventArgs^ e)
{
	int result = 0;
	try{
		result = values_input_check();
	}
	catch(Exception^ e){
		MessageBox::Show(this, e->Message, "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
		result = 1;
	}
	finally {
		if (result == 0) {
			btn_save_key_public->Enabled = true;	// для проверок пока
			btn_save_key_private->Enabled = true;
			key.d = generate_private_key();
		}
	}

	return System::Void();
}

int IPR2TI::MainWindow::values_input_check()
{
	if ((input_p->Text != "") && (input_q->Text != "") && (input_e->Text != "")) {
		confidential.p = System::Convert::ToInt32(input_p->Text);
		confidential.q = System::Convert::ToInt32(input_q->Text);
		key.e = System::Convert::ToInt32(input_e->Text);
		key.n = confidential.p * confidential.q;
		for (unsigned i = 2; i <= static_cast<unsigned>(sqrt(confidential.p)); i++) {
			if (confidential.p % i == 0)
				throw gcnew Exception("p не является простым числом.");
		}
		for (unsigned i = 2; i <= static_cast<unsigned>(sqrt(confidential.q)); i++) {
			if (confidential.q % i == 0)
				throw gcnew Exception("q не является простым числом.");
		}
		for (unsigned i = 2; i <= static_cast<unsigned>(sqrt(key.e)); i++) {
			if (key.e % i == 0) 
				throw gcnew Exception("e не является простым числом.");
		}
		unsigned int fn = (confidential.p - 1) * (confidential.q - 1);
		if (key.e > fn) 
			throw gcnew Exception("e слишком велико.");
		if (std::gcd(key.e, fn) != 1) 
			throw gcnew Exception("e не подходит под параметры (НОД != 1).");
	}
	else
		throw gcnew Exception("Не все параметры введены.");
	return 0;
}

unsigned int IPR2TI::MainWindow::generate_private_key()
{
	confidential.fn = (confidential.p - 1) * (confidential.q - 1);
	long int x = 0, y = 0;
	extended_gcd(key.e, confidential.fn, x, y);
	x = ((x % confidential.fn) + confidential.fn) % confidential.fn;
	return x;
}

long int IPR2TI::MainWindow::extended_gcd(long int a, long int b, long int &x, long int &y)
{
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	long int x1 = 0, y1 = 0;
	long int d = extended_gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

System::Void IPR2TI::MainWindow::btn_save_key_public_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FilePublicKey = saveFileDialog->FileName;
	}
	try {
		FileStream^ file = gcnew FileStream(FilePublicKey, FileMode::Create);
		BinaryWriter^ writer = gcnew BinaryWriter(file);
			writer->Write(key.n);
			writer->Write(key.e);
		file->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show(this, "Файл не был сохранен", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_save_key_private_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FilePrivateKey = saveFileDialog->FileName;
	}
	try {
		FileStream^ file = gcnew FileStream(FilePrivateKey, FileMode::Create);
		BinaryWriter^ writer = gcnew BinaryWriter(file);
		writer->Write(key.n);
		writer->Write(key.d);
		file->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show(this, "Файл не был сохранен", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_upload_input_file_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileInput = openFileDialog->FileName;
	}
	try
	{
		String^ a = "";

		FileStream^ file = gcnew FileStream(FileInput, FileMode::Open);
		BinaryReader^ reader = gcnew BinaryReader(file);
		int file_size = reader->BaseStream->Length;

		for (int i = 0; i < file_size; i++) {
			a = a + reader->ReadByte() + " ";
		}
		file->Close();
		tb_view_input_file->Text = a;
		tb_view_input_file->Visible = true;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(this, "Не получилось открыть файл с ключом", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_upload_key_public_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FilePublicKey = openFileDialog->FileName;
	}
	try
	{
		FileStream^ file = gcnew FileStream(FilePublicKey, FileMode::Open);
		BinaryReader^ reader = gcnew BinaryReader(file);
		key.n = reader->ReadInt32();
		key.e = reader->ReadInt32();
		file->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(this, "Не получилось открыть файл с ключом", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_encrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	int result = 0;
	try {
		encrypt_file();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(this, e->Message, "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
		result = 1;
	}
	finally {
		if (result == 0) {

		}
	}
	return System::Void();
}

void IPR2TI::MainWindow::encrypt_file()
{
	if (FilePublicKey == "" || FileInput == "")
	{
		throw gcnew Exception("Загружены не все файлы.");
	}
	else {
		try
		{
			String^ a = "";
			FileStream^ file = gcnew FileStream(FileInput, FileMode::Open);
			BinaryReader^ reader = gcnew BinaryReader(file);
			file_size = reader->BaseStream->Length;
			int number = 0;
			encrypted = gcnew array<int>(file_size);
			for (int i = 0; i < file_size; i++) {
				number = reader->ReadByte();
				encrypted[i] = mod_power(number, key.e, key.n);
				a = a + encrypted[i] + " ";
			}
			file->Close();
			tb_view_output_file->Text = a;
			tb_view_output_file->Visible = true;
			btn_save_encrypted_file->Visible = true;
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Не получилось открыть файл с ключом", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	return System::Void();
}

int IPR2TI::MainWindow::mod_power(int number, int power, int mod)
{
	if (power == 0LL) return 1LL;
	if (power % 2 == 1)
		return (number * mod_power(number, power - 1, mod)) % mod;
	long long tmp = mod_power(number, power / 2, mod); 
	return (tmp * tmp) % mod; 
}

System::Void IPR2TI::MainWindow::save_encrypted_file_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileOutput = saveFileDialog->FileName;
	}
	try {
		FileStream^ file = gcnew FileStream(FileOutput, FileMode::Create);
		BinaryWriter^ writer = gcnew BinaryWriter(file);
		for (int i = 0; i < file_size; i++) {
			writer->Write(encrypted[i]);
		}
		file->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show(this, "Файл не был сохранен", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_upload_input_file_binary_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileInput = openFileDialog->FileName;
	}
	try
	{
		String^ a = "";

		FileStream^ file = gcnew FileStream(FileInput, FileMode::Open);
		BinaryReader^ reader = gcnew BinaryReader(file);
		int file_size = reader->BaseStream->Length / 4;//sizeof int

		for (int i = 0; i < file_size; i++) {
			a = a + reader->ReadInt32() + " ";
		}
		file->Close();
		tb_view_input_file->Text = a;
		tb_view_input_file->Visible = true;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(this, "Не получилось открыть файл с ключом", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_upload_key_private_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FilePrivateKey = openFileDialog->FileName;
	}
	try
	{
		FileStream^ file = gcnew FileStream(FilePrivateKey, FileMode::Open);
		BinaryReader^ reader = gcnew BinaryReader(file);
		key.n = reader->ReadInt32();
		key.d = reader->ReadInt32();
		file->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(this, "Не получилось открыть файл с ключом", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_decrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	int result = 0;
	try {
		decrypt_file();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(this, e->Message, "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
		result = 1;
	}
	finally {
		if (result == 0) {

		}
	}
	return System::Void();
}

void IPR2TI::MainWindow::decrypt_file()
{
	if (FilePrivateKey == "" || FileInput == "")
	{
		throw gcnew Exception("Загружены не все файлы.");
	}
	else {
		try
		{
			String^ a = "";
			FileStream^ file = gcnew FileStream(FileInput, FileMode::Open);
			BinaryReader^ reader = gcnew BinaryReader(file);
			file_size = reader->BaseStream->Length / 4;	//sizeof int
			int number = 0;
			decrypted = gcnew array<Byte>(file_size);
			for (int i = 0; i < file_size; i++) {
				number = reader->ReadInt32();
				decrypted[i] = mod_power(number, key.d, key.n);
				a = a + decrypted[i] + " ";
			}
			file->Close();
			tb_view_output_file->Text = a;
			tb_view_output_file->Visible = true;
			btn_save_decrypted_file->Visible = true;
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Не получилось открыть файл с ключом", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	return System::Void();
}

System::Void IPR2TI::MainWindow::btn_save_decrypted_file_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileOutput = saveFileDialog->FileName;
	}
	try {
		FileStream^ file = gcnew FileStream(FileOutput, FileMode::Create);
		BinaryWriter^ writer = gcnew BinaryWriter(file);
		for (int i = 0; i < file_size; i++) {
			writer->Write(decrypted[i]);
		}
		file->Close();
	}
	catch (Exception^ e) {
		MessageBox::Show(this, "Файл не был сохранен", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	return System::Void();
}




