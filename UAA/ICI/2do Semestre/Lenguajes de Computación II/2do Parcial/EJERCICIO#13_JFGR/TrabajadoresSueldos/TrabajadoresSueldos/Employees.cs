using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrabajadoresSueldos
{
    internal class Employees
    {
        string name;
        double salary;

        public string Name
        {
            set { name = value; }
            get { return name; }
        }

        public double Salary
        {
            set { salary = value; }
            get { return salary; }
        }
    }
}
