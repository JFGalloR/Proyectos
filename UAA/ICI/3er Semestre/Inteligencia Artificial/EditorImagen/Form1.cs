using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EditorImagen
{
    public partial class Form1 : Form
    {
        Bitmap original;
        Bitmap imagen1;
        Bitmap imagen2;
        public Form1()
        {
            InitializeComponent();
            panel1.Visible = false;
            menuStrip1.Items[1].Enabled = false;
            menuStrip1.Items[2].Enabled = false;
            menuStrip1.Items[3].Enabled = false;
            button1.Enabled = false;
        }

        private void abrirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog
            {
                Title = "Selecciona imagen",
                Filter = "Archivos de imagen| *.jpg;*.jpeg;*.png;*.gif;*.bmp"
            };

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                original = new Bitmap(openFileDialog.FileName);
                imagen1 = (Bitmap)original.Clone();
                imagen2 = (Bitmap)original.Clone();
                pictureBox1.Image = original;
                pictureBox2.Image = original;
                progressBar1.Maximum = original.Width * original.Height;
                menuStrip1.Items[1].Enabled = true;
                menuStrip1.Items[2].Enabled = true;
                menuStrip1.Items[3].Enabled = true;
                button1.Enabled = true;
                panel1.Visible = false;
                trackBar1.Value = trackBar1.Maximum / 2;
            }
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void originalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            imagen2 = (Bitmap)original.Clone();
            pictureBox2.Image = imagen2;
            panel1.Visible = false;
        }

        private void grisesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            imagen2 = (Bitmap)imagen1.Clone();
            panel1.Visible = false;
            progressBar1.Visible = true;
            button1.Enabled = false;
            for (int y = 0; y < imagen2.Height; y++)
            {
                for (int x = 0; x < imagen2.Width; x++)
                {
                    Color pixelColor = imagen2.GetPixel(x, y);
                    int promedio = (pixelColor.R + pixelColor.G + pixelColor.B) / 3;
                    Color nuevoColor = Color.FromArgb(promedio, promedio, promedio);
                    imagen2.SetPixel(x, y, nuevoColor);
                    progressBar1.Value++;
                }
            }
            progressBar1.Visible = false;
            button1.Enabled = true;
            progressBar1.Value = 0;
            pictureBox2.Image = imagen2;
        }



        private void negativosToolStripMenuItem_Click(object sender, EventArgs e)
        {
            imagen2 = (Bitmap)imagen1.Clone();
            panel1.Visible = false;
            progressBar1.Visible = true;
            button1.Enabled = false;
            for (int y = 0; y < imagen2.Height; y++)
            {
                for (int x = 0; x < imagen2.Width; x++)
                {
                    Color pixelColor = imagen2.GetPixel(x, y);
                    Color nuevoColor = Color.FromArgb(255 - pixelColor.R, 255 - pixelColor.G, 255 - pixelColor.B);
                    imagen2.SetPixel(x, y, nuevoColor);
                    progressBar1.Value++;
                }
            }
            progressBar1.Visible = false;
            button1.Enabled = true;
            progressBar1.Value = 0;
            pictureBox2.Image = imagen2;
        }
        private void potenciaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            panel1.Visible = true;
        }

        private void potenciaTool()
        {
            imagen2 = (Bitmap)original.Clone();
            progressBar1.Visible = true;
            button1.Enabled = false;
            double valor = trackBar1.Value / 100.0;
            for (int y = 0; y < imagen2.Height; y++)
            {
                for (int x = 0; x < imagen2.Width; x++)
                {
                    Color pixelColor = imagen2.GetPixel(x, y);
                    int r = (int)(255.0 * Math.Pow(pixelColor.R / 255.0, valor));
                    int g = (int)(255.0 * Math.Pow(pixelColor.G / 255.0, valor));
                    int b = (int)(255.0 * Math.Pow(pixelColor.B / 255.0, valor));
                    Color nuevoColor = Color.FromArgb(r, g, b);
                    imagen2.SetPixel(x, y, nuevoColor);
                    progressBar1.Value++;
                }
            }
            panel1.Visible = true;
            progressBar1.Visible = false;
            button1.Enabled = true;
            progressBar1.Value = 0;
            pictureBox2.Image = imagen2;
        }

        private void binarizaciónToolStripMenuItem_Click(object sender, EventArgs e)
        {
            imagen2 = (Bitmap)imagen1.Clone();
            panel1.Visible = false;
            progressBar1.Visible = true;
            button1.Enabled = false;
            for (int y = 0; y < imagen2.Height; y++)
            {
                for (int x = 0; x < imagen2.Width; x++)
                {
                    Color pixelColor = imagen2.GetPixel(x, y);
                    int color = (pixelColor.R > 128) ? 255 : 0;
                    Color nuevoColor = Color.FromArgb(color, color, color);
                    imagen2.SetPixel(x, y, nuevoColor);
                    progressBar1.Value++;
                }
            }
            progressBar1.Visible = false;
            button1.Enabled = true;
            progressBar1.Value = 0;
            pictureBox2.Image = imagen2;
        }

        private void trackBar1_MouseUp(object sender, MouseEventArgs e)
        {
            potenciaTool();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            imagen1 = (Bitmap)imagen2.Clone();
            pictureBox1.Image = pictureBox2.Image;
            panel1.Visible = false;
            trackBar1.Value = trackBar1.Maximum / 2;
        }

        private void guardarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (imagen1 != null)
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Filter = "Archivos de imagen|*.jpg;*.jpeg;*.png;*.bmp|Todos los archivos (*.*)|*.*";

                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    string filePath = saveFileDialog.FileName;
                    imagen1.Save(filePath, ImageFormat.Jpeg);
                    MessageBox.Show("Imagen guardada exitosamente.", "Guardar imagen", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            else
            {
                MessageBox.Show("Imagen no cargada.", "Guardar imagen", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void recuperarColorToolStripMenuItem_Click(object sender, EventArgs e)
        {


        }

        private void gammaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            imagen2 = (Bitmap)imagen1.Clone();
            panel1.Visible = false;
            progressBar1.Visible = true;
            button1.Enabled = false;
            for (int y = 0; y < imagen2.Height; y++)
            {
                for (int x = 0; x < imagen2.Width; x++)
                {
                    Color pixelColor = imagen2.GetPixel(x, y);
                    int promedio = (pixelColor.R + pixelColor.G + pixelColor.B) / 3;
                    Color nuevoColor = Color.FromArgb(promedio, promedio, promedio);
                    imagen2.SetPixel(x, y, nuevoColor);
                    progressBar1.Value++;
                }
            }
            progressBar1.Visible = false;
            button1.Enabled = true;
            progressBar1.Value = 0;
            pictureBox2.Image = imagen2;
        }

        private void pixelHomogéneoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(colorDialog1.ShowDialog() == DialogResult.OK)
            {
                Pixel p = new Pixel(colorDialog1.Color);
                p.Show();
            }
            else
            {
                MessageBox.Show("Color no elegido.", "Seleccionar pixel", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void colorearImágenToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
        private void rojoRToolStripMenuItem_Click(object sender, EventArgs e)
        {
            redGrafica red = new redGrafica((Bitmap)imagen1.Clone());
            red.Show();
        }

        private void verdeGToolStripMenuItem_Click(object sender, EventArgs e)
        {
            greenGrafica green = new greenGrafica((Bitmap)imagen1.Clone());
            green.Show();
        }

        private void azulBToolStripMenuItem_Click(object sender, EventArgs e)
        {
            blueGrafica blue = new blueGrafica((Bitmap)imagen1.Clone());
            blue.Show();
        }
    }
}
