using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProyectoFinal_ECA
{
    public partial class Principal : Form
    {
        public Grafo g;

        public Principal()
        {
            InitializeComponent();
            g = new Grafo();
        }

        private void Principal_Activated(object sender, EventArgs e)
        {
            bool val = false;

            if (g.listaAdyacencia.Count > 0)
            {
                val = true;
            }

            button2.Enabled = val;
            button3.Enabled = val;
            button4.Enabled = val;
            button5.Enabled = val;
            button6.Enabled = val; 
            button7.Enabled = val;
            button8.Enabled = val;
        }

        private void BtnHover(object sender, EventArgs e)
        {
            Button b = sender as Button;

            label2.Font = new Font("Segoe UI", 18F, FontStyle.Regular);
            switch (b.Name)
            {
                case "button1":
                    label2.Text = "Ingresar nodos al grafo.";
                    break;
                case "button2":
                    label2.Text = "Mostrar la lista y matriz de adyacencia del grafo.";
                    break;
                case "button3":
                    label2.Text = "Mostrar el recorrido del grafo en anchura.";
                    break;
                case "button4":
                    label2.Text = "Mostrar el recorrido del grafo en profundidad.";
                    break;
                case "button5":
                    label2.Text = "Mostrar los componentes conexos del grafo.";
                    break;
                case "button6":
                    label2.Text = "Mostrar el camino más corto entre dos nodos con Dijkstra.";
                    break;
                case "button7":
                    label2.Text = "Mostrar el pareo del un grafo normal.";
                    break;
                case "button8":
                    label2.Text = "Mostrar el pareo del un grafo bipartito.";
                    break;
            }
        }

        private void BtnLeave(object sender, EventArgs e)
        {
            label2.Font = new Font("Segoe UI", 18F, FontStyle.Bold);
            label2.Text = "Selecciona una opción.";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Ventana1 v = new Ventana1(this);
            v.Show(); 
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Ventana2 v = new Ventana2(this);
            v.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Ventana3 v = new Ventana3(this);
            v.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Ventana4 v = new Ventana4(this);
            v.Show();
            this.Hide();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Ventana5 v = new Ventana5(this);
            v.Show();
            this.Hide();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Ventana6 v = new Ventana6(this);
            v.Show();
            this.Hide();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Ventana7 v = new Ventana7(this);
            v.Show();
            this.Hide();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Ventana8 v = new Ventana8(this);
            v.Show();
            this.Hide();
        }
    }
}