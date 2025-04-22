using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EJERCICIO_ComboBox
{
    public partial class Form2 : Form
    {
        private Form1 Menu;

        public Form2(Form1 Menu)
        {
            InitializeComponent();
            this.Menu = Menu;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
            Menu.Show();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            Text = comboBox1.Text;
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.Close();
            Menu.Show();
        }
    }
}
