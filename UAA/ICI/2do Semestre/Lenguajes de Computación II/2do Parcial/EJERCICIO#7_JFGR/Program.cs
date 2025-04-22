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
 -Luis Pablo Esparza Terrones
 -Luis Manuel Flores Jiménez
 -Juan Francisco Gallo Ramírez
 13/03/2023 I.C.I.
=========================================================*/
using System;

internal class Program
{
	const int MAX_1 = 4;
    static void Main(string[] args)
    {
        int opc, n=0;
        int[,] num = new int[MAX_1, MAX_1];
        Console.SetWindowSize(240,75);
        Console.SetBufferSize(240, 75);
        do
		{
            Console.Clear();
            Console.Write("================= MENÚ DE MATRICES =================\n\n\n\n");
            Console.Write("  1)  Matrices de {0}*{0}  ->\n\n", MAX_1);
            Console.Write("  2)  Matrices de n*n  ->\n\n");
            Console.Write("  3)  << Salir.\n\n\n\n");
            Console.Write("====================================================\n");
            Console.Write("- Ingresa una opción: ");
            opc = Convert.ToInt32(Console.ReadLine());
            Console.Clear();

			switch (opc)
			{
				case 1:
					do
					{
                        Console.Clear();
                        Console.Write("================= MENÚ DE MATRICES =================\n\n");
                        Console.Write(" ----------------------------------\n");
                        Console.Write(" -- MATRICES DE {0}*{0} ----------\n", MAX_1);
                        Console.Write(" ------------------------\n\n");
                        Console.Write("  1)  Suma de todos los elementos de la matriz ->\n");
                        Console.Write("  2)  Suma de los elementos por fila           ->\n");
                        Console.Write("  3)  Suma de los elementos por columna        ->\n");
                        Console.Write("  4)  Suma de los elementos por fila y columna ->\n");
                        Console.Write("  5)  <- Regresar.\n\n");
                        Console.Write("====================================================\n");
                        Console.Write("- Ingresa una opción: ");
                        opc = Convert.ToInt32(Console.ReadLine());
                        Console.Clear();

						switch(opc)
						{
							case 1:
								funcion_1(num);
								break;
                            case 2:
                                funcion_2(num);
                                break;
                            case 3:
                                funcion_3(num);
                                break;
                            case 4:
                                funcion_4(num);
                                break;
                            case 5:
                                break;
                            default:
                                Console.Write("### OPCIÓN NO VÁLIDA ###\n");
                                Console.Write("\nIntenta de nuevo...\n");
                                Console.ReadKey();
                                break;
                        }
                    } while (opc != 5);
                    break;
                case 2:
                    do
                    {
                        Console.Clear();
                        Console.Write("================= MENÚ DE MATRICES =================\n\n");
                        Console.Write(" ----------------------------------\n");
                        Console.Write(" -- MATRICES DE n*n ----------\n");
                        Console.Write(" ------------------------\n\n");
                        Console.Write("  1)  Multiplicación de matriz por n  ->\n");
                        Console.Write("  2)  Suma de dos matrices            ->\n");
                        Console.Write("  3)  Matriz de menor a mayor         ->\n");
                        Console.Write("  4)  Matriz de mayor a menor         ->\n");
                        Console.Write("  5)  Matriz identidad                ->\n");
                        Console.Write("  6)  <- Regresar.\n\n");
                        Console.Write("====================================================\n");
                        Console.Write("- Ingresa una opción: ");
                        opc = Convert.ToInt32(Console.ReadLine());
                        if (opc!=6)
                        {
                            Console.Write("\n- Ingresa la longitud de la matriz: ");
                            n = Convert.ToInt32(Console.ReadLine());
                        }
                        double[,] num_1 = new double[n, n];
                        double[,] res = new double[n, n];
                        Console.Clear();
                        switch (opc)
                        {
                            case 1:
                                funcion_5(num_1, res, n);
                                break;
                            case 2:
                                funcion_6(num_1, res, n);
                                break;
                            case 3:
                                funcion_7(num_1, n);
                                break;
                            case 4:
                                funcion_8(num_1, n);
                                break;
                            case 5:
                                funcion_9(num_1, n);
                                break;
                            case 6:
                                break;
                            default:
                                Console.Write("### OPCIÓN NO VÁLIDA ###\n");
                                Console.Write("\nIntenta de nuevo...\n");
                                Console.ReadKey();
                                break;
                        }
                    } while (opc != 6);
                    break;
                case 3:
                    Console.Write("        =====================\n");
                    Console.Write("=============== SALIR ===============\n");
                    Console.Write("        =====================\n");
                    Console.ReadKey();
                    break;
                default:
                    Console.Write("### OPCIÓN NO VÁLIDA ###\n");
                    Console.Write("\nIntenta de nuevo...\n");
                    Console.ReadKey();
                    break;
			}
		} while (opc != 3);
    }
	// - - - FUNCIÓN #1
	static void funcion_1(int [,] num)
	{
        int asum = 0;
        int c = 0;
        Console.Clear();
        Console.Write("==== SUMA DE TODOS LOS ELEMENTOS DE LA MATRIZ ====\n");
        Console.SetCursorPosition(0, MAX_1 * MAX_1 + 3);
        Console.Write("==================================================\n");
        for (int i = 0; i < MAX_1; i++)
        {
            Console.SetCursorPosition(53, (i + 1) * 3 + 2);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < MAX_1; j++)
            {
                Console.SetCursorPosition(0, c + 2);
                Console.Write("- Ingresa el valor de ({0},{1}): ", i + 1, j + 1);
                num[i,j] =Convert.ToInt32(Console.ReadLine());
                asum = asum + num[i,j];
                Console.SetCursorPosition((j + 7) * 8 + 1, 3);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (i + 1) * 3 + 2);
                Console.Write("{0}", num[i,j]);
                Console.SetCursorPosition(57, 1);
                Console.Write("- ACUMULADOR DE SUMA = {0}", asum);
                c++;
            }
        }
        Console.SetCursorPosition(0, MAX_1 * MAX_1 + 4);
        Console.Write(" FINALIZADO...\n");
        Console.ReadKey();
    }
    // - - - FUNCIÓN #2
    static void funcion_2(int [,] num)
    {
        Console.Clear();
        int asumf = 0;
        int c = 0;
        Console.Write("==== SUMA DE LOS ELEMENTOS POR FILA DE LA MATRIZ ====\n");
        Console.SetCursorPosition(0, MAX_1 * MAX_1 + 3);
        Console.Write("=====================================================\n");
        for (int i = 0; i < MAX_1; i++)
        {
            Console.SetCursorPosition(56, (i + 1) * 3);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < MAX_1; j++)
            {
                Console.SetCursorPosition(0, c + 2);
                Console.Write("- Ingresa el valor de ({0},{1}): ", i + 1, j + 1);
                num[i,j] = Convert.ToInt32(Console.ReadLine());
                asumf = asumf + num[i,j];
                Console.SetCursorPosition((j + 7) * 8 + 4, 1);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 4, (i + 1) * 3);
                Console.Write("{0}", num[i,j]);
                Console.SetCursorPosition((MAX_1 + 6) * 8 + 4, (i + 1) * 3);
                Console.Write("\t= {0}", asumf);
                c++;
            }
            asumf = 0;
        }
        Console.SetCursorPosition(0, MAX_1 * MAX_1 + 4);
        Console.Write(" FINALIZADO...\n");
        Console.ReadKey();
    }
    // - - - FUNCIÓN #3
    static void funcion_3(int[,] num)
    {
        int c=0;
        int[] asumc = new int[MAX_1];
        Console.Clear();
        for (int i = 0; i < MAX_1; i++)
        {
            asumc[i] = 0;
        }
        c = 0;
        Console.Write("== SUMA DE LOS ELEMENTOS POR COLUMNA DE LA MATRIZ ==\n");
        Console.SetCursorPosition(0, MAX_1 * MAX_1 + 3);
        Console.Write("=====================================================\n");
        for (int i = 0; i < MAX_1; i++)
        {
            Console.SetCursorPosition(56, (i + 1) * 3);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < MAX_1; j++)
            {
                Console.SetCursorPosition(0, c + 2);
                Console.Write("- Ingresa el valor de ({0},{0}): ", i + 1, j + 1);
                num[i, j] = Convert.ToInt32(Console.ReadLine());
                asumc[j] = asumc[j] + num[i, j];
                Console.SetCursorPosition((j + 7) * 8 + 4, 1);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 4, (i + 1) * 3);
                Console.Write("{0}", num[i,j]);
                Console.SetCursorPosition((j + 7) * 8 + 4, (MAX_1 - 1) * 3 + 5);
                Console.Write("=");
                Console.SetCursorPosition((j + 7) * 8 + 4, (MAX_1 - 1) * 3 + 6);
                Console.Write("{0}", asumc[j]);
                c++;
            }
        }
        Console.SetCursorPosition(0, MAX_1 * MAX_1 + 4);
        Console.Write(" FINALIZADO...\n");
        Console.ReadKey();
    }
    // - - - FUNCIÓN #4
    static void funcion_4(int[,] num)
    {
        int asumf=0;
        int[] asumc = new int[MAX_1];
        int c = 0;
        Console.Clear();
        Console.Write("===== SUMA DE LOS ELEMENTOS POR FILA Y COLUMNA =====\n");
        Console.SetCursorPosition(0, MAX_1 * MAX_1 + 3);
        Console.Write("====================================================\n");
        for (int i = 0; i < MAX_1; i++)
        {
            Console.SetCursorPosition(56, (i + 1) * 3);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < MAX_1; j++)
            {
                Console.SetCursorPosition(0, c + 2);
                Console.Write("- Ingresa el valor de ({0},{1}): ", i + 1, j + 1);
                num[i, j] = Convert.ToInt32(Console.ReadLine());
                asumf = asumf + num[i,j];
                asumc[j] = asumc[j] + num[i, j];
                Console.SetCursorPosition((j + 7) * 8 + 4, 1);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 4, (i + 1) * 3);
                Console.Write("{0}", num[i, j]);
                Console.SetCursorPosition((MAX_1 + 6) * 8 + 4, (i + 1) * 3);
                Console.Write("\t= {0}", asumf);
                Console.SetCursorPosition((j + 7) * 8 + 4, (MAX_1 - 1) * 3 + 5);
                Console.Write("=");
                Console.SetCursorPosition((j + 7) * 8 + 4, (MAX_1 - 1) * 3 + 6);
                Console.Write("{0}", asumc[j]);
                c++;
            }
            asumf = 0;
        }
        Console.SetCursorPosition(0, MAX_1 * MAX_1 + 4);
        Console.Write(" FINALIZADO...\n");
        Console.ReadKey();
    }
    // - - - FUNCIÓN #5
    static void funcion_5(double[,] num_1, double [,] res, int n)
    {
        int c = 0;
        double x = 0;
        Console.Clear();
        Console.Write("======== MULTIPLICACIÓN DE MATRIZ POR N ========\n");
        Console.Write("\n- Ingresa el número por el cual multiplicar: ");
        x = Convert.ToDouble(Console.ReadLine());
        Console.SetCursorPosition(0, n * n + 5);
        Console.Write("=================================================\n");
        Console.SetCursorPosition(55, (n) * 3 + 4);
        Console.Write("- RESULTADOS:");

        for (int i = 0; i < n; i++)
        {
            Console.SetCursorPosition(53, (i + 1) * 3);
            Console.Write("{0}) ", i + 1);
            Console.SetCursorPosition(53, (n) * 3 + (i + 1) * 3 + 5);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < n; j++)
            {
                Console.SetCursorPosition(0, c + 4);
                Console.Write("- Ingresa el valor de ({0},{1}): ", i + 1, j + 1);
                num_1[i, j] = Convert.ToDouble(Console.ReadLine());
                Console.SetCursorPosition((j + 7) * 8 + 1, 1);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 3 + 6);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (i + 1) * 3);
                Console.Write("{0}", num_1[i,j]);
                c++;
                res[i,j] = num_1[i, j] * x;
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 3 + (i + 1) * 3 + 5);
                Console.Write("{0}", res[i, j]);
            }
        }
        Console.SetCursorPosition(0, n * n + 6);
        Console.Write(" FINALIZADO...\n");
        Console.ReadKey();
    }
    // - - - FUNCIÓN #6
    static void funcion_6(double[,] num_1, double[,] res, int n)
    {
        int c = 0;
        double[,] num_2 = new double[n, n];
        Console.Clear();
        Console.Write("========= SUMA DE 2 MATRICES CUADRADAS =========\n");
        Console.SetCursorPosition(0, n * n * 2 + 3);
        Console.Write("================================================\n");
        Console.SetCursorPosition(55, 1);
        Console.Write("- MATRIZ #1:");
        Console.SetCursorPosition(55, (n) * 3 + 4);
        Console.Write("- MATRIZ #2:");
        Console.SetCursorPosition(55, (n) * 6 + 7);
        Console.Write("- MATRIZ DE RESULTADOS:");

        for (int i = 0; i < n; i++)
        {
            Console.SetCursorPosition(53, (i + 1) * 3 + 2);
            Console.Write("{0}) ", i + 1);
            Console.SetCursorPosition(53, (n) * 3 + (i + 1) * 3 + 5);
            Console.Write("{0}) ", i + 1);
            Console.SetCursorPosition(53, (n) * 6 + (i + 1) * 3 + 8);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < n; j++)
            {
                Console.SetCursorPosition(0, c + 2 + c);
                Console.Write("- Ingresa el valor #1 de ({0},{1}): ", i + 1, j + 1);
                num_1[i, j] = Convert.ToDouble(Console.ReadLine());
                Console.SetCursorPosition(0, c + 3 + c);
                Console.Write("- Ingresa el valor #2 de ({0},{1}): ", i + 1, j + 1);
                num_2[i, j] = Convert.ToDouble(Console.ReadLine());
                res[i,j] = num_1[i,j] + num_2[i,j];
                Console.SetCursorPosition((j + 7) * 8 + 1, 3);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 3 + 6);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 6 + 9);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (i + 1) * 3 + 2);
                Console.Write("{0}", num_1[i,j]);
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 3 + (i + 1) * 3 + 5);
                Console.Write("{0}", num_2[i,j]);
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 6 + (i + 1) * 3 + 8);
                Console.Write("{0}", res[i,j]);
                c++;
            }
        }
        Console.SetCursorPosition(0, n * n * 2 + 4);
        Console.Write(" FINALIZADO...\n");
        Console.ReadKey();
    }
    // - - - FUNCIÓN #7
    static void funcion_7(double[,] num_1, int n)
    {
        int c = 0, l = 0;
        double q = 0;

        Console.Clear();
        Console.Write("============ MATRIZ DE MENOR A MAYOR ============\n");
        Console.SetCursorPosition(0, n * n + 3);
        Console.Write("================================================\n");
        Console.SetCursorPosition(55, 1);
        Console.Write("- MATRIZ:");
        Console.SetCursorPosition(55, (n) * 3 + 4);
        Console.Write("- MATRIZ DE RESULTADOS:");

        for (int i = 0; i < n; i++)
        {
            Console.SetCursorPosition(53, (i + 1) * 3 + 2);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < n; j++)
            {
                Console.SetCursorPosition(0, c + 2);
                Console.Write("- Ingresa el valor de ({0},{1}): ", i + 1, j + 1);
                num_1[i, j] = Convert.ToDouble(Console.ReadLine());
                Console.SetCursorPosition((j + 7) * 8 + 1, 3);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (i + 1) * 3 + 2);
                Console.Write("{0}", num_1[i,j]);
                c++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for ( l = 0; l < n - 1; l++)
                    {
                        if (num_1[k, l] > num_1[k, l + 1])
                        {
                            q = num_1[k, l];
                            num_1[k, l] = num_1[k, l + 1];
                            num_1[k, l + 1] = q;
                        }
                    }
                    if (k < n - 1)
                    {
                        if (num_1[k, l] > num_1[k + 1, 0])
                        {
                            q = num_1[k, l];
                            num_1[k, l] = num_1[k + 1, 0];
                            num_1[k + 1, 0] = q;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            Console.SetCursorPosition(53, (n) * 3 + (i + 1) * 3 + 5);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < n; j++)
            {
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 3 + 6);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 3 + (i + 1) * 3 + 5);
                Console.Write("{0}", num_1[i, j]);
            }
        }
        Console.SetCursorPosition(0, n * n + 4);
        Console.Write(" FINALIZADO...\n");
        Console.ReadKey();
    }
    // - - - FUNCIÓN #8
    static void funcion_8(double[,] num_1, int n)
    {
        int c = 0, l = 0;
        double q = 0;

        Console.Clear();
        Console.Write("============ MATRIZ DE MAYOR A MENOR ============\n");
        Console.SetCursorPosition(0, n * n + 3);
        Console.Write("================================================\n");
        Console.SetCursorPosition(55, 1);
        Console.Write("- MATRIZ:");
        Console.SetCursorPosition(55, (n) * 3 + 4);
        Console.Write("- MATRIZ DE RESULTADOS:");

        for (int i = 0; i < n; i++)
        {
            Console.SetCursorPosition(53, (i + 1) * 3 + 2);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < n; j++)
            {
                Console.SetCursorPosition(0, c + 2);
                Console.Write("- Ingresa el valor de ({0},{1}): ", i + 1, j + 1);
                num_1[i, j] = Convert.ToDouble(Console.ReadLine());
                Console.SetCursorPosition((j + 7) * 8 + 1, 3);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (i + 1) * 3 + 2);
                Console.Write("{0}", num_1[i, j]);
                c++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    for (l = 0; l < n - 1; l++)
                    {
                        if (num_1[k,l] < num_1[k, l + 1])
                        {
                            q = num_1[k, l];
                            num_1[k, l] = num_1[k, l + 1];
                            num_1[k, l + 1] = q;
                        }
                    }
                    if (k < n - 1)
                    {
                        if (num_1[k, l] < num_1[k + 1, 0])
                        {
                            q = num_1[k, l];
                            num_1[k, l] = num_1[k + 1, 0];
                            num_1[k + 1, 0] = q;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            Console.SetCursorPosition(53, (n) * 3 + (i + 1) * 3 + 5);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < n; j++)
            {
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 3 + 6);
                Console.Write("{0}) ", j + 1);
                Console.SetCursorPosition((j + 7) * 8 + 1, (n) * 3 + (i + 1) * 3 + 5);
                Console.Write("{0}", num_1[i, j]);
            }
        }
        Console.SetCursorPosition(0, n * n + 4);
        Console.Write(" FINALIZADO...\n");
        Console.ReadKey();
    }
    // - - - FUNCIÓN #9
    static void funcion_9(double[,] num_1, int n)
    {
        int c = 0;
        Console.Clear();
        Console.Write("============= MATRIZ DE INDENTIDAD =============\n");
        Console.SetCursorPosition(0, (n + 1) * 3 + 3);
        Console.Write("================================================\n");
        Console.SetCursorPosition(4, 2);
        Console.Write("- MATRIZ IDENTIDAD");

        for (int i = 0; i < n; i++)
        {
            Console.SetCursorPosition(1, (i + 1) * 3 + 3);
            Console.Write("{0}) ", i + 1);
            for (int j = 0; j < n; j++)
            {
                Console.SetCursorPosition(j * 8 + 5, 4);
                Console.Write("{0}) ", j + 1);
                num_1[i,j] = 0;
                num_1[i, i] = 1;
                Console.SetCursorPosition(j * 8 + 5, (i + 1) * 3 + 3);
                Console.Write("{0}", num_1[i, j]);
                c++;
            }
        }

        Console.SetCursorPosition(0, (n + 1) * 3 + 4);
        Console.Write(" FINALIZADO...\n");
        Console.ReadKey();
    }
}