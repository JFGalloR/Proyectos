/*===================================================
  EJERCICIO #5. Arreglos multidimensionales.
 --------------------------------------------------
  OBJETIVO:
	Elaborar un programa que por medio de un
	arreglo de 6*3*4 y su llenado con número 
	aleatorios que simulen ingreso de personas 
	por hora:
	 a) El total de personas que entraron al banco 
	    en el día por cada semana.
	 b) Cuántas horas no entró ninguna persona y 
	    cuáles fueron por día de cada semana.
	 c) Cuál fue la hora en la que entró el mayor 
	    número de personas de los lunes de cada 
		semana.
	 d) El número promedio de personas por hora 
	    que entraron al banco por día de cada 
		semana.
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
#include <time.h>
#include <windows.h>
using namespace std;

// Se declaran las constantes necesarias.
#define HOR 6
#define DIA 3
#define SEM 4
#define MAX 30
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

//__________________ FUNCIÓN PARA MOSTRAR DATOS  _____
/*----------------------------------------------------
	Función que nos a mostrar los datos generados 
	aleatoriamente, segun la hora, dia y semana.
  --------------------------------------------------*/
void mostrarDatos(int arreglo[][DIA][SEM])
{
	// Se recorre cada indice del arreglo y se imprimen la cantidad de personas.
	for(int i=0;i<SEM;i++)
	{
		for(int j=0;j<DIA;j++)
		{
			for(int k=0;k<HOR;k++)
			{
				color(gric,roj);cout<<" Semana = ";color(gric,neg);cout<<i+1;color(gric,roj);
				// 'Switch' para colocar el nombre del día segín sea el número del ciclo.
				switch (j)
				{
					case 0:
						cout<<"    Lunes     \t";
						break;
					case 1:
						cout<<"    Miércoles \t";
						break;
					case 2:
						cout<<"    Viernes   \t";
						break;
				}cout<<" Hora = ";color(gric,neg);cout<<k+1;color(gric,roj);cout<<"\t Personas: ";color(gric,neg);cout<<arreglo[k][j][i]<<endl;
			}
		}
	}
}

//____________ FUNCIÓN PARA MOSTRAR ESTADÍSTICAS _____
/*----------------------------------------------------
	Función encargada de mostrar las estadísticas 
	solicitadas.
  --------------------------------------------------*/
void mostrarEst(int arreglo[][DIA][SEM])
{
	// Se inicializan las variables necesarias.
	int personasDia[SEM][DIA]={0};
	int horas[HOR]={0};
	float aux, aux1;
	int hM=0, cP=0, cH=0;
	// Ciclo 'for' para recorrer los indices del arreglo.
	for(int i=0;i<SEM;i++)
	{
		color(gric,roj);cout<<"  "<<FF<<" SEMANA #"<<i+1<<endl;
		for(int j=0;j<DIA;j++)
		{
			// 'Switch' para colocar el nombre del día segín sea el número del ciclo.
			color(gric,azu);
			switch (j)
			{
				case 0:
					hM=0;cP=0;
					cout<<"\t"<<F<<" Lunes:\n";
					break;
				case 1:
					cout<<"\t"<<F<<" Miércoles:\n";
					break;
				case 2:
					cout<<"\t"<<F<<" Viernes\n";
					break;
			}
			cH=0;
			for(int k=0;k<HOR;k++)
			{
				if(j==0)
				{
					// Comparativa para obtener la hora en la que los lunes entro más personas.
					if(cP<arreglo[k][j][i])
					{
						hM=k;
						cP=arreglo[k][j][i];
					}
				}
				// Comparativa para analizar las horas en las que nadie fue al banco.
				if(arreglo[k][j][i]==0)
				{
					horas[cH]=k+1;
					cH++;
				}
				personasDia[i][j]+=arreglo[k][j][i];
			}
			// Se imprimen los datos generados.
			color(gric,neg);cout<<"\t\tIngresaron ";color(gric,ver);cout<<personasDia[i][j];color(gric,neg);;cout<<" personas.\n";
			aux=personasDia[i][j];aux1=HOR;
			color(gric,neg);cout<<"\t\tEn promedio "<<aux/aux1<<" por hora este día.\n";
			if(j==0)
			{
				color(gric,mor);cout<<"\t\tLa hora mas concurrida fue la # "<<hM+1<<".\n";
			}
			if(cH>0)
			{
				color(gric,cel);cout<<"\t\tHoras que no entró ninguna persona: "<<cH<<endl;
				cout<<"\t\tHora #: ";
				for(int l=0;l<cH;l++)
				{
					cout<<horas[l]<<"\t";
				}
				cout<<endl;
			}
		}
	}
}

//____________________________ FUNCIÓN PRINCIPAL _____
main()
{
	// Se llama al,comando para uso de acentos, y se establece la consola con fondo blanco.
	setlocale(LC_ALL,"");srand(time(NULL));system("color F0");
	// Se declaran la variable necesaria.
	string opc;
	do
	{
		// Se declaran la variables necesarias.
		int arreglo[HOR][DIA][SEM]={0};
		// Se asignan valores al arreglo de manera aleatoria, cada vez que el ciclo comience.
		for(int i=0;i<HOR;i++)
		{
			for(int j=0;j<DIA;j++)
			{
				for(int k=0;k<SEM;k++)
				{
					arreglo[i][j][k]= rand() % (MAX+1);
				}
			}
		}
		// Ciclo do-while para menú de interacción.
		do
		{
			// Menú inicial.
			system("cls");
			color(roj,gric);cout<<"                       ESTUDIO DE BANCO                       \n\n";color(gric,neg);
			color(gric,roj);cout<<"\t  a.";color(gric,neg);cout<<" Ver datos generados.\n";
			color(gric,roj);cout<<"\t  b.";color(gric,neg);cout<<" Ver estadíticas.\n";
			color(gric,roj);cout<<"\t  c.";color(gric,neg);cout<<" <-- Rehacer datos.\n";
			color(gric,roj);cout<<"\t  d. <<- Salir.\n\n";
			color(gric,roj);cout<<"\t"<<FF;color(gric,neg);cout<<" Ingresa una opción: ";
			color(gric,roj);cin>>opc;
			// Toma de opciones y comparación de la misma.
			if(opc=="a")
			{	// Llama a la función para mostrar los datos generados.
				system("cls");
				color(roj,gric);cout<<"                       ESTUDIO DE BANCO                       \n\n";color(gric,neg);
				mostrarDatos(arreglo);
			}else
			if(opc=="b")
			{	// Llama a la función para mostrar las estadísticas solicitadas.
				system("cls");
				color(roj,gric);cout<<"                       ESTUDIO DE BANCO                       \n\n";color(gric,neg);
				mostrarEst(arreglo);
			}else
			if(opc=="c")
			{	// Musetra la leyenda de nuevos datos generados, sale del ciclo y vuelve a asignar valores.
				color(gric,ver);cout<<"\n\t+ + + NUEVOS DATOS GENGERADOS + + +";
			}else
			if(opc=="d")
			{
				color(gric,ama);cout<<"\n\t  "<<C<<" EJECUCIÓN FINALIZADA "<<C<<"  ";
			}else
			{
				cout<<"\n\t# # # OPCIÓN INVÁLIDA # # #";getch();
			}
			getch();
		}while(opc!="c"&&opc!="d");
	}while(opc!="d");
	// Fin del programa.	
}
