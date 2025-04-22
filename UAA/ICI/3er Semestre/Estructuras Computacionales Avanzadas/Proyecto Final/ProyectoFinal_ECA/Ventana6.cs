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
    public partial class Ventana6 : Form
    {
        Grafo g;
        Principal p;
        public Ventana6(Principal p)
        {
            InitializeComponent();
            this.p = p;
            g = p.g;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
            p.Show();
        }

        private void Ventana6_FormClosing(object sender, FormClosingEventArgs e)
        {
            p.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = string.Empty;
            if (nodo1.Text != String.Empty && nodo2.Text != String.Empty)
            {
                if (g.listaAdyacencia.ContainsKey(nodo1.Text) && g.listaAdyacencia.ContainsKey(nodo2.Text))
                {
                    List<String> lis = g.Dijkstra(nodo1.Text, nodo2.Text);

                    if(lis != null)
                    {
                        foreach (String aux in lis)
                        {
                            textBox1.Text += (textBox1.Text == String.Empty) ? aux : "-" + aux;
                        }
                        textBox1.Text += Environment.NewLine + Environment.NewLine + "Peso del camino: " + g.PesoCamino(lis);
                    }
                    else
                    {
                        textBox1.Text = "No se encontró un camino.";
                    }
                }
                else
                {
                    MessageBox.Show("Nodo no encontrado.", "Camino más corto", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                MessageBox.Show("Ingresa los nodos correctamente.", "Camino más corto", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }
    }
}
