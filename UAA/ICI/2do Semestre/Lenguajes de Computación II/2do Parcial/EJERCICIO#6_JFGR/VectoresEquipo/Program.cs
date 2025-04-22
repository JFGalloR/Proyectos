/*
    --------------------------------------------------------------------------------------
    LENGUAJES DE COMPUTACIÓN II                                                 00|00|0000
    --------------------------------------------------------------------------------------
    Programa: VectoresEquipo.cs                            Alumnos: 
                                                            Luis Pablo Esparza Terrones
                                                            Juan Francisco Gallo Ramirez
                                                            Luis Manuel Flores Jimenez
Objetivo:

Ejercicios con Vectores 

1.- Escribir un programa que pida 10 números enteros por teclado y que imprima por pantalla: 
	a) Cuántos de esos números son pares. 
	b) Cuál es el valor del número máximo 
	c) Cuál es el valor del número mínimo 

2.- Escribir un programa que lea 10 números por teclado. Luego lea dos más e indique si éstos 
    están entre los anteriores e indicar en qué posición se encuentran. 

3.- Leer un vector de 10 elementos enteros y ordenarlo de menor a mayor. 

4.- Leer un vector de 10 elementos enteros y ordenarlo de mayor a menor. 

5.- Leer 10 números enteros, guardarlos en un vector, elevarlos al cuadrado y guardar el resultado 
    en otro vector. Al final imprimir los 2 vectores. 

6.- Leer 8 números enteros, guardarlos en un vector, multiplicarlos por 2 y guardar el resultado 
    en otro vector. Al final imprimir los 2 vectores. 

7.- Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en 
    otro vector. Sumarlos y el resultado guardarlo en otro vector. Al final imprimir los 3 vectores. 

8.- Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro
    vector. Restarlos y el resultado guardarlo en otro vector. Al final imprimir los 3 vectores.

9.- Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector.
    Multiplicarlos y el resultado guardarlo en otro vector. Al final imprimir los 3 vectores.

10.- Leer 8 números enteros, guardarlos en un vector, leer otros 8 números enteros, guardarlos en otro vector. 
    Dividirlos y el resultado guardarlo en otro vector. Al final imprimir los 3 vectores.

*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VectoresEquipo
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int opc = 0;
            do
            {
                opc = 0;
                int n;
                Console.Clear();
                Console.WriteLine("======================= MENÚ DE VECTORES =======================\n");
                Console.Write("Tamaño del vector: ");
                n = int.Parse(Console.ReadLine());
                int[] array = new int[n];
                for (int i = 0; i < array.Length; i++)
                {
                    Console.Write(" > Ingresa el número {0}: ", i+1);
                    array[i] = int.Parse(Console.ReadLine());
                }
                Console.WriteLine("================================================================");
                do
                {
                    Console.Clear();
                    Console.WriteLine("======================= MENÚ DE VECTORES =======================\n");
                    Console.WriteLine(" 1.  Números Pares, Máximo y Mínimo.");
                    Console.WriteLine(" 2.  Búsqueda y Posicion de Dos Números.");
                    Console.WriteLine(" 3.  Ordenar de Menor a Mayor.");
                    Console.WriteLine(" 4.  Ordenar de Mayor a Menor.");
                    Console.WriteLine(" 5.  Elevar al Cuadrado.");
                    Console.WriteLine(" 6.  Multiplicar por Dos");
                    Console.WriteLine(" 7.  Suma de Dos Vectores.");
                    Console.WriteLine(" 8.  Resta de Dos Vectores");
                    Console.WriteLine(" 9.  Multiplicar Dos Vectores.");
                    Console.WriteLine(" 10. Dividir Dos Vectores.");
                    Console.WriteLine(" 11. <- Salir. ");
                    Console.WriteLine("\n================================================================");
                    Console.Write(" > Ingresa una opción: ");
                    opc = int.Parse(Console.ReadLine());
                    switch(opc)
                    {
                        case 1:
                            function_1(array);
                            break;
                        case 2:
                            function_2(array);
                            break;
                        case 3:
                            function_3(array);
                            break;
                        case 4:
                            function_4(array);
                            break;
                        case 5:
                            function_5(array);
                            break;
                        case 6:
                            function_6(array);
                            break;
                        case 7:
                            function_7(array);
                            break;
                        case 8:
                            function_8(array);
                            break;
                        case 9:
                            function_9(array);
                            break;
                        case 10:
                            function_10(array);
                            break;
                        default:
                            break;
                    }
                } while (opc < 1 || opc > 11);

            } while (opc != 11);
        }

        static void function_1(int[] array)
        {
            int higher = 0, lower = array[0], pares = 0;
            Console.Clear();
            Console.WriteLine("======PARES || MAXIMO || MINIMO======");
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] % 2 == 0)
                    pares++;
                if (array[i] > higher)
                    higher = array[i];
                if (array[i] < lower)
                    lower = array[i];
            }
            if (pares > 0)
            {
                Console.Write("\nNumeros pares --- ");
                for (int i = 0; i < array.Length; i++)
                {
                    if (array[i] % 2 == 0)
                    {
                        Console.Write(array[i] + " || ");
                    }
                }
            }
            else
            {
                Console.WriteLine("\nNo se encontraron numeros que sean pares");
            }
            Console.WriteLine("\nMaximo > " + higher);
            Console.WriteLine("Minimo > " + lower);
            Console.ReadKey();
        }

        static void function_2(int[] array)
        {
            int a, b, j=0, k=0;
            int[] positionA=new int[array.Length];
            int[] positionB=new int[array.Length];
            Console.Clear();
            Console.WriteLine("======ENCUENTRA VALORES======");
            Console.Write("\nValor 1: ");
            a = int.Parse(Console.ReadLine());
            Console.Write("\nValor 2: ");
            b = int.Parse(Console.ReadLine());
            Console.Write("\nArray ---->>>\t");
            for (int i=0; i < array.Length; i++)
            {
                Console.Write($" {array[i]}\t");
                if (array[i].Equals(a))
                {
                    positionA[j]=i;
                    j++;
                }
                if (array[i].Equals(b))
                {
                    positionB[k]=i;
                    k++;
                }  
            }

            if (j == 0)
            {
                Console.Write($"\n\nEl valor {a} no se encuentra en el array");
            } else
            {
                Console.Write($"\n\nValor {a} se encuentra en la(s) posición(es): ");
                for (int i = 0; i < j; i++)
                {
                    Console.Write($"{positionA[i]+1} || ");
                }
            }

            if (k == 0)
            {
                Console.Write($"\n\nEl valor {b} no se encuentra en el array");
            }
            else
            {
                Console.Write($"\n\nValor {b} se encuentra en la(s) posición(es): ");
                for (int i = 0; i < k; i++)
                {
                    Console.Write($"{positionB[i]+1} || ");
                }
            }
            Console.ReadKey();
        }

        static void function_3(int[] array)
        {
            int aux;
            Console.Clear();
            Console.WriteLine("======MENOR A MAYOR======");
            Console.Write("\nVector original --->\t\t");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }
            
            for (int i=0; i < array.Length - 1 ; i++)
            {
                
                for (int j=i+1; j < array.Length; j++)
                {
                    if(array[i]>array[j])
                    {
                        aux=array[i];
                        array[i]=array[j];
                        array[j]=aux;
                    }
                }
            }
            Console.Write("\n\nVector ordenado (Menor->Mayor) --->\t");
            for(int i=0;i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }
            Console.ReadKey();
        }

        static void function_4(int[] array)
        {
            int aux;
            Console.Clear();
            Console.WriteLine("======MAYOR A MENOR======");
            Console.Write("\nVector original --->\t\t");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }

            for (int i = 0; i < array.Length - 1; i++)
            {

                for (int j = i + 1; j < array.Length; j++)
                {
                    if (array[i] < array[j])
                    {
                        aux = array[i];
                        array[i] = array[j];
                        array[j] = aux;
                    }
                }
            }
            Console.Write("\n\nVector ordenado (Mayor->Menor) --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }
            Console.ReadKey();
        }

        static void function_5(int[] array)
        {
            int[] square=new int[array.Length];
            Console.Clear();
            Console.WriteLine("======VECTOR AL CUADRADO======");
            Console.Write("\nVector original --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }
            Console.Write("\nVector al cuadrado --->\t");
            for (int i = 0;i<array.Length;i++)
            {
                square[i]=Convert.ToInt32(Math.Pow(array[i],2));
                Console.Write($"{square[i]}\t");
            }
            Console.ReadKey();
        }

        static void function_6(int[] array)
        {
            int[] multiplication = new int[array.Length];
            Console.Clear();
            Console.WriteLine("======MULTIPLICACION DE VECTOR======");
            Console.Write("\nVector original --->\t\t");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }
            Console.Write("\nVector multiplicado por 2 --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                multiplication[i] = array[i] * 2;
                Console.Write($"{multiplication[i]}\t");
            }
            Console.ReadKey();
        }

        static void function_7(int[] array)
        {
            int[] array2 = new int[array.Length];
            int[] sum = new int[array.Length];
            Console.Clear();
            Console.WriteLine("======SUMA DE VECTORES======");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(" > Ingresa el número {0}: ", i + 1);
                array2[i] = int.Parse(Console.ReadLine());
            }
            Console.Clear();
            Console.WriteLine("======SUMA DE VECTORES======");
            Console.Write("\nVector original --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }
            Console.Write("\nVector dos --->\t\t");
            for (int i = 0; i < array2.Length; i++)
            {
                Console.Write($"{array2[i]}\t");
            }
            Console.Write("\nSuma de vectores --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                sum[i] = array[i] + array2[i];
                Console.Write($"{sum[i]}\t");
            }
            Console.ReadKey();
        }

        static void function_8(int[] array)
        {
            int[] array2 = new int[array.Length];
            int[] subtraction = new int[array.Length];
            Console.Clear();
            Console.WriteLine("======RESTA DE VECTORES======");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(" > Ingresa el número {0}: ", i + 1);
                array2[i] = int.Parse(Console.ReadLine());
            }
            Console.Clear();
            Console.WriteLine("======RESTA DE VECTORES======");
            Console.Write("\nVector original --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }
            Console.Write("\nVector dos --->\t\t");
            for (int i = 0; i < array2.Length; i++)
            {
                Console.Write($"{array2[i]}\t");
            }
            Console.Write("\nResta de vectores --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                subtraction[i] = array[i] - array2[i];
                Console.Write($"{subtraction[i]}\t");
            }
            Console.ReadKey();
        }

        static void function_9(int[] array)
        {
            int[] array2 = new int[array.Length];
            int[] multiplication = new int[array.Length];
            Console.Clear();
            Console.WriteLine("======MULTIPLICACION DE VECTORES======");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(" > Ingresa el número {0}: ", i + 1);
                array2[i] = int.Parse(Console.ReadLine());
            }
            Console.Clear();
            Console.WriteLine("======MULTIPLICACION DE VECTORES======");
            Console.Write("\nVector original --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }
            Console.Write("\nVector dos --->\t\t");
            for (int i = 0; i < array2.Length; i++)
            {
                Console.Write($"{array2[i]}\t");
            }
            Console.Write("\nMultiplicacion de vectores --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                multiplication[i] = array[i] * array2[i];
                Console.Write($"{multiplication[i]}\t");
            }
            Console.ReadKey();
        }

        static void function_10(int[] array)
        {
            int[] array2 = new int[array.Length];
            int[] division = new int[array.Length];
            Console.Clear();
            Console.WriteLine("======DIVISION DE VECTORES======");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(" > Ingresa el número {0}: ", i + 1);
                array2[i] = int.Parse(Console.ReadLine());
            }
            Console.Clear();
            Console.WriteLine("======DIVISION DE VECTORES======");
            Console.Write("\nVector original --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]}\t");
            }
            Console.Write("\nVector dos --->\t\t");
            for (int i = 0; i < array2.Length; i++)
            {
                Console.Write($"{array2[i]}\t");
            }
            Console.Write("\nDivision de vectores --->\t");
            for (int i = 0; i < array.Length; i++)
            {
                division[i] = array[i] / array2[i];
                Console.Write($"{division[i]}\t");
            }
            Console.ReadKey();
        }
    }
}
