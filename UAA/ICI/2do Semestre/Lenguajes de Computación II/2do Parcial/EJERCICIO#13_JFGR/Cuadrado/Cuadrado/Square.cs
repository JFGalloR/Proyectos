using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cuadrado
{
    internal class Square
    {
        double side;
        public void setSide(double side)
        {
            this.side = side;
        }
        public double getPerimeter()
        {
            return (side * 4);
        }
        public double getArea()
        {
            return (side * side);
        }
    }
}
