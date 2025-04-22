/*=====================================================================
 SISTEMA DE COMPRA
=======================================================================
 OBJETIVO: Calcular el monto a pagar por artículos establecidos además
 del total a pagar con los datos otorgados por el usuario.
=======================================================================
 ENTRADAS: Valor de libros, cuadernos y plumas; cantidad de artículos.
=======================================================================
 SALIDAS: Cantidad de cada artíulo, total de cada artículo y total de 
 compra.
=======================================================================
 TABLA DE CONSTANTES Y VARIABLES:
 ---------------------------------------------------------------------
 = Descripción = Identificador = Tipo = Variable = Constante = Valor =
 ---------------------------------------------------------------------
    Libros             L        Entero     -           x        100
   Cuadernos           C         Real      -           x       15.5
    Plumas             P         Real      -           x       2.35
  Cant. libros       Cant_l     Entero     x           -         -
  Cant. cuader.      Cant_c     Entero     x           -         -
  Cant. plumas       Cant_p     Entero     x           -         -
   Tot. libros       Tot_l       Real      x           -         -
 Tot. cuadernos      Tot_c       Real      x           -         -
   Tot. plumas       Tot_p       Real      x           -         -
   Total compra       Tot        Real      x           -         -
   Opción final        c        Entero     x          -          -
 ---------------------------------------------------------------------
=======================================================================
 HERRAMIENTA DE PROGRAMACIÓN (Pseudocódigo):
 -------------------------------------------
 INICIO.
	Var: 
		Enteras: cant_l, cant_c, cant_p
		Reales: tot = 0, tot_l = 0, tot_c = 0, tot_p = 0
	Const:
		Reales: L = 100, C = 15.5, P = 2.35
	Repetir
		Escribir ("Ingresa la cantidad de libros: ")
		Leer (cant_l)
		Escribir ("Ingresa la cantidad de cuadernos: ")
		Leer (cant_c)
		Escribir ("Ingresa la cantidad de plumas: ")
		Leer (cant_p)
		
		Hacer:
			al = al + cant_l;
			ac = ac + cant_c;
			ap = ap + cant_p;
			tot_c = cant_c * C;
			tot_l = cant_l * L;
			tot_p = cant_p * P;
			tot = tot_l + tot_c + tot_p;
		Escribir (al, " libros de $", L, " el total : ", tot_l)
		Escribir (ac, " cuadernos de $", C, " el total : ", tot_c)
		Escribir (ap, " plumas de $", P, " el total : ", tot_p)
		Escribir ("El total es: ", tot)
	Hasta que c !=1
 FIN.
=======================================================================
 AUTOR: Juan Francisco Gallo Ramírez
 28/09/2022 I.C.I.
=====================================================================*/


#include <stdio.h>
#include <locale.h>


int main ()
{
	#define L 100
	#define C 15.5
	#define P 2.35

	int cant_l, cant_c, cant_p, al=0, ac=0, ap=0, c;
	float tot=0, tot_l=0, tot_c=0, tot_p=0;
	
	setlocale(LC_ALL, "");
	
	printf("========= SISTEMA DE COMPRA =========\n");
	do
	{
		printf("- Ingresa la cantidad de LIBROS: \n");
		scanf("%i", &cant_l);
		al = al + cant_l;
		
		printf("- Ingresa la cantidad de CUADERNOS: \n");
		scanf("%i", &cant_c);
		ac = ac + cant_c;
		
		printf("- Ingresa la cantidad de PLUMAS: \n");
		scanf("%i", &cant_p);
		ap = ap + cant_p;
		
		tot_c = al * C;
		tot_l = ac * L;
		tot_p = ap * P;
		
		tot = tot_l + tot_c + tot_p;
		
		printf("-- COMPRA -------------------------\n");
		printf("- Libros %i x $%i      = $%.2f\n", al, L, tot_l);
		printf("- Cuadernos %i x $%.2f = $%.2f\n", ac, C, tot_c);
		printf("- Plumas %i x $%.2f     = $%.2f\n", ap, P, tot_p);
		printf("-----------------------------------\n");
		printf("- TOTAL DE COMPRA      = $%.2f\n", tot);
		printf("-----------------------------------\n");
		printf("======================================\n");
		printf("-Digite 1 para agregar más artículos.\n");
		printf("-Digite otro número para terminar.\n");
		scanf("%i", &c);
	}
	while(c==1);
	
	
	
	return 0;
}
