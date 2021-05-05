#pragma once
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmYouWin
	/// </summary>
	public ref class FrmYouWin : public System::Windows::Forms::Form
	{	
		Graphics^ animacion;
		BufferedGraphics^ buffer;
		Bitmap^ spriteGob;
		Bitmap^ fondo;
		Int16 fil;
		Int16 col;
		float ancho;
		float alto;
	private: System::Windows::Forms::Timer^ timer1;

		   BufferedGraphicsContext^ espbuffer;
	public:
		FrmYouWin(void)
		{
			InitializeComponent();
			fondo = gcnew Bitmap("victoria.png");
			spriteGob = gcnew Bitmap("gobernante xl.png");
			animacion = CreateGraphics();
			espbuffer = BufferedGraphicsManager::Current;
			buffer = espbuffer->Allocate(animacion, ClientRectangle);
			col = 1;
			ancho = spriteGob->Width / 13;
			alto = spriteGob->Height / 2;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmYouWin()
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
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmYouWin::timer1_Tick);
			// 
			// FrmYouWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(931, 527);
			this->Name = L"FrmYouWin";
			this->Text = L"FrmYouWin";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		Rectangle aVisible = Rectangle(col * ancho, 0, ancho, alto);
		buffer->Graphics->Clear(SystemColors::Control);
		buffer->Graphics->DrawImage(fondo, 0, 0);
		buffer->Graphics->DrawImage(spriteGob, 460, 300, aVisible, GraphicsUnit::Pixel);
		if (++col > 12)
			col = 1;
		buffer->Render(animacion);
	}
	};
}
