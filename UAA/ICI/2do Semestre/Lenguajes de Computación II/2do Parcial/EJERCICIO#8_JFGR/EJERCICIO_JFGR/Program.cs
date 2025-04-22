using System;
using System.Collections.Generic;
using System.Text;

namespace Ej12_GetSet_Persona
{
    class clsPersona
    {
        //Atributo
        private string? nombre;
        private int edad;

        //Metodos
        //______________________________ SET
        public void setNombre(string _nombre)
        {
            nombre = _nombre;
        }
        public void setEdad(int _edad)
        {
            edad = _edad;
        }
        //______________________________ GET
        public string getNombre()
        {
            return nombre!;
        }
        public int getEdad()
        {
            return edad;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            clsPersona p1 = new clsPersona();
            p1.setNombre("Juan");
            p1.setEdad(18);

            Console.WriteLine("\n\t> La persona se llama " + p1.getNombre() + " y tiene " + p1.getEdad() + " años.");
            Console.ReadKey();
        }
    }
}
