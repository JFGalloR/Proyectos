/*================================================================
   EJERCICIO. Orden de Llamada de los Constructores.
 ---------------------------------------------------------------
    OBJETIVO.
        Crear un programa que contenga las siguientes clases:
        • Una clase Trabajador, cuyo constructor escriba en 
          pantalla “Soy un trabajador”.
        • Una clase Programador, que derive de Trabajador, 
          cuyo constructor escriba en pantalla “Soy 
          Programador”.
        • Una clase Analista, que derive de Trabajador, cuyo 
          constructor escriba en pantalla “Soy Analista”.
        • Una clase Ingeniero, que derive de Trabajador, cuyo 
          constructor escriba en pantalla “Soy Ingeniero”.
        • Una clase IngenieroInformatico, que derive de 
          Ingeniero, cuyo constructor escriba en pantalla “Soy
          Ingeniero informático”.
        • En el main del proyecto “PruebadeTrabajadores”, cree 
          un objeto perteneciente a cada una de esas clases. 
 ---------------------------------------------------------------
    Juan Francisco Gallo Ramírez
    15 de Marzo de 2023
    I.C.I. 232872
================================================================*/

using System;

class Trabajador
{
    public Trabajador()
    {
        Console.WriteLine("Soy un trabajador");
    }
}

class Programador : Trabajador
{
    public Programador()
    {
        Console.WriteLine("Soy Programador");
    }
}

class Analista : Trabajador
{
    public Analista()
    {
        Console.WriteLine("Soy Analista");
    }
}

class Ingeniero : Trabajador
{
    public Ingeniero()
    {
        Console.WriteLine("Soy Ingeniero");
    }
}

class IngenieroInformatico : Ingeniero
{
    public IngenieroInformatico()
    {
        Console.WriteLine("Soy Ingeniero informático");
    }
}

class PruebaDeTrabajadores
{
    static void Main(string[] args)
    {
        Trabajador t = new Trabajador();
        Console.WriteLine();

        Programador p = new Programador();
        Console.WriteLine();

        Analista a = new Analista();
        Console.WriteLine();

        Ingeniero i = new Ingeniero();
        Console.WriteLine();

        IngenieroInformatico ii = new IngenieroInformatico();
        Console.WriteLine();
    }
}