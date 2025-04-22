/*===================================================
  EJERCICIO. Apuntadores - Estructuras.
 --------------------------------------------------
  OBJETIVO:
	En el Hospital “La Fraternidad” almacenan la 
	siguiente información de sus N pacientes. 
	Nombre y apellidos: Cadena de caracteres. 
	Edad: Entero. Sexo: Carácter. Condición: 
	Entero (Se refiere al estado de salud en que 
	ingresa el paciente. Los valores que toma van 
	de 1…5, y representan el máximo grado de 
	gravedad.) Teléfono. Escribir un programa en 
	C que genere lo siguiente: 
	• El porcentaje de hombres y mujeres 
	  registrados en el hospital. 
	• El número de paciente de cada una de las 
	  categorías de condición. 
	• El nombre y teléfono de todos los pacientes 
	  que tuvieron una condición de ingreso de 
	  máxima gravedad.
 --------------------------------------------------
  ELABORADORES:
	- Alejandro Castillo Mota
	- Luis Manuel Flores Jiménez
	- Juan Francisco Gallo Ramírez
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
// Definimos constantes para el uso de la función 'color()'.
const char C=2, F=16, FF=187;
const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;

//__________________ FUNCIÓN DE APOYO PARA COLOR _____
/*----------------------------------------------------
	Función que nos ayuda a modificar los colores 
	del texto en la consola.
  --------------------------------------------------*/
void color(int c_fondo,int c_texto)
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

//________ FUNCIÓN DE APOYO PARA VALIDAR NÚMEROS _____
/*----------------------------------------------------
	Función que nos ayuda a validar números mediante
	una comparación del rango de caracteres. Retorna 
	error si la cadena no es numérica.
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

//________ FUNCIÓN DE APOYO PARA VALIDAR LETRAS ______
/*----------------------------------------------------
	Función que nos ayuda a validar cadenas mediante
	una comparación del rango de caracteres. Retorna 
	error si la cadena es numérica.
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

//_________________________ FUNCIÓN PEDIR DATOS ______
/*----------------------------------------------------
	Función que nos ayuda a pedir los datos de los 
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
			color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NO NUMÉRICOS # # # ";
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
			// Finalmente, si se ingresó adecuadamente, se copia al destino.
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
			color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NUMÉRICOS # # # ";
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
			// Finalmente, si se ingresó adecuadamente, se copia al destino.
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
			color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NO NUMÉRICOS # # # ";
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
			// Finalmente, si se ingresó adecuadamente, se copia al destino.
			strcpy((p_paciente+i)->sexo,aux);
		}
	}while(error==true);
	// Pidiendo condición ==========================================================================================
	do
	{
		system("cls");error=false;
		color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";color(gric,neg);
		color(gric,negc);cout<<"\t PACIENTE #"<<i+1<<endl<<endl;
		color(gric,ver);cout<<"\t Condición"<<endl<<endl;color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa condición: ";
		fflush(stdin);color(gric,roj);gets(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionNum(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NUMÉRICOS # # # ";
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
			// Finalmente, si se ingresó adecuadamente, se copia al destino.
			(p_paciente+i)->cond=atoi(aux);
		}
	}while(error==true);
	// Pidiendo condición ==========================================================================================
	do
	{
		system("cls");error=false;
		color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";color(gric,neg);
		color(gric,negc);cout<<"\t PACIENTE #"<<i+1<<endl<<endl;
		color(gric,ver);cout<<"\t Teléfono"<<endl<<endl;color(gric,neg);
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa teléfono: ";
		fflush(stdin);color(gric,roj);gets(aux);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionNum(aux)==1)
		{
			// Se valida que sea una cadena de caracteres.
			color(gric,roj);cout<<"\n\t# # # INGRESA DÍGITOS NUMÉRICOS # # # ";
			error=true;
			getch();
		}else
		if(strlen(aux)!=10)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA TELÉFONO VÁLIDO (10 NÚMEROS) # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingresó adecuadamente, se copia al destino.
			(p_paciente+i)->tel=atoi(aux);
		}
	}while(error==true);
}

//_____________ FUNCIÓN % DE PACIENTES POR SEXO ______
/*----------------------------------------------------
	Función que nos ayuda a obtener el porcentaje de 
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
	color(gric,ver);cout<<"\tPorcentaje de pacientes según género.\n\n";
	color(gric,azu);cout<<"\tHombres: ";color(gric,neg);cout<<(cH*100)/PAC<<"%"<<endl;
	color(gric,azu);cout<<"\tMujeres: ";color(gric,neg);cout<<(cM*100)/PAC<<"%"<<endl;	
}

//_____________ FUNCIÓN PACIENTES POR CATEGORÍA ______
/*----------------------------------------------------
	Función que nos ayuda a obtener losmpacientes por 
	categoría de gravedad.
  --------------------------------------------------*/
