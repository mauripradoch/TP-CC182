#pragma once

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmGameOver
	/// </summary>
	public ref class FrmGameOver : public System::Windows::Forms::Form
	{
		Graphics^ animacion;
		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ espbuffer;
		Bitmap^ spriteEne;
		Bitmap^ fondo;
		Int16 fil;
		Int16 col;
		float ancho;
	private: System::Windows::Forms::Timer^ timer1;
		   float alto;
	public:
		FrmGameOver(void)
		{
			InitializeComponent();
			fondo = gcnew Bitmap("derrota.png");
			spriteEne = gcnew Bitmap("enemigo xl.png");
			animacion = CreateGraphics();
			espbuffer = BufferedGraphicsManager::Current;
			buffer = espbuffer->Allocate(animacion, ClientRectangle);
			col = 1;
			ancho = spriteEne->Width / 13;
			alto = spriteEne->Height / 2;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmGameOver()
		{
			if (components)
			{
				delete components;
			}
		}
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 32;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmGameOver::timer1_Tick);
			// 
			// FrmGameOver
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(931, 527);
			this->Name = L"FrmGameOver";
			this->Text = L"Derrota";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		Rectangle aVisible = Rectangle(col * ancho, 0, ancho, alto);
		Rectangle aVisible2 = Rectangle(col * ancho, alto, ancho, alto);
		buffer->Graphics->Clear(SystemColors::Control);
		buffer->Graphics->DrawImage(fondo, 0, 0);
		buffer->Graphics->DrawImage(spriteEne, 380, 300, aVisible, GraphicsUnit::Pixel);
		buffer->Graphics->DrawImage(spriteEne, 500, 300, aVisible2, GraphicsUnit::Pixel);
		if (++col > 12)
			col = 1;
		buffer->Render(animacion);
	}
	};
}
