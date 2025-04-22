/*===================================================
  EJERCICIO. Apuntadores - Estructuras.
 --------------------------------------------------
  OBJETIVO:
	En el Hospital �La Fraternidad� almacenan la 
	siguiente informaci�n de sus N pacientes. 
	Nombre y apellidos: Cadena de caracteres. 
	Edad: Entero. Sexo: Car�cter. Condici�n: 
	Entero (Se refiere al estado de salud en que 
	ingresa el paciente. Los valores que toma van 
	de 1�5, y representan el m�ximo grado de 
	gravedad.) Tel�fono. Escribir un programa en 
	C que genere lo siguiente: 
	� El porcentaje de hombres y mujeres 
	  registrados en el hospital. 
	� El n�mero de paciente de cada una de las 
	  categor�as de condici�n. 
	� El nombre y tel�fono de todos los pacientes 
	  que tuvieron una condici�n de ingreso de 
	  m�xima gravedad.
 --------------------------------------------------
  ELABORADORES:
	- Alejandro Castillo Mota
	- Luis Manuel Flores Jim�nez
	- Juan Francisco Gallo Ram�rez
 --------------------------------------------------
	17 de Febrero de 2023
	I.C.I. U.A.A.
====================================================*/
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
using namespace std;

// Se declaran las constantes necesarias.
#define PAC 5
// Definimos constantes para el uso de la funci�n 'color()'.
const char C=2, F=16, FF=187;
const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

//__________________ FUNCI�N DE APOYO PARA COLOR _____
/*----------------------------------------------------
	Funci�n que nos ayuda a modificar los colores 
	del texto en la consola.
  --------------------------------------------------*/
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//________ FUNCI�N DE APOYO PARA VALIDAR N�MEROS _____
/*----------------------------------------------------
	Funci�n que nos ayuda a validar n�meros mediante
	una comparaci�n del rango de caracteres. Retorna 
	error si la cadena no es num�rica.
  --------------------------------------------------*/
bool validacionNum(char *aux)
{
	for(;*aux;++aux)
	if( '0' > *aux || '9' < *aux )
	{
		return 1;
	}
	return 0;
}

//________ FUNCI�N DE APOYO PARA VALIDAR LETRAS ______
/*----------------------------------------------------
	Funci�n que nos ayuda a validar cadenas mediante
	una comparaci�n del rango de caracteres. Retorna 
	error si la cadena es num�rica.
  --------------------------------------------------*/
bool validacionCar(char *aux)
{
	for(;*aux;++aux)
	if( '0' < *aux && '9' > *aux )
	{
		return 1;
	}
	return 0;
}

//___________________________ STRUCT "Paciente" _____
struct Paciente
{
	char nombre[26];
	int edad;
	char sexo[2];
	int cond;
	unsigned int tel;
}paciente[PAC], *p_paciente = paciente;

//_________________________ FUNCI�N PEDIR DATOS ______
/*----------------------------------------------------
	Funci�n que nos ayuda a pedir los datos de los 
	pacientes.
  --------------------------------------------------*/
