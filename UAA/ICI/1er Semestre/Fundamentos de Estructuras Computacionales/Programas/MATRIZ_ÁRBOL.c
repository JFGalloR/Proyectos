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
			m_ady[i][i]=0;
			m_ady[i][j]=0;
		}
	}
	for(i=0;i<tam;i++)
	{
		for(j=0;j<tam;j++)
		{
			m_ady[0][1]=1;
			m_ady[0][2]=1;
			m_ady[0][3]=1;
			m_ady[3][4]=1;
			m_ady[4][5]=1;
			m_ady[j][i]=m_ady[i][j];
			printf(" %i", m_ady[j][i]); 
		}
		printf("\n");
	}
}
