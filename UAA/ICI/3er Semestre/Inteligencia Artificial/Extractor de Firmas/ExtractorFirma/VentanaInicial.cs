using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace ExtractorFirma
{
    public partial class VentanaInicial : Form
    {
        Bitmap imagen, firma;
        List<Elemento> lis = new List<Elemento>();
        List<Elemento> fir = new List<Elemento>();
        public VentanaInicial()
        {
            InitializeComponent();
            cargar.Select();
            progressBar1.Visible = false;
            extraer.Enabled = false; 
        }

        private void cargar_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog
            {
                Title = "Selecciona imagen",
                Filter = "Archivos de imagen| *.jpg;*.jpeg;*.png;*.gif;*.bmp"
            };

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                imagen = new Bitmap(openFileDialog.FileName);
                firma = (Bitmap)imagen.Clone();
                pictureBox1.Image = imagen;
                extraer.Enabled = true;
            }
        }

        private void extraer_MouseMove(object sender, MouseEventArgs e)
        {
            extraer.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));

        }

        private void extraer_MouseLeave(object sender, EventArgs e)
        {
            extraer.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
        }

        private void ProcesoEdicion()
        {
            progressBar1.Visible = true;
            // Escala de Grises
            for (int y = 0; y < firma.Height; y++)
            {
                for (int x = 0; x < firma.Width; x++)
                {
                    Color pixelColor = firma.GetPixel(x, y);
                    int promedio = (pixelColor.R + pixelColor.G + pixelColor.B) / 3;
                    Color nuevoColor = Color.FromArgb(promedio, promedio, promedio);
                    firma.SetPixel(x, y, nuevoColor);
                    progressBar1.Value++;
                }
            }
            // Binarizacion
            for (int y = 0; y < firma.Height; y++)
            {
                for (int x = 0; x < firma.Width; x++)
                {
                    Color pixelColor = firma.GetPixel(x, y);
                    int color = (pixelColor.R > 110) ? 255 : 0;
                    Color nuevoColor = Color.FromArgb(color, color, color);
                    firma.SetPixel(x, y, nuevoColor);
                    progressBar1.Value++;
                }
            }
            progressBar1.Visible = false;
        }
        private void ProcesoExtraccion()
        {
            HashSet<Pixel> pixelsToProcess = new HashSet<Pixel>();

            for (int y = 0; y < firma.Height; y++)
            {
                for (int x = 0; x < firma.Width; x++)
                {
                    Color pixelColor = firma.GetPixel(x, y);
                    if (pixelColor.R < 255)
                    {
                        pixelsToProcess.Add(new Pixel(x, y));
                    }
                    progressBar1.Value++;
                }
            }

            while (pixelsToProcess.Count > 0)
            {
                Queue<Pixel> queue = new Queue<Pixel>();
                Pixel startPixel = pixelsToProcess.First();
                queue.Enqueue(startPixel);
                pixelsToProcess.Remove(startPixel);

                List<Pixel> aux = new List<Pixel>();

                while (queue.Count > 0)
                {
                    Pixel currentPixel = queue.Dequeue();
                    aux.Add(currentPixel);

                    foreach (Pixel adjacentPixel in GetAdjacentPixels(currentPixel))
                    {
                        if (pixelsToProcess.Contains(adjacentPixel))
                        {
                            queue.Enqueue(adjacentPixel);
                            pixelsToProcess.Remove(adjacentPixel);
                        }
                    }
                }

                lis.Add(new Elemento(aux));
            }
        }

        private List<Pixel> GetAdjacentPixels(Pixel pixel)
        {
            List<Pixel> adjacentPixels = new List<Pixel>();

            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (dx != 0 || dy != 0)
                    {
                        int newX = pixel.x + dx;
                        int newY = pixel.y + dy;

                        if (newX >= 0 && newX < firma.Width && newY >= 0 && newY < firma.Height)
                        {
                            adjacentPixels.Add(new Pixel(newX, newY));
                        }
                    }
                }
            }

            return adjacentPixels;
        }

        private void MostrarResultado()
        {
            if (lis.Count == 0)
            {
                return; // No hay elementos para procesar
            }

            
            double promedioLargo = lis.Average(e => e.Largo());
            double promedioAncho = lis.Average(e => e.Ancho());

            foreach (Elemento e in lis)
            {
                if (e.Largo() > promedioLargo*7 && e.Ancho() > promedioAncho*7)
                {
                    fir.Add(e);
                }
            }
            lis.Clear();

            int minX = int.MaxValue;
            int minY = int.MaxValue;
            int maxX = int.MinValue;
            int maxY = int.MinValue;

            foreach (Elemento e in fir)
            {
                foreach (Pixel pix in e.pixel)
                {
                    if (pix.x < minX)
                        minX = pix.x;
                    if (pix.x > maxX)
                        maxX = pix.x;
                    if (pix.y < minY)
                        minY = pix.y;
                    if (pix.y > maxY)
                        maxY = pix.y;
                }
            }

            int nuevoAncho = maxX - minX + 1;
            int nuevoAlto = maxY - minY + 1;

            Bitmap nuevoBitmap = new Bitmap(nuevoAncho+10, nuevoAlto+10);

            for (int y = 0; y < nuevoBitmap.Height; y++)
            {
                for (int x = 0; x < nuevoBitmap.Width; x++)
                {
                    nuevoBitmap.SetPixel(x, y, Color.White);
                }
            }

            foreach (Elemento e in fir)
            {
                foreach (Pixel pix in e.pixel)
                {
                    int xDestino = pix.x - minX;
                    int yDestino = pix.y - minY;
                    nuevoBitmap.SetPixel(xDestino+5, yDestino+5, Color.Black);
                }
            }

            if(fir.Count() > 0)
            {
                VentanaExtraccion ve = new VentanaExtraccion(nuevoBitmap);
                ve.ShowDialog();
            }
            else
            {
                MessageBox.Show("No se pudo identificar la firma.", "Extraer Imagen", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }

            fir.Clear();
        }

        private void extraer_Click(object sender, EventArgs e)
        {
            progressBar1.Value = 0;
            progressBar1.Maximum = imagen.Width * imagen.Height * 3;
            ProcesoEdicion();
            ProcesoExtraccion();
            MostrarResultado();
        }
    }
}
