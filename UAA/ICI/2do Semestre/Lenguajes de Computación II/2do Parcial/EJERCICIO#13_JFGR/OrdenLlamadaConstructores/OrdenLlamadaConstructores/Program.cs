using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OrdenLlamadaConstructores
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Trabajador[] trabajador = new Trabajador[5];
            
            trabajador[0] = new Trabajador();
            Console.WriteLine();
            trabajador[1] = new Programador();
            Console.WriteLine();
            trabajador[2] = new Analista();
            Console.WriteLine();
            trabajador[3] = new Ingeniero();
            Console.WriteLine();
            trabajador[4] = new IngenieroInformatico();
            Console.WriteLine(); 
            Console.WriteLine();
        }
    }
}
