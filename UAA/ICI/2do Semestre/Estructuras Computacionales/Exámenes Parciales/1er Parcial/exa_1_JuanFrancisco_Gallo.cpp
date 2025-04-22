/*=========================================================
   EXAMEN PARCIAL #1. Información de Estudiantes.
  --------------------------------------------------------
   OBJETIVO:
    Realizar un programa obtenenga las siguientes 
	estadísticas:
	 1. Captura de los datos de los n estudiantes.
	 2. Número de estudiantes  con promedio aprobado.
	 3. Número de estudiantes  donde la calificación 1 
	    fue aprobada.
	 4. Calificación más alta de los promedios de hombres.
	 5. Calificación más baja de los promedios de mujeres.
	 6. Incluir  validación de la captura de los N 
	    estudiantes y realizar documentación mínima 
		definida para un programa formal.
  --------------------------------------------------------
   Juan Francisco Gallo Ramírez
   3 de Febrero de 2023. 
   I.C.I.
=========================================================*/
#include <iostream>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;

#define N_EST 5

//______________________ FUNCIÓN DE APOYO PARA COLOR _____
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//____________________________ ESTRUCTURA ESTUDIANTE _____
struct estudiante
{
	//Información de los estudiantes
	char nombre[50];
	char genero;
	float calificacion[2]; 
	float prom;     
}alumno[N_EST];

//_______________________________ FUNCIÓN PRINCIPAL ______
main()
{
	string opc;
	char aux[5];
	char num[5];
	bool error=false;
	float cal=0;;
	int aux1;
	// Se establecen los comandos neceasrios para el funcionamiento del programa.
	setlocale(LC_ALL, "");system("color F0");
	// Ciclo do-while para validar.
	do
	{
		system("cls");
		color(4,15);cout<<"                        ESTADÍSTICA ESTUDIANTIL                        \n\n";color(15,0);
		cout<<"\ta. Capturar datos.\n";
		cout<<"\tb. Estudiantes con promedio aprobado.\n";
		cout<<"\tc. Estudiantes con calificación #1 aprobada.\n";
		cout<<"\td. Calificación más alta (Hombres).\n";
		cout<<"\te. Calificación más alta (Mujeres).\n";
		color(15,4);cout<<"\tf. <- Salir.\n\n";
		color(15,8);cout<<"\t> Ingresa opción: ";
		color(15,1);cin>>opc;
		// Menú principal.
		// Opción a.
		if(opc=="a")
		{
			// Se capturan datos por medio de un ciclo for y se validan entradas.
			for(int i=0;i<N_EST;i++)
			{
				system("cls");
				color(4,15);cout<<"                        ESTADÍSTICA ESTUDIANTIL                        \n\n";color(15,0);
				cout<<"\tALUMNO #"<<i+1<<":\n\n";
				cout<<"\t> Ingresa nombre: ";
				color(15,1);fflush(stdin);gets(alumno[i].nombre);
				do
				{
					system("cls");
					color(4,15);cout<<"                        ESTADÍSTICA ESTUDIANTIL                        \n\n";color(15,0);
					cout<<"\tALUMNO #"<<i+1<<":\n\n";
					cout<<"\t> Ingresa género (H o M): ";
					color(15,1);fflush(stdin);cin>>alumno[i].genero;
					if(alumno[i].genero!='H' && alumno[i].genero!='M')
					{
						color(15,4);cout<<"\n\t# # # OPCIÓN INVÁLIDA # # # \n";
						getch();
					}
				}while(alumno[i].genero!='H' && alumno[i].genero!='M');
				for(int j=0;j<2;j++)
				{
					do
					{
						error=false;
						system("cls");
						color(4,15);cout<<"                        ESTADÍSTICA ESTUDIANTIL                        \n\n";color(15,0);
						cout<<"\tALUMNO #"<<i+1<<":\n\n";
						cout<<"\t> Ingresa calificación #"<<j+1<<": ";
						color(15,1);fflush(stdin);gets(aux);
						if(strcmp(aux,"0")!=0&&strcmp(aux,"1")!=0&&strcmp(aux,"2")!=0&&strcmp(aux,"3")!=0&&strcmp(aux,"4")!=0&&strcmp(aux,"5")!=0&&strcmp(aux,"6")!=0&&strcmp(aux,"7")!=0&&strcmp(aux,"8")!=0&&strcmp(aux,"9")!=0&&strcmp(aux,"10")!=0)
						{
							color(15,4);cout<<"\n\t# # # DATOS INVÁLIDOS # # # \n";
							getch();
							error=true;
						}else
						{
							alumno[i].calificacion[j]=atof(aux);
						}
					}while(error==true);
					
					for(int i=0;i<N_EST;i++)
					{
						alumno[i].prom=(alumno[i].calificacion[0]+alumno[i].calificacion[1])/2;
					}	
				}
			}
		}else
		// Opción b.
		if(opc=="b")
		{
			// Se comparan promedios mayores a 7.
			system("cls");
			color(4,15);cout<<"                        ESTADÍSTICA ESTUDIANTIL                        \n\n";color(15,0);
			cout<<"\tEstudiantes con promedio aprobado:\n\n";
			for(int i=0;i<N_EST;i++)
			{
				if(alumno[i].prom>7)
				{
					cout<<"\tAlumno: "<<alumno[i].nombre<<endl;
				}
			}
			getch();
		}else
		// Opción c.
		if(opc=="c")
		{
			// Se comparan calificacione #1 mayores a 7.
			system("cls");
			color(4,15);cout<<"                        ESTADÍSTICA ESTUDIANTIL                        \n\n";color(15,0);
			cout<<"\tEstudiantes con calificación #1 aprobada:\n\n";
			for(int i=0;i<N_EST;i++)
			{
				if(alumno[i].calificacion[0]>7)
				{
					cout<<"\tAlumno: "<<alumno[i].nombre<<endl;
				}
			}
		}else
		// Opción d.
		if(opc=="d")
		{
			// Se comparan calificciones entre hombres.
			system("cls");aux1=0;
			color(4,15);cout<<"                        ESTADÍSTICA ESTUDIANTIL                        \n\n";color(15,0);
			cout<<"\tCalificación más alta (Hombres):\n\n";
			for(int i=0;i<N_EST;i++)
			{
				if(alumno[i].prom>cal&&alumno[i].genero=='H')
				{
					cal=alumno[i].prom;
					aux1=i;
				}
			}
			cout<<"\t"<<alumno[aux1].nombre<<endl;
			cout<<"\tPromedio: "<<alumno[aux1].prom<<endl;
			getch();
		}else
		// Opción e.
		if(opc=="e")
		{
			// Se comparan calificciones entre mujeres.
			system("cls");aux1=0;
			color(4,15);cout<<"                        ESTADÍSTICA ESTUDIANTIL                        \n\n";color(15,0);
			cout<<"\tCalificación más alta (Mujeres):\n\n";
			for(int i=0;i<N_EST;i++)
			{
				if(alumno[i].prom>cal&&alumno[i].genero=='M')
				{
					cal=alumno[i].prom;
					aux1=i;
				}
			}
			cout<<"\t"<<alumno[aux1].nombre<<endl;
			cout<<"\tPromedio: "<<alumno[aux1].prom<<endl;
			getch();
		}else
		// Opción f.
		if(opc=="f")
		{
			color(15,2);cout<<"\n\t+ + + EJECUCIÓN FINALIZADA + + + \n";
		}else
		{
			color(15,4);cout<<"\n\t# # # OPCIÓN INVÁLIDA # # # \n";
			getch();
		}
	}while(opc!="f");
	getch();
	// Fin del programa.
}
