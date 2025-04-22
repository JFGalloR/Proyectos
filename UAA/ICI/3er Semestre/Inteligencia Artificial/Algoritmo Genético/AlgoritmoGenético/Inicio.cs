using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AlgoritmoGenético
{
    public partial class Inicio : Form
    {
        bool validado = false;
        int generacion; int min = 0; int max=20; double presicion; int pob; int mutacion; int cruce;
        public Inicio()
        {
            InitializeComponent();
            button1.Select();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            validado = true;
            if (textBox3.Text.Length != 0)
            {
                if(int.Parse(textBox3.Text) < 100)
                cruce = int.Parse(textBox3.Text);
            }
            else
            {
                validado = false;
            }
            
            if (textBox4.Text.Length != 0)
            {
                if(int.Parse(textBox4.Text) < 100)
                mutacion = int.Parse(textBox4.Text);
            }
            else
            {
                validado = false;
            }

            if(textBox1.Text.Length == 0)
            {
                validado = false;
            }
            else
            {
                presicion = double.Parse(textBox1.Text);
            }

            if (textBox2.Text.Length == 0)
            {
                validado = false;
            }
            else
            {
                pob = int.Parse(textBox2.Text);
            }

            if (textBox5.Text.Length == 0)
            {
                validado = false;
            }
            else
            {
                generacion = int.Parse(textBox5.Text);
            }



            if (validado)
            {
                Grafica g = new Grafica(generacion, min, max, presicion, pob, mutacion, cruce);
                g.ShowDialog();
            }
            else
            {
                MessageBox.Show("Ingresa datos válidos.", "Obtener Máximo", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '.' && e.KeyChar != (char)Keys.Back)
            {
                e.Handled = true;
            }
            if ((e.KeyChar == '.') && ((sender as TextBox).Text.IndexOf('.') > -1))
            {
                e.Handled = true;
            }
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '.' && e.KeyChar != (char)Keys.Back)
            {
                e.Handled = true;
            }
        }

        private void textBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '.' && e.KeyChar != (char)Keys.Back)
            {
                e.Handled = true;
            }
            if ((e.KeyChar == '.') && ((sender as TextBox).Text.IndexOf('.') > -1))
            {
                e.Handled = true;
            }
        }

        private void textBox4_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '.' && e.KeyChar != (char)Keys.Back)
            {
                e.Handled = true;
            }
            if ((e.KeyChar == '.') && ((sender as TextBox).Text.IndexOf('.') > -1))
            {
                e.Handled = true;
            }
        }

        private void textBox5_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '.' && e.KeyChar != (char)Keys.Back)
            {
                e.Handled = true;
            }
        }

    }
}
