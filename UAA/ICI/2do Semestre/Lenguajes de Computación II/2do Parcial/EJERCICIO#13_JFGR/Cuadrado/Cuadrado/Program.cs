using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cuadrado
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Square r1 = new Square();

            Console.WriteLine("============== AREA AND PERIMETER ==============");
            Console.Write("\t> Type the saquare side: ");
            r1.setSide(Convert.ToDouble(Console.ReadLine()));
            Console.WriteLine("------------------------------------------------");
            Console.WriteLine($"\t= Perimeter: {r1.getPerimeter()}");
            Console.WriteLine($"\t= Area: {r1.getArea()}");
            Console.WriteLine("------------------------------------------------\n");
        }
    }
}
