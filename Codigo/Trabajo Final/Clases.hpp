#pragma once
#include <ctime>
#include <fstream>
#include "FrmNegociacion.h"
#include "FrmYouWin.h"
#include "FrmGameOver.h"
#define casilla_ancho 30
#define casilla_alto 50
using namespace TrabajoFinal;
using namespace cli;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::endl;
template <typename G>
ref struct Nodo 
{
	G valor;
	Nodo<G>^ sig;
	Nodo(G v) { valor = v; }
	Nodo(G v, Nodo^ s) { valor = v; sig = s; }
};
template <class G>
ref class Lista 
{
	Nodo<G>^ inicio;
	Nodo<G>^ fin;
	unsigned long cantidad;
public:
	Lista() 
	{
		inicio = fin = nullptr;

		cantidad = 0;
	}
	unsigned long getCantidad() { return cantidad; }
	
	G obtenerValorPos(unsigned long pos) 
	{
		Nodo<G>^ aux = inicio;
		for (long i = 0; i < pos; ++i)
		{
			aux = aux->sig;
		}
		return aux->valor;
	}
	G operator[] (unsigned long pos)
	{
		return obtenerValorPos(pos);
	}
	void push_back(G valor) 
	{
		
		Nodo<G>^ nuevo = gcnew Nodo<G>(valor);
		if (cantidad==0)
			inicio = nuevo;
		else
			fin->sig = nuevo;
		fin = nuevo;
		++cantidad;
	}
};
template <typename G>
ref struct NodoDoble
{
	G valor;
	NodoDoble<G>^ sig;
	NodoDoble<G>^ ant;
	NodoDoble(G v)
	{
		valor = v;
		sig = nullptr;
		ant = nullptr;
	}
	NodoDoble(G v, NodoDoble^ s, NodoDoble^ a) :valor(v), sig(s), ant(a) {}
};
template <class G>
ref class ListaDoble
{
	NodoDoble<G>^ inicio;
	NodoDoble<G>^ fin;
	unsigned long cantidad;
public:
	ListaDoble()
	{
		inicio = fin = nullptr;      
		cantidad = 0;
	}
	unsigned long getCantidad() { return cantidad; }
	void delete_front()
	{
		NodoDoble<G>^ aux;
		if (cantidad == 0)
			return;
		else if (cantidad == 1)
			fin = nullptr;
		aux = inicio;
		inicio = inicio->sig;
		delete aux;
		--cantidad;
	}
	void insert_pos(G valor, long pos)
	{
		if (pos=0)
			push_back(valor);
		else if (pos >= cantidad)
			push_back(valor);
		else 
		{
			NodoDoble<G>^ nuevo = new NodoDoble<G>(valor);
			NodoDoble<G>^ aux = inicio;
			for (long i = 0; i <= pos; ++i) 
			{
				aux = aux->sig;
			}
			nuevo->sig = aux;
			nuevo->ant = aux->ant;
			aux->ant->sig = nuevo;
			aux->ant = nuevo;
			++cantidad;
		}
	}
	void push_back(G valor) 
	{
		NodoDoble<G>^ nuevo = gcnew NodoDoble<G>(valor);
		if (cantidad == 0)
			inicio = nuevo;
		else 
		{
			nuevo->ant = fin;
			fin->sig = nuevo;
		}
		fin = nuevo;
		++cantidad;
	}
	void delete_pos(long pos) 
	{
		if (cantidad <= 0)
			return;
		else if (cantidad == 1)
			delete_front();
		else
		{
			NodoDoble<G>^ aux = inicio;
			for (long i = 0; i < pos; ++i)
			{
				aux = aux->sig;
			}
			aux->ant->sig = aux->sig;
			aux->sig->ant = aux->ant;
			--cantidad;
		}
	}
	G obtenerValorPos(unsigned long pos) 
	{
		NodoDoble<G>^ aux = inicio;
		for (long i = 0; i < pos; ++i)
		{
			aux = aux->sig;
		}
		return aux->valor;
	}
	G operator[] (unsigned long pos)
	{
		return obtenerValorPos(pos);
	}
};
ref class UbiCasilla
{
	Int16 x;
	Int16 y;
public:
	UbiCasilla(Int16 x, Int16 y)
		:x(x), y(y)
	{
		
	}
	Int16 getX() { return x; }
	Int16 getY() { return y; }
};
ref class UbiCasillas
{
	Int16 cont;
	Lista<UbiCasilla^>^ lisUbi;
public:
	UbiCasillas()
	{
		cont = 0;
		lisUbi = gcnew Lista<UbiCasilla^>();
	}
	~UbiCasillas()
	{
		delete lisUbi;
	}
	Int16 getCont() { return cont; }
	Void agregar(Int16 x, Int16 y)
	{
		lisUbi->push_back(gcnew UbiCasilla(x, y));
	}
	Boolean colisona(Rectangle posJ)
	{
		Rectangle aux;
		for (Int16 i = 0; i < lisUbi->getCantidad(); ++i)
		{
			aux = Rectangle(lisUbi[i]->getX(), lisUbi[i]->getY(), 30, 50);
			if (posJ.IntersectsWith(aux))
			{
				return false;
				break;
			}
		}
		return true;
	}
	UbiCasilla^ obtenerCasilla(Int16 pos) { return lisUbi->obtenerValorPos(pos); }
};
ref class Laberinto
{
	array<array<Int16>^>^ matriz;
	Random r;
	Int16 entrada;
	Int16 salida;
	Int16 fils;
	Int16 cols;
	Int16 xLlegada;
	Int16 yLlegada;
	Char opclaberinto;
	UbiCasillas^ ubiLava;
	UbiCasillas^ ubiRojas;
	UbiCasillas^ portales;
public:
	Laberinto(Char opclaberinto) :opclaberinto(opclaberinto)
	{
		Int16 c1 = 0, c2 = 0;
		Int16 tmp = casilla_ancho + 1;
		Int16 tmp2 = casilla_alto + 1;
		fils = 11;
		cols = 20;
		matriz = gcnew array<array<Int16>^>(fils);
		for (Int16 i = 0; i < fils; ++i)
		{
			matriz[i] = gcnew array<Int16>(cols);
		}
		ubiLava = gcnew UbiCasillas();
		portales = gcnew UbiCasillas();
		ubiRojas = gcnew UbiCasillas();
		switch (opclaberinto)
		{
		case 'D':
			laberintoDefecto();
			break;
		case 'A':
			laberintoAleatorio();
			break;
		}
		for (Int16 i = 0; i < fils; ++i)
		{
			for (Int16 j = 0; j < cols; ++j)
			{
				switch (matriz[i][j])
				{
				case 0:
					ubiLava->agregar(c1, c2);
					break;
				case 1:
					ubiRojas->agregar(c1, c2);
					break;
				case 2:
					xLlegada = c1;
					yLlegada = c2;
				}
				c1 += tmp;
			}
			c2 += tmp2;
			c1 = 0;
		}
	}
	~Laberinto()
	{
		delete matriz;
		delete ubiLava;
		delete ubiRojas;
		delete portales;
	}
	Int16 getEntrada() { return entrada; }
	Int16 getSalida() { return salida; }
	Int16 getXLlegada() { return xLlegada; }
	Int16 getYLlegada() { return yLlegada; }
	UbiCasillas^ getUbiLava() { return ubiLava; }
	UbiCasillas^ getPortales() { return portales; }
	UbiCasillas^ getUbiVerdes() { return ubiRojas; }
	Void laberintoDefecto()
	{
		Int16 c1 = 0, c2 = 0;
		Int16 tmp = casilla_ancho + 1;
		Int16 tmp2 = casilla_alto + 1;
		short ma[11][20] = { {0,1,1,2,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1},
							 {0,1,0,0,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1},
							 {0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1},
							 {0,1,0,0,1,1,1,1,1,1,1,1,0,0,0,1,0,1,0,1},
							 {0,1,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,0,1},
							 {0,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0},
							 {0,1,0,1,0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,0},
							 {0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
							 {0,1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
							 {0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
							 {0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0} };
		for (Int16 i = 0; i < 11; ++i)
		{
			for (Int16 j = 0; j < 20; ++j)
			{
				matriz[i][j] = ma[i][j];
			}
		}
		entrada = 3;
		salida = 7;

	}
	Void laberintoAleatorio() 
	{
		for (Int16 i = 0; i < fils; ++i)
		{
			for (Int16 j = 0; j < cols; ++j)
			{
				matriz[i][j] = r.Next(0, 2);
			}
		}
		entrada = r.Next(0, cols);
		salida = r.Next(0, cols);
		matriz[0][entrada] = 2;
		matriz[fils - 1][salida] = 2;
	}
	Void mostrar(Graphics^ lienzo)
	{
		Int16 c1 = 0, c2 = 0;
		Brush^ brocha;
		Int16 tmp = casilla_ancho + 1;
		Int16 tmp2 = casilla_alto + 1;
		for (Int16 i = 0; i < fils; ++i)
		{
			for (Int16 j = 0; j < cols; ++j)
			{
				switch (matriz[i][j])
				{
				case 1:
					brocha = Brushes::DarkRed;
					break;
				case 2:
					brocha = Brushes::Blue;
					break;
				case 3:
					brocha = Brushes::Purple;
				}
				if (matriz[i][j] > 0)
					lienzo->FillRectangle(brocha, c1, c2, casilla_ancho, casilla_alto);
				c1 += tmp;
			}
			c2 += tmp2;
			c1 = 0;
		}
	}
	Void activarPortales()
	{
		Int16 c1 = 0, c2 = 0;
		Int16 tmp = casilla_ancho + 1;
		Int16 tmp2 = casilla_alto + 1;
		Int16 v1, v2;
		switch (opclaberinto)
		{
		case 'D':
			matriz[5][5] = 3;
			matriz[4][19] = 3;
			break;
		case 'A':
			for (Int16 i = 1; i <= 2; ++i)
			{
				while (matriz[v1][v2] != 1 || matriz[v1][v2]==3)
				{
					v1 = r.Next(0, 11);
					v2 = r.Next(0, 20);
				}
				matriz[v1][v2] = 3;
			}
			break;
		}
		for (Int16 i = 0; i < fils; ++i)
		{
			for (Int16 j = 0; j < cols; ++j)
			{
				if (matriz[i][j] == 3)
					portales->agregar(c1, c2);
				c1 += tmp;
			}
			c2 += tmp2;
			c1 = 0;
		}
	}
};
ref class Personaje
{
protected:
	Bitmap^ spriteSheet;
	Rectangle aVisible;
	Int16 x;
	Int16 y;
	Int16 dx;
	Int16 dy;
	Int16 fil;
	Int16 col;
	Int16 maxcol;
	float ancho;
	float alto;
	Boolean walking;
public:
	Personaje(Int16 x, Int16 y) :x(x), y(y)
	{
		walking = false;
	}
	~Personaje()
	{
		delete spriteSheet;
	}
	Int16 getX() { return x; }
	Int16 getY() { return y; }
	Void quieto()
	{
		walking = false;
	}
};
ref class PosicionJ
{
	array<Personaje^>^ capturadora;
	Int16 cont;
public:
	PosicionJ(Int16 x, Int16 y)
	{
		cont = 20;
		capturadora = gcnew array<Personaje^>(cont);
		for (Int16 i = 0; i < cont; ++i)
			capturadora[i] = gcnew Personaje(x, y);
	}
	~PosicionJ()
	{
		delete capturadora;
	}
	Void agregar(Int16 x, Int16 y)
	{
		array<Personaje^>^ aux = gcnew array<Personaje^>(cont);
		Int16 c1 = -1;
		for (Int16 i = 0; i < cont; ++i)
		{
			if (i != 0)
				aux[++c1] = capturadora[i];
		}
		capturadora = aux;
		capturadora[cont - 1] = gcnew Personaje(x, y);
	}
	Personaje^ obtenerCasilla(Int16 pos) { return capturadora[pos]; }
};
ref class Gobernante :public Personaje
{
	Int16 vidas;
	Int16 vInicial;
public:
	Gobernante(Int16 x, Int16 vidas) :Personaje(x, 0), vidas(vidas), vInicial(vidas)
	{
		col = 1;
		spriteSheet = gcnew Bitmap("Gobernante.png");
		ancho = spriteSheet->Width / 13;
		alto = spriteSheet->Height / 2;
		maxcol = 12;
		dx = 5;
		dy = 5;
	}
	void setX(Int16 v) { x = v; }
	void setY(Int16 v) { y = v; }
	Int16 getVidas() { return vidas; }
	Int16 getVInicial() { return vInicial; }
	Rectangle margenColision(Char direccion)
	{
		Rectangle rect;
		switch (direccion)
		{
		case 'U':
			rect = Rectangle(x, y - dy, 25, 40);
			break;
		case 'D':
			rect = Rectangle(x, y + dy, 25, 40);
			break;
		case 'L':
			rect = Rectangle(x - dx, y, 25, 40);
			break;
		case 'R':
			rect = Rectangle(x + dx, y, 25, 40);
			break;
		}
		return rect;
	}
	Rectangle areaRec() { return Rectangle(x, y, 25, 40); }
	Void graficar(Graphics^ lienzo)
	{
		if (walking)
			aVisible = Rectangle(col * ancho, fil * alto, ancho, alto);
		else
			aVisible = Rectangle(0 * ancho, fil * alto, ancho, alto);
		lienzo->DrawImage(spriteSheet, x, y, aVisible, GraphicsUnit::Pixel);
		if (++col > maxcol)
			col = 1;
	}
	Void mover(KeyEventArgs^ e, Laberinto^ l)
	{
		walking = true;
		switch (e->KeyCode)
		{
		case Keys::Up:
			if (y - dy > 0 && l->getUbiLava()->colisona(margenColision('U')))
				y -= dy;
			break;
		case Keys::Down:
			if (y + dy < 520 && l->getUbiLava()->colisona(margenColision('D')))
				y += dy;
			break;
		case Keys::Left:
			fil = 1;
			if (x - dx > 0 && l->getUbiLava()->colisona(margenColision('L')))
				x -= dx;
			break;
		case Keys::Right:
			fil = 0;
			if (x + dx < 590 && l->getUbiLava()->colisona(margenColision('R')))
				x += dx;
		}
	}
	Void restarvida(Int16 num)
	{
		vidas -= num;
	}
	Void teletransportar(Laberinto^ l)
	{
		Rectangle r1, r2;
		r1 = Rectangle(l->getPortales()->obtenerCasilla(0)->getX(), l->getPortales()->obtenerCasilla(0)->getY(), casilla_ancho, casilla_alto);
		r2 = Rectangle(l->getPortales()->obtenerCasilla(1)->getX(), l->getPortales()->obtenerCasilla(1)->getY(), casilla_ancho, casilla_alto);
		if (r1.IntersectsWith(areaRec()))
		{
			x = l->getPortales()->obtenerCasilla(1)->getX() + 5;
			y = l->getPortales()->obtenerCasilla(1)->getY() + 5;
		}
		else if (r2.IntersectsWith(areaRec()))
		{
			x = l->getPortales()->obtenerCasilla(0)->getX() + 5;
			y = l->getPortales()->obtenerCasilla(0)->getY() + 5;
		}
	}
};
ref class Aliado :public Personaje
{
protected:
	Random r;
public:
	Aliado(Int16 x, Int16 y) :Personaje(x, y)
	{
		spriteSheet = gcnew Bitmap("Aliado.png");
		ancho = spriteSheet->Width / 9;
		alto = spriteSheet->Height / 4;
		col = 0;
		fil = 1;
		maxcol = 8;
		dx = 5;
		dy = 5;
		walking = true;
	}
	Void graficar(Graphics^ lienzo)
	{
		aVisible = Rectangle(col * ancho, fil * alto, ancho, alto);
		lienzo->DrawImage(spriteSheet, x - 15, y - 10, aVisible, GraphicsUnit::Pixel);
		if (walking)
			if (++col > maxcol)
				col = 0;
	}
	Rectangle margenColision(Char direccion)
	{
		Rectangle rect;
		switch (direccion)
		{
		case 'U':
			rect = Rectangle(x, y - dy, ancho - 15, alto - 1);
			break;
		case 'D':
			rect = Rectangle(x, y + dy, ancho - 15, alto - 1);
			break;
		case 'L':
			rect = Rectangle(x - dx, y, ancho - 15, alto - 1);
			break;
		case 'R':
			rect = Rectangle(x + dx, y, ancho - 15, alto - 1);
			break;
		}
		return rect;
	}
	Rectangle areaRec() { return Rectangle(x, y, ancho - 15, alto - 1); }
	Void moverse(Laberinto^ l)
	{
		Int32 aux = r.Next(1, 4000001);
		if (aux <= 1000000)
		{
			if (y - dy > 0 && l->getUbiLava()->colisona(margenColision('U')))
			{
				fil = 0;
				y -= dy;
			}
		}
		if (aux > 1000000 && aux <= 2000000)
		{
			if (y + dy < 520 && l->getUbiLava()->colisona(margenColision('D')))
			{
				fil = 2;
				y += dy;
			}
		}
		if (aux > 2000000 && aux <= 3000000)
		{
			if (x - dx > 0 && l->getUbiLava()->colisona(margenColision('L')))
			{
				fil = 1;
				x -= dx;
			}
		}
		if (aux > 300000)
		{
			if (x + dx < 590 && l->getUbiLava()->colisona(margenColision('R')))
			{
				fil = 3;
				x += dx;
			}
		}
	}
};
ref class AliadoSeguidor :public Aliado
{
public:
	AliadoSeguidor(Int16 x, Int16 y, Int16 col) :Aliado(x, y)
	{
		spriteSheet = gcnew Bitmap("aliado2.png");
		fil = 3;
		this->col = col;
		walking = false;
	}
	Void moverse(Personaje^ f)
	{
		walking = true;
		x = f->getX();
		y = f->getY();
	}
};
ref class Corrupt :public Personaje 
{
protected:
	Random r;
	Int32 xf;
	Int32 yf;
public:
	Corrupt(Int32 _x, Int32 _y) :Personaje(_x, _y) {
		spriteSheet = gcnew Bitmap("Enemigo.png");
		ancho = spriteSheet->Width / 13;
		alto = spriteSheet->Height / 2;
		fil = col = 0;
		xf = r.Next(0, 800);
		yf = r.Next(0, 700);
		maxcol = 11;
	}
	Rectangle areaRec() { return Rectangle(x, y, 25, 40); }
	Void graficar(Graphics^ lienzo)
	{
		aVisible = Rectangle((col + 1) * ancho, fil * alto, ancho, alto);
		lienzo->DrawImage(spriteSheet, x, y, aVisible, GraphicsUnit::Pixel);
		if (++col > maxcol)
			col = 0;
	}
	Void aleatorio() 
	{
		if (Math::Abs(xf - x) <= 5 && Math::Abs(yf - y)) {
			xf = r.Next(0, 800);
			yf = r.Next(0, 700);

		}
		int c1 = xf - x;
		int c2 = yf - y;
		int h = Math::Sqrt(c1 * c1 + c2 * c2);
		double C = 3.0 / h;
		dx = c1 * C;
		dy = c2 * C;
		x += dx;
		y += dy;
	}
};
ref class Assasin :public Corrupt
{
public:
	Assasin(Int16 _x, Int16 _y):Corrupt(_x,_y)
	{
		dx = 10;
		dy = 10;
	}
	Void aleatorio() {

		if (Math::Abs(xf - x) <= 5 && Math::Abs(yf - y)) {
			xf = r.Next(0, 800);
			yf = r.Next(0, 700);

		}
		int c1 = xf - x;
		int c2 = yf - y;
		int h = Math::Sqrt(c1 * c1 + c2 * c2);
		double C = 5.5 / h;
		dx = c1 * C;
		dy = c2 * C;

		x += dx;
		y += dy;
	}
};
ref class Aliados
{
	ListaDoble<Aliado^>^ lisDoAl;
	Int16 NumAli;
	Random r;
public:
	Aliados(Int16 NumAli, Laberinto^ l):NumAli(NumAli)
	{
		Int16 x, y;
		Int16 cantidad = l->getUbiVerdes()->getCont();
		Int16 pos;
		lisDoAl = gcnew ListaDoble<Aliado^>();
		for (Int16 i = 0; i < NumAli; ++i)
		{
			pos = r.Next(0, cantidad);
			x = l->getUbiVerdes()->obtenerCasilla(pos)->getX();
			y = l->getUbiVerdes()->obtenerCasilla(pos)->getY();
			lisDoAl->push_back(gcnew Aliado(x, y));
		}
	}
	~Aliados()
	{
		delete lisDoAl;
	}
	unsigned long getNumAli() { return lisDoAl->getCantidad(); }
	Void graficar(Graphics^ lienzo)
	{
		for (Int16 i = 0; i < lisDoAl->getCantidad(); ++i)
		{
			lisDoAl[i]->graficar(lienzo);
		}
	}
	Void eliminar(Int16 pos)
	{
		lisDoAl->delete_pos(pos);
	}
	Void movimiento(Laberinto^ l)
	{
		for (Int16 i = 0; i < NumAli; ++i)
			lisDoAl->obtenerValorPos(i)->moverse(l);
	}
	ListaDoble<Aliado^>^ obtenerLista() { return lisDoAl; }
};
ref class AliadosSeguidores
{
	Lista<AliadoSeguidor^>^ lisAlSeg;
	PosicionJ^ posJ;
	Int16 cantidad;
	Random r;
public:
	AliadosSeguidores(Int16 x, Int16 y)
	{
		cantidad = 2;
		lisAlSeg = gcnew Lista<AliadoSeguidor^>();
		posJ = gcnew PosicionJ(x, y);
		for (Int16 i = 0; i < cantidad; ++i)
			lisAlSeg->push_back(gcnew AliadoSeguidor(x, y, r.Next(0, 9)));
	}
	~AliadosSeguidores()
	{
		delete lisAlSeg;
		delete posJ;
	}
	Void setPosJ(PosicionJ^ v) { posJ = v; }
	Void capturarPosJ(Int16 x, Int16 y)
	{
		posJ->agregar(x, y);
	}
	Void graficar(Graphics^ lienzo)
	{
		for (Int16 i = 0; i < cantidad; ++i)
			lisAlSeg[i]->graficar(lienzo);
	}
	Void movimiento()
	{
		lisAlSeg->obtenerValorPos(0)->moverse(posJ->obtenerCasilla(5));
		lisAlSeg->obtenerValorPos(1)->moverse(posJ->obtenerCasilla(12));
	}
	Void quietos()
	{
		for (Int16 i = 0; i < cantidad; ++i)
			lisAlSeg[i]->quieto();
	}
};
ref class AliadosImpostores
{
	ListaDoble<Aliado^>^ lisDoImpostores;
	Int16 NumAli;
public:
	AliadosImpostores(Int16 NumAli):NumAli(NumAli)
	{
		lisDoImpostores = gcnew ListaDoble<Aliado^>();
	}
	~AliadosImpostores()
	{
		delete lisDoImpostores;
	}
	Void agregar(Aliado^ a)
	{
		if (lisDoImpostores->getCantidad() < NumAli)
			lisDoImpostores->push_back(a);
	}
	Void transformar(Aliados^ as)
	{
		Rectangle r1, r2;
		ListaDoble<Aliado^>^ aux = as->obtenerLista();
		if (as->getNumAli() > 0)
			for (Int16 i = 0; i < lisDoImpostores->getCantidad(); ++i)
			{
				r1 = lisDoImpostores->obtenerValorPos(i)->areaRec();
				for (Int16 j = 0; j < aux->getCantidad(); ++j)
				{
					r2 = aux->obtenerValorPos(j)->areaRec();
					if (r1.IntersectsWith(r2))
					{
						agregar(aux->obtenerValorPos(j));
						as->eliminar(j);
					}
				}
			}
	}
	Void graficar(Graphics^ lienzo)
	{
		for (Int16 i = 0; i < lisDoImpostores->getCantidad(); ++i)
		{
			lisDoImpostores[i]->graficar(lienzo);
		}
	}
	Void eliminar(Int16 pos)
	{
		lisDoImpostores->delete_pos(pos);
	}
	Void movimiento(Laberinto^ l)
	{
		for (Int16 i = 0; i < lisDoImpostores->getCantidad(); ++i)
			lisDoImpostores->obtenerValorPos(i)->moverse(l);
	}
	Boolean kamikaze(Rectangle areaJ)
	{
		for (Int16 i = 0; i < lisDoImpostores->getCantidad(); ++i)
		{
			if (lisDoImpostores[i]->areaRec().IntersectsWith(areaJ))
			{
				eliminar(i);
				return true;
				break;
			}
		}
		return false;
	}
};
ref class Corrupts
{
	ListaDoble<Corrupt^>^ lisDoCor;
	Random r;
	Int16 cantidad;
public:
	Corrupts(Int16 num)
	{
		cantidad = num;
		lisDoCor = gcnew ListaDoble<Corrupt^>();
		for (Int16 i = 0; i < cantidad; ++i)
		{
			lisDoCor->push_back(gcnew Corrupt(r.Next(0, 500), r.Next(0, 500)));
		}
	}
	~Corrupts()
	{
		delete lisDoCor;
	}
	Int16 getCantidad() { return lisDoCor->getCantidad(); }
	Void graficar(Graphics^ lienzo)
	{
		for (Int16 i = 0; i < lisDoCor->getCantidad(); ++i)
		{
			lisDoCor[i]->graficar(lienzo);
		}
	}
	Void eliminar(Int16 pos)
	{
		lisDoCor->delete_pos(pos);
	}
	Void movimiento()
	{
		for (Int16 i = 0; i < lisDoCor->getCantidad(); ++i)
		{
			lisDoCor->obtenerValorPos(i)->aleatorio();
		}
	}
	Boolean kamikaze(Rectangle areaJ)
	{
		for (Int16 i = 0; i < lisDoCor->getCantidad(); ++i)
		{
			if (lisDoCor[i]->areaRec().IntersectsWith(areaJ))
			{
				eliminar(i);
				return true;
				break;
			}
		}
		return false;
	}
	Void eliminarAliado(Aliados^ as, AliadosImpostores^ imp)
	{
		Rectangle r1, r2;
		ListaDoble<Aliado^>^ aux = as->obtenerLista();
		if (as->getNumAli() > 0)
			for (Int16 i = 0; i < cantidad; ++i)
			{
				r1 = lisDoCor[i]->areaRec();
				for (Int16 j = 0; j < as->getNumAli(); ++j)
				{
					r2 = aux[j]->areaRec();
					if (r1.IntersectsWith(r2))
					{
						imp->agregar(aux[j]);
						as->eliminar(j);
					}
				}
			}
	}
};
ref class Assassins
{
	ListaDoble<Assasin^>^ lisDoAs;
	Random r;
public:
	Assassins(Int16 cantidad)
	{
		lisDoAs = gcnew ListaDoble<Assasin^>();
		for (Int16 i = 0; i < cantidad; ++i)
			lisDoAs->push_back(gcnew Assasin(r.Next(0, 501), r.Next(0, 501)));
	}
	~Assassins()
	{
		delete lisDoAs;
	}
	Void graficar(Graphics^ lienzo)
	{
		for (Int16 i = 0; i < lisDoAs->getCantidad(); ++i)
		{
			lisDoAs[i]->graficar(lienzo);
		}
	}
	Void eliminar(Int16 pos)
	{
		lisDoAs->delete_pos(pos);
	}
	Void movimiento()
	{
		for (Int16 i = 0; i < lisDoAs->getCantidad(); ++i)
		{
			lisDoAs->obtenerValorPos(i)->aleatorio();
		}
	}
	Boolean kamikaze(Rectangle areaJ)
	{
		for (Int16 i = 0; i < lisDoAs->getCantidad(); ++i)
		{
			if (lisDoAs[i]->areaRec().IntersectsWith(areaJ))
			{
				eliminar(i);
				return true;
				break;
			}
		}
		return false;
	}
	Void eliminarAliado(Aliados^ as, AliadosImpostores^ imp)
	{
		Rectangle r1, r2;
		ListaDoble<Aliado^>^ aux = as->obtenerLista();
		if (as->getNumAli() > 0)
			for (Int16 i = 0; i < lisDoAs->getCantidad(); ++i)
			{
				r1 = lisDoAs[i]->areaRec();
				for (Int16 j = 0; j < aux->getCantidad(); ++j)
				{
					r2 = aux[j]->areaRec();
					if (r1.IntersectsWith(r2))
					{
						imp->agregar(aux[j]);
						as->eliminar(j);
					}
				}
			}
	}
};
ref class Controlador
{
	Bitmap^ fondo;
	FrmNegociacion^ frmNego;
	FrmYouWin^ frmWin;
	FrmGameOver^ frmOver;
	Laberinto^ lab;
	Gobernante^ j;
	Aliados^ aliados;
	AliadosSeguidores^ seguidores;
	AliadosImpostores^ impostores;
	Corrupts^ corrupts;
	Assassins^ assasins;
	Boolean negociaron;
	Boolean activoPortales;
	Int16 tiempo;
	Int16 cronometro;
	clock_t horainicio;
	clock_t coold_teletransporte;
public:
	Controlador(Int16 NumAli, Int16 vidas, Int16 tiempo, Char opclaberinto):tiempo(tiempo)
	{
		frmNego = gcnew FrmNegociacion();
		frmWin = gcnew FrmYouWin();
		frmOver = gcnew FrmGameOver();
		fondo = gcnew Bitmap("Lava.png");
		lab = gcnew Laberinto(opclaberinto);
		j = gcnew Gobernante(lab->getEntrada() * 31, vidas);
		aliados = gcnew Aliados(NumAli, lab);
		seguidores = gcnew AliadosSeguidores(j->getX(), j->getY());
		impostores = gcnew AliadosImpostores(NumAli);
		corrupts = gcnew Corrupts(Math::Round(0.4 * NumAli));
		assasins = gcnew Assassins(Math::Round(0.6 * NumAli));
		negociaron = false;
		activoPortales = false;
		horainicio = clock();
		coold_teletransporte = clock();
	}
	~Controlador()
	{
		delete fondo;
		delete frmNego;
		delete frmWin;
		delete frmOver;
		delete lab;
		delete j;
		delete aliados;
		delete seguidores;
		delete impostores;
		delete corrupts;
		delete assasins;
	}
	Void fotograma(Graphics^ lienzo)
	{
		lienzo->DrawImage(fondo, 0, 0);
		lab->mostrar(lienzo);
		lienzo->DrawString("Vidas: " + j->getVidas(), gcnew Font("Calibri", 18), Brushes::White, 950, 0);
		if (negociaron)
		{
			assasins->movimiento();
			assasins->graficar(lienzo);
		}
		else
		{
			corrupts->movimiento();
			corrupts->graficar(lienzo);
		}
		seguidores->graficar(lienzo);
		j->graficar(lienzo);
		aliados->movimiento(lab);
		aliados->graficar(lienzo);
		impostores->movimiento(lab);
		impostores->graficar(lienzo);
	}
	Void usoPortales()
	{
		if (clock() - coold_teletransporte > CLOCKS_PER_SEC * 3 && activoPortales)
		{
			j->teletransportar(lab);
			coold_teletransporte = clock();
		}
	}
	Void accionesConTecla(KeyEventArgs^ e)
	{
		seguidores->capturarPosJ(j->getX(), j->getY());
		seguidores->movimiento();
		j->mover(e, lab);
	}
	Void soltarTecla()
	{
		j->quieto();
		seguidores->quietos();
	}
	Void pocaVida()
	{
		Int16 aux(Math::Round(j->getVInicial() * 0.5));
		if (j->getVidas() < aux && !activoPortales)
		{
			lab->activarPortales();
			activoPortales = true;
		}
	}
	Void colisones()
	{
		impostores->transformar(aliados);
		if (!negociaron)
		{
			corrupts->eliminarAliado(aliados, impostores);
			if (corrupts->kamikaze(j->areaRec()))
				j->restarvida(10);
		}
		else
		{
			assasins->eliminarAliado(aliados, impostores);
			if (assasins->kamikaze(j->areaRec()) && negociaron)
				j->restarvida(20);
		}
		if (impostores->kamikaze(j->areaRec()))
			j->restarvida(15);
	}
	Void negociacion(Timer^ t)
	{
		if (corrupts->getCantidad() == 0 && !negociaron)
		{
			t->Enabled = false;
			frmNego->Show();
			if (frmNego->fin())
			{
				frmNego->Close();
				negociaron = true;
				t->Enabled = true;
			}
		}
	}
	Void findeljuego(Timer^ t1, Timer^ t2)
	{
		if (j->getVidas() <= 0 || cronometro == 0)
		{
			t1->Enabled = false;
			t2->Enabled = false;
			frmOver->Show();
		}
	}
	Void ganar(Timer^ t1, Timer^ t2)
	{
		Rectangle aux = Rectangle(lab->getXLlegada(), lab->getYLlegada() + (casilla_alto / 2), casilla_ancho, casilla_alto / 2);
		if (j->areaRec().IntersectsWith(aux))
		{
			t1->Enabled = false;
			t2->Enabled = false;
			frmWin->Show();
		}
	}
	Void temporizador(Graphics^ lienzo, Timer^ t1, Timer^ t2)
	{
		cronometro = Int16(tiempo - (clock() - horainicio) / 1000);
		lienzo->DrawString("Tiempo: " + cronometro, gcnew Font("Calibri", 18), SystemBrushes::ActiveBorder, 700, 0);
	}
	Void guardar()
	{
		ofstream file("config.txt");
		if (file.is_open())
		{
			file << j->getX() << ' ' << j->getY() << endl;
			file.close();
		}
	}
	Void Restaurar()
	{
		ifstream file("config.txt");
		if (file.is_open())
		{
			Int16 x, y;
			file >> x >> y; j->setX(x); j->setY(y);
			file.close();
		}
	}
};