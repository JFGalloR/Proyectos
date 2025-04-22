/* Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
Es posible que el codigo generado no sea completamente correcto. Si encuentra
errores por favor reportelos en el foro (http://pseint.sourceforge.net). */

#include<stdio.h>

/* En C no hay variables para guardar cadenas de texto, sino que debe construirse
   un arreglo de caracteres (tipo char). El tamaño del arreglo determina la longitud
   máxima que puede tener la cadena que guarda (tamaño-1, por el caracter de terminación).
   La constante MAX_STRLEN define el tamaño máximo que se utiliza en este programa para
   cualquier cadena. */
#define MAX_STRLEN 256

/* ============================================================================= */
/* /EJERCICIOS CON CONDICIONALES #1: APROBACIÓN O REPROBACIÓN DE ALUMNOS */
/* AUTOR: Juan Francisco Gallo Ramírez */
/* Universidad Autónoma de Aguascalientes */
/* I.C.I 31/08/2022 */
/* ============================================================================= */
/* /OBJETIVO:  */
/* Determinar con el promedio de las calificaciónes otorgadas si un alumno  */
/* aprueba o reprueba un curso.  */
/* ============================================================================= */
/* /DATOS DE ENTRADA:  */
/* Tres calificaciones. */
/* ============================================================================= */
/* /DATOS DE SALIDA:  */
/* Promedio de tres calificaciones y si aprueba o no. */
/* ============================================================================= */
/* /TABLA DE CONSTANTES Y VARIABLES: */
/* ---------------------------------------------------------------------- */
/* = Descripción = Identificador = Tipo = Variable = Constante = Valor = */
/* ---------------------------------------------------------------------- */
/* Calificación       C          Real       X          -         - */
/* Contador         I         Entero      X          -         - */
/* Acum. Cal.        AC         Real       X          -         - */
/* Promedio         P          Real       X          -         - */
/* Situación         S         Cadena      X          -         - */
/* ---------------------------------------------------------------------- */
/* ============================================================================= */
int main() {
	float ac;
	float c;
	int i;
	float p;
	char s[MAX_STRLEN];
	c = 0;
	ac = 0;
	printf("*** APROBACIÓN O REPROBACIÓN DE ALUMNOS ***\n");
	printf("___________________________________________\n");
	for (i=1;i<=3;i+=1) {
		printf("- Ingresa calificación # %i:\n",i);
		scanf("%f",&c);
		ac = ac+c;
	}
	p = ac/3;
	if (p>=7) {
		s = "APROBADO";
	} else {
		s = "REPROBADO";
	}
	printf("___________________________________________\n");
	printf("PROMEDIO: %f\n",p);
	printf("*** ALUMNO %s ***\n",s);
	return 0;
}

