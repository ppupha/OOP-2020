#pragma once
#include "form_event.h"

namespace OOP
{
    using namespace System;
    using namespace System::Runtime::InteropServices;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
        public:
            Form1(void)
            {
                InitializeComponent();
            }
        protected:
            ~Form1()
            {
                if (components)
                {
                    delete components;
                }
            }
        private: System::Windows::Forms::PictureBox^  pictureBox1;
        private: System::Windows::Forms::Button^  btnRotate;
        private: System::Windows::Forms::TextBox^  textBox1;
        private: System::Windows::Forms::TextBox^  textBox2;
        private: System::Windows::Forms::TextBox^  textBox3;
        private: System::Windows::Forms::TextBox^  textBox4;
        private: System::Windows::Forms::Button^  btnScale;
        private: System::Windows::Forms::Button^  btnShift;
        private: System::Windows::Forms::TextBox^  textBox5;
        private: System::Windows::Forms::TextBox^  textBox6;
        private: System::Windows::Forms::TextBox^  textBox7;
        private: System::Windows::Forms::Button^  btnLoad;
        private: System::Windows::Forms::Label^  label1;
        private: System::Windows::Forms::Label^  label2;
        private: System::Windows::Forms::Label^  label3;
        private: System::Windows::Forms::Label^  label4;
        private: System::Windows::Forms::Label^  label5;
        private: System::Windows::Forms::Label^  label6;
        private: System::Windows::Forms::Label^  label7;

        private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;


	private: System::ComponentModel::Container ^components;

