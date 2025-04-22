using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EJERCICIO_JFGR
{
    public partial class Ejercicio3 : Form
    {
        public Ejercicio3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (Text == "Ejercicio 3")
            {
                Text = string.Empty;
            }
            Text += button1.Text;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (Text == "Ejercicio 3")
            {
                Text = string.Empty;
            }
            Text += button2.Text;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (Text == "Ejercicio 3")
            {
                Text = string.Empty;
            }
            Text += button3.Text;
        }

        private void Regresar_Click(object sender, EventArgs e)
        {
            Menu menu = new Menu();
            this.Hide();
            menu.Show();
        }

        private void Ejercicio3_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}
