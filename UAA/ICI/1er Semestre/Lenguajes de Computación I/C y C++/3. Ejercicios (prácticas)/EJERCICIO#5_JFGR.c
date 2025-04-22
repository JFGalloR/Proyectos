/*=====================================================================
 QUIÉN ES MAYOR
=======================================================================
 OBJETIVO: Indicar cual es el mayor de dos personas y además de pedir su
 edad, pedir su nombre.
=======================================================================
 ENTRADAS: Nombres y edades de dos personas.
=======================================================================
 SALIDAS: Nombres de las personas y quién es mayor.
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripción = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
    Nombre 1          n1        Cadena     x           -         -
    Nombre 2          n2        Cadena     x           -         -
	Edad 1            e1        Entero     x           -         -
	Edad 2            e2        Entero     x           -         -
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACIÓN (Pseudocódigo):
 -------------------------------------------
 INICIO.
	Var: 
		Cadena: n1, n2
		Enteras: e1, e2
	Escribir ("Ingresa nombre 1: ")
	Leer (n1)
	Escribir ("Ingresa edad 1: ")
	Leer (e1)
	Escribir ("Ingresa nombre 2: ")
	Leer (n2)
	Escribir ("Ingresa edad 2: ")
	Leer (e2)
	Hacer:
		Si e1>e2 entonces
			Escribir (n1, " es mayor que ", n2)
		Si_no
			Si e1<e2 entonces
				Escribir (n2, " es mayor que ", n1)
			Si_no
				Escribir (n1, " tiene la misma edad que ", n2)
		Fin_Si
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ramírez
 28/09/2022 I.C.I.
=====================================================================*/

#include <stdio.h>
#include <locale.h>

int main ()
{
	char n1[20];
	char n2[20];
	int e1, e2;
	
	setlocale(LC_ALL, "");
	
	printf("=========== ¿QUIÉN ES MAYOR? ===========\n");
	
	printf("- Ingresa el nombre #1: \n");
	gets(n1);
	printf("- Ingresa su edad: \n");
	scanf("%i", &e1);
	fflush(stdin);
	printf("- Ingresa el nombre #2: \n");
	gets(n2);
	printf("- Ingresa su edad: \n");
	scanf("%i", &e2);
	
	printf("----------------------------------\n");
	if(e1>e2)
	{
		printf(" %s es mayor que %s.\n", n1, n2);
	}
	else 
	{
		if(e1<e2)
		{
			printf(" %s es mayor que %s.\n", n2, n1);
		}
		else
		{
			printf(" %s tiene la misma edad que %s.\n", n1, n2);
		}
	}
	printf("----------------------------------\n");
	printf("========================================\n");
	
	return 0;
}
