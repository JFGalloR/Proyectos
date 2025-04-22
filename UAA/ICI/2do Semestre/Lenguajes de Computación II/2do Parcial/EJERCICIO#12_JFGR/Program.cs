/*===============================================================
    EJERCICIO. Uso de "Static". 
----------------------------------------------------------------
    OBJETIVO:
    > Ejercicio 1. 
    Del ejemplo, en donde usamos la función "BorrarPantalla" 
    de una clase "Hardware" sin necesidad de crear primero un 
    objeto, ahora escriba una función "static" llamada 
    "EscribirCentrado", que escriba centrado horizontalmente 
    el texto que se le indique como parámetro.
    > Ejercicio 2. 
    Del ejemplo, en donde usamos la función "BorrarPantalla" 
    de una clase "Hardware" creando un objeto para acceder a 
    sus métodos, escriba una función llamada "EscribirCentrado", 
    que escriba centrado horizontalmente el texto que se le 
    indique como parámetro. Al contrario que en el ejercicio 1, 
    esta versión no será "static".
----------------------------------------------------------------
      Juan Francisco Gallo Ramírez
      23 de Marzo de 2023
      U.A.A. I.C.I. 
===============================================================*/
using EJERCICIO_JFGR;
using System;
using System.Diagnostics.Metrics;

internal class Program
{
    private static void Main(string[] args)
    {
        Hardware Hardware1 = new Hardware();

        Console.ForegroundColor = ConsoleColor.Red;
        Hardware.CenterText("====================================== TEXTO CENTRADO ======================================\n");
        Console.ForegroundColor = ConsoleColor.White;

        // Con 'static'.
        Console.WriteLine("\t> Texto centrado (con 'static'):\n");
        Console.ForegroundColor = ConsoleColor.Yellow;
        // Ejemplo de texto.
        Hardware.CenterText("Lorem ipsum dolor sit amet consectetur adipiscing elit eu,");
        Hardware.CenterText("eros dignissim a sollicitudin cursus pharetra ante elementum ultrices,");
        Hardware.CenterText("congue metus torquent iaculis magnis suscipit venenatis.");
        Console.WriteLine();

        // Sin 'static'.
        Console.ForegroundColor = ConsoleColor.White;
        Console.WriteLine("\t> Texto centrado (sin 'static'):\n");
        Console.ForegroundColor = ConsoleColor.Yellow;
        // Ejemplo de texto.
        Hardware1.centerText("Lorem ipsum dolor sit amet consectetur adipiscing elit eu,");
        Hardware1.centerText("eros dignissim a sollicitudin cursus pharetra ante elementum ultrices,");
        Hardware1.centerText("congue metus torquent iaculis magnis suscipit venenatis.");
        Console.WriteLine();

        Console.ReadKey();
    }
}