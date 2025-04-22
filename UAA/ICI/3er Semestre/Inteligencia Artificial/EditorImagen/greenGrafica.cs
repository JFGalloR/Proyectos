using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace EditorImagen
{
    public partial class greenGrafica : Form
    {
        int[] pixel = new int[256];
        public greenGrafica(Bitmap imagen)
        {
            InitializeComponent();

            for (int y = 0; y < imagen.Height; y++)
            {
                for (int x = 0; x < imagen.Width; x++)
                {
                    Color color = imagen.GetPixel(x, y);
                    pixel[(int)color.G]++;
                }
            }
            for (int i = 0; i < 256; i++)
            {
                chart1.Series["green"].Points.Add(pixel[i]);
            }
        }
    }
}
