/*===========================================================
  EJERCICIO. Matriz de Números.
 ----------------------------------------------------------
  OBJETIVO.
    Elaborar un programa de una matriz del numero de filas 
    y columnas que indique el usuario y mostrar la suma de 
    las filas y la suma de las columnas que tiene la matriz.
 ----------------------------------------------------------
    Juan Francisco Gallo Ramírez
    23 de Febrero de 2023
    I.C.I.
===========================================================*/
using System;

namespace SumaFilasColumnasMatriz
{
    class Program
    {
        static void Main(string[] args)
        {
            int filas, columnas;

            Console.WriteLine("============================ MATRIZ DE NÚMEROS ============================\n");
            Console.Write("\t> Ingrese el número de filas de la matriz: ");
            filas = Convert.ToInt32(Console.ReadLine());
            Console.Write("\t> Ingrese el número de columnas de la matriz: ");
            columnas = Convert.ToInt32(Console.ReadLine());
            Console.Clear();
            Console.WriteLine("============================ MATRIZ DE NÚMEROS ============================\n");
            int[,] matriz = new int[filas, columnas];
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    Console.Write("\t> Ingrese el elemento [{0},{1}]: ", i, j);
                    matriz[i, j] = Convert.ToInt32(Console.ReadLine());
                }
            }
            Console.Clear();
            Console.WriteLine("============================ MATRIZ DE NÚMEROS ============================\n");
            Console.WriteLine("\tMatriz:");
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    Console.Write("\t" + matriz[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine("\n----------------------------------------------------------------------\n") ;
            for (int i = 0; i < filas; i++)
            {
                int sumaFila = 0;
                for (int j = 0; j < columnas; j++)
                {
                    sumaFila += matriz[i, j];
                }
                Console.WriteLine("\t- La suma de la fila {0} es: {1}", i, sumaFila);
            }
            Console.WriteLine("\n----------------------------------------------------------------------\n");
            for (int j = 0; j < columnas; j++)
            {
                int sumaColumna = 0;
                for (int i = 0; i < filas; i++)
                {
                    sumaColumna += matriz[i, j];
                }
                Console.WriteLine("\t- La suma de la columna {0} es: {1}", j, sumaColumna);
            }
            Console.ReadKey();
        }
    }
}