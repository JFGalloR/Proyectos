/*==================================================
 EJERCICIO Instanciaci�n de Objetos (Rect�ngulo).
 ------------------------------------------------
 OBJETIVO:
 Construir un programa con POO que obtenga el 
 �rea y el per�metro de un Rect�ngulo.
 ------------------------------------------------
 Juan Francisco Gallo Ram�rez
 31/Enero/2023
 I.C.I. 
==================================================*/
#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;

const char f=16,g=187;

void color(int c_fondo,int c_texto)//FUNCI�N DE APOYO PARA COLOR
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

class Rectangulo
{
	private: // - - - Antributos
		float base, altura;
		
	public:  // - - - M�todos
		Rectangulo(float, float);
		void area();
		void per();	
};

Rectangulo::Rectangulo(float b, float a) // - - - Contructor
{
	base = b;
	altura = a;
}

void Rectangulo::area()
{
	float res;
	res=base*altura;
	color(1,15);cout<<" "<<f<<" �rea:           "<<endl;
	color(15,0);cout<<"   "<<res<<endl;
}

void Rectangulo::per()
{
	float res;
	res=(base+altura)*2;
	color(1,15);cout<<" "<<f<<" Per�metro:      "<<endl;
	color(15,0);cout<<"   "<<res<<endl;
}

main()
{
	float a,b;
	setlocale(LC_ALL,"");system("color F0");
	color(15,4);cout<<"-------------------------------------------"<<endl;
	color(4,15);cout<<"       OBTENCI�N DE �REA Y PER�METRO       "<<endl;
	color(15,4);cout<<"-------------------------------------------"<<endl<<endl;
	color(15,0);cout<<" "<<g<<" Ingresa la base del rect�ngulo: ";color(15,1);cin>>a;
	color(15,0);cout<<" "<<g<<" Ingresa el per�metro del rect�ngulo: ";color(15,1);cin>>b;
	color(15,0);cout<<endl<<"-------------------------------------------"<<endl;
	Rectangulo r1(a,b);
	
	r1.area();
	r1.per();
}
