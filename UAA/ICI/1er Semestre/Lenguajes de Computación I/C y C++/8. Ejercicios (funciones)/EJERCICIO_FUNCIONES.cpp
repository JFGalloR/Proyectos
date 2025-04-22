/*=========================================================
 MEN� DE EJERCICIOS CON FUNCIONES
-----------------------------------------------------------
 OBJETIVO:
 Realizar un men� que muestre opciones de programas y seg�n 
 la opci�n elegida mientras no sea SALIR realizar:
 - PROGRAMA #1.
	 Usando una funci�n realizar la operaci�n de la f�rmula
	 general con los tres valores otorgados por el usuario,
	 y mostrar los resultados.
 - PROGRAMA #2.
 	 Usando funciones calcular la ra�z en�sima de un n�mero 
	 otorgado por el usuario, donde el �ndice tambi�n ser�
	 otorgar� el usuario, al final mostrar el resultado.
 Al elegir SALIR termina la ejecuci�n del programa.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
 31/10/2022 I.C.I.
=========================================================*/

#include <iostream>
#include <locale.h>
#include <math.h>
#include <windows.h>
using namespace std;

//--------FUNCI�N CON PASO DE PAR�METROS POR VALOR:
void f_general(float n1, float n2, float n3);
//--------FUNCI�N CON PASO DE PAR�METROS POR REFERENCIA:
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
		cout<<"========== MEN� DE PROGRAMAS ==========\n\n\n\n";
		cout<<" 1. Valores de ""x"" con f�rmula general.\n\n";
		cout<<" 2. Ra�z en�sima.\n\n";
		cout<<" 3. "<<"� Salir\n\n\n";
		cout<<"\n=======================================\n";
		cout<<" � Ingresa una opci�n: ";
		cin>>opc;
		
		switch(opc)
		{
			case 1://--------FUNCI�N CON PASO DE PAR�METROS POR VALOR:
				system("cls");
				cout<<"=========== F�RMULA GENERAL ===========\n\n";
				cout<<"\t     -b �(b�-4ac)^�\n";
				cout<<"\t x=-------------------\n";
				cout<<"\t           2a\n\n";
				cout<<"=======================================\n";
				cout<<" Donde:     ax� + bx + c = 0\n";
				cout<<"=======================================\n";
				cout<<" � Ingresa el valor de a: ";
				cin>>a;
				cout<<" � Ingresa el valor de b: ";
				cin>>b;
				cout<<" � Ingresa el valor de c: ";
				cin>>c;
				
				f_general(a, b, c);
				
				system("pause");
				
				break;
			case 2://--------FUNCI�N CON PASO DE PAR�METROS POR REFERENCIA:
				system("cls");
				cout<<"============ RA�Z EN�SIMA ============\n\n";
				cout<<" � Ingresa el valor del radicando: ";
				cin>>d;
				cout<<" � Ingresa el valor del �ndice: ";
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
				cout<<"\n\n ��� OPCI�N INV�LIDA ���\n\n\n";
				system("pause");	
		}
	}
	while(opc!=3);
	
	return 0;
}

//--------FUNCI�N CON PASO DE PAR�METROS POR VALOR:
void f_general(float n1, float n2, float n3)
{
	float res1, res2;
	system("cls");
	cout<<"============== RESULTADO ==============\n";
	cout<<"           "<<n1<<"x�"<<" + "<<n2<<"x + "<<n3<<" = 0\n";
	cout<<"=======================================\n";
	
	res1 = ((-1*n2)-sqrt(pow(n2,2)-4*n1*n3))/(2*n1);
	res2 = ((-1*n2)+sqrt(pow(n2,2)-4*n1*n3))/(2*n1);
	
	cout<<" x1 = "<<res1<<endl;
	cout<<" x2 = "<<res2<<endl;
	cout<<"=======================================\n";
}

//--------FUNCI�N CON PASO DE PAR�METROS POR REFERENCIA:
void r_enesima(float &d, float &e)
{
	e = pow(d,(1/e));
}


