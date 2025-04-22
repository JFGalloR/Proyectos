/*=========================================================
 MEN� CON 1O EJERCICIOS DE VECTORES
-----------------------------------------------------------
 OBJETIVO:
 Realizar un men� que muestre opciones de programas y seg�n 
 la opci�n elegida realizar.
 - PROGRAMA #1.
	 Pedir al usuario 10 n�meros y con base a ello 
	 mostrar el n�mero mayor, menor y la cantidad de 
	 n�meros pares.
 - PROGRAMA #2.
	 Pedir al usuario 10 n�meros enteros, para depu�s 
	 pedir otros 2 n�meros, y determinar si estos 2 �ltimos 
	 se encuentran en los 10 primeros, adem�s de mostrar su 
	 posici�n.
 - PROGRAMA #3.
	 Pedir al usuario 10 n�meros enteros para mostrarlos de 
	 menor a mayor.
 - PROGRAMA #4.
	 Pedir al usuario 10 n�meros enteros para mostrarlos de
	 mayor a menor.
 - PROGRAMA #5.
	 Pedir al usuario 10 n�meros enteros para elevarlos al 
	 cuadrado y mostrar los resultados.
 - PROGRAMA #6.
	 Pedir al usuario 8 n�meros enteros para multiplicarlos 
	 por 2 y mostrar los resultados.
 - PROGRAMA #7.
	 Pedir al usuario 8 n�meros enteros, para despu�s
	 pedir otros 8 n�meros y sumarlos, finalmente mostar al 
	 resultado.
 - PROGRAMA #8.
	 Pedir al usuario 8 n�meros enteros, para despu�s
	 pedir otros 8 n�meros y resarlos, finalmente mostar al 
	 resultado.
 - PROGRAMA #9.
	 Pedir al usuario 8 n�meros enteros, para despu�s
	 pedir otros 8 n�meros y multiplicarlos, finalmente mostar 
	 al resultado.
 - PROGRAMA #10.
	 Pedir al usuario 8 n�meros enteros, para despu�s
	 pedir otros 8 n�meros y dividirlos, finalmente mostar 
	 al resultado.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ram�rez
 09/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

int main ()
{
	int cnum=10, cnum1=10, cnum2=10;
	int num[cnum], num1[cnum1], num2[cnum2], anr[cnum2], res[cnum];
	float num1f[cnum], num2f[cnum], resf[cnum];
	int i, j, n, opc, nma, nme, anp;
	
	setlocale(LC_ALL, "");
	
	do
	{
		system("cls");
		printf("========= MEN� DE PROGRAMAS =========\n");
		printf(" 1)  N�mero mayor, menor y pares.\n");
		printf(" 2)  N�meros repetidos.\n");
		printf(" 3)  N�meros de menor a mayor.\n");
		printf(" 4)  N�meros de mayor a menor.\n");
		printf(" 5)  N�meros al cuadrado.\n");
		printf(" 6)  N�meros multiplicados por dos.\n");
		printf(" 7)  Suma de n�meros.\n");
		printf(" 8)  Resta de n�meros.\n");
		printf(" 9)  Multiplicaci�n de n�meros.\n");
		printf(" 10) Divisi�n de n�meros.\n");
		printf(" 11) Salir.\n");
		printf("=====================================\n");
		printf("- Ingresa una opci�n: ");
		scanf("%i", &opc);
		system("cls");
		
		switch(opc)
		{
			case 1:
				//-------------------------PROGRAMA #1:
				
				anp=0;
				printf("===== N�MERO MAYOR, MENOR Y PARES =====\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num[i]);
					
					if(i==0)
					{
						nma = num[i];
					}else
					{
						if(nma<num[i])
						{
							nma = num[i];
						}
					}
					if(i==0)
					{
						nme = num[i];
					}else
					{
						if(nme>num[i])
						{
							nme = num[i];
						}
					}
					if(num[i]%2==0)
					{
						anp ++;
					}
				}
				printf("=======================================\n");
				printf("  LOS N�MEROS SON:\n");
				
				for(i=0;i<cnum;i++)
				{
					printf("  %i", num[i]);
				}
				printf("\n=======================================\n");
				printf("  EL N�MERO MAYOR ES: %i\n", nma);
				printf("  SU POSICI�N ES: ");
				for(i=0;i<cnum;i++)
				{
					if(nma==num[i])
					{
						printf("%i ", i+1);
					}
				}
				
				printf("\n---------------------------------------\n");
				printf("  EL N�MERO MENOR ES: %i\n", nme);
				printf("  SU POSICI�N ES: ");
				for(i=0;i<cnum;i++)
				{
					if(nme==num[i])
					{
						printf("%i ", i+1);
					}
				}
				
				printf("\n---------------------------------------\n");
				printf("  CANTIDAD DE N�MEROS PARES: %i", anp);
				if(anp>0)
				{
					printf("\n  N�MEROS PARES: ");
					for(i=0;i<cnum;i++)
					{
						if(num[i]%2==0)
						{
							printf("%i ", num[i]);
						}
					}
					printf("\n  SU POSICI�N ES: ");
					for(i=0;i<cnum;i++)
					{
						if(num[i]%2==0)
						{
							printf("%i ", i+1);
						}
					}
				}
				
				printf("\n=======================================\n");
				getch();
				
				break;
				
			case 2:
				//-------------------------PROGRAMA #2:
				
				cnum1=10;
				cnum2=2;
				for(i=0;i<cnum2;i++)
				{
					anr[i]=0;
				}
				printf("======== N�MEROS REPETIDOS ========\n");
	
				for(i=0;i<cnum1;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("===================================\n");
				
				
				printf("  LOS N�MEROS SON:\n");
				
				for(i=0;i<cnum1;i++)
				{
					printf("  %i", num1[i]);
				}
				
				printf("\n===================================\n");
				
				printf(" Ingresa %i n�meros m�s: \n", cnum2);
				
				for(i=0;i<cnum2;i++)
				{
					printf("- Ingresa el n�mero #%i: ", i+1);
					scanf("%i", &num2[i]);
					
					for(j=0;j<cnum1;j++)
					{
						if(num2[i]==num1[j])
						{
							anr[i] ++;
						}
					}
				}
				printf("===================================");
				
				for(i=0;i<cnum2;i++)
				{
					if(anr[i]>0)
					{
						if(anr[i]>1)
						{
							printf("\n - EL N�MERO %i SE REPITE %i VECES.\n", num2[i], anr[i]);
						}
						else
						{
							printf("\n - EL N�MERO %i SE REPITE %i VEZ.\n", num2[i], anr[i]);
						}
						
						printf("   SU POSICI�N ES: ");
							
						for(j=0;j<cnum1;j++)
						{
							if(num2[i]==num1[j])
							{
								printf("  %i", j+1);
							}
						}
					}
					else
					{
						printf("\n - EL N�MERO %i NO SE REPITE.", num2[i]);
					}
				}
				printf("\n===================================\n");
				getch();
				
				break;
				
			case 3:
				//-------------------------PROGRAMA #3:
				
				cnum=10;
				printf("====== N�MEROS DE MENOR A MAYOR ======\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num[i]);
				}
				printf("======================================\n");
				printf(" LOS N�MEROS SON:\n");
				
				for(i=0;i<cnum;i++)
				{
					printf(" %i ", num[i]);
				}
				
				for(i=0;i<cnum-1;i++)
				{
					for(j=0;j<cnum-1;j++)
					{
						if(num[j]>num[j+1])
						{
							n=num[j];
							num[j]=num[j+1];
							num[j+1]=n;
						}
					}
				}
				
				printf("\n======================================\n");
				printf(" LOS N�MEROS DE MENOR A MAYOR SON:\n");
				
				for(i=0;i<cnum;i++)
				{
					printf(" %i ", num[i]);
				}
				
				printf("\n======================================\n");
				getch();
				
				break;
				
			case 4:
				//-------------------------PROGRAMA #4:
				
				cnum=10;
				printf("====== N�MEROS DE MAYOR A MENOR ======\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num[i]);
				}
				printf("======================================\n");
				printf(" LOS N�MEROS SON:\n");
				
				for(i=0;i<cnum;i++)
				{
					printf(" %i ", num[i]);
				}
				
				for(i=0;i<cnum-1;i++)
				{
					for(j=0;j<cnum-1;j++)
					{
						if(num[j]<num[j+1])
						{
							n=num[j];
							num[j]=num[j+1];
							num[j+1]=n;
						}
					}
				}
				
				printf("\n======================================\n");
				printf(" LOS N�MEROS DE MAYOR A MENOR SON:\n");
				
				for(i=0;i<cnum;i++)
				{
					printf(" %i ", num[i]);
				}
				
				printf("\n======================================\n");
				getch();
				
				break;
				
			case 5:
				//-------------------------PROGRAMA #5:
				
				cnum=10;
				printf("====== N�MEROS AL CUADRADO ======\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num[i]);
					
					res[i]=pow(num[i], 2);
				}
				printf("=================================\n");
				printf(" RESULTADOS: \n");
				
				for(i=0;i<cnum;i++)
				{
					printf(" %i.  %i^2 = %i\n", i+1, num[i], res[i]);
				}
				printf("=================================\n");
				getch();
				
				break;
				
			case 6:
				//-------------------------PROGRAMA #6:
				
				cnum=10;
				printf("========== N�MEROS POR 2 ==========\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num[i]);
					
					res[i]=num[i]*2;
				}
				printf("===================================\n");
				printf(" RESULTADOS: \n");
				
				for(i=0;i<cnum;i++)
				{
					printf(" %i.  %i * 2 = %i\n", i+1,num[i], res[i]);
				}
				printf("===================================\n");
				getch();
				
				break;
				
			case 7:
				//-------------------------PROGRAMA #7:
				
				cnum=8;
				for(i=0;i<cnum2;i++)
				{
					num1[i]=0;
				}
				
				printf("====== SUMA DE DOS N�MEROS ======\n");
				printf("PRIMEROS %i N�MEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("---------------------------------\n");
				printf("SEGUNDOS %i N�MEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num2[i]);
				}
				
				printf("=================================\n");
				printf(" RESULTADOS: \n");
				
				for(i=0;i<cnum;i++)
				{
					res[i]=num1[i]+num2[i];
					printf(" %i.  %i + %i = %i\n", i+1, num1[i], num2[i], res[i]);
				}
				printf("=================================\n");
				getch();
				
				break;
				
			case 8:
				//-------------------------PROGRAMA #8:
				
				cnum=8;
				printf("====== RESTA DE DOS N�MEROS ======\n");
				printf("PRIMEROS %i N�MEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("----------------------------------\n");
				printf("SEGUNDOS %i N�MEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num2[i]);
				}
				
				printf("==================================\n");
				printf(" RESULTADOS: \n");
				
				for(i=0;i<cnum;i++)
				{
					res[i]=num1[i]-num2[i];
					printf(" %i.  %i - %i = %i\n", i+1, num1[i], num2[i], res[i]);
				}
				printf("==================================\n");
				getch();
				
				break;
				
			case 9:
				//-------------------------PROGRAMA #9:
				
				cnum=8;
				printf("==== MULTIPLICACI�N DE DOS N�MEROS ====\n");
				printf("PRIMEROS %i N�MEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("---------------------------------------\n");
				printf("SEGUNDOS %i N�MEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero #%i: ", i+1);
					scanf("%i", &num2[i]);
				}
				
				printf("=======================================\n");
				printf(" RESULTADOS: \n");
				
				for(i=0;i<cnum;i++)
				{
					res[i]=num1[i]*num2[i];
					printf(" %i.  %i * %i = %i\n", i+1, num1[i], num2[i], res[i]);
				}
				printf("=======================================\n");
				getch();
				
				break;
				
			case 10:
				//-------------------------PROGRAMA #10:
				
				cnum=8;
				printf("==== DIVISI�N DE DOS N�MEROS ====\n");
				printf("PRIMEROS %i N�MEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("---------------------------------\n");
				printf("SEGUNDOS %i N�MEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el n�mero entero #%i: ", i+1);
					scanf("%i", &num2[i]);
				}
				
				printf("=================================\n");
				printf(" RESULTADOS: \n");
				
				for(i=0;i<cnum;i++)
				{
					num1f[i]=num1[i];
					num2f[i]=num2[i];
					resf[i]=num1f[i]/num2f[i];
					printf(" %i.  %i / %i = %.2f\n", i+1, num1[i], num2[i], resf[i]);
				}
				printf("=================================\n");
				getch();
				
				break;
				
			case 11:
				//-------------------------SALIR:
				
				printf("        =====================\n");
				printf("=============== SALIR ===============\n");
				printf("        =====================\n");
				getch();
				
				break;
			
			default:
				
				printf("### OPCI�N NO V�LIDA ###\n");
				printf("\nIntenta de nuevo...\n");
				getch();
				
		}
	}
	while(opc!=11);
	
	return 0;
}


