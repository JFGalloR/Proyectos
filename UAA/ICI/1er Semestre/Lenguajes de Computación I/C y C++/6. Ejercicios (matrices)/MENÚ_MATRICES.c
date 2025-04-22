/*=========================================================
 MENÚ DE EJERCICIOS DE MATRICES
-----------------------------------------------------------
 OBJETIVO:
 Realizar un menú que muestre opciones de programas y según 
 la opción elegida mientras no sea SALIR realizar:
 - PROGRAMA #1.
	 Realizar una matriz de 4*4 con números enteros los 
	 cuales son otorgados por el usuario, e imprimir la 
	 matriz realizada así como la suma de todos los 
	 elementos contenidos en dicha matriz.
 - PROGRAMA #2.
	 Realizar una matriz de 4*4 con números enteros los 
	 cuales son otorgados por el usuario, e imprimir la 
	 matriz realizada así como la suma de los elementos 
	 contenidos en cada fila de dicha matriz.
 - PROGRAMA #3.
	 Realizar una matriz de 4*4 con números enteros los 
	 cuales son otorgados por el usuario, e imprimir la 
	 matriz realizada así como la suma de los elementos 
	 contenidos en cada columna de dicha matriz.
 - PROGRAMA #3.
	 Realizar una matriz de 4*4 con números enteros los 
	 cuales son otorgados por el usuario, e imprimir la 
	 matriz realizada así como la suma de los elementos 
	 contenidos en cada columna y fila de dicha matriz.
 - PROGRAMA #5.
	 Realizar una matriz cuadrada con números enteros 
	 otorgados por el usuario de n*n donde n es un entero
	 otorgado por el usuario, y multiplicar dicha matriz
	 por un escalar otorgado por el usuario, finalmente
	 imprimir una matriz con los datos ingresados y otra
	 matriz con los resultados.
 - PROGRAMA #6.
	 Realizar dos matrices cuadradas con números enteros 
	 otorgados por el usuario de n*n donde n es un entero
	 otorgado por el usuario, sumar dichas matrices para
	 finalmente imprimir las dos matrices con los datos
	 ingresados y una tercera con los resultados de sumar
	 cada casilla de una matriz con la homóloga de la otra.
 - PROGRAMA #7.
	 Realizar una matriz cuadrada con números enteros 
	 otorgados por el usuario de n*n donde n es un entero
	 otorgado por el usuario, y ordenar los datos de menor
	 a mayor, finalmente imprimir la matriz de datos 
	 ingresados y la matriz de datos ordenados.
 - PROGRAMA #8.
	 Realizar una matriz cuadrada con números enteros 
	 otorgados por el usuario de n*n donde n es un entero
	 otorgado por el usuario, y ordenar los datos de mayor
	 a menor, finalmente imprimir la matriz de datos 
	 ingresados y la matriz de datos ordenados.
 - PROGRAMA #9.
	 Realizar una matriz cuadrada de n*n donde n es un entero
	 otorgado por el usuario, de tal forma que tenga las
	 caraterísticas de una matriz identidad.
 Al elegir SALIR termina la ejecución del programa.
-----------------------------------------------------------
 AUTOR: Juan Francisco Gallo Ramírez
 13/10/2022 I.C.I.
=========================================================*/

#include <stdio.h>
#include <locale.h>
#include <windows.h>

 void gotoxy(int x,int y)
 {
	HANDLE hcon;  
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
 } 
 
