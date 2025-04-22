using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtractorFirma
{
    internal class Elemento
    {
        public List<Pixel> pixel = new List<Pixel>();
        
        public Elemento(List<Pixel> pixel) 
        {
            this.pixel = new List<Pixel>(pixel);
        }
        public Elemento(Pixel pixel)
        {
            this.pixel.Add(pixel);
        }

        public int Ancho()
        {
            if (pixel.Count != 0)
            {
                int maxX = pixel[0].x;
                int minX = pixel[0].x;

                foreach (Pixel p in pixel)
                {
                    if (p.x > maxX)
                    {
                        maxX = p.x;
                    }

                    if (p.x < minX)
                    {
                        minX = p.x;
                    }
                }

                int ancho = maxX - minX;
                return ancho;
            }
            return 0;
        }

        public int Largo()
        {
            if (pixel.Count != 0)
            {
                int maxY = pixel[0].y;
                int minY = pixel[0].y;

                foreach (Pixel p in pixel)
                {
                    if (p.y > maxY)
                    {
                        maxY = p.y;
                    }

                    if (p.y < minY)
                    {
                        minY = p.y;
                    }
                }

                int largo = maxY - minY;
                return largo;
            }
            return 0;
        }
    }
}