void pedirDatos(Paciente *p_paciente, int i)
{
	char aux[30];
	bool error=false;
	// Pidiendo el nombre =========================================================================================
	do
	{
		system("cls");error=false;
		color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";color(gric,neg);
		color(gric,negc);cout<<"\t PACIENTE #"<<i+1<<endl<<endl;
		color(gric,ver);cout<<"\t Nombre"<<endl<<endl;color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa nombre: ";
		fflush(stdin);color(gric,roj);gets(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionCar(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NO NUM�RICOS # # # ";
			error=true;
			getch();
		}else
		if(strlen(aux)>25)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA NOMBRE MENOR A 25 CARACTERES # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingres� adecuadamente, se copia al destino.
			strcpy((p_paciente+i)->nombre,aux);
		}
	}while(error==true);
	// Pidiendo edad ==============================================================================================
	do
	{
		system("cls");error=false;
		color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";color(gric,neg);
		color(gric,negc);cout<<"\t PACIENTE #"<<i+1<<endl<<endl;
		color(gric,ver);cout<<"\t Edad"<<endl<<endl;color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa edad: ";
		fflush(stdin);color(gric,roj);gets(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionNum(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
			error=true;
			getch();
		}else
		if(atoi(aux)>120||atoi(aux)<0)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA EDAD ENTRE 0 Y 120 # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingres� adecuadamente, se copia al destino.
			(p_paciente+i)->edad=atoi(aux);
		}
	}while(error==true);
	// Pidiendo sexo ===============================================================================================
	do
	{
		system("cls");error=false;
		color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";color(gric,neg);
		color(gric,negc);cout<<"\t PACIENTE #"<<i+1<<endl<<endl;
		color(gric,ver);cout<<"\t Sexo"<<endl<<endl;color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa sexo (H o M): ";
		fflush(stdin);color(gric,roj);gets(aux);strupr(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionCar(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NO NUM�RICOS # # # ";
			error=true;
			getch();
		}else
		if(strcmp(aux,"H")!=0&&strcmp(aux,"M")!=0)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA H o M # # # ";
			error=true;
			getch();
		}else
		if(strlen(aux)>1)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA SOLO UNA LETRA # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingres� adecuadamente, se copia al destino.
			strcpy((p_paciente+i)->sexo,aux);
		}
	}while(error==true);
	// Pidiendo condici�n ==========================================================================================
	do
	{
		system("cls");error=false;
		color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";color(gric,neg);
		color(gric,negc);cout<<"\t PACIENTE #"<<i+1<<endl<<endl;
		color(gric,ver);cout<<"\t Condici�n"<<endl<<endl;color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa condici�n: ";
		fflush(stdin);color(gric,roj);gets(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionNum(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
			error=true;
			getch();
		}else
		if(atoi(aux)>5||atoi(aux)<1)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA GRAVEDAD ENTRE 1 Y 5 # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingres� adecuadamente, se copia al destino.
			(p_paciente+i)->cond=atoi(aux);
		}
	}while(error==true);
	// Pidiendo condici�n ==========================================================================================
	do
	{
		system("cls");error=false;
		color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";color(gric,neg);
		color(gric,negc);cout<<"\t PACIENTE #"<<i+1<<endl<<endl;
		color(gric,ver);cout<<"\t Tel�fono"<<endl<<endl;color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa tel�fono: ";
		fflush(stdin);color(gric,roj);gets(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionNum(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
			error=true;
			getch();
		}else
		if(strlen(aux)!=10)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA TEL�FONO V�LIDO (10 N�MEROS) # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingres� adecuadamente, se copia al destino.
			(p_paciente+i)->tel=atoi(aux);
		}
	}while(error==true);
}

//_____________ FUNCI�N % DE PACIENTES POR SEXO ______
/*----------------------------------------------------
	Funci�n que nos ayuda a obtener el porcentaje de 
	hombres y mujeres en el hospital.
  --------------------------------------------------*/
void porcentaje(Paciente *p_paciente)
{
	int cH=0, cM=0;
	// Se compara el sexo de los pacientes y se suman los contadores.
	for(int i=0;i<PAC;i++)
	{
		cout<<(p_paciente+i)->sexo<<endl;
		if(strcmp(((p_paciente+i)->sexo),"H")==0)
		{
			cH++;
		}else
		{
			cM++;
		}
	}
	// Se imprimen los resultados.
	system("cls");
	color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";
	color(gric,ver);cout<<"\tPorcentaje de pacientes seg�n g�nero.\n\n";
	color(gric,azu);cout<<"\tHombres: ";color(gric,neg);cout<<(cH*100)/PAC<<"%"<<endl;
	color(gric,azu);cout<<"\tMujeres: ";color(gric,neg);cout<<(cM*100)/PAC<<"%"<<endl;	
}

//_____________ FUNCI�N PACIENTES POR CATEGOR�A ______
/*----------------------------------------------------
	Funci�n que nos ayuda a obtener losmpacientes por 
	categor�a de gravedad.
  --------------------------------------------------*/
