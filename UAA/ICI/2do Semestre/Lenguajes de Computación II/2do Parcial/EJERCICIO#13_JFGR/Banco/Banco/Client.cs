using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Banco
{
    internal class Client
    {
        string name;
        double account = 0;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public double Account
        { 
            get { return account; } 
            set { account = value; } 
        }    
        public void retirar()
        {
            Console.WriteLine(" > Ingresa cantidad a retirar: ");
            double cant = Convert.ToDouble(Console.ReadLine());
            if(cant>account)
            {
                Console.WriteLine(" # # # FONDOS INSUFICIENTES # # #");
            }
            else
            {
                this.account -= cant;
                Console.WriteLine("\n-------------------------------------\n");
                Console.WriteLine($" > Se han retirado ${cant}");
                Console.WriteLine($" > FONDOS ACTUALES ${account}");
            }
            Console.ReadKey();
        }
        public void ingresar()
        {
            Console.WriteLine(" > Ingresa cantidad a ingresar: ");
            double cant = Convert.ToDouble(Console.ReadLine());
            this.account += cant;
            Console.WriteLine("\n-------------------------------------\n");
            Console.WriteLine($" > Se han ingresado ${cant}");
            Console.WriteLine($" > FONDOS ACTUALES  ${account}");
            Console.ReadKey(); 
        }
    }

}
