﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClaseEmpleadoPersona
{
    internal class Person
    {
        string name;
        int age;
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public int Age
        {
            get { return age; }
            set { age = value; }
        }
        public void personShowData()
        {
            Console.WriteLine($"  > Me llamo {name}, y tengo {age} años.");
        }
    }

}
