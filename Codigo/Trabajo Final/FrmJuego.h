#pragma once
#include "Clases.hpp"
#include "FrmNegociacion.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmJuego
	/// </summary>
	public ref class FrmJuego : public System::Windows::Forms::Form
	{
	private:
		Controlador^ c;
		Graphics^ lienzo;
		BufferedGraphicsContext^ espacioBuffer;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ opcionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ guardarDatosToolStripMenuItem;


		   BufferedGraphics^ buffer;
	public:
		FrmJuego(Int16 NumAli, UInt16 vidas, Int16 tiempo, Char opclaberinto)
		{
			InitializeComponent();
			c = gcnew Controlador(NumAli, vidas, tiempo, opclaberinto);
			lienzo = pnlTrabajoFinal->CreateGraphics();
			espacioBuffer = BufferedGraphicsManager::Current;
			buffer = espacioBuffer->Allocate(lienzo, this->ClientRectangle);
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Timer^ getTimer1() { return timer1; }
		Void cargarDatos()
		{
			c->Restaurar();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmJuego()
		{
			delete c;
			delete lienzo;
			delete espacioBuffer;
			delete buffer;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlTrabajoFinal;
	protected:

	private: System::Windows::Forms::Timer^ timer1;
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
			this->pnlTrabajoFinal = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->opcionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guardarDatosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlTrabajoFinal
			// 
			this->pnlTrabajoFinal->Location = System::Drawing::Point(12, 44);
			this->pnlTrabajoFinal->Name = L"pnlTrabajoFinal";
			this->pnlTrabajoFinal->Size = System::Drawing::Size(1159, 565);
			this->pnlTrabajoFinal->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 32;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmJuego::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 10;
			this->timer2->Tick += gcnew System::EventHandler(this, &FrmJuego::timer2_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->opcionesToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1183, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// opcionesToolStripMenuItem
			// 
			this->opcionesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->guardarDatosToolStripMenuItem });
			this->opcionesToolStripMenuItem->Name = L"opcionesToolStripMenuItem";
			this->opcionesToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->opcionesToolStripMenuItem->Text = L"Opciones";
			// 
			// guardarDatosToolStripMenuItem
			// 
			this->guardarDatosToolStripMenuItem->Name = L"guardarDatosToolStripMenuItem";
			this->guardarDatosToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->guardarDatosToolStripMenuItem->Text = L"Guardar datos";
			this->guardarDatosToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmJuego::guardarDatosToolStripMenuItem_Click);
			// 
			// FrmJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1183, 621);
			this->Controls->Add(this->pnlTrabajoFinal);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FrmJuego";
			this->Text = L"Among the Laberinth";
			this->Load += gcnew System::EventHandler(this, &FrmJuego::FrmJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmJuego::FrmJuego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmJuego::FrmJuego_KeyUp);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		buffer->Graphics->Clear(SystemColors::Control);
		c->fotograma(buffer->Graphics);
		c->temporizador(buffer->Graphics, timer1, timer2);
		c->colisones();
		c->ganar(timer1, timer2);
		c->findeljuego(timer1, timer2);
		buffer->Render(lienzo);
	}
	private: System::Void FrmJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		c->accionesConTecla(e);
	}
	private: System::Void FrmJuego_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		c->soltarTecla();
	}
	private: System::Void FrmJuego_Load(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		c->negociacion(timer1);
		c->pocaVida();
		c->usoPortales();
	}
private: System::Void guardarDatosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	c->guardar();
}
};
}