/*=========================================================
 EVALUACIÓN DE ALUMNOS.
-----------------------------------------------------------
 OBJETIVO:
 Según el nombre, tres calificaciones, y el total de faltas
 otorgado por el usuario, mostrar el nombre del alumno, sus
 tres calificaciones, su promedio, sus faltas, y si tiene 
 derecho al examen (más de 12 faltas pierde el derecho).
-----------------------------------------------------------
 AUTOR:
 Juan Francisco Gallo Ramírez
 16/11/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

#define CANT 10

struct materia
{
	char nombre[20];
	float cal[3];
	float prom;
	int faltas;
};

void main()
{
	struct materia alumno[CANT];
	int i, j;
	
	setlocale(LC_ALL, "");
	
	for(i=0;i<CANT;i++)
	{
		printf("================= MATERIA =================\n");
		printf("------------------------------------------\n");
		printf("  ALUMNO #%i\n", i+1);
		printf("------------------------------------------\n");
		printf("» Ingresa nombre:\n"); fflush(stdin);
		gets(alumno[i].nombre);
		for(j=0;j<3;j++)
		{
			printf("» Ingresa calificaión #%i:\n", j+1); 
			scanf("%f", &alumno[i].cal[j]);
		}
		printf("» Ingresa faltas:\n"); 
		scanf("%i", &alumno[i].faltas);
		system("cls");
	}
	
	printf("========================== MATERIA ==========================\n");
	printf("------------------------------------------------------------\n");
	printf(" Nombre \tE1\tE2\tE3\tProm\tFaltas\n");
	printf("------------------------------------------------------------\n");
	for(i=0;i<CANT;i++)
	{
		alumno[i].prom = 0;
		for(j=0;j<3;j++)
		{
			alumno[i].prom += alumno[i].cal[j];
		}
		
		alumno[i].prom = alumno[i].prom / 3;
		
		printf(" %s\t", alumno[i].nombre);
		for(j=0;j<3;j++)
		{
			printf("%.2f\t", alumno[i].cal[j]);
		}
		printf("%.2f\t", alumno[i].prom);
		
		printf("%i\t", alumno[i].faltas);
		
		if(alumno[i].faltas>12)
		{
			printf(" SD\n");
		}else
		{
			printf(" CD\n");
		}
	}
}