void condicion(Paciente *p_paciente)
{
	int c[5]={0,0,0,0,0};
	// Se suman los contadores según la gravedad del paciente.
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
	color(gric,ver);cout<<"\tPacientes por categoría de gravedad.\n\n";
	for(int i=0;i<5;i++)
	{
		color(gric,azu);cout<<"\tGrado "<<i+1<<": ";color(gric,neg);cout<<c[i]<<" pacientes."<<endl;
	}		
}

//_____________ FUNCIÓN PACIENTES POR CATEGORÍA ______
/*----------------------------------------------------
	Función que nos ayuda a obtener losmpacientes por 
	categoría de gravedad.
  --------------------------------------------------*/
void gravedad(Paciente *p_paciente)
{
	int grav=0;
	// Se comparan los pacientes en gravedad y con ello se imprimen sólo los de gravedad 5.
	for(int i=0;i<PAC;i++)
	{
		if((p_paciente+i)->cond==5)
		{
			grav++;
		}
	}
	// Se iumprimen pacientes sólo con gravedad 5.
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
				color(gric,azu);cout<<"\tTeléfono: ";color(gric,neg);cout<<(p_paciente+i)->tel<<endl<<endl;
			}
		}
	}else
	{
		color(gric,roj);cout<<"\tNINGÚN PACIENTE EN ESTA CONDICIÓN...";
	}		
}

//____________________________ FUNCIÓN PRINCIPAL _____
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
		// Menú principal.
		do
		{
			system("cls");
			color(roj,gric);cout<<"                   HOSPITAL 'La Fraternidad'                  \n\n";color(gric,neg);
			color(gric,roj);cout<<"\t  a.";color(gric,neg);cout<<" Porcentaje de Hombres y Mujeres.\n";
			color(gric,roj);cout<<"\t  b.";color(gric,neg);cout<<" Pacientes en cada categoría.\n";
			color(gric,roj);cout<<"\t  c.";color(gric,neg);cout<<" Pacientes en gravedad.\n";
			color(gric,roj);cout<<"\t  d.";color(gric,neg);cout<<" Volver a ejecutar.\n";
			color(gric,roj);cout<<"\t  e. <- Salir.\n\n";
			color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opción: ";
			color(gric,roj);cin>>opc;
			if(opc=="a")
			{
				// Función para el porcentaje según género.
				porcentaje(p_paciente);
				getch();
			}else
			if(opc=="b")
			{
				// Función para pacientes por condición.
				condicion(p_paciente);
				getch();
			}else
			if(opc=="c")
			{
				// Función para pacientes sólo con máxima gravedad.
				gravedad(p_paciente);
				getch();
			}else
			if(opc=="d")
			{
				// Volver a ejecutar si se desea.
			}
			if(opc=="e")
			{
				color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
			}else
			{
				cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";
			}
		}while(opc!="d"&&opc!="e");
	}while(opc!="e");
	// Fin del programa.
}
