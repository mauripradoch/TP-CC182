#pragma once
#include "FrmJuego.h"
#include "FrmPresentacion.h"
#include "FrmCreditos.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmInicio
	/// </summary>
	public ref class FrmInicio : public System::Windows::Forms::Form
	{
		FrmJuego^ juego;
		FrmPresentacion^ presentacion;
		FrmCreditos^ creditos;
		Char opclaberinto;
		Boolean opcCargar;
	private: System::Windows::Forms::Button^ btnCargar;

	private: System::Windows::Forms::ToolStripMenuItem^ créditosToolStripMenuItem;
	public:
		FrmInicio(void)
		{
			InitializeComponent();
			opclaberinto = ' ';
			opcCargar = false;
			presentacion = gcnew FrmPresentacion();
			creditos = gcnew FrmCreditos();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmInicio()
		{
			if (components)
			{
				delete components;
			}
			delete juego;
			delete presentacion;
			delete creditos;
		}
	private: System::Windows::Forms::Label^ lblTitulo;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ npdNumAliados;
	private: System::Windows::Forms::Button^ btnIniciar;
	private: System::Windows::Forms::Label^ lblVida;
	private: System::Windows::Forms::NumericUpDown^ npdVida;
	private: System::Windows::Forms::MenuStrip^ menuOpciones;
	private: System::Windows::Forms::ToolStripMenuItem^ opcionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ presentaciónToolStripMenuItem;

	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::NumericUpDown^ npdTiempo;

	private: System::Windows::Forms::RadioButton^ rbnDefecto;
	private: System::Windows::Forms::RadioButton^ rbnAleatorio;
	private: System::Windows::Forms::Label^ lblLaberinto;







	private: System::ComponentModel::IContainer^ components;

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
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->npdNumAliados = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->lblVida = (gcnew System::Windows::Forms::Label());
			this->npdVida = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuOpciones = (gcnew System::Windows::Forms::MenuStrip());
			this->opcionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->presentaciónToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->créditosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->npdTiempo = (gcnew System::Windows::Forms::NumericUpDown());
			this->rbnDefecto = (gcnew System::Windows::Forms::RadioButton());
			this->rbnAleatorio = (gcnew System::Windows::Forms::RadioButton());
			this->lblLaberinto = (gcnew System::Windows::Forms::Label());
			this->btnCargar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->npdNumAliados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->npdVida))->BeginInit();
			this->menuOpciones->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->npdTiempo))->BeginInit();
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Broadway", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::Red;
			this->lblTitulo->Location = System::Drawing::Point(146, 73);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(257, 24);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Among the Laberinth";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Crimson;
			this->label1->Location = System::Drawing::Point(120, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Número de aliados:";
			// 
			// npdNumAliados
			// 
			this->npdNumAliados->Location = System::Drawing::Point(315, 147);
			this->npdNumAliados->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->npdNumAliados->Name = L"npdNumAliados";
			this->npdNumAliados->Size = System::Drawing::Size(120, 20);
			this->npdNumAliados->TabIndex = 3;
			this->npdNumAliados->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// btnIniciar
			// 
			this->btnIniciar->Location = System::Drawing::Point(179, 359);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(75, 23);
			this->btnIniciar->TabIndex = 4;
			this->btnIniciar->Text = L"Iniciar";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &FrmInicio::btnIniciar_Click);
			// 
			// lblVida
			// 
			this->lblVida->AutoSize = true;
			this->lblVida->ForeColor = System::Drawing::Color::Crimson;
			this->lblVida->Location = System::Drawing::Point(120, 193);
			this->lblVida->Name = L"lblVida";
			this->lblVida->Size = System::Drawing::Size(82, 13);
			this->lblVida->TabIndex = 5;
			this->lblVida->Text = L"Puntos de Vida:";
			// 
			// npdVida
			// 
			this->npdVida->Location = System::Drawing::Point(315, 191);
			this->npdVida->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->npdVida->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->npdVida->Name = L"npdVida";
			this->npdVida->Size = System::Drawing::Size(120, 20);
			this->npdVida->TabIndex = 6;
			this->npdVida->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// menuOpciones
			// 
			this->menuOpciones->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->opcionesToolStripMenuItem });
			this->menuOpciones->Location = System::Drawing::Point(0, 0);
			this->menuOpciones->Name = L"menuOpciones";
			this->menuOpciones->Size = System::Drawing::Size(558, 24);
			this->menuOpciones->TabIndex = 7;
			this->menuOpciones->Text = L"menuStrip1";
			// 
			// opcionesToolStripMenuItem
			// 
			this->opcionesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->presentaciónToolStripMenuItem,
					this->créditosToolStripMenuItem
			});
			this->opcionesToolStripMenuItem->Name = L"opcionesToolStripMenuItem";
			this->opcionesToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->opcionesToolStripMenuItem->Text = L"Opciones";
			// 
			// presentaciónToolStripMenuItem
			// 
			this->presentaciónToolStripMenuItem->Name = L"presentaciónToolStripMenuItem";
			this->presentaciónToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->presentaciónToolStripMenuItem->Text = L"Presentación";
			this->presentaciónToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmInicio::presentaciónToolStripMenuItem_Click);
			// 
			// créditosToolStripMenuItem
			// 
			this->créditosToolStripMenuItem->Name = L"créditosToolStripMenuItem";
			this->créditosToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->créditosToolStripMenuItem->Text = L"Créditos";
			this->créditosToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmInicio::créditosToolStripMenuItem_Click);
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->ForeColor = System::Drawing::Color::Crimson;
			this->lblTiempo->Location = System::Drawing::Point(120, 243);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(45, 13);
			this->lblTiempo->TabIndex = 8;
			this->lblTiempo->Text = L"Tiempo:";
			// 
			// npdTiempo
			// 
			this->npdTiempo->Location = System::Drawing::Point(315, 241);
			this->npdTiempo->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->npdTiempo->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->npdTiempo->Name = L"npdTiempo";
			this->npdTiempo->Size = System::Drawing::Size(120, 20);
			this->npdTiempo->TabIndex = 9;
			this->npdTiempo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// rbnDefecto
			// 
			this->rbnDefecto->AutoSize = true;
			this->rbnDefecto->Location = System::Drawing::Point(250, 288);
			this->rbnDefecto->Name = L"rbnDefecto";
			this->rbnDefecto->Size = System::Drawing::Size(80, 17);
			this->rbnDefecto->TabIndex = 10;
			this->rbnDefecto->TabStop = true;
			this->rbnDefecto->Text = L"Por defecto";
			this->rbnDefecto->UseVisualStyleBackColor = true;
			this->rbnDefecto->CheckedChanged += gcnew System::EventHandler(this, &FrmInicio::rbnDefecto_CheckedChanged);
			// 
			// rbnAleatorio
			// 
			this->rbnAleatorio->AutoSize = true;
			this->rbnAleatorio->Location = System::Drawing::Point(413, 288);
			this->rbnAleatorio->Name = L"rbnAleatorio";
			this->rbnAleatorio->Size = System::Drawing::Size(66, 17);
			this->rbnAleatorio->TabIndex = 11;
			this->rbnAleatorio->TabStop = true;
			this->rbnAleatorio->Text = L"Aleatorio";
			this->rbnAleatorio->UseVisualStyleBackColor = true;
			this->rbnAleatorio->CheckedChanged += gcnew System::EventHandler(this, &FrmInicio::rbnAleatorio_CheckedChanged);
			// 
			// lblLaberinto
			// 
			this->lblLaberinto->AutoSize = true;
			this->lblLaberinto->ForeColor = System::Drawing::Color::Crimson;
			this->lblLaberinto->Location = System::Drawing::Point(120, 290);
			this->lblLaberinto->Name = L"lblLaberinto";
			this->lblLaberinto->Size = System::Drawing::Size(54, 13);
			this->lblLaberinto->TabIndex = 12;
			this->lblLaberinto->Text = L"Laberinto:";
			// 
			// btnCargar
			// 
			this->btnCargar->Location = System::Drawing::Point(315, 359);
			this->btnCargar->Name = L"btnCargar";
			this->btnCargar->Size = System::Drawing::Size(75, 23);
			this->btnCargar->TabIndex = 13;
			this->btnCargar->Text = L"Cargar";
			this->btnCargar->UseVisualStyleBackColor = true;
			this->btnCargar->Click += gcnew System::EventHandler(this, &FrmInicio::btnCargar_Click);
			// 
			// FrmInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 430);
			this->Controls->Add(this->btnCargar);
			this->Controls->Add(this->lblLaberinto);
			this->Controls->Add(this->rbnAleatorio);
			this->Controls->Add(this->rbnDefecto);
			this->Controls->Add(this->npdTiempo);
			this->Controls->Add(this->lblTiempo);
			this->Controls->Add(this->npdVida);
			this->Controls->Add(this->lblVida);
			this->Controls->Add(this->btnIniciar);
			this->Controls->Add(this->npdNumAliados);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->menuOpciones);
			this->MaximizeBox = false;
			this->Name = L"FrmInicio";
			this->Text = L"Among the Laberinth";
			this->Load += gcnew System::EventHandler(this, &FrmInicio::FrmInicio_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->npdNumAliados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->npdVida))->EndInit();
			this->menuOpciones->ResumeLayout(false);
			this->menuOpciones->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->npdTiempo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Int16 numaliados;
		Int16 vida;
		Int16 tiempo;
		if (opclaberinto != ' ')
		{
			numaliados = Convert::ToInt16(npdNumAliados->Text);
			vida = Convert::ToInt16(npdVida->Text);
			tiempo = Convert::ToInt16(npdTiempo->Text);
			juego = gcnew FrmJuego(numaliados, vida, tiempo, opclaberinto);
			if (opcCargar)
				juego->cargarDatos();
			juego->Show();
		}
	}
	private: System::Void FrmInicio_Load(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void rbnDefecto_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		opclaberinto = 'D';
	}
	private: System::Void rbnAleatorio_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		opclaberinto = 'A';
	}
	private: System::Void presentaciónToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		presentacion = gcnew FrmPresentacion();
		presentacion->Show();
	}
private: System::Void créditosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	creditos = gcnew FrmCreditos();
	creditos->Show();
}

private: System::Void btnCargar_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (opcCargar)
	{
		opcCargar = false;
		btnCargar->Text = "Cargar";
		rbnAleatorio->Enabled = true;
	}
	else
	{
		opcCargar = true;
		btnCargar->Text = "No cargar";
		rbnAleatorio->Enabled = false;
	}
}
};
}
