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
    public partial class Ventana1 : Form
    {
        Grafo g;
        Principal p;
        public Ventana1(Principal p)
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

        private void Ventana1_FormClosing(object sender, FormClosingEventArgs e)
        {
            p.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(nodo1.Text != String.Empty && nodo2.Text != String.Empty && peso.Text != String.Empty)
            {
                if (g.AgregarArista(nodo1.Text, nodo2.Text, int.Parse(peso.Text), checkBox1.Checked))
                {
                    MessageBox.Show("Nodos y arista agregados.", "Agregar Nodo y Arista", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    nodo1.Text = String.Empty;
                    nodo2.Text = String.Empty;
                    peso.Text = String.Empty;
                }
                else
                {
                    String mensaje = "Ya existe una arista de \"" + nodo1.Text + "\" a \"" + nodo2.Text + "\".";
                    MessageBox.Show(mensaje, "Agregar Nodo y Arista", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                MessageBox.Show("Llena correctamente los datos.", "Agregar Nodo y Arista", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void peso_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != (char)Keys.Back)
            {
                e.Handled = true;
            }
        }
    }
}
