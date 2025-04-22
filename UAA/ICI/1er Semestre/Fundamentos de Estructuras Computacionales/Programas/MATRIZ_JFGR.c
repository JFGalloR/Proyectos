/*=====================================
 MATRIZ DE AYDACENCIAS
---------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 FECHA: 17/10/2022
=====================================*/

#include <stdio.h>

int main()
{
	int tam = 5;
	int m_ady[tam][tam];
	int i, j;
	
	for(i=0;i<tam;i++)
	{
		for(j=0;j<tam;j++)
		{
			m_ady[i][j]=1;
			m_ady[i][i]=0;
			printf(" %i", m_ady[i][j]); 
		}
		printf("\n");
	}
}
