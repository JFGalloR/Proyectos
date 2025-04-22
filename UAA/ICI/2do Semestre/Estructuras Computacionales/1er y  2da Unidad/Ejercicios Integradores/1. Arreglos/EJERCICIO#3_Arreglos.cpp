/*===================================================
  EJERCICIO #3. Arreglos multidimensionales.
 --------------------------------------------------
  OBJETIVO:
	Elaborar un programa donde se escriba una 
	funci�n que intercambie la fila i-�sima por 
	la j-�sima de un arreglo de dos dimensiones, 
	m x n. 
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
#include <time.h>
#include <windows.h>
using namespace std;

// Definimos nuestros par�metros m�ximos de cadenas de carateres.
#define MAX 20
#define MAX_2 22

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
bool validacionNum(char *cant)
{
	for(;*cant;++cant)
	if( '0' > *cant || '9' < *cant )
	{
		return 1;
	}
	return 0;
}

//___________________ FUNCI�N DE MOSTRAR MATRIZ ______
/*----------------------------------------------------
	Funci�n encargada de imprimir los valores de la
	matriz generada.
  --------------------------------------------------*/
void mostrarMatriz(int matriz[][MAX], int c, int f)
{
	color(gric,gric);cout<<endl<<"   ";
	for(int i=0;i<c;i++)
	{
		color(gric,roj);cout<<"\t"<<i+1;
	}
	cout<<endl<<endl;
	for(int i=0;i<f;i++)
	{
		color(gric,roj);cout<<"   "<<i+1;
		color(gric,neg);
		for(int j=0;j<c;j++)
		{
			cout<<"\t"<<matriz[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

//__________ FUNCI�N DE INTERCAMBIO DE COLUMNAS ______
/*----------------------------------------------------
	Funci�n encargada de obtener intercambiar columnas
	indicadas en la matriz.
  --------------------------------------------------*/
void cambioColumnas(int matriz[][MAX], char *cant, int c, int f)
{
	int aux[MAX];
	int col1, col2;
	bool error;
	system("cls");
	
	do
	{
		// Validamos datos de entrada.
		system("cls");error=false;
		color(azu,gric);cout<<"                   INTERCAMBIO DE COLUMNAS                    \n";
		mostrarMatriz(matriz, c, f);
		color(gric,azu);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa n�mero de columna: ";
		fflush(stdin);color(gric,azu);gets(cant);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionNum(cant)==1)
		{
			// Se valida que sea una cadena n�merica.
			color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
			error=true;
			getch();
		}else
		if(atoi(cant)>c || atoi(cant)<1)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA N�MERO ENTRE 1 Y "<<c<<" # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingres� adecuadamente, se convierte a num�rica.
			col1=atoi(cant)-1;
		}
	}while(error==true);
	do
	{
		system("cls");error=false;
		color(azu,gric);cout<<"                   INTERCAMBIO DE COLUMNAS                    \n";
		mostrarMatriz(matriz, c, f);
		color(gric,azu);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa columna destino: ";
		fflush(stdin);color(gric,azu);gets(cant);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionNum(cant)==1)
		{
			// Se valida que sea una cadena n�merica.
			color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
			error=true;
			getch();
		}else
		if(atoi(cant)>c || atoi(cant)<1)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA N�MERO ENTRE 1 Y "<<c<<" # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingres� adecuadamente, se convierte a num�rica.
			col2=atoi(cant)-1;
		}
	}while(error==true);
	// Se realiza en proceso de intercambio.
	for(int i=0;i<f;i++)
	{
		aux[i]=matriz[i][col1];
		matriz[i][col1]=matriz[i][col2];
		matriz[i][col2]=aux[i];
	}
	// Se muestra resultado.
	system("cls");
	color(azu,gric);cout<<"                   INTERCAMBIO DE COLUMNAS                    \n";
	mostrarMatriz(matriz, c, f);
	color(gric,azu);cout<<"\n\t+ + + MATRIZ ACTUALIZADA + + + ";
}
//_____________ FUNCI�N DE INTERCAMBIO DE FILAS ______
/*----------------------------------------------------
	Funci�n encargada de obtener intercambiar filas
	indicadas en la matriz.
  --------------------------------------------------*/
void cambioFilas(int matriz[][MAX], char *cant, int c, int f)
{
	int aux[MAX];
	int fil1, fil2;
	bool error;
	system("cls");
	
	do
	{
		// Validamos datos de entrada.
		system("cls");error=false;
		color(azu,gric);cout<<"                     INTERCAMBIO DE FILAS                     \n";
		mostrarMatriz(matriz, c, f);
		color(gric,azu);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa n�mero de fila: ";
		fflush(stdin);color(gric,azu);gets(cant);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionNum(cant)==1)
		{
			// Se valida que sea una cadena n�merica.
			color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
			error=true;
			getch();
		}else
		if(atoi(cant)>f || atoi(cant)<1)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA N�MERO ENTRE 1 Y "<<f<<" # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingres� adecuadamente, se convierte a num�rica.
			fil1=atoi(cant)-1;
		}
	}while(error==true);
	do
	{
		system("cls");error=false;
		color(azu,gric);cout<<"                     INTERCAMBIO DE FILAS                     \n";
		mostrarMatriz(matriz, c, f);
		color(gric,azu);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa fila destino: ";
		fflush(stdin);color(gric,azu);gets(cant);
		// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
		if(validacionNum(cant)==1)
		{
			// Se valida que sea una cadena n�merica.
			color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
			error=true;
			getch();
		}else
		if(atoi(cant)>f || atoi(cant)<1)
		{
			// Se valida que sea de la longitud adecuada.
			color(gric,roj);cout<<"\n\t# # # INGRESA N�MERO ENTRE 1 Y "<<f<<" # # # ";
			error=true;
			getch();
		}else
		{
			// Finalmente, si se ingres� adecuadamente, se convierte a num�rica.
			fil2=atoi(cant)-1;
		}
	}while(error==true);
	// Se realiza en proceso de intercambio.
	for(int i=0;i<c;i++)
	{
		aux[i]=matriz[fil1][i];
		matriz[fil1][i]=matriz[fil2][i];
		matriz[fil2][i]=aux[i];
	}
	// Se muestra resultado.
	system("cls");
	color(azu,gric);cout<<"                     INTERCAMBIO DE FILAS                     \n";
	mostrarMatriz(matriz, c, f);
	color(gric,azu);cout<<"\n\t+ + + MATRIZ ACTUALIZADA + + + ";
}

