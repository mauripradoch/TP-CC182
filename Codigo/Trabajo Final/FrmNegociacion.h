#pragma once

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmNegociacion
	/// </summary>
	public ref class FrmNegociacion : public System::Windows::Forms::Form
	{
		array<String^>^ dialogos;
		Int16 cont;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ gbxBotones;
	private: System::Windows::Forms::Button^ btnAtras;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ lblAssasin;

	public:
		FrmNegociacion(void)
		{
			InitializeComponent();
			dialogos = gcnew array<String^>(12);
			dialogos[0] = "¡Caímos ante el gobernante!";
			dialogos[1] = "Sabía que iban a fallar.";
			dialogos[2] = "¿Nos ayudan a eliminarlo?";
			dialogos[3] = "No les saldrá gratis.";
			dialogos[4] = "¿Cuánto dinero desean?";
			dialogos[5] = "No queremos dinero.";
			dialogos[6] = "¡¿Entonces que es lo que piden?!";
			dialogos[7] = "Deseo la cabeza de un tripulante.";
			dialogos[8] = "Está bien, está bien. Yo te la daré.";
			dialogos[9] = "Entonces quedamos así. No nos decepciones.";
			dialogos[10] = "Vale. Gracias amigos Assasins";
			dialogos[11] = "De nada, corruptos.";
			cont = -1;
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Boolean fin()
		{
			return (cont == 12);
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmNegociacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblCorrupt;

	private: System::Windows::Forms::Button^ btnSiguiente;
	protected:
	private: System::ComponentModel::IContainer^ components;

	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmNegociacion::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblCorrupt = (gcnew System::Windows::Forms::Label());
			this->btnSiguiente = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->gbxBotones = (gcnew System::Windows::Forms::GroupBox());
			this->btnAtras = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->lblAssasin = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->gbxBotones->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmNegociacion::timer1_Tick);
			// 
			// lblCorrupt
			// 
			this->lblCorrupt->AutoSize = true;
			this->lblCorrupt->BackColor = System::Drawing::Color::White;
			this->lblCorrupt->ForeColor = System::Drawing::Color::Peru;
			this->lblCorrupt->Location = System::Drawing::Point(114, 88);
			this->lblCorrupt->Name = L"lblCorrupt";
			this->lblCorrupt->Size = System::Drawing::Size(67, 13);
			this->lblCorrupt->TabIndex = 0;
			this->lblCorrupt->Text = L"Hola assasin";
			// 
			// btnSiguiente
			// 
			this->btnSiguiente->Location = System::Drawing::Point(552, 19);
			this->btnSiguiente->Name = L"btnSiguiente";
			this->btnSiguiente->Size = System::Drawing::Size(75, 23);
			this->btnSiguiente->TabIndex = 1;
			this->btnSiguiente->Text = L"Siguiente";
			this->btnSiguiente->UseVisualStyleBackColor = true;
			this->btnSiguiente->Click += gcnew System::EventHandler(this, &FrmNegociacion::btnSiguiente_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(21, 213);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(215, 313);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// gbxBotones
			// 
			this->gbxBotones->Controls->Add(this->btnAtras);
			this->gbxBotones->Controls->Add(this->btnSiguiente);
			this->gbxBotones->Location = System::Drawing::Point(12, 532);
			this->gbxBotones->Name = L"gbxBotones";
			this->gbxBotones->Size = System::Drawing::Size(901, 53);
			this->gbxBotones->TabIndex = 3;
			this->gbxBotones->TabStop = false;
			// 
			// btnAtras
			// 
			this->btnAtras->Location = System::Drawing::Point(237, 19);
			this->btnAtras->Name = L"btnAtras";
			this->btnAtras->Size = System::Drawing::Size(75, 23);
			this->btnAtras->TabIndex = 2;
			this->btnAtras->Text = L"Atrás";
			this->btnAtras->UseVisualStyleBackColor = true;
			this->btnAtras->Click += gcnew System::EventHandler(this, &FrmNegociacion::btnAtras_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(650, 213);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(215, 313);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// lblAssasin
			// 
			this->lblAssasin->AutoSize = true;
			this->lblAssasin->BackColor = System::Drawing::Color::White;
			this->lblAssasin->ForeColor = System::Drawing::Color::Red;
			this->lblAssasin->Location = System::Drawing::Point(522, 88);
			this->lblAssasin->Name = L"lblAssasin";
			this->lblAssasin->Size = System::Drawing::Size(65, 13);
			this->lblAssasin->TabIndex = 5;
			this->lblAssasin->Text = L"Hola corrupt";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(491, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(299, 228);
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(74, 12);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(299, 228);
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			// 
			// FrmNegociacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(926, 586);
			this->ControlBox = false;
			this->Controls->Add(this->lblCorrupt);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->lblAssasin);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->gbxBotones);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FrmNegociacion";
			this->Text = L"Negociación";
			this->Load += gcnew System::EventHandler(this, &FrmNegociacion::FrmNegociacion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->gbxBotones->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		if (cont < 0)
		{
			btnAtras->Enabled = false;
		}
		else
		{
			btnAtras->Enabled = true;
		}
		if (cont < 0)
			btnSiguiente->Text = "Iniciar";
		else
			if (cont == 11)
				btnSiguiente->Text = "Finalizar";
			else
				btnSiguiente->Text = "Siguiente";
		switch (cont)
		{
		case 0:
			lblCorrupt->Text = dialogos[0];
			lblAssasin->Text = "";
			break;
		case 1:
			lblCorrupt->Text = dialogos[0];
			lblAssasin->Text = dialogos[1];
			break;
		case 2:
			lblCorrupt->Text = dialogos[2];
			lblAssasin->Text = "";
			break;
		case 3:
			lblCorrupt->Text = dialogos[2];
			lblAssasin->Text = dialogos[3];
			break;
		case 4:
			lblCorrupt->Text = dialogos[4];
			lblAssasin->Text = "";
			break;
		case 5:
			lblCorrupt->Text = dialogos[4];
			lblAssasin->Text = dialogos[5];
			break;
		case 6:
			lblCorrupt->Text = dialogos[6];
			lblAssasin->Text = "";
			break;
		case 7:
			lblCorrupt->Text = dialogos[6];
			lblAssasin->Text = dialogos[7];
			break;
		case 8:
			lblCorrupt->Text = dialogos[8];
			lblAssasin->Text = "";
			break;
		case 9:
			lblCorrupt->Text = dialogos[8];
			lblAssasin->Text = dialogos[9];
			break;
		case 10:
			lblCorrupt->Text = dialogos[10];
			lblAssasin->Text = "";
			break;
		case 11:
			lblCorrupt->Text = dialogos[10];
			lblAssasin->Text = dialogos[11];
			break;
		default:
			lblCorrupt->Text = "Hola corrupt";
			lblAssasin->Text = "Hola assasin";
		}
	}
	private: System::Void btnSiguiente_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		++cont;
		Console::Clear();
		Console::Write(cont);
	}
private: System::Void btnAtras_Click(System::Object^ sender, System::EventArgs^ e) 
{
	--cont;
	Console::Clear();
	Console::Write(cont);
}
private: System::Void FrmNegociacion_Load(System::Object^ sender, System::EventArgs^ e) 
{

}
};
}
