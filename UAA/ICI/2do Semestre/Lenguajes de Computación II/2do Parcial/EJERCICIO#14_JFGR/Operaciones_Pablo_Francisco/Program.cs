using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Operaciones_Pablo_Francisco
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double numero1,numero2; 
            //Valores ingresados por el usuario
            Console.Write("Dame un numero: ");
            numero1= Convert.ToDouble(Console.ReadLine());
            Console.Write("Dame otro numero: ");
            numero2 = Convert.ToDouble(Console.ReadLine());

            //Objeto suma
            Suma sum= new Suma();
            sum.Num1 = numero1; sum.Num2 = numero2; //Propiedad Set() 
            //Propiedad Get() sum.Num1 & sum.Num2
            Console.WriteLine($"{sum.Num1} + {sum.Num2} = {sum.operaciones()}"); //Metodo operaciones de la clase Suma

            //Objeto resta
            Resta res = new Resta();
            res.Num1 = numero1; res.Num2 = numero2; //Propiedad Set()
            //Propiedad Get() res.Num1 & res.Num2
            Console.WriteLine($"{res.Num1} - {res.Num2} = {res.operaciones()}"); //Metodo operaciones de la clase Resta

            //Objeto division
            Division div = new Division(); 
            div.Num1 = 18; div.Num2 = 8; //Propiedad Set()
            //Propiedad Get() div.Num1 & div.Num2
            Console.WriteLine($"{div.Num1} / {div.Num2} = {div.operaciones()}"); //Metodo operaciones de la clase Division

            //Objeto multiplicacion
            Multiplicacion mult = new Multiplicacion();
            mult.Num1 = 80;mult.Num2 = 8;//Propiedad Set()
            //Propiedad Get() mult.Num1 & mult.Num2
            Console.WriteLine($"{mult.Num1} * {mult.Num2} = {mult.operaciones()}");//Metodo operaciones de la clase multiplicacion
        }
    }
}