//____________________________ FUNCI�N PRINCIPAL _____
main()
{
	// Se establecen las variables necesarias.
	string opc;
	char cant[4];
	int matriz[MAX][MAX];
	int fil, col;
	bool error;
	// Se llama al,comando para uso de acentos, y se establece la consola con fondo blanco.
	setlocale(LC_ALL,"");srand(time(NULL));system("color F0");
	do
	{
		// Se pide la cantidad de columnas.
		do
		{
			system("cls");error=false;
			color(roj,gric);cout<<"                        MATRIZ DE n*n                         \n\n";
			color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa cantidad de columnas: ";
			fflush(stdin);color(gric,roj);gets(cant);
			// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
			if(validacionNum(cant)==1)
			{
				// Se valida que sea una cadena n�merica.
				color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
				error=true;
				getch();
			}else
			if(atoi(cant)>MAX || atoi(cant)<1)
			{
				// Se valida que sea de la longitud adecuada.
				color(gric,roj);cout<<"\n\t# # # INGRESA N�MERO ENTRE 1 Y "<<MAX<<" # # # ";
				error=true;
				getch();
			}else
			{
				// Finalmente, si se ingres� adecuadamente, se convierte a num�rica.
				col=atoi(cant);
			}
		}while(error==true);
		// Se pide la cantidad de filas.
		do
		{
			system("cls");error=false;
			color(roj,gric);cout<<"                        MATRIZ DE n*n                         \n\n";
			color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa cantidad de filas: ";
			fflush(stdin);color(gric,roj);gets(cant);
			// Sentencias para validar la cadena ingresada, se ingresa una cadena de caracteres.
			if(validacionNum(cant)==1)
			{
				// Se valida que sea una cadena n�merica.
				color(gric,roj);cout<<"\n\t# # # INGRESA D�GITOS NUM�RICOS # # # ";
				error=true;
				getch();
			}else
			if(atoi(cant)>MAX || atoi(cant)<1)
			{
				// Se valida que sea de la longitud adecuada.
				color(gric,roj);cout<<"\n\t# # # INGRESA N�MERO ENTRE 1 Y "<<MAX<<" # # # ";
				error=true;
				getch();
			}else
			{
				// Finalmente, si se ingres� adecuadamente, se convierte a num�rica.
				fil=atoi(cant);
			}
		}while(error==true);
		// Se inizializa la matriz con n�meros aleatorios.
		for(int i=0;i<fil;i++)
		{
			for(int j=0;j<col;j++)
			{
				matriz[i][j] = rand() % (100);
			}
		}
		do
		{
			// Men� principal.
			system("cls");
			color(roj,gric);cout<<"                        MATRIZ DE n*n                         \n\n";
			color(gric,roj);cout<<"\t  a.";color(gric,neg);cout<<" Intercambiar columnas.\n";
			color(gric,roj);cout<<"\t  b.";color(gric,neg);cout<<" Intercambiar filas.\n";
			color(gric,roj);cout<<"\t  c.";color(gric,ver);cout<<" --> Mostrar matriz.\n";
			color(gric,roj);cout<<"\t  d.";color(gric,neg);cout<<" <-- Rehacer matriz.\n";
			color(gric,roj);cout<<"\t  e. <<- Salir.\n\n";
			color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opci�n: ";
			color(gric,roj);cin>>opc;
			// Tomando opci�n para evaluarla.
			if(opc=="a")
			{	// Llama a la funci�n para intercambiar columnas.
				cambioColumnas(matriz, cant, col, fil);getch();
			}else
			if(opc=="b")
			{	// Llama a la funci�n para intercambiar filas.
				cambioFilas(matriz, cant, col, fil);getch();
			}else
			if(opc=="c")
			{
				// Mostramos la matriz.
				system("cls");
				color(roj,gric);cout<<"                        MATRIZ DE n*n                         \n";
				mostrarMatriz(matriz, col, fil);getch();
			}else
			if(opc=="d")
			{
			}else
			if(opc=="e")
			{
				color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
			}else
			{
				cout<<"\n\t# # # OPCI�N INV�LIDA # # #";getch();
			}
		}while(opc!="d"&&opc!="e");
	}while(opc!="e");
	// Fin del programa.	
}
