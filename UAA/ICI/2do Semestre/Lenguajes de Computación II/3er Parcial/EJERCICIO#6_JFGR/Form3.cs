using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EJERCICIO_CheckBox
{
    public partial class Form3 : Form
    {
        private Form1 Menu;

        public Form3(Form1 Menu)
        {
            InitializeComponent();
            this.Menu = Menu;
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked == true)
            {
                checkBox2.Font = new Font("Cascadia Code", 12F, FontStyle.Bold, GraphicsUnit.Point);
                button1.Enabled = true;
            }
            else
            {
                checkBox2.Font = new Font("Cascadia Code", 12F, FontStyle.Regular, GraphicsUnit.Point);
                button1.Enabled = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
            MessageBox.Show("Ingreso exitoso.", "Aplicación", MessageBoxButtons.OK, MessageBoxIcon.Information);
            Menu.Show();
        }

        private void Form3_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.Close();
            Menu.Show();
        }
    }
}
