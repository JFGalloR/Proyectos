using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Operaciones_Pablo_Francisco
{
    internal class Operacion
    {
        //Protected: Las clases hijas pueden acceder a los atributos
        protected double num1;
        protected double num2;

        //Propiedad Get-Set para Numero 1
        public double Num1
        {
            get { return num1; }
            set { num1 = value; }
        }

        //Propiedad Get-Set para Numero 2
        public double Num2
        {
            get { return num2; }
            set { num2 = value; }
        }
    }
}
