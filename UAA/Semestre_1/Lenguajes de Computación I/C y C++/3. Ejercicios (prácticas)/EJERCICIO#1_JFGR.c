/*=====================================================================
 C�LCULO DEL �REA DE UN C�RCULO (con "#define")
=======================================================================
 OBJETIVO: Obtener el �rea de un c�rculo con los datos
 otorgados por el usuario utilizando "#define".
=======================================================================
 ENTRADAS: Valor de PI y el radio del c�rculo.
=======================================================================
 SALIDAS: El �rea del c�rculo con el radio proporcionada.
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripci�n = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
   N�mero PI          PI         Real      -          x       3.141592
    Radio             r          Real      x          -          -
  Opci�n final        c         Entero     x          -          -
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACI�N (Pseudoc�digo):
 -------------------------------------------
 INICIO.
	Var: 
		Reales: a, r
		Enteras: c
	Const:
		Reales: PI = 3.141592
	Repetir
		Escribir ("Ingresa el radio del c�rculo:")
		Leer (r)
		Hacer:
			a = PI * r^2
		Escribir ("El �rea es: ", a)
		Escribir ("Digite 1 para volver a calcular.")
		Escribir ("Digite otro n�mero para terminar.")
		Leer c
	Hasta que c !=1
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ram�rez
 28/09/2022 I.C.I.
=====================================================================*/

#include <stdio.h>
#include <math.h>
#include <locale.h>


int main ()
{
	#define PI 3.141592
	
	float a, r;
	int c;
	
	setlocale(LC_ALL, "");
	
	do
	{
		system ("cls");
		printf("======= �REA DE UN C�RCULO =======\n");
		printf("- Ingresa el radio del c�rculo: \n");
		scanf("%f", &r);
		
		a = PI * pow(r,2);
		
		printf("--------------------------------\n");
		printf(" �rea = PI * %.2f^2 = %.2f\n", r, a);
		printf("--------------------------------\n");
		printf("==================================\n");
		printf("-Digite 1 para calcular otra �rea.\n");
		printf("-Digite otro n�mero para terminar.\n");
		scanf("%i", &c);
	}
	while(c==1);
	
	
	return 0;
}
