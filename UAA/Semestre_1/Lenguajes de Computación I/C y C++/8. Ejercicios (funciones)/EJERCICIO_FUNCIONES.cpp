/*=========================================================
 MENÚ DE EJERCICIOS CON FUNCIONES
-----------------------------------------------------------
 OBJETIVO:
 Realizar un menú que muestre opciones de programas y según 
 la opción elegida mientras no sea SALIR realizar:
 - PROGRAMA #1.
	 Usando una función realizar la operación de la fórmula
	 general con los tres valores otorgados por el usuario,
	 y mostrar los resultados.
 - PROGRAMA #2.
 	 Usando funciones calcular la raíz enésima de un número 
	 otorgado por el usuario, donde el índice también será
	 otorgará el usuario, al final mostrar el resultado.
 Al elegir SALIR termina la ejecución del programa.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 31/10/2022 I.C.I.
=========================================================*/

#include <iostream>
#include <locale.h>
#include <math.h>
#include <windows.h>
using namespace std;

//--------FUNCIÓN CON PASO DE PARÁMETROS POR VALOR:
void f_general(float n1, float n2, float n3);
//--------FUNCIÓN CON PASO DE PARÁMETROS POR REFERENCIA:
void r_enesima(float &d, float &e);

int main()
{
	setlocale(LC_ALL, "");
	
	int opc;
	char z=16;
	float a, b, c, d, e;
	
	do
	{
		system("cls");
		cout<<"========== MENÚ DE PROGRAMAS ==========\n\n\n\n";
		cout<<" 1. Valores de ""x"" con fórmula general.\n\n";
		cout<<" 2. Raíz enésima.\n\n";
		cout<<" 3. "<<"« Salir\n\n\n";
		cout<<"\n=======================================\n";
		cout<<" « Ingresa una opción: ";
		cin>>opc;
		
		switch(opc)
		{
			case 1://--------FUNCIÓN CON PASO DE PARÁMETROS POR VALOR:
				system("cls");
				cout<<"=========== FÓRMULA GENERAL ===========\n\n";
				cout<<"\t     -b ±(b²-4ac)^½\n";
				cout<<"\t x=-------------------\n";
				cout<<"\t           2a\n\n";
				cout<<"=======================================\n";
				cout<<" Donde:     ax² + bx + c = 0\n";
				cout<<"=======================================\n";
				cout<<" « Ingresa el valor de a: ";
				cin>>a;
				cout<<" « Ingresa el valor de b: ";
				cin>>b;
				cout<<" « Ingresa el valor de c: ";
				cin>>c;
				
				f_general(a, b, c);
				
				system("pause");
				
				break;
			case 2://--------FUNCIÓN CON PASO DE PARÁMETROS POR REFERENCIA:
				system("cls");
				cout<<"============ RAÍZ ENÉSIMA ============\n\n";
				cout<<" « Ingresa el valor del radicando: ";
				cin>>d;
				cout<<" « Ingresa el valor del índice: ";
				cin>>e;
				cout<<"\n======================================\n";
				cout<<" "<<z<<" ("<<d<<")^1/"<<e;
				
				r_enesima(d, e);
				
				cout<<" = "<<e<<"\n";
				cout<<"=======================================\n";
				system("pause");
				
				break;
			case 3:
				system("cls");
				cout<<"------------------------\n";
				cout<<"------ FINALIZADO ------\n";
				cout<<"------------------------\n";
				
				break;
			default:
				system("cls");
				cout<<"\n\n ¤¤¤ OPCIÓN INVÁLIDA ¤¤¤\n\n\n";
				system("pause");	
		}
	}
	while(opc!=3);
	
	return 0;
}

//--------FUNCIÓN CON PASO DE PARÁMETROS POR VALOR:
void f_general(float n1, float n2, float n3)
{
	float res1, res2;
	system("cls");
	cout<<"============== RESULTADO ==============\n";
	cout<<"           "<<n1<<"x²"<<" + "<<n2<<"x + "<<n3<<" = 0\n";
	cout<<"=======================================\n";
	
	res1 = ((-1*n2)-sqrt(pow(n2,2)-4*n1*n3))/(2*n1);
	res2 = ((-1*n2)+sqrt(pow(n2,2)-4*n1*n3))/(2*n1);
	
	cout<<" x1 = "<<res1<<endl;
	cout<<" x2 = "<<res2<<endl;
	cout<<"=======================================\n";
}

//--------FUNCIÓN CON PASO DE PARÁMETROS POR REFERENCIA:
void r_enesima(float &d, float &e)
{
	e = pow(d,(1/e));
}


