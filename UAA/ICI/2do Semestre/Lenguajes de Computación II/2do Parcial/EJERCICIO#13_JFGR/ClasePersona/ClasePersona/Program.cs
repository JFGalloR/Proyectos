using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClasePersona
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string name;
            int age;
            Console.Write("Cual es tu nombre? ");
            name = Console.ReadLine();
            Console.Write("Cual es tu edad? ");
            age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine();
            Persona persona_1 = new Persona(name,age);
            persona_1.introduce();
            Console.WriteLine();
            if(persona_1.legalAge())
            {
                Console.WriteLine("Mayor de edad");
            }
            else
            {
                Console.WriteLine("Menor de edad");
            }
            Console.WriteLine();
        }
    }
}