    #pragma region Windows Form Designer generated code
            void InitializeComponent(void)
            {
				this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				this->btnRotate = (gcnew System::Windows::Forms::Button());
				this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				this->textBox3 = (gcnew System::Windows::Forms::TextBox());
				this->textBox4 = (gcnew System::Windows::Forms::TextBox());
				this->btnScale = (gcnew System::Windows::Forms::Button());
				this->btnShift = (gcnew System::Windows::Forms::Button());
				this->textBox5 = (gcnew System::Windows::Forms::TextBox());
				this->textBox6 = (gcnew System::Windows::Forms::TextBox());
				this->textBox7 = (gcnew System::Windows::Forms::TextBox());
				this->btnLoad = (gcnew System::Windows::Forms::Button());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				this->button1 = (gcnew System::Windows::Forms::Button());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				this->SuspendLayout();
				// 
				// pictureBox1
				// 
				this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
				this->pictureBox1->Location = System::Drawing::Point(0, 0);
				this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
				this->pictureBox1->Name = L"pictureBox1";
				this->pictureBox1->Size = System::Drawing::Size(778, 538);
				this->pictureBox1->TabIndex = 0;
				this->pictureBox1->TabStop = false;
				// 
				// btnRotate
				// 
				this->btnRotate->Location = System::Drawing::Point(810, 157);
				this->btnRotate->Margin = System::Windows::Forms::Padding(2);
				this->btnRotate->Name = L"btnRotate";
				this->btnRotate->Size = System::Drawing::Size(86, 32);
				this->btnRotate->TabIndex = 1;
				this->btnRotate->Text = L"Rotate";
				this->btnRotate->UseVisualStyleBackColor = true;
				this->btnRotate->Click += gcnew System::EventHandler(this, &Form1::btnRotate_Click);
				// 
				// textBox1
				// 
				this->textBox1->Location = System::Drawing::Point(810, 88);
				this->textBox1->Margin = System::Windows::Forms::Padding(2);
				this->textBox1->Name = L"textBox1";
				this->textBox1->Size = System::Drawing::Size(87, 20);
				this->textBox1->TabIndex = 2;
				this->textBox1->Text = L"0";
				this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
				// 
				// textBox2
				// 
				this->textBox2->Location = System::Drawing::Point(810, 109);
				this->textBox2->Margin = System::Windows::Forms::Padding(2);
				this->textBox2->Name = L"textBox2";
				this->textBox2->Size = System::Drawing::Size(87, 20);
				this->textBox2->TabIndex = 3;
				this->textBox2->Text = L"0";
				this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox2_KeyPress);
				// 
				// textBox3
				// 
				this->textBox3->Location = System::Drawing::Point(810, 130);
				this->textBox3->Margin = System::Windows::Forms::Padding(2);
				this->textBox3->Name = L"textBox3";
				this->textBox3->Size = System::Drawing::Size(87, 20);
				this->textBox3->TabIndex = 4;
				this->textBox3->Text = L"0";
				this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox3_KeyPress);
				// 
				// textBox4
				// 
				this->textBox4->Location = System::Drawing::Point(810, 201);
				this->textBox4->Margin = System::Windows::Forms::Padding(2);
				this->textBox4->Name = L"textBox4";
				this->textBox4->Size = System::Drawing::Size(87, 20);
				this->textBox4->TabIndex = 5;
				this->textBox4->Text = L"1";
				this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox4_KeyPress);
				// 
				// btnScale
				// 
				this->btnScale->Location = System::Drawing::Point(810, 231);
				this->btnScale->Margin = System::Windows::Forms::Padding(2);
				this->btnScale->Name = L"btnScale";
				this->btnScale->Size = System::Drawing::Size(86, 32);
				this->btnScale->TabIndex = 6;
				this->btnScale->Text = L"Scale";
				this->btnScale->UseVisualStyleBackColor = true;
				this->btnScale->Click += gcnew System::EventHandler(this, &Form1::btnScale_Click);
				// 
				// btnShift
				// 
				this->btnShift->Location = System::Drawing::Point(810, 341);
				this->btnShift->Margin = System::Windows::Forms::Padding(2);
				this->btnShift->Name = L"btnShift";
				this->btnShift->Size = System::Drawing::Size(86, 32);
				this->btnShift->TabIndex = 7;
				this->btnShift->Text = L"Move";
				this->btnShift->UseVisualStyleBackColor = true;
				this->btnShift->Click += gcnew System::EventHandler(this, &Form1::btnShift_Click);
				// 
				// textBox5
				// 
				this->textBox5->Location = System::Drawing::Point(810, 275);
				this->textBox5->Margin = System::Windows::Forms::Padding(2);
				this->textBox5->Name = L"textBox5";
				this->textBox5->Size = System::Drawing::Size(87, 20);
				this->textBox5->TabIndex = 8;
				this->textBox5->Text = L"0";
				this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox5_KeyPress);
				// 
				// textBox6
				// 
				this->textBox6->Location = System::Drawing::Point(810, 296);
				this->textBox6->Margin = System::Windows::Forms::Padding(2);
				this->textBox6->Name = L"textBox6";
				this->textBox6->Size = System::Drawing::Size(87, 20);
				this->textBox6->TabIndex = 9;
				this->textBox6->Text = L"0";
				this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox6_KeyPress);
				// 
				// textBox7
				// 
				this->textBox7->Location = System::Drawing::Point(810, 316);
				this->textBox7->Margin = System::Windows::Forms::Padding(2);
				this->textBox7->Name = L"textBox7";
				this->textBox7->Size = System::Drawing::Size(87, 20);
				this->textBox7->TabIndex = 10;
				this->textBox7->Text = L"0";
				this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox7_KeyPress);
				// 
				// btnLoad
				// 
				this->btnLoad->Location = System::Drawing::Point(810, 35);
				this->btnLoad->Margin = System::Windows::Forms::Padding(2);
				this->btnLoad->Name = L"btnLoad";
				this->btnLoad->Size = System::Drawing::Size(86, 30);
				this->btnLoad->TabIndex = 11;
				this->btnLoad->Text = L"Load";
				this->btnLoad->UseVisualStyleBackColor = true;
				this->btnLoad->Click += gcnew System::EventHandler(this, &Form1::btnLoad_Click);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(792, 92);
				this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(12, 13);
				this->label1->TabIndex = 12;
				this->label1->Text = L"x";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(792, 113);
				this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(12, 13);
				this->label2->TabIndex = 13;
				this->label2->Text = L"y";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(792, 134);
				this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(12, 13);
				this->label3->TabIndex = 14;
				this->label3->Text = L"z";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(792, 205);
				this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(13, 13);
				this->label4->TabIndex = 15;
				this->label4->Text = L"k";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Location = System::Drawing::Point(793, 279);
				this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(12, 13);
				this->label5->TabIndex = 16;
				this->label5->Text = L"x";
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Location = System::Drawing::Point(793, 299);
				this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(12, 13);
				this->label6->TabIndex = 17;
				this->label6->Text = L"y";
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Location = System::Drawing::Point(793, 320);
				this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(12, 13);
				this->label7->TabIndex = 18;
				this->label7->Text = L"z";
				// 
				// openFileDialog1
				// 
				this->openFileDialog1->FileName = L"openFileDialog1";
				this->openFileDialog1->Filter = L"txt files (*.txt)|*.txt";
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(810, 387);
				this->button1->Margin = System::Windows::Forms::Padding(2);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(86, 32);
				this->button1->TabIndex = 19;
				this->button1->Text = L"Draw";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
				// 
				// Form1
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::SystemColors::Control;
				this->ClientSize = System::Drawing::Size(901, 549);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->label7);
				this->Controls->Add(this->label6);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->btnLoad);
				this->Controls->Add(this->textBox7);
				this->Controls->Add(this->textBox6);
				this->Controls->Add(this->textBox5);
				this->Controls->Add(this->btnShift);
				this->Controls->Add(this->btnScale);
				this->Controls->Add(this->textBox4);
				this->Controls->Add(this->textBox3);
				this->Controls->Add(this->textBox2);
				this->Controls->Add(this->textBox1);
				this->Controls->Add(this->btnRotate);
				this->Controls->Add(this->pictureBox1);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				this->Margin = System::Windows::Forms::Padding(2);
				this->MaximizeBox = false;
				this->MinimizeBox = false;
				this->Name = L"Form1";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Lab OOP";
				this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
				this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
    #pragma endregion
        private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
                {
                    Form_data_t fdata;
                    wrapper_canvas cont;
                    cont.pb = pictureBox1; 
                    fdata.canva = &cont;
                    action_process(canvasInit, &fdata);
                }

        private: System::Void btnLoad_Click(System::Object^  sender, System::EventArgs^  e) 
                {
                    Error_t rc = OK;
                    if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                    {
						Form_data_t fdata;
						// get input file
						fdata.filename = (char*)(void*)Marshal::StringToHGlobalAnsi(this->openFileDialog1->FileName);
						//  Load Model
						rc = action_process(LoadFigure, &fdata);
                    }
                    if (rc != OK)
						MessageBox::Show("Error_Load_CLick\n");
                }
        private: System::Void btnRotate_Click(System::Object^  sender, System::EventArgs^  e)
                {
                    Form_data_t fdata;
					if (textBox1->Text->Length && textBox2->Text->Length && textBox3->Text->Length)
					{
						fdata.data_rotate.angle_x = Convert::ToInt32(textBox1->Text);
						fdata.data_rotate.angle_y = Convert::ToInt32(textBox2->Text);
						fdata.data_rotate.angle_z = Convert::ToInt32(textBox3->Text);
						Error_t rc = action_process(RotateFigure, &fdata);
						if (rc != OK)
							MessageBox::Show("Error: Rotate_Click\n");
					}
					else
						MessageBox::Show("Error: Input Rotate_Click\n");
                }
        private: System::Void btnScale_Click(System::Object^  sender, System::EventArgs^  e)
                {
                    Form_data_t fdata;
                    if (textBox4->Text->Length)
					{
						//textBox4->Text = textBox4->Text->Replace(".", ",");
						fdata.data_scale.scale = Convert::ToDouble(textBox4->Text);
						double p = Convert::ToDouble(textBox4->Text);
						Error_t rc = action_process(ScaleFigure, &fdata);
						if (rc != OK)
							MessageBox::Show("Error: Scale_CLick\n");
					}
					else
						MessageBox::Show("Error:Input  Scale_Click\n");
                }
        private: System::Void btnShift_Click(System::Object^  sender, System::EventArgs^  e)
                {
					if (textBox5->Text->Length && textBox6->Text->Length && textBox7->Text->Length)
					{
						Form_data_t fdata;
						fdata.data_shift.dx = Convert::ToInt32(textBox5->Text);
						fdata.data_shift.dy = Convert::ToInt32(textBox6->Text);
						fdata.data_shift.dz = Convert::ToInt32(textBox7->Text);
						Error_t rc = action_process(ShiftFigure, &fdata);
						if (rc != OK)
							MessageBox::Show("Error: Shift_Click");
					}
					else
						MessageBox::Show("Error: Input Shift_Click");
                }
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
				{
					Form_data_t fdata;
					wrapper_canvas cont;
					cont.pb = pictureBox1; 
					fdata.canva = &cont;
					Error_t rc = action_process(DrawFigure, &fdata);
					if (rc != OK)
						MessageBox::Show("Error: Draw_Click");
				}

        private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
                {
					Form_data_t fdata;
                    action_process(DeleteFigure, &fdata);
                }
		private: System::Void toolStripbtnRotate_Click(System::Object^  sender, System::EventArgs^  e)
			 {
			 }
		private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox1->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Error");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox1->Text->Length == 0)
				 {
					 if (textBox1->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
					 return;

			 e->Handled = true;
		 }
	private: System::Void textBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox2->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Error");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox2->Text->Length == 0)
				 {
					 if (textBox2->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
				 return;

			 e->Handled = true;
		 }
private: System::Void textBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox3->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Error");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox3->Text->Length == 0)
				 {
					 if (textBox3->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
					 return;

			 e->Handled = true;
		 }
private: System::Void textBox4_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox4->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ','|| e->KeyChar == '.')
				 {
					 if (textBox4->Text->IndexOf(',') != -1 ||  textBox4->Text->IndexOf('.') != -1 
						 || textBox4->Text->Length == 0)
						 e->Handled = true;
					 return;
				 }
				 if (e->KeyChar == '-' && textBox4->Text->Length == 0)
				 {
					 if (textBox4->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
				 return;

			 e->Handled = true;
		 }
private: System::Void textBox5_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox5->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Error");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox5->Text->Length == 0)
				 {
					 if (textBox5->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
				 return;

			 e->Handled = true;
		 }
private: System::Void textBox6_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox6->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Error");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox6->Text->Length == 0)
				 {
					 if (textBox6->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
				 return;

			 e->Handled = true;
		 }
private: System::Void textBox7_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		 {
			 if (textBox7->Text->Length < 13)
			 {
				 if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
					 return;
				 if (e->KeyChar == ',' || e->KeyChar == '.')
				 {
					 MessageBox::Show("Error");
					 e->Handled = true;
				 }
				 if (e->KeyChar == '-' && textBox7->Text->Length == 0)
				 {
					 if (textBox7->Text->IndexOf('-') != -1)
						 e->Handled = true;
					 return;
				 }
			 }
			 if (Char::IsControl(e->KeyChar))
					 return;

			 e->Handled = true;
		 }
	
};
}

