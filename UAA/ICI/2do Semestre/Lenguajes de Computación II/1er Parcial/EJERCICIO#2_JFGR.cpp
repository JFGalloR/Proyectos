/*===================================================
 EJERCICIO. Baraja Inglesa.
 --------------------------------------------------
 OBJETIVO:
  Mostrar al usuario una carta de la baraja inglesa.
  Según el dato proporcionado mostar una carta 
  aleatoria cumpliendo con la clase o el número que
  otorga.
 --------------------------------------------------
 Juan Francisco Gallo Ramírez
 1/Febrero/2023
 I.C.I. 
===================================================*/
#include <iostream>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <time.h>
using namespace std;

const char P=6,D=4,T=5,C=3,F=187;
const string t[4]={"Pica","Diamante","Trébol","Corazón"};

void color(int c_fondo,int c_texto)// - - - FUNCIÓN DE APOYO PARA COLOR
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

void pantalla()// - - - FUNCIÓN DE APOYO PARA COLOR
{
	system("cls");
	color(15,4);cout<<endl<<"                  BARAJA INGLESA                  "<<endl;
	color(15,8);cout<<"\t------------ ";
	color(15,0);cout<<P;cout<<" ";
	color(15,4);cout<<D<<" ";
	color(15,0);cout<<T<<" ";
	color(15,4);cout<<C;
	color(15,8);cout<<" -------------"<<endl<<endl;	
}

class Carta             // - - - Clase
{
	private:
		int num;
		string tipo;
	public:
		Carta(int);     // - - - Contructor #1
		Carta(string);  // - - - Contructor #2
		~Carta();
		mostrar_carta();
};

Carta::Carta(int n)     // - - - Contructor #1
{
	int a;
	a = rand() % 4;
	num = n;
	tipo = t[a];
}

Carta::Carta(string t)   // - - - Contructor #2
{
	int a;
	a = 1 + rand() % 13;
	num = a;
	tipo = t;
}

Carta::~Carta()          // - - - Destructor
{
	color(6,15);cout<<endl<<"\t         CARTA ELIMINADA          "<<endl<<endl<<"\t";
	color(15,0);system("pause");
}

Carta::mostrar_carta()   // - - - Método Mostrar Carta
{
	pantalla();
	color(15,0);cout<<"\t    ";color(2,0);cout<<"           "<<endl;
	color(15,0);cout<<"\t    ";color(2,0);cout<<"   ";
	if(tipo==t[0]||tipo==t[2])color(15,0);else color(15,4);
	switch(num){case 10:cout<<num<<"   ";break;
				case 1: cout<<"A    ";break;
				case 11:cout<<"J    ";break;
				case 12:cout<<"Q    ";break;
				case 13:cout<<"K    ";break;
				default:cout<<num<<"    ";}
	color(2,0);cout<<"   ";color(15,1);cout<<" Número: ";color(15,0);cout<<num<<endl;
	color(15,0);cout<<"\t    ";color(2,0);cout<<"   ";color(15,0);cout<<"  ";
	if(tipo==t[0]){color(15,0);cout<<P;}
	else if(tipo==t[1]){color(15,4);cout<<D;}
	else if(tipo==t[2]){color(15,0);cout<<T;}
	else if(tipo==t[3]){color(15,4);cout<<C;}cout<<"  ";color(2,0);cout<<"   "<<endl;
	color(15,0);cout<<"\t    ";color(2,0);cout<<"   ";
	if(tipo==t[0]||tipo==t[2])color(15,0);else color(15,4);
	switch(num){case 10:cout<<"   "<<num;break;
				case 1: cout<<"    A";break;
				case 11:cout<<"    J";break;
				case 12:cout<<"    Q";break;
				case 13:cout<<"    K";break;
				default:cout<<"    "<<num;}
	color(2,0);cout<<"   ";color(15,1);cout<<" Tipo: ";if(tipo==t[0]||tipo==t[2])color(15,0);else color(15,4);cout<<tipo<<endl;
	color(15,0);cout<<"\t    ";color(2,0);cout<<"           "<<endl<<endl;
	color(15,8);cout<<"\t----------------------------------"<<endl<<endl<<"\t";
	color(15,0);system("pause");
}

main()                   // - - - FUNCIÓN PRINCIPAL
{
	int opc,a,i;
	char b[20];
	
	setlocale(LC_ALL,"");
	srand(time(NULL));
	system("color F0");
	
	do
	{
		pantalla();a=0;
		color(15,1);cout<<"\t1.";color(15,0);cout<<" Ingresar el número de carta."<<endl;
		color(15,1);cout<<"\t2.";color(15,0);cout<<" Ingresar el tipo de carta."<<endl;
		color(15,1);cout<<"\t3.";color(15,4);cout<<" Salir ->"<<endl<<endl;
		color(15,8);cout<<"\t----------------------------------"<<endl;
		color(15,8);cout<<"\t"<<F<<" Ingresa opción: ";color(15,9);cin>>opc;
		switch (opc)
		{
			case 1:
				do
				{
					pantalla();
					color(15,8);cout<<"\t"<<F<<" Ingresa número: ";color(15,9);cin>>a;
					if(a<1 || a>13)
					{
						color(4,15);cout<<endl<<"\t   INGRESA VALORES DEL 1 AL 13    "<<endl<<endl<<"\t";
						color(15,0);system("pause");a=0;
					}else
					{
						Carta a1(a);
						a1.mostrar_carta();
					}
				}while(a==0);
				break;
			case 2:
				do
				{
					pantalla();a=1;
					color(15,8);cout<<"\t"<<F<<" Ingresa tipo: ";color(15,9);cin>>b;
					strupr(b);
					if(strcmp(b,"PICA")==0||strcmp(b,"PICAS")==0)
					{
						Carta a1(t[0]);
						a1.mostrar_carta();
					}else if(strcmp(b,"DIAMANTE")==0||strcmp(b,"DIAMANTES")==0)
					{
						Carta a1(t[1]);
						a1.mostrar_carta();
					}else if(strcmp(b,"TRÉBOL")==0||strcmp(b,"TREBOL")==0||strcmp(b,"TRÉBOLES")==0||strcmp(b,"TREBOLES")==0)
					{
						Carta a1(t[2]);
						a1.mostrar_carta();
					}else if(strcmp(b,"CORAZÓN")==0||strcmp(b,"CORAZON")==0||strcmp(b,"CORAZONES")==0)
					{
						Carta a1(t[3]);
						a1.mostrar_carta();
					}else
					{
						color(4,15);cout<<endl<<"\t          TIPO INVÁLIDO           "<<endl;
						color(4,14);cout<<"\t  Tipos válidos:                  "<<endl;
						cout<<"\t  Pica,Diamante,Trébol o Corazón  "<<endl<<endl<<"\t";
						color(15,0);system("pause");a=0;
					}
				}while(a==0);
				break;
			case 3:
				color(2,15);cout<<endl<<"\t            FINALIZADO            "<<endl<<endl<<"\t";
				color(15,0);system("pause");
				break;
			default:
				color(4,15);cout<<endl<<"\t         OPCIÓN INVÁLIDA          "<<endl<<endl<<"\t";
				color(15,0);system("pause");
		}
	}while(opc!=3);
		
}

























