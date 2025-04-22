/*==================================================
  EJERCICIO #1. Ventas.
 ------------------------------------------------
 OBJETIVO:
 Obtener con base a datos ingresados, o bien, 
 generados aleatoriamente:
  > Nombre del mes en el que se obtuvo la mejor 
    venta.
  > El monto de la venta máxima obtenida.
  > Total de las ventas.
  > Promedio de ventas.
  > Mostrar las ventas de menor a mayor.
 ------------------------------------------------
 Juan Francisco Gallo Ramírez
 30/Enero/2023
 I.C.I. 
==================================================*/
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define MAX 12

const int neg=0, azu=1, ver=2, cel=3, roj=4, mor=5, ama=6, gri=7;
const int negc=8, azuc=9, verc=10, celc=11, rojc=12, morc=13, amac=14, gric=15;


void color(int c_fondo,int c_texto)//FUNCIÓN DE APOYO PARA COLOR
{
	int c_pix;
	c_pix = c_fondo*(16) + c_texto;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c_pix);
}

int main()
{
	float venta[MAX],venta2[MAX],aux[MAX];
	char mes[12][11]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
	float aux1=0;
	int opc,i,j,aux2=0,aux3[MAX]={0,1,2,3,4,5,6,7,8,9,10,11};
	
	setlocale(LC_ALL,"");
	srand(time(NULL));
	system("color F0");
	
	// - - - MENÚ INICIAL
	do
	{
		system("cls");
		color(4,15);printf("           RESUMEN DE VENTAS ANUALES           \n");
		color(15,4);printf("-----------------------------------------------\n");
		color(15,1);printf("\n\t1. ");
		color(15,0);printf("Ingresar datos.\n");
		color(15,1);printf("\t2. ");
		color(15,0);printf("Generar datos (aleatoriamente).\n");
		color(15,4);printf("\n-----------------------------------------------\n");
		color(15,4);printf("  %c ", 187);color(15,0);printf("Ingresa una opción: ");
		color(15,1);scanf("%i", &opc);
		if(opc<1 || opc>2)
		{
			color(7,4);printf("\n          ###   OPCIÓN INVÁLIDA   ###          \n\n");
			color(15,0);system("pause");
		}
	}while(opc<1 || opc>2);
	system("cls");
	
	// - - - CAPTURA O GENERACIÓN DE DATOS
	switch(opc)
	{
		case 1:
			system("cls");
			color(4,15);printf("             INTRODUCCIÓN DE DATOS             \n");
			color(15,4);printf("-----------------------------------------------\n");
			for(i=0;i<MAX;i++)
			{
				color(15,1);printf("   %c ", 187);
				color(15,0);printf("Ventas del mes #%i: ", i+1);
				color(15,1);scanf("%f", &venta[i]);
			}
			color(15,4);printf("-----------------------------------------------\n");
			color(2,15);printf("               DATOS CAPTURADOS                \n\n");
			color(15,0);system("pause");
			break;
		case 2:
			for(i=0;i<MAX;i++)
			{
				venta[i] = rand() % (RAND_MAX+1);
				venta[i] *= 1+rand() % (1000);
				venta[i] /= 100;
			}
			break;
	}
	
	// - - - MUESTRA DE RESULTADOS
	system("cls");
	color(4,15);printf("                MUESTRA DE DATOS               \n");
	color(15,4);printf("-----------------------------------------------\n");
	color(3,15);printf(" VENTAS POR MES                                \n");
	for(i=0;i<MAX;i++)
	{
		color(15,8);printf(" %c %s:\n",16,mes[i]);
		color(15,0);printf("\t$%.2f\n",venta[i]);
		aux1+=venta[i];
	}
	color(3,15);printf("\n TOTAL ANUAL                                   ");
	color(15,4);printf("\n\t$%.2f\n\n",aux1);
	color(3,15);printf(" PROMEDIO MENSUAL                              ");
	color(15,0);printf("\n\t$%.2f\n\n",aux1/MAX);
	color(3,15);printf(" VENTA MÁXIMA OBTENIDA                         ");
	aux1=venta[0];
	for(i=0;i<MAX;i++)
	{
		if(aux1<venta[i])
		{
			aux1=venta[i];
			aux2=i;
		}
	}
	color(15,0);printf("\n\tSe realizó en el mes de ");color(15,2);printf("%s",mes[aux2]);color(15,0);printf(":\n");
	color(15,1);printf("\t$%.2f\n\n", aux1);
	color(3,15);printf(" VENTAS DE MENOR A MAYOR                       ");
	for(i=0;i<MAX;i++)
	{
		venta2[i]=venta[i];
	}
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			if(venta2[i]<venta2[j])
			{
				aux[i]=venta2[i];
				venta2[i]=venta2[j];
				venta2[j]=aux[i];
				
				aux2=aux3[i];
				aux3[i]=aux3[j];
				aux3[j]=aux2;
			}
		}
	}
	for(i=0;i<MAX;i++)
	{
		color(15,8);printf("\n %c %s:\n",16,mes[aux3[i]]);
		color(15,0);printf("\t$%.2f",venta2[i]);
	}
	color(15,4);printf("\n-----------------------------------------------\n");
	color(4,15);printf("                  FINALIZADO                   ");
	color(15,4);printf("\n-----------------------------------------------\n");
	color(15,0);system("pause");
}


















