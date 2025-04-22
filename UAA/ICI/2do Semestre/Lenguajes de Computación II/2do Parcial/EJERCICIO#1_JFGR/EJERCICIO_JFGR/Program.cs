/*=============================================
 EJERCICIO #1. PESO EN TONELADAS.
 ----------------------------------------------
 OBJETIVO:
    Leer el peso en toneladas de una cosa, y 
    si es mayor a 500 toneladas, escribir 
    “Pesa más de media tonelada”, si es menor 
    escribir “Pesa menos de media tonelada”, 
    si es igual a 500 toneladas escribir 
    “Pesa media tonelada”.
 ----------------------------------------------
 Juan Francisco Gallo Ramírez
 23 de Febrero de 2023
 I.C.I.
=============================================*/
using System;

namespace Peso_en_toneladas
{
    class Peso_en_toneladas
    {
        static void Main(string[] args)
        {
            int peso;

            Console.WriteLine("=============== PESO EN TONELADAS ===============");
            Console.WriteLine();
            Console.WriteLine("> Ingresa peso en (kg):");
            peso = Convert.ToInt32(Console.ReadLine());

            if (peso > 500)
            {
                Console.WriteLine("      -----------------------------------");
                Console.WriteLine("       EL PESO ES MAYOR A MEDIA TONELADA");
                Console.WriteLine("      -----------------------------------");
            }
            else
            if (peso < 500)
            {
                Console.WriteLine("      -----------------------------------");
                Console.WriteLine("       EL PESO ES MENOR A MEDIA TONELADA");
                Console.WriteLine("      -----------------------------------");
            }
            else
            {
                Console.WriteLine("      -----------------------------------");
                Console.WriteLine("       EL PESO ES IGUAL A MEDIA TONELADA");
                Console.WriteLine("      -----------------------------------");
            }
            Console.WriteLine("=================================================");
            Console.ReadKey();
        }
    }
}