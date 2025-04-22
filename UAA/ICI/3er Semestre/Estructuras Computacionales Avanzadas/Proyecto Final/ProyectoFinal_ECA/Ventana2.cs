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
    public partial class Ventana2 : Form
    {
        Grafo g;
        Principal p;
        public Ventana2(Principal p)
        {   
            this.p = p;
            g = p.g;
            InitializeComponent();
            LlenarTablas();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
            p.Show();
        }

        private void Ventana2_FormClosing(object sender, FormClosingEventArgs e)
        {
            p.Show();
        }

        private void LlenarTablas()
        {
            // Lista  de Adyacencias.
            int c = 0;
            foreach (String aux1 in g.listaAdyacencia.Keys)
            {
                DataGridViewTextBoxColumn nC = new DataGridViewTextBoxColumn();
                nC.HeaderText = aux1;
                matrizAdy.Columns.Add(nC);

                matrizAdy.Rows.Add();
                matrizAdy.Rows[c].HeaderCell.Value = aux1;


                String aristas = String.Empty;
                foreach (String aux2 in g.listaAdyacencia[aux1].Keys)
                {
                    aristas += aristas.Equals(String.Empty) ? aux2 : ", " + aux2;
                }
                listaAdy.Rows.Add(aux1, aristas);
                c++;
            }

            // Matriz de Adyacencias.
            c = 0;
            foreach (String aux1 in g.listaAdyacencia.Keys)
            {
                int j = 0;
                foreach (String aux2 in g.listaAdyacencia.Keys)
                {
                    int aux = 0;
                    if (g.listaAdyacencia[aux1].ContainsKey(aux2))
                    {
                        aux = g.listaAdyacencia[aux1][aux2];
                    }
                    matrizAdy.Rows[c].Cells[j].Value = aux;
                    j++;
                }
                c++;
            }
        }
    }
}
