/*=====================================================================
 MES DEL A�O 
=======================================================================
 OBJETIVO: Indicar a cual mes del a�o pertenece el n�mero otorgado por
 el usuario, y si esta fuera de rango marcar error.
=======================================================================
 ENTRADAS: Un n�mero entero.
=======================================================================
 SALIDAS: Mes del a�o.
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripci�n = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
	Un n�mero          m        Entero     x           -         -
	Mes               mes       Cadena     x           -         -
	Opci�n final        c         Entero     x          -          -
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACI�N (Pseudoc�digo):
 -------------------------------------------
 INICIO.
	Var: 
		Enteras: m, c
		Cadena: mes
	Repetir
		Repetir
			Escribir ("Ingresa un n�mero: ")
			Leer (m)
			Si m < 1 || m > 12 entonces
				Escrbir ("Mes icnorreto")
			Fin_Si
		Hasta que m > 1 || m < 12
		Seg�n_sea m Hacer:
			1: mes = "ENERO"
			2: mes = "FEBRERO"
			3: mes = "MARZO"
			4: mes = "ABRIL"
			5: mes = "MAYO"
			6: mes = "JUNIO"
			7: mes = "JULIO"
			8: mes = "AGOSTO"
			9: mes = "SEPTIEMBRE"
			10: mes = "OCTUBRE"
			11: mes = "NOVIEMBRE"
			12: mes = "DICIEMBRE"
		Fin_Seg�n
		Escribir ("El mes es ", mes)
		Escribir ("Digite 1 para volver a calcular.")
		Escribir ("Digite otro n�mero para terminar.")
		Leer c
	Hasta que c != 1
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ram�rez
 28/09/2022 I.C.I.
=====================================================================*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main ()
{
	int m;
	char mes [10];
	
	setlocale(LC_ALL, "");
	
	do
	{
		do
		{
			system("cls");
			cout << "======== MES DEL A�O ========" << endl;
			cout << "- Ingresa el n�mero del mes: " << endl;
			cin >> m;
			if(m<1 || m>12)
			{
				system("cls");
				cout << "----------------------" << endl;
				cout << "### MES INCORRECTO ###" << endl;
				cout << "----------------------" << endl;
				getch();
			}
		}
		while(m<1 || m>12);
		
		
		switch (m)
		{
			case 1:
				strcpy(mes, "ENERO");
				break;
			case 2:
				strcpy(mes, "FEBRERO");
				break;
			case 3:
				strcpy(mes, "MARZO");
				break;
			case 4:
				strcpy(mes, "ABRIL");
				break;
			case 5:
				strcpy(mes, "MAYO");
				break;
			case 6:
				strcpy(mes, "JUNIO");
				break;
			case 7:
				strcpy(mes, "JULIO");
				break;
			case 8:
				strcpy(mes, "AGOSTO");
				break;
			case 9:
				strcpy(mes, "SEPTIEMBRE");
				break;
			case 10:
				strcpy(mes, "OCTUBRE");
				break;
			case 11:
				strcpy(mes, "NOVIEMBRE");
				break;
			case 12:
				strcpy(mes, "DICIEMBRE");
				break;
		}
		
		cout << "--------------------------" << endl;
		cout << "  El mes es " << mes << endl;
		cout << "--------------------------" << endl;
		cout << "=============================" << endl;
		cout << "-Digite 1 para calcular otra �rea." << endl;
		cout << "-Digite otro n�mero para terminar." << endl;
		cin >> c;
	}
	while (c == 1);
		
	
	return 0;
}
