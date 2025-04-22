using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlturaPromedio
{
    internal class Program
    {
        static void Main(string[] args)
        {
            float average=0;
            float[] tall = new float[5];
            int greaterThan=0, lessThan=0;
            for(int i=0;i<tall.Length;i++)
            {
                Console.Write($"Altura {i+1}: ");
                tall[i] = float.Parse(Console.ReadLine());
                average += tall[i];
            }
            average /= tall.Length;
            foreach(int i in tall)
            {
                if(i > average)
                {
                    greaterThan++;
                }
                else
                {
                    lessThan++;
                }
            }
            Console.WriteLine();
            Console.WriteLine($"Promedio = {average}");
            Console.WriteLine();
            Console.WriteLine($"{greaterThan} personas son mas altas que el promedio");
            Console.WriteLine($"{lessThan} personas son menos altas que el promedio");
            Console.WriteLine();
        }
    }
}
