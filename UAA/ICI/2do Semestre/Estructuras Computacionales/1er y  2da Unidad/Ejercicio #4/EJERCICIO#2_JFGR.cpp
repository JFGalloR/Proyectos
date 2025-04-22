/*==================================================
  EJERCICIO #2. Uniones.
 ------------------------------------------------
 OBJETIVO:
 Capturar datos de alumnos, y dependiendo el 
 tipo de alumnos, caoturar porcentaje de beca, 
 o deporte en el que cursa; además mostrar 
 alumnos becarios y deportistas; adicionalmente,
 mostrar alumnos deportistas de entre 20 y 25.
 ------------------------------------------------
 Juan Francisco Gallo Ramírez
 16/Febrero/2023
 I.C.I. 
==================================================*/
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
using namespace std;

const char F=16, FF=187;
const int CA = 5;

//___________________________ FUNCIÓN DE COLOR _____
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}
//_________________________________ UNION "info" _____
union info
{
	float porcentaje;
	char deporte[10];
}adicional;
//_______________________________ STRUCT "datos" _____
struct datos
{
	int id;
	char nombre[30];
	int edad;
	char tipo[10];
	info adicional;
}alumno[CA];
//____________________________ FUNCIÓN PRINCIPAL _____
main()
{
	int i, error;
	system("color F0");
	setlocale(LC_ALL, "");
	
	for(i=0;i<CA;i++)
	{
		system("cls");
		color(6,15);cout<<"                     INFORMACIÓN ESTUDIANTIL                     \n\n";
		color(15,6);cout<<" "<<F<<" Alumno #"<<i+1<<" "<<endl;
		color(15,8);cout<<"\n\t"<<FF<<" Ingresa ID: ";
		color(15,0);cin>>alumno[i].id;
		system("cls");
		color(6,15);cout<<"                     INFORMACIÓN ESTUDIANTIL                     \n\n";
		color(15,6);cout<<" "<<F<<" Alumno #"<<i+1<<" "<<endl;
		color(15,8);cout<<"\n\t"<<FF<<" Ingresa nombre: ";
		color(15,0);fflush(stdin);gets(alumno[i].nombre);
		system("cls");
		color(6,15);cout<<"                     INFORMACIÓN ESTUDIANTIL                     \n\n";
		color(15,6);cout<<" "<<F<<" Alumno #"<<i+1<<" "<<endl;
		color(15,8);cout<<"\n\t"<<FF<<" Ingresa edad: ";
		color(15,0);cin>>alumno[i].edad;
		do
		{
			system("cls");error=0;
			color(6,15);cout<<"                     INFORMACIÓN ESTUDIANTIL                     \n\n";
			color(15,6);cout<<" "<<F<<" Alumno #"<<i+1<<" "<<endl;
			color(15,8);cout<<"\n\t"<<FF<<" Ingresa tipo de alumno: ";
			color(15,0);fflush(stdin);gets(alumno[i].tipo);
			strupr(alumno[i].tipo);
			if(strcmp(alumno[i].tipo,"BECARIO")==0)
			{
				system("cls");
				color(6,15);cout<<"                     INFORMACIÓN ESTUDIANTIL                     \n\n";
				color(15,6);cout<<" "<<F<<" Alumno #"<<i+1<<" "<<endl;
				color(15,8);cout<<"\n\t"<<FF<<" Ingresa porcentaje de beca: ";
				color(15,0);cin>>alumno[i].adicional.porcentaje;
			}else if(strcmp(alumno[i].tipo,"DEPORTISTA")==0)
			{
				system("cls");
				color(6,15);cout<<"                     INFORMACIÓN ESTUDIANTIL                     \n\n";
				color(15,6);cout<<" "<<F<<" Alumno #"<<i+1<<" "<<endl;
				color(15,8);cout<<"\n\t"<<FF<<" Ingresa deporte: ";
				color(15,0);cin>>alumno[i].adicional.deporte;
			}else
			{
				error=1;
				color(4,15);cout<<"\n\t    # # # OPCIÓN INVÁLIDA # # #     ";
				color(15,2);cout<<"\n\t (Ingresa 'Becario' ó 'Deportista') ";
				getch();
			}
		}while(error==1);
	}
	system("cls");
	color(6,15);cout<<"                     INFORMACIÓN ESTUDIANTIL                     \n\n";
	color(4,15);cout<<"  Alumnos becarios:  \n";
	color(15,4);cout<<"\n-----------------------------------------------------------------\n";
	for(i=0;i<CA;i++)
	{
		if(strcmp(alumno[i].tipo,"BECARIO")==0)
		{
			color(15,4);cout<<"\tID:\t\t";
			color(15,0);cout<<alumno[i].id;
			color(15,4);cout<<"\n\tNombre:\t\t";
			color(15,0);cout<<alumno[i].nombre;
			color(15,4);cout<<"\n\tEdad:\t\t";
			color(15,0);cout<<alumno[i].edad;
			color(15,4);cout<<"\n\tPorcentaje:\t";
			color(15,0);cout<<alumno[i].adicional.porcentaje<<"%";
			color(15,4);cout<<"\n-----------------------------------------------------------------\n";
		}
	}
	color(1,15);cout<<"\n  Alumnos deportistas:  \n";
	color(15,1);cout<<"\n-----------------------------------------------------------------\n";
	for(i=0;i<CA;i++)
	{
		if(strcmp(alumno[i].tipo,"DEPORTISTA")==0)
		{
			color(15,1);cout<<"\tID:\t\t";
			color(15,0);cout<<alumno[i].id;
			color(15,1);cout<<"\n\tNombre:\t\t";
			color(15,0);cout<<alumno[i].nombre;
			color(15,1);cout<<"\n\tEdad:\t\t";
			color(15,0);cout<<alumno[i].edad;
			color(15,1);cout<<"\n\tDeporte:\t";
			color(15,0);cout<<alumno[i].adicional.deporte;
			color(15,1);cout<<"\n-----------------------------------------------------------------\n";
		}
	}
	color(2,15);cout<<"\n  Alumnos deportistas de entre 20 y 25 años:  ";
	color(15,2);cout<<"\n\n-----------------------------------------------------------------\n";
	for(i=0;i<CA;i++)
	{
		if(strcmp(alumno[i].tipo,"DEPORTISTA")==0 && alumno[i].edad>=20 && alumno[i].edad<=25)
		{
			color(15,2);cout<<"\tID:\t\t";
			color(15,0);cout<<alumno[i].id;
			color(15,2);cout<<"\n\tNombre:\t\t";
			color(15,0);cout<<alumno[i].nombre;
			color(15,2);cout<<"\n\tEdad:\t\t";
			color(15,0);cout<<alumno[i].edad;
			color(15,2);cout<<"\n\tDeporte:\t";
			color(15,0);cout<<alumno[i].adicional.deporte;
			color(15,2);cout<<"\n-----------------------------------------------------------------\n";
		}
	}
	
}
