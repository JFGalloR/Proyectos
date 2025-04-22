using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EJERCICIO_ArchivosTxt
{
    public partial class Consultar : Form
    {
        // Constructor donde se inicializa el contenido del textBox.
        public Consultar()
        {
            InitializeComponent();
            string[] lineas = File.ReadAllLines("Alumnos_UAA.txt");

            for (int i = 0; i < lineas.Length; i += 5)
            {

                textBox1.Text += "ID:\t" + lineas[i] + Environment.NewLine;
                textBox1.Text += "Nombre:\t" + lineas[i + 1] + Environment.NewLine;
                textBox1.Text += "Centro:\t" + lineas[i + 2] + Environment.NewLine;
                textBox1.Text += "Carrera:\t" + lineas[i + 3] + Environment.NewLine + Environment.NewLine;
            }
        }
        // Evento para dar efecto al botón de salida.
        private void pictureBox2_MouseMove(object sender, MouseEventArgs e)
        {
            pictureBox2.Size = new Size(38, 38);
            pictureBox2.Location = new Point(12, 7);
        }
        // Evento para dar efecto al botón de salida.
        private void pictureBox2_MouseLeave(object sender, EventArgs e)
        {
            pictureBox2.Size = new Size(32, 32);
            pictureBox2.Location = new Point(12, 10);
        }
        // Evento para el botón de salida.
        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
