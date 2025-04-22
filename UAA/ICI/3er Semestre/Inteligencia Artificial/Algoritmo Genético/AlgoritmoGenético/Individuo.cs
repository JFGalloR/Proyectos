using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgoritmoGenético
{
    internal class Individuo
    {
        public string cromosoma = string.Empty;
        public double x = 0.0;
        public double y = 0.0;
        Random r;
        public Individuo(int l, int min, int max, Random r)
        {
            this.r = r;
            for (int i = 0; i < l; i++)
            {
                cromosoma += r.Next(2).ToString();
            }
            x = min + Convert.ToInt32(cromosoma, 2) * (max - min) / (Math.Pow(2, l) + 1);
            funcion();
            
        }

        public Individuo(string data, int l, int min, int max)
        {
            this.cromosoma = data;
            x = min + Convert.ToInt32(cromosoma, 2) * (max - min) / (Math.Pow(2, l) + 1);
            funcion();
        }

        public void funcion()
        {
            y = x / (1 + Math.Pow(x, 2));
        }
    }
}
