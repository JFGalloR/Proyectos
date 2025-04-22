/*==================================================
  EJERCICIO. Polimorfismo.
 ------------------------------------------------
  OBJETIVO:
  Crear un programa en C++ que tenga la jerarquía 
  de clases: Animal, Humano y Perro y hacer 
  polimorfismo con el método comer().
 ------------------------------------------------
  Juan Francisco Gallo Ramírez
  7/Febrero/2023
  I.C.I. 
==================================================*/
#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;

void color(int c_fondo,int c_texto)// - - - FUNCIÓN DE APOYO PARA COLOR
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}
//======================= Clases y Subclases =======
class Animal
{
	private:
		string anatomia;     //Vertebrado o Invertebrado
		string alimentacion; //Hervívoro, Carnívoro u Omnívoro
		string habitad;		 //Terrestre o Acuático
	public:
		Animal(string, string, string);
		virtual void comer();
		void mostrar();
};

class Humano : public Animal
{
	private:
		string nombre;
	public:
		Humano(string, string, string, string);
		void comer(); 
};

class Perro : public Animal
{
	private:
		string nombre;
		string raza;
	public:
		Perro(string, string, string, string, string);
		void comer(); 
};

//============================ Constructores =======
Animal::Animal(string _an, string _al, string _ha)
{
	anatomia = _an;
	alimentacion = _al;
	habitad = _ha;
}

Humano::Humano(string _an, string _al, string _ha,string _nom):Animal(_an, _al, _ha)
{
	nombre = _nom;
}

Perro::Perro(string _an, string _al, string _ha,string _nom,string _raz):Animal(_an, _al, _ha)
{
	nombre = _nom;
	raza = _raz;
}

//================================== Métodos =======
void Animal::comer()
{
	color(15,2);cout<<"  Animal comiendo..."<<endl;
}
void Animal::mostrar()
{
	color(4,15);cout<<"                           ANIMAL:                           "<<endl<<endl;
	color(15,4);cout<<"\t> Anatomía:\t";color(15,0);cout<<anatomia<<endl;
	color(15,4);cout<<"\t> Alimentación:\t";color(15,0);cout<<alimentacion<<endl;
	color(15,4);cout<<"\t> Habitad:\t";color(15,0);cout<<habitad<<endl<<endl;
}
void Humano::comer()
{
	Animal::mostrar();
	Animal::comer();
	color(15,2);cout<<"  Se trata de "<<nombre<<" que come como HUMANO."<<endl;
}
void Perro::comer()
{
	Animal::mostrar();
	Animal::comer();
	color(15,2);cout<<"  Se trata de "<<nombre<<" de raza "<<raza<<" que come como PERRO."<<endl;
}

main()
{
	int i;
	Animal *a[4];
	a[0]=new Humano("Vertebrado","Omnívoro","Terrestre","Diosbelindo Cazares");
	a[1]=new Perro("Vertebrado","Omnívoro","Terrestre","Solovino","Husky");
	a[2]=new Humano("Vertebrado","Omnívoro","Terrestre","Chalino Sánchez");
	a[3]=new Perro("Vertebrado","Omnívoro","Terrestre","Dumbo","Sabueso");
	
	setlocale(LC_ALL,"");
	system("color F0");
	
	for(i=0;i<4;i++)
	{
		system("cls");
		a[i]->comer();
		color(15,0);cout<<endl;system("pause");
	}
	
	
}
