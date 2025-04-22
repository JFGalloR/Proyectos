/*===========================================================
  EJERCICIO. Introducir Contraseña.
 ----------------------------------------------------------
  OBJETIVO.
    Realice un programa en C#, en donde pida una contraseña.
    Si la contraseña es igual a hola, escribir: "Contraseña 
    Valida". Si la contraseña no es hola, seguir pidiéndola 
    hasta que la de bien.
 ----------------------------------------------------------
    Juan Francisco Gallo Ramírez
    23 de Febrero de 2023
    I.C.I.
===========================================================*/
using System;
namespace Contrsaeña;
internal class Program
{
    private static void Main(string[] args)
    {
        string password = "Hola";
        bool error;
        do
        {
            Console.Clear();
            error = false;
            Console.WriteLine("================= INGRESA AL SISTEMA =================\n");
            Console.Write("\t> Ingresa contraseña: ");
            if (!Console.ReadLine().Equals(password))
            {
                Console.WriteLine("\n\t# # # CONTRASEÑA INCORRECTA # # #");
                Console.ReadKey();
                error = true;
            }
            else
            {
                Console.WriteLine("\n\t+ + + CONTRASEÑA CORRECTA + + +");
                Console.ReadKey();
            }
        } while (error);
        Console.WriteLine("\n\t+ + +  EJECUCIÓN EXITOSA  + + +");
    }
}