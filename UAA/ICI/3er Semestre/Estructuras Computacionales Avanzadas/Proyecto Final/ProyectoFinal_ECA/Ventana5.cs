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
    public partial class Ventana5 : Form
    {
        Grafo g;
        Principal p;
        public Ventana5(Principal p)
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

        private void Ventana5_FormClosing(object sender, FormClosingEventArgs e)
        {
            p.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            List<String> lis = g.ComponentesConexos();
            
            textBox1.Text = String.Empty;

            if(lis.Count > 0)
            {
                foreach (String str in lis)
                {
                    textBox1.Text += str + Environment.NewLine;
                }
            }
            else
            {
                textBox1.Text = "- No se encontraron Componentes -";
            }
        }
    }
}