int main ()
{
	int opc, i, j, k, l, q, asum, c, asumf, n;
	int a=4, b=100;
	int num[b][b], asumc[b], num1[b][b], sum[b][b];
	float numf[b][b], res[b][b];
	float x;
	
	setlocale(LC_ALL, "");
	
	do
	{
		system("cls");
		printf("================= MENÚ DE MATRICES =================\n\n\n\n");
		printf("  1)  Matrices de %i*%i  ->\n\n", a, a);
		printf("  2)  Matrices de n*n  ->\n\n");
		printf("  3)  Salir.\n\n\n\n");
		printf("====================================================\n");
		printf("- Ingresa una opción: ");
		scanf("%i", &opc);
		system("cls");
		switch(opc)
		{
			case 1:
				do
				{
					system("cls");
					printf("================= MENÚ DE MATRICES =================\n\n");
					printf(" ----------------------------------\n");
					printf(" -- MATRICES DE %i*%i ----------\n", a, a);
					printf(" ------------------------\n\n");
					printf("  1)  Suma de todos los elementos de la matriz ->\n");
					printf("  2)  Suma de los elementos por fila           ->\n");
					printf("  3)  Suma de los elementos por columna        ->\n");
					printf("  4)  Suma de los elementos por fila y columna ->\n");
					printf("  5)  <- Regresar.\n\n");
					printf("====================================================\n");
					printf("- Ingresa una opción: ");
					scanf("%i", &opc);
					system("cls");
					switch(opc)
					{
						case 1:
							//---------------- PROGRAMA #1:
							system("cls");
							asum=0;
							c=0;
							printf("==== SUMA DE TODOS LOS ELEMENTOS DE LA MATRIZ ====\n");
							gotoxy(0,a*a+3);
							printf("==================================================\n");
							for(i=0;i<a;i++)
							{
								gotoxy(53, (i+1)*3+2);
								printf("%i) ",i+1);
								for(j=0;j<a;j++)
								{
									gotoxy(0,c+2);
									printf("- Ingresa el valor de (%i,%i): ", i+1, j+1);
									scanf("%i", &num[i][j]);
									asum=asum+num[i][j];
									gotoxy((j+7)*8+1, 3);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (i+1)*3+2);
									printf("%i", num[i][j]);
									gotoxy(57, 1);
									printf("- ACUMULADOR DE SUMA = %i", asum);
									c++;
								}
							}
							gotoxy(0,a*a+4);
							printf(" FINALIZADO...\n");
							getch();
							
							break;
						case 2:
							//---------------- PROGRAMA #2:
							system("cls");
							asumf=0;
							c=0;
							printf("==== SUMA DE LOS ELEMENTOS POR FILA DE LA MATRIZ ====\n");
							gotoxy(0,a*a+3);
							printf("=====================================================\n");
							for(i=0;i<a;i++)
							{
								gotoxy(56, (i+1)*3);
								printf("%i) ",i+1);
								for(j=0;j<a;j++)
								{
									gotoxy(0,c+2);
									printf("- Ingresa el valor de (%i,%i): ", i+1, j+1);
									scanf("%i", &num[i][j]);
									asumf=asumf+num[i][j];
									gotoxy((j+7)*8+4, 1);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+4, (i+1)*3);
									printf("%i", num[i][j]);
									gotoxy((a+6)*8+4, (i+1)*3);
									printf("\t= %i", asumf);
									c++;
								}
								asumf=0;
							}
							gotoxy(0,a*a+4);
							printf(" FINALIZADO...\n");
							getch();
							
							break;
						case 3:
							//---------------- PROGRAMA #3:
							system("cls");
							for(i=0;i<a;i++)
							{
								asumc[i]=0;
							}
							c=0;
							printf("== SUMA DE LOS ELEMENTOS POR COLUMNA DE LA MATRIZ ==\n");
							gotoxy(0,a*a+3);
							printf("=====================================================\n");
							for(i=0;i<a;i++)
							{
								gotoxy(56, (i+1)*3);
								printf("%i) ",i+1);
								for(j=0;j<a;j++)
								{
									gotoxy(0,c+2);
									printf("- Ingresa el valor de (%i,%i): ", i+1, j+1);
									scanf("%i", &num[i][j]);
									asumc[j]=asumc[j]+num[i][j];
									gotoxy((j+7)*8+4, 1);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+4, (i+1)*3);
									printf("%i", num[i][j]);
									gotoxy((j+7)*8+4, (a-1)*3+5);
									printf("=");
									gotoxy((j+7)*8+4, (a-1)*3+6);
									printf("%i", asumc[j]);
									c++;
								}
								asumf=0;
							}
							gotoxy(0,a*a+4);
							printf(" FINALIZADO...\n");
							getch();
							
							break;
						case 4:
							//---------------- PROGRAMA #4:
							system("cls");
							for(i=0;i<a;i++)
							{
								asumc[i]=0;
							}
							c=0;
							printf("===== SUMA DE LOS ELEMENTOS POR FILA Y COLUMNA =====\n");
							gotoxy(0,a*a+3);
							printf("====================================================\n");
							for(i=0;i<a;i++)
							{
								gotoxy(56, (i+1)*3);
								printf("%i) ",i+1);
								for(j=0;j<a;j++)
								{
									gotoxy(0,c+2);
									printf("- Ingresa el valor de (%i,%i): ", i+1, j+1);
									scanf("%i", &num[i][j]);
									asumf=asumf+num[i][j];
									asumc[j]=asumc[j]+num[i][j];
									gotoxy((j+7)*8+4, 1);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+4, (i+1)*3);
									printf("%i", num[i][j]);
									gotoxy((a+6)*8+4, (i+1)*3);
									printf("\t= %i", asumf);
									gotoxy((j+7)*8+4, (a-1)*3+5);
									printf("=");
									gotoxy((j+7)*8+4, (a-1)*3+6);
									printf("%i", asumc[j]);
									c++;
								}
								asumf=0;
							}
							gotoxy(0,a*a+4);
							printf(" FINALIZADO...\n");
							getch();
							
							break;
						case 5:
							break;
						default:
							printf("### OPCIÓN NO VÁLIDA ###\n");
							printf("\nIntenta de nuevo...\n");
							getch();
					}
				}
				while(opc!=5);
				break;
			case 2:
				do
				{
					system("cls");
					printf("================= MENÚ DE MATRICES =================\n\n");
					printf(" ----------------------------------\n");
					printf(" -- MATRICES DE N*N ----------\n");
					printf(" ------------------------\n\n");
					printf("  1)  Multiplicación de matriz por n  ->\n");
					printf("  2)  Suma de dos matrices            ->\n");
					printf("  3)  Matriz de menor a mayor         ->\n");
					printf("  4)  Matriz de mayor a menor         ->\n");
					printf("  5)  Matriz identidad                ->\n");
					printf("  6)  <- Regresar.\n\n");
					printf("====================================================\n");
					printf("- Ingresa una opción: ");
					scanf("%i", &opc);
					system("cls");
					switch(opc)
					{
						case 1:
							//---------------- PROGRAMA #5:
							system("cls");
							asum=0;
							c=0;
							printf("======== MULTIPLICACIÓN DE MATRIZ POR N ========\n");
							printf("\n- Ingresa la longitud de la matriz: ");
							scanf("%i", &n);
							printf("- Ingresa el número por el cual multiplicar: ");
							scanf("%f", &x);
							gotoxy(0,n*n+6);
							printf("=================================================\n");
							gotoxy(55, (n)*3+4);
							printf("- RESULTADOS:");
							
							for(i=0;i<n;i++)
							{
								gotoxy(53, (i+1)*3);
								printf("%i) ",i+1);
								gotoxy(53, (n)*3+(i+1)*3+5);
								printf("%i) ",i+1);
								for(j=0;j<n;j++)
								{
									gotoxy(0,c+5);
									printf("- Ingresa el valor de (%i,%i): ", i+1, j+1);
									scanf("%i", &num[i][j]);
									gotoxy((j+7)*8+1, 1);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (n)*3+6);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (i+1)*3);
									printf("%i", num[i][j]);
									c++;
									numf[i][j]=num[i][j];
									res[i][j]=numf[i][j]*x;
									gotoxy((j+7)*8+1, (n)*3+(i+1)*3+5);
									printf("%.2f", res[i][j]);
								}
							}
							gotoxy(0,n*n+7);
							printf(" FINALIZADO...\n");
							getch();
							
							break;
						case 2:
							//---------------- PROGRAMA #6:
							system("cls");
							c=0;
							printf("========= SUMA DE 2 MATRICES CUADRADAS =========\n");
							printf("\n- Ingresa la longitud de la matriz: ");
							scanf("%i", &n);
							gotoxy(0,n*n*2+5);
							printf("================================================\n");
							gotoxy(55, 1);
							printf("- MATRIZ #1:");
							gotoxy(55, (n)*3+4);
							printf("- MATRIZ #2:");
							gotoxy(55, (n)*6+7);
							printf("- MATRIZ DE RESULTADOS:");
							
							for(i=0;i<n;i++)
							{
								gotoxy(53, (i+1)*3+2);
								printf("%i) ",i+1);
								gotoxy(53, (n)*3+(i+1)*3+5);
								printf("%i) ",i+1);
								gotoxy(53, (n)*6+(i+1)*3+8);
								printf("%i) ",i+1);
								for(j=0;j<n;j++)
								{
									gotoxy(0,c+4+c);
									printf("- Ingresa el valor #1 de (%i,%i): ", i+1, j+1);
									scanf("%i", &num[i][j]);
									gotoxy(0,c+5+c);
									printf("- Ingresa el valor #2 de (%i,%i): ", i+1, j+1);
									scanf("%i", &num1[i][j]);
									sum[i][j]=num[i][j]+num1[i][j];
									gotoxy((j+7)*8+1, 3);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (n)*3+6);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (n)*6+9);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (i+1)*3+2);
									printf("%i", num[i][j]);
									gotoxy((j+7)*8+1, (n)*3+(i+1)*3+5);
									printf("%i", num1[i][j]);
									gotoxy((j+7)*8+1, (n)*6+(i+1)*3+8);
									printf("%i", sum[i][j]);
									c++;
								}
							}
							gotoxy(0,n*n*2+6);
							printf(" FINALIZADO...\n");
							getch();
							
							break;
						case 3:
							//---------------- PROGRAMA #7:
							system("cls");
							c=0;
							printf("============ MATRIZ DE MENOR A MAYOR ============\n");
							printf("\n- Ingresa la longitud de la matriz: ");
							scanf("%i", &n);
							gotoxy(0,n*n+5);
							printf("================================================\n");
							gotoxy(55, 1);
							printf("- MATRIZ:");
							gotoxy(55, (n)*3+4);
							printf("- MATRIZ DE RESULTADOS:");
							
							for(i=0;i<n;i++)
							{
								gotoxy(53, (i+1)*3+2);
								printf("%i) ",i+1);
								for(j=0;j<n;j++)
								{
									gotoxy(0,c+4);
									printf("- Ingresa el valor de (%i,%i): ", i+1, j+1);
									scanf("%i", &num[i][j]);
									gotoxy((j+7)*8+1, 3);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (i+1)*3+2);
									printf("%i", num[i][j]);
									c++;
								}
							}
							
							for(i=0;i<n;i++)
							{
								for(j=0;j<n;j++)
								{
									for(k=0;k<n;k++)
									{
										for(l=0;l<n-1;l++)
										{
											if(num[k][l]>num[k][l+1])
											{
												q=num[k][l];
												num[k][l]=num[k][l+1];
												num[k][l+1]=q;
											}
										}
										if(k<n-1)
										{
											if(num[k][l]>num[k+1][0])
											{
												q=num[k][l];
												num[k][l]=num[k+1][0];
												num[k+1][0]=q;
											}
										}
									}
								}
							}
							
							for(i=0;i<n;i++)
							{
								gotoxy(53, (n)*3+(i+1)*3+5);
								printf("%i) ",i+1);
								for(j=0;j<n;j++)
								{
									gotoxy((j+7)*8+1, (n)*3+6);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (n)*3+(i+1)*3+5);
									printf("%i", num[i][j]);
								}
							}
							gotoxy(0,n*n+6);
							printf(" FINALIZADO...\n");
							getch();
							
							break;
						case 4:
							//---------------- PROGRAMA #8:
							system("cls");
							c=0;
							printf("============ MATRIZ DE MAYOR A MENOR ============\n");
							printf("\n- Ingresa la longitud de la matriz: ");
							scanf("%i", &n);
							gotoxy(0,n*n+5);
							printf("================================================\n");
							gotoxy(55, 1);
							printf("- MATRIZ:");
							gotoxy(55, (n)*3+4);
							printf("- MATRIZ DE RESULTADOS:");
							
							for(i=0;i<n;i++)
							{
								gotoxy(53, (i+1)*3+2);
								printf("%i) ",i+1);
								for(j=0;j<n;j++)
								{
									gotoxy(0,c+4);
									printf("- Ingresa el valor de (%i,%i): ", i+1, j+1);
									scanf("%i", &num[i][j]);
									gotoxy((j+7)*8+1, 3);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (i+1)*3+2);
									printf("%i", num[i][j]);
									c++;
								}
							}
							
							for(i=0;i<n;i++)
							{
								for(j=0;j<n;j++)
								{
									for(k=0;k<n;k++)
									{
										for(l=0;l<n-1;l++)
										{
											if(num[k][l]<num[k][l+1])
											{
												q=num[k][l];
												num[k][l]=num[k][l+1];
												num[k][l+1]=q;
											}
										}
										if(k<n-1)
										{
											if(num[k][l]<num[k+1][0])
											{
												q=num[k][l];
												num[k][l]=num[k+1][0];
												num[k+1][0]=q;
											}
										}
									}
								}
							}
							
							for(i=0;i<n;i++)
							{
								gotoxy(53, (n)*3+(i+1)*3+5);
								printf("%i) ",i+1);
								for(j=0;j<n;j++)
								{
									gotoxy((j+7)*8+1, (n)*3+6);
									printf("%i) ",j+1);
									gotoxy((j+7)*8+1, (n)*3+(i+1)*3+5);
									printf("%i", num[i][j]);
								}
							}
							gotoxy(0,n*n+6);
							printf(" FINALIZADO...\n");
							getch();
							
							break;
						case 5:
							//---------------- PROGRAMA #8:
							system("cls");
							c=0;
							printf("============= MATRIZ DE INDENTIDAD =============\n");
							printf("\n- Ingresa la longitud de la matriz: ");
							scanf("%i", &n);
							gotoxy(0,(n+1)*3+5);
							printf("================================================\n");
							gotoxy(4, 4);
							printf("- MATRIZ IDENTIDAD");
							
							for(i=0;i<n;i++)
							{
								gotoxy(1, (i+1)*3+5);
								printf("%i) ",i+1);
								for(j=0;j<n;j++)
								{
									gotoxy(j*8+5, 6);
									printf("%i) ",j+1);
									num[i][j]=0;
									num[i][i]=1;
									gotoxy(j*8+5, (i+1)*3+5);
									printf("%i", num[i][j]);
									c++;
								}
							}
							
							gotoxy(0,(n+1)*3+6);
							printf(" FINALIZADO...\n");
							getch();
							
							break;
						case 6:
							break;
						default:
							printf("### OPCIÓN NO VÁLIDA ###\n");
							printf("\nIntenta de nuevo...\n");
							getch();
					}
				}
				while(opc!=6);
				break;
			case 3:
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
	while(opc!=3);
	
	return 0;
}