void condicion(Paciente *p_paciente)
{
	int c[5]={0,0,0,0,0};
	// Se suman los contadores seg�n la gravedad del paciente.
	for(int i=0;i<PAC;i++)
	{
		switch((p_paciente+i)->cond)
		{
			case 1:
				c[0]++;
				break;
			case 2:
				c[1]++;
				break;
			case 3:
				c[2]++;
				break;
			case 4:
				c[3]++;
				break;
			case 5:
				c[4]++;
				break;
		}
	}
	// Se imprimen resultados.
	system("cls");
	color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";
	color(gric,ver);cout<<"\tPacientes por categor�a de gravedad.\n\n";
	for(int i=0;i<5;i++)
	{
		color(gric,azu);cout<<"\tGrado "<<i+1<<": ";color(gric,neg);cout<<c[i]<<" pacientes."<<endl;
	}		
}

//_____________ FUNCI�N PACIENTES POR CATEGOR�A ______
/*----------------------------------------------------
	Funci�n que nos ayuda a obtener losmpacientes por 
	categor�a de gravedad.
  --------------------------------------------------*/
void gravedad(Paciente *p_paciente)
{
	int grav=0;
	// Se comparan los pacientes en gravedad y con ello se imprimen s�lo los de gravedad 5.
	for(int i=0;i<PAC;i++)
	{
		if((p_paciente+i)->cond==5)
		{
			grav++;
		}
	}
	// Se iumprimen pacientes s�lo con gravedad 5.
	system("cls");
	color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";
	color(gric,ver);cout<<"\tPacientes en gravedad.\n\n";
	if(grav>0)
	{
		for(int i=0;i<PAC;i++)
		{
			if((p_paciente+i)->cond==5)
			{
				color(gric,azu);cout<<"\tNombre: ";color(gric,neg);cout<<(p_paciente+i)->nombre<<endl;
				color(gric,azu);cout<<"\tEdad: ";color(gric,neg);cout<<(p_paciente+i)->edad<<endl;
				color(gric,azu);cout<<"\tTel�fono: ";color(gric,neg);cout<<(p_paciente+i)->tel<<endl<<endl;
			}
		}
	}else
	{
		color(gric,roj);cout<<"\tNING�N PACIENTE EN ESTA CONDICI�N...";
	}		
}

//____________________________ FUNCI�N PRINCIPAL _____
main()
{
	// Se llama al,comando para uso de acentos, y se establece la consola con fondo blanco.
	setlocale(LC_ALL,"");system("color F0");
	// Se declaran la variable necesaria.
	string opc;
	char aux[30];
	bool error=false;
	
	do
	{
		// Se piden datos.
		for(int i=0;i<PAC;i++)
		{
			pedirDatos(p_paciente, i);
		}
		// Men� principal.
		do
		{
			system("cls");
			color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";color(gric,neg);
			color(gric,roj);cout<<"\t  a.";color(gric,neg);cout<<" Porcentaje de Hombres y Mujeres.\n";
			color(gric,roj);cout<<"\t  b.";color(gric,neg);cout<<" Pacientes en cada categor�a.\n";
			color(gric,roj);cout<<"\t  c.";color(gric,neg);cout<<" Pacientes en gravedad.\n";
			color(gric,roj);cout<<"\t  d.";color(gric,neg);cout<<" Volver a ejecutar.\n";
			color(gric,roj);cout<<"\t  e. <- Salir.\n\n";
			color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opci�n: ";
			color(gric,roj);cin>>opc;
			if(opc=="a")
			{
				// Funci�n para el porcentaje seg�n g�nero.
				porcentaje(p_paciente);
				getch();
			}else
			if(opc=="b")
			{
				// Funci�n para pacientes por condici�n.
				condicion(p_paciente);
				getch();
			}else
			if(opc=="c")
			{
				// Funci�n para pacientes s�lo con m�xima gravedad.
				gravedad(p_paciente);
				getch();
			}else
			if(opc=="d")
			{
				// Volver a ejecutar si se desea.
			}
			if(opc=="e")
			{
				color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
			}else
			{
				cout<<"\n\t# # # OPCI�N INV�LIDA # # #";
			}
		}while(opc!="d"&&opc!="e");
	}while(opc!="e");
	// Fin del programa.
}
