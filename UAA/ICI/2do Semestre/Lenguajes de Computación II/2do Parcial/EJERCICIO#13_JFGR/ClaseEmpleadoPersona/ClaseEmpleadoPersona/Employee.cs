using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClaseEmpleadoPersona
{
    internal class Employee : Person
    {
        double salary;
        public double Salary
        {
            get { return salary; }
            set { salary = value; }
        }
        public void employeeshowData()
        {
            personShowData();
            Console.WriteLine($"  > Mi sueldo es de ${salary}");
        }
    }
}
