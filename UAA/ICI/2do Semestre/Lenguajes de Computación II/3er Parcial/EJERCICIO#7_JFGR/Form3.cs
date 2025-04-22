using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace EJERCICIO_ComboBox
{
    public partial class Form3 : Form
    {
        private Form1 Menu;
        public Form3(Form1 Menu)
        {
            InitializeComponent();
            this.Menu = Menu;
        }
        private void Form3_Load(object sender, EventArgs e)
        {
            for (int f = 0; f <= 255; f++)
            {
                comboBox1.Items.Add(f);
                comboBox2.Items.Add(f);
                comboBox3.Items.Add(f);
            }
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
            comboBox3.SelectedIndex = 0;
        }
        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
            Menu.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            BackColor = panel1.BackColor = Color.FromArgb(int.Parse(comboBox1.Text), int.Parse(comboBox2.Text), int.Parse(comboBox3.Text));
        }

        private void Cambio_ComboBox(object sender, EventArgs e)
        {
            if ( comboBox1.Text != string.Empty && comboBox2.Text != string.Empty && comboBox3.Text != string.Empty )
            {
                panel1.BackColor = panel1.BackColor = Color.FromArgb(int.Parse(comboBox1.Text), int.Parse(comboBox2.Text), int.Parse(comboBox3.Text));
            }

        }
    }
}
