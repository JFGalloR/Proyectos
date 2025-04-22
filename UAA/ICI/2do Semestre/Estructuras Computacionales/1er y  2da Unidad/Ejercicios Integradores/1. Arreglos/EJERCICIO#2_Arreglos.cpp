/*===================================================
  EJERCICIO #2. Arreglos unidimensionales.
 --------------------------------------------------
  OBJETIVO:
	Elaborar uin programa donde se lea una frase y 
	determinar qu� caracteres se encuentran 
	repetidos, y cu�ntas veces aparece repetido 
	cada car�cter. Utilizar un arreglo con los 
	caracteres que van apareciendo y otro 
	correspondiente a la misma posici�n con el 
	n�mero de repeticiones. 
 --------------------------------------------------
  ELABORADORES:
	- Alejandro Castillo Mota
	- Luis Manuel Flores Jim�nez
	- Juan Francisco Gallo Ram�rez
 --------------------------------------------------
	17 de Febrero de 2023
	I.C.I. U.A.A.
====================================================*/
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <windows.h>
using namespace std;

// Definimos nuestros par�metros m�ximos de cadenas de carateres.
#define MAX 17

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

//_________________________ FUNCI�N DE B�SQUEDA ______
/*----------------------------------------------------
	Funci�n encargada de obtener las repeticiones de 
	cada caracter, e imprimir los resultados.
  --------------------------------------------------*/
void funcionPalabra()
{
	// Se definen las variables a utilizar.
	char palabra[MAX];
	char caracteres[MAX];
	int repeticion[MAX]={0};
	int n=0;
	// Se valida la entrada de la palabra.
	do
	{
		system("cls");
		color(roj,gric);cout<<"             REPETICIONES DE CARACTERES EN PALABRA            \n\n";
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa la palabra donde buscar: ";
		fflush(stdin);color(gric,roj);gets(palabra);
		if(strlen(palabra)>MAX-2)
		{
			color(gric,roj);cout<<"\n\t# # # INGRESA CADENA MENOR A "<<MAX-2<<" CARACTERES # # # ";
			getch();
		}
	}while(strlen(palabra)>MAX-2);
	
	for (int i = 0; i < strlen(palabra); i++)
    {
        bool aux = false;
        // Buscar el caracter en el arreglo de caracteres
        for (int j = 0; j < n; j++)
        {
            if (palabra[i] == caracteres[j])
            {
                aux = true;
                repeticion[j]++;
                break;
            }
        }
        // Si el caracter no ha sido encontrado, agregarlo al arreglo de caracteres
        if (aux==false)
        {
            caracteres[n] = palabra[i];
            repeticion[n]++;
            n++;
        }
    }
    // Se imprimen los resultados.
	system("cls");
	color(roj,gric);cout<<"             REPETICIONES DE CARACTERES EN PALABRA            \n\n";
	color(gric,roj);cout<<"\t> Palabra:\n";
	color(gric,neg);cout<<"\t  "<<palabra<<endl<<endl;
	color(gric,roj);cout<<"\t> Repeticiones:\n";
	for (int i = 0; i < n; i++)
    {
		color(gric,neg);cout << "\t- El caracter ";color(gric,roj);cout << caracteres[i];
		color(gric,neg);cout<< " se repite ";color(gric,roj);cout<< repeticion[i];color(gric,neg);cout<< " veces." << endl;
    }
	
}
//____________________________ FUNCI�N PRINCIPAL _____
main()
{
	// Se establecen las variables necesarias.
	string opc;
	// Se llama al,comando para uso de acentos, y se establece la consola con fondo blanco.
	setlocale(LC_ALL,"");system("color F0");
	// Men� inicial.
	do
	{
		system("cls");
		color(roj,gric);cout<<"             REPETICIONES DE CARACTERES EN PALABRA            \n\n";
		color(gric,roj);cout<<"\t  a.";color(gric,neg);cout<<" Ingresar palabra.\n";
		color(gric,roj);cout<<"\t  b. <- Salir.\n\n";
		color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opci�n: ";
		color(gric,roj);cin>>opc;
		// Tomando opci�n para evaluarla.
		if(opc=="a")
		{	// Llama a la funci�n para buscar un n�mero en un array de n�meros.
			funcionPalabra();
		}else
		if(opc=="b")
		{
			color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCI�N FINALIZADA "<<C<<"  ";
		}else
		{
			cout<<"\n\t# # # OPCI�N INV�LIDA # # #";
		}
		getch();
	}while(opc!="b");
	// Fin del programa.	
}
