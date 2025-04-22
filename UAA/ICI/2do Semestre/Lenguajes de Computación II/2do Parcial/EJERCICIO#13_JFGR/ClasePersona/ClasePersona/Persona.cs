using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClasePersona
{
    internal class Persona
    {
        string name;
        int age;

        public Persona(string name, int age)
        {
            this.name = name;
            this.age = age;
        }

        public void introduce()
        {
            Console.WriteLine($"Name: {name} \n Age: {age}");
        }

        public bool legalAge()
        {
            return age >= 18;
        }
    }
}
