/*==================================================
 EJERCICIO Instanciación de Objetos (Rectángulo).
 ------------------------------------------------
 OBJETIVO:
 Construir un programa con POO que obtenga el 
 área y el perímetro de un Rectángulo.
 ------------------------------------------------
 Juan Francisco Gallo Ramírez
 31/Enero/2023
 I.C.I. 
==================================================*/
#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;

const char f=16,g=187;

void color(int c_fondo,int c_texto)//FUNCIÓN DE APOYO PARA COLOR
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
		
	public:  // - - - Métodos
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
	color(1,15);cout<<" "<<f<<" Área:           "<<endl;
	color(15,0);cout<<"   "<<res<<endl;
}

void Rectangulo::per()
{
	float res;
	res=(base+altura)*2;
	color(1,15);cout<<" "<<f<<" Perímetro:      "<<endl;
	color(15,0);cout<<"   "<<res<<endl;
}

main()
{
	float a,b;
	setlocale(LC_ALL,"");system("color F0");
	color(15,4);cout<<"-------------------------------------------"<<endl;
	color(4,15);cout<<"       OBTENCIÓN DE ÁREA Y PERÍMETRO       "<<endl;
	color(15,4);cout<<"-------------------------------------------"<<endl<<endl;
	color(15,0);cout<<" "<<g<<" Ingresa la base del rectángulo: ";color(15,1);cin>>a;
	color(15,0);cout<<" "<<g<<" Ingresa el perímetro del rectángulo: ";color(15,1);cin>>b;
	color(15,0);cout<<endl<<"-------------------------------------------"<<endl;
	Rectangulo r1(a,b);
	
	r1.area();
	r1.per();
}
