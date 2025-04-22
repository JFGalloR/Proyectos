/*===========================================================
  EJERCICIO. Vector de Números.
 ----------------------------------------------------------
  OBJETIVO.
    Elaborar un programa de un vector de 10 elementos o 
    pedirle al usuario de cuantos elementos desea el vector, 
    crearlo, y encontrar el numero mayor y el menor y su 
    posición.
 ----------------------------------------------------------
    Juan Francisco Gallo Ramírez
    23 de Febrero de 2023
    I.C.I.
===========================================================*/
using System;
namespace VectorMayorMenor;
    class Program
{
    static void Main(string[] args)
    {
        int n;
        Console.WriteLine("======================= VECTOR DE n ELEMENTOS =======================\n");
        Console.Write("\t> Ingrese la cantidad de elementos del vector: ");
        n = Convert.ToInt32(Console.ReadLine());

        int[] vector = new int[n];
        for (int i = 0; i < n; i++)
        {
            Console.Write("\t> Ingrese el elemento {0}: ", i + 1);
            vector[i] = Convert.ToInt32(Console.ReadLine());
        }

        int mayor = vector[0];
        int posMayor = 0;
        for (int i = 1; i < n; i++)
        {
            if (vector[i] > mayor)
            {
                mayor = vector[i];
                posMayor = i+1;
            }
        }

        int menor = vector[0];
        int posMenor = 0;
        for (int i = 1; i < n; i++)
        {
            if (vector[i] < menor)
            {
                menor = vector[i];
                posMenor = i+1;
            }
        }
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.WriteLine("\t> El número mayor del vector es: {0} (posición {1})", mayor, posMayor);
        Console.WriteLine("\t> El número menor del vector es: {0} (posición {1})", menor, posMenor);

        Console.ReadKey();
    }
}