using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrabajadoresSueldos
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string name;
            double salary;
            double maxSalary=-1;
            int index=0;
            Employees[] emp = new Employees[5];
            for(int i=0;i<5;i++)
            {
                emp[i] = new Employees();
            }
            for(int i=0; i<5; i++)
            {
                Console.Write("Nombre: ");
                name=Console.ReadLine();
                Console.Write("Salario: ");
                salary=Double.Parse(Console.ReadLine());
                emp[i].Name = name; emp[i].Salary = salary;
                if(salary > maxSalary)
                {
                    maxSalary = salary;
                    index = i;
                }
                Console.WriteLine();
            }
            Console.WriteLine();
            Console.WriteLine($"El sueldo mayor es de ${maxSalary} y le pertenece a {emp[index].Name}");
            Console.WriteLine();
        }
    }
}
