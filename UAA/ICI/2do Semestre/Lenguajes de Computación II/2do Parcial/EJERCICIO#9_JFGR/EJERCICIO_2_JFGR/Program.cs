/*-------------------------------------------------------------
  EJERCICIO. Métodos get / set
 *-------------------------------------------------------------
  Objetivo.
    Utilizar los método get y set en una clase llamada persona,
    donde los atributos sean el nombre y la edad ed la persona.
 *-------------------------------------------------------------
    Juan Francisco Gallo Ramírez
    09 de febrero de 2023
    I.C.I.
-------------------------------------------------------------*/

using System;
using System.Collections.Generic;
using System.Text;

namespace Ej12_GetSet_Perro
{
    class clsPersona
    {
        //Atributo
        private string? nombre;
        private int edad;

        //______________________________ SET
        public string Nombre
        {
            set { nombre = value; }
            get { return nombre!; }
        }
        public int Edad
        {
            set { edad = value; }
            get { return edad!; }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            clsPersona p1 = new clsPersona();
            p1.Nombre = "Juan";
            p1.Edad = 18;

            Console.WriteLine("\n\t> La persona se llama " + p1.Nombre + " y tiene " + p1.Edad + " años.");
            Console.ReadKey();
        }
    }
}
