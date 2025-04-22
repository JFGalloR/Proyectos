/*=====================================================================
 CÁLCULO DEL ÁREA DE UN CÍRCULO (con "#define")
=======================================================================
 OBJETIVO: Obtener el área de un círculo con los datos
 otorgados por el usuario utilizando "#define".
=======================================================================
 ENTRADAS: Valor de PI y el radio del círculo.
=======================================================================
 SALIDAS: El área del círculo con el radio proporcionada.
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripción = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
   Número PI          PI         Real      -          x       3.141592
    Radio             r          Real      x          -          -
  Opción final        c         Entero     x          -          -
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACIÓN (Pseudocódigo):
 -------------------------------------------
 INICIO.
	Var: 
		Reales: a, r
		Enteras: c
	Const:
		Reales: PI = 3.141592
	Repetir
		Escribir ("Ingresa el radio del círculo:")
		Leer (r)
		Hacer:
			a = PI * r^2
		Escribir ("El área es: ", a)
		Escribir ("Digite 1 para volver a calcular.")
		Escribir ("Digite otro número para terminar.")
		Leer c
	Hasta que c !=1
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ramírez
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
		printf("======= ÁREA DE UN CÍRCULO =======\n");
		printf("- Ingresa el radio del círculo: \n");
		scanf("%f", &r);
		
		a = PI * pow(r,2);
		
		printf("--------------------------------\n");
		printf(" Área = PI * %.2f^2 = %.2f\n", r, a);
		printf("--------------------------------\n");
		printf("==================================\n");
		printf("-Digite 1 para calcular otra área.\n");
		printf("-Digite otro número para terminar.\n");
		scanf("%i", &c);
	}
	while(c==1);
	
	
	return 0;
}
