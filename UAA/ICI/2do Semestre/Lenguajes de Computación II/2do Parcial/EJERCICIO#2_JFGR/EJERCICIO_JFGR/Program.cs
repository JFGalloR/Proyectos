/*=============================================
 EJERCICIO #2. NÚMERO MAYOR.
 ----------------------------------------------
 OBJETIVO:
    Realice un programa en C#, en donde 
    utilizando la instrucción If o If - else, 
    indicar cual numero es mayor de dos números 
    dados.
 ----------------------------------------------
 Juan Francisco Gallo Ramírez
 23 de Febrero de 2023
 I.C.I.
=============================================*/

using System;

namespace EJERCICIO_JFGR
{
    class Program
    {
        static void Main(string[] args)
        {
            int num1, num2;
            Console.WriteLine("=================== NÚMERO MAYOR ===================");
            Console.WriteLine();
            Console.WriteLine(" > Ingresa el número #1: ");
            num1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(" > Ingresa el número #2: ");
            num2 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine();
            Console.WriteLine("----------------------------------------------------");
            if (num1 > num2)
            {
                Console.WriteLine(" >> El número {0} es mayor que el número {1}.", num1, num2);
            }
            else
            if (num1 < num2)
            {
                Console.WriteLine(" >> El número {1} es mayor que el número {0}.", num1, num2);
            }
            else
            {
                Console.WriteLine(" >> El número {0} es igual que el número {1}.", num1, num2);
            }
            Console.WriteLine("====================================================");
            Console.ReadKey();
        }
    }
}
