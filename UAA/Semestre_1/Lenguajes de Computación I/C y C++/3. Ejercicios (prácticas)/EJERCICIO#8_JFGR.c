/*=====================================================================
 PERSONAS MAYORES DE EDAD
=======================================================================
 OBJETIVO: Pedir la edad de 10 personas y determinar el número de
 personas que son  mayores de edad y las que no lo son.
=======================================================================
 ENTRADAS: Las 10 edades de personas.
=======================================================================
 SALIDAS: La cantidad de personas mayores y menores de edad.
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripción = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
	Edad              e         Entero     x           -         -
    Contador          i         Entero     x           -         -
    Acumulador        ma        Entero     x           -         -
	mayores
    Acumulador        me        Entero     x           -         -
	menores
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACIÓN (Pseudocódigo):
 -------------------------------------------
 INICIO.
	Var: 
		Enteras: e, i, ma, me
	Desde i=1 hasta i=10
		Hacer:
		Escribir ("Ingresa edad ")
		Leer (e)
		Si e<18 Entonces
			me = me + 1
		Si_No
			ma = ma + 1
		Fin_Si
	Fin_Desde
	Esribir ("Mayores de edad: ", ma)
	Esribir ("Menores de edad: ", me)
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ramírez
 28/09/2022 I.C.I.
=====================================================================*/

#include <stdio.h>

int main ()
{
	int i=1;
	int e, ma=0, me=0;
	
	for(i; i<=10; i++)
	{
		printf("====== PERSONAS MAYORES DE EDAD ======\n");
		printf("-----------------------\n");
		printf("MAYORES DE EDAD: %i\n", ma);
		printf("MENORES DE EDAD: %i\n", me);
		printf("-----------------------\n");
		printf("======================================\n");
		printf("- Ingresa edad de persona #%i: \n", i);
		scanf("%i", &e);
		
		if(e<18)
		{
			me += 1;
		}
		else
		{
			ma += 1;
		}
		
		system("cls");
	}
	printf("====== PERSONAS MAYORES DE EDAD ======\n");
	printf("-----------------------\n");
	printf("MAYORES DE EDAD: %i\n", ma);
	printf("MENORES DE EDAD: %i\n", me);
	printf("-----------------------\n");
	printf("======================================\n");
}
