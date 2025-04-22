using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClaseEmpleadoPersona
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Person p1 = new Person();
            Employee e1 = new Employee();
            p1.Name = "Luyz Pavlo";
            p1.Age = 20;

            e1.Name = "Mi tio";
            e1.Age = 21;
            e1.Salary = 23;

            p1.personShowData();
            Console.WriteLine("\n");
            e1.employeeshowData();



        }
    }
}
