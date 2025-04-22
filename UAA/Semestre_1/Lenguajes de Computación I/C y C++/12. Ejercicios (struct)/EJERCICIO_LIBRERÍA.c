/*=========================================================
 BASE DE DATOS DE LIBRER�A.
-----------------------------------------------------------
 OBJETIVO:
 Guardar y Mostrar el Nombre del libro, el Nombre del 
 Autor y el Precio de la cantidad de Libros que indique 
 el usuario.
-----------------------------------------------------------
 AUTOR:
 Juan Francisco Gallo Ram�rez
 16/11/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>

struct libreria
{
	char titulo[100];
	char autor[75];
	unsigned long precio;
};

void main()
{
	struct libreria libro[10];
	int n, i;
	
	setlocale(LC_ALL, "");
	
	do
	{
		printf("================= LIBRER�A =================\n");
		printf("� Ingresa la cantidad de libros:\n");
		scanf("%i", &n); fflush(stdin);
		if(n<=0)
		{
			printf("\n\n ��� OPCI�N INV�LIDA ���\n\n\n");
			system("pause");
		}
		system("cls");
	}while(n<=0);
	

	for(i=0;i<n;i++)
	{
		printf("================= LIBRER�A =================\n");
		printf("------------------------------------------\n");
		printf("  LIBRO #%i\n", i+1);
		printf("------------------------------------------\n");
		printf("� T�tulo:\n");
		gets(libro[i].titulo); fflush(stdin);
		printf("� Autor:\n");
		gets(libro[i].autor); fflush(stdin);
		printf("� Precio:\n");
		scanf("%u", &libro[i].precio); fflush(stdin);
		printf("------------------------------------------\n");
		system("cls");
	}
	
	printf("================= LIBRER�A =================\n");
	printf("- Aqu� se muestran los libros ingresados:\n");
	printf("------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("  LIBRO #%i\n", i+1);
		printf("------------------------------------------\n");
		printf("� T�tulo:\n");
		printf("%s\n", libro[i].titulo);
		printf("� Autor:\n");
		printf("%s\n", libro[i].autor);
		printf("� Precio:\n");
		printf("%u\n", libro[i].precio);
		printf("------------------------------------------\n");
	}
	system("pause");
}
