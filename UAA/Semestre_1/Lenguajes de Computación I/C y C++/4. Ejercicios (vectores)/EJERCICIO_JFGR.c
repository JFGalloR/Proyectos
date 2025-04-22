/*=========================================================
 MENÚ CON 1O EJERCICIOS DE VECTORES
-----------------------------------------------------------
 OBJETIVO:
 Realizar un menú que muestre opciones de programas y según 
 la opción elegida realizar.
 - PROGRAMA #1.
	 Pedir al usuario 10 números y con base a ello 
	 mostrar el número mayor, menor y la cantidad de 
	 números pares.
 - PROGRAMA #2.
	 Pedir al usuario 10 números enteros, para depués 
	 pedir otros 2 números, y determinar si estos 2 últimos 
	 se encuentran en los 10 primeros, además de mostrar su 
	 posición.
 - PROGRAMA #3.
	 Pedir al usuario 10 números enteros para mostrarlos de 
	 menor a mayor.
 - PROGRAMA #4.
	 Pedir al usuario 10 números enteros para mostrarlos de
	 mayor a menor.
 - PROGRAMA #5.
	 Pedir al usuario 10 números enteros para elevarlos al 
	 cuadrado y mostrar los resultados.
 - PROGRAMA #6.
	 Pedir al usuario 8 números enteros para multiplicarlos 
	 por 2 y mostrar los resultados.
 - PROGRAMA #7.
	 Pedir al usuario 8 números enteros, para después
	 pedir otros 8 números y sumarlos, finalmente mostar al 
	 resultado.
 - PROGRAMA #8.
	 Pedir al usuario 8 números enteros, para después
	 pedir otros 8 números y resarlos, finalmente mostar al 
	 resultado.
 - PROGRAMA #9.
	 Pedir al usuario 8 números enteros, para después
	 pedir otros 8 números y multiplicarlos, finalmente mostar 
	 al resultado.
 - PROGRAMA #10.
	 Pedir al usuario 8 números enteros, para después
	 pedir otros 8 números y dividirlos, finalmente mostar 
	 al resultado.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
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
		printf("========= MENÚ DE PROGRAMAS =========\n");
		printf(" 1)  Número mayor, menor y pares.\n");
		printf(" 2)  Números repetidos.\n");
		printf(" 3)  Números de menor a mayor.\n");
		printf(" 4)  Números de mayor a menor.\n");
		printf(" 5)  Números al cuadrado.\n");
		printf(" 6)  Números multiplicados por dos.\n");
		printf(" 7)  Suma de números.\n");
		printf(" 8)  Resta de números.\n");
		printf(" 9)  Multiplicación de números.\n");
		printf(" 10) División de números.\n");
		printf(" 11) Salir.\n");
		printf("=====================================\n");
		printf("- Ingresa una opción: ");
		scanf("%i", &opc);
		system("cls");
		
		switch(opc)
		{
			case 1:
				//-------------------------PROGRAMA #1:
				
				anp=0;
				printf("===== NÚMERO MAYOR, MENOR Y PARES =====\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
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
				printf("  LOS NÚMEROS SON:\n");
				
				for(i=0;i<cnum;i++)
				{
					printf("  %i", num[i]);
				}
				printf("\n=======================================\n");
				printf("  EL NÚMERO MAYOR ES: %i\n", nma);
				printf("  SU POSICIÓN ES: ");
				for(i=0;i<cnum;i++)
				{
					if(nma==num[i])
					{
						printf("%i ", i+1);
					}
				}
				
				printf("\n---------------------------------------\n");
				printf("  EL NÚMERO MENOR ES: %i\n", nme);
				printf("  SU POSICIÓN ES: ");
				for(i=0;i<cnum;i++)
				{
					if(nme==num[i])
					{
						printf("%i ", i+1);
					}
				}
				
				printf("\n---------------------------------------\n");
				printf("  CANTIDAD DE NÚMEROS PARES: %i", anp);
				if(anp>0)
				{
					printf("\n  NÚMEROS PARES: ");
					for(i=0;i<cnum;i++)
					{
						if(num[i]%2==0)
						{
							printf("%i ", num[i]);
						}
					}
					printf("\n  SU POSICIÓN ES: ");
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
				printf("======== NÚMEROS REPETIDOS ========\n");
	
				for(i=0;i<cnum1;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("===================================\n");
				
				
				printf("  LOS NÚMEROS SON:\n");
				
				for(i=0;i<cnum1;i++)
				{
					printf("  %i", num1[i]);
				}
				
				printf("\n===================================\n");
				
				printf(" Ingresa %i números más: \n", cnum2);
				
				for(i=0;i<cnum2;i++)
				{
					printf("- Ingresa el número #%i: ", i+1);
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
							printf("\n - EL NÚMERO %i SE REPITE %i VECES.\n", num2[i], anr[i]);
						}
						else
						{
							printf("\n - EL NÚMERO %i SE REPITE %i VEZ.\n", num2[i], anr[i]);
						}
						
						printf("   SU POSICIÓN ES: ");
							
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
						printf("\n - EL NÚMERO %i NO SE REPITE.", num2[i]);
					}
				}
				printf("\n===================================\n");
				getch();
				
				break;
				
			case 3:
				//-------------------------PROGRAMA #3:
				
				cnum=10;
				printf("====== NÚMEROS DE MENOR A MAYOR ======\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
					scanf("%i", &num[i]);
				}
				printf("======================================\n");
				printf(" LOS NÚMEROS SON:\n");
				
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
				printf(" LOS NÚMEROS DE MENOR A MAYOR SON:\n");
				
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
				printf("====== NÚMEROS DE MAYOR A MENOR ======\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
					scanf("%i", &num[i]);
				}
				printf("======================================\n");
				printf(" LOS NÚMEROS SON:\n");
				
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
				printf(" LOS NÚMEROS DE MAYOR A MENOR SON:\n");
				
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
				printf("====== NÚMEROS AL CUADRADO ======\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
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
				printf("========== NÚMEROS POR 2 ==========\n");
	
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
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
				
				printf("====== SUMA DE DOS NÚMEROS ======\n");
				printf("PRIMEROS %i NÚMEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("---------------------------------\n");
				printf("SEGUNDOS %i NÚMEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
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
				printf("====== RESTA DE DOS NÚMEROS ======\n");
				printf("PRIMEROS %i NÚMEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("----------------------------------\n");
				printf("SEGUNDOS %i NÚMEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
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
				printf("==== MULTIPLICACIÓN DE DOS NÚMEROS ====\n");
				printf("PRIMEROS %i NÚMEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("---------------------------------------\n");
				printf("SEGUNDOS %i NÚMEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número #%i: ", i+1);
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
				printf("==== DIVISIÓN DE DOS NÚMEROS ====\n");
				printf("PRIMEROS %i NÚMEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
					scanf("%i", &num1[i]);
				}
				
				printf("---------------------------------\n");
				printf("SEGUNDOS %i NÚMEROS\n", cnum);
				
				for(i=0;i<cnum;i++)
				{
					printf("- Ingresa el número entero #%i: ", i+1);
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
				
				printf("### OPCIÓN NO VÁLIDA ###\n");
				printf("\nIntenta de nuevo...\n");
				getch();
				
		}
	}
	while(opc!=11);
	
	return 0;
}


