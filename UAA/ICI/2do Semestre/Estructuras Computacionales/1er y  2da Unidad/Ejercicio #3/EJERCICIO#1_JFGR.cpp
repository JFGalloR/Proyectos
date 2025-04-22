/*==================================================
  EJERCICIO #1. Estructuras.
 ------------------------------------------------
  OBJETIVO:
  Utilizando estructuras, capturar datos para el
  corredor y obtener la categoría a la que 
  pertenece dependiendo de su edad:
  	-Edad mayor de 40 corrresponde a Veterano.
  	-Edad entre 19-40 corrresponde a Adulto.
  	-Menores de 19 corresponde  a juvenil.
 ------------------------------------------------
  Juan Francisco Gallo Ramírez
  7/Febrero/2023
  I.C.I. 
==================================================*/
#include <iostream>
#include <locale.h>
#include <string.h>
#include <windows.h>
using namespace std;

void color(int c_fondo,int c_texto)// - - - FUNCIÓN DE APOYO PARA COLOR
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

struct corredor
{
	char nombre[30];
	char clubnom[25];
	char categoria[12];
	char genero;
	int edad;
}persona;

main()
{
	setlocale(LC_ALL,"");
	system("color F0");
	color(4,15);cout<<"                CORREDOR                "<<endl<<endl;
	color(15,0);cout<<"   > Ingresa nombre: ";color(15,1);fflush(stdin);cin.getline(persona.nombre,30,'\n');
	color(15,0);cout<<"   > Ingresa edad: ";color(15,1);cin>>persona.edad;
	color(15,0);cout<<"   > Ingresa género (H o M): ";color(15,1);fflush(stdin);cin>>persona.genero;
	color(15,0);cout<<"   > Ingresa club: ";color(15,1);fflush(stdin);cin.getline(persona.clubnom,20,'\n');
	
	if(persona.edad>40)strcpy(persona.categoria,"Veterano");
	else if(persona.edad>=19 && persona.edad<=40)strcpy(persona.categoria,"Adulto");
	else if(persona.edad<19)strcpy(persona.categoria,"Juvenil");
	
	system("cls");
	color(4,15);cout<<"             DATOS CORREDOR             "<<endl<<endl;
	color(15,0);cout<<"   > Nombre:\t";color(15,1);cout<<persona.nombre<<endl;
	color(15,0);cout<<"   > Edad:\t";color(15,1);cout<<persona.edad<<endl;
	color(15,0);cout<<"   > Género:\t";color(15,1);cout<<persona.genero<<endl;
	color(15,0);cout<<"   > Categoría:\t";color(15,1);cout<<persona.categoria<<endl;
	color(15,0);cout<<"   > Club:\t";color(15,1);cout<<persona.clubnom<<endl;
	
}













