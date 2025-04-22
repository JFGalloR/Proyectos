using Microsoft.VisualBasic;
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
    public partial class Form2 : Form
    {
        private Form1 Menu;

        public Form2(Form1 Menu)
        {
            InitializeComponent();
            this.Menu = Menu;
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked == true)
            {
                checkBox2.Font = new Font("Cascadia Code", 12F, FontStyle.Bold, GraphicsUnit.Point);
                if (Text == "Ejercicio #1") Text = string.Format("({0}) ", checkBox2.Text);
                else Text += string.Format($"({checkBox2.Text}) ");
            }
            else
            {
                checkBox2.Font = new Font("Cascadia Code", 12F, FontStyle.Regular, GraphicsUnit.Point);
                Text = Text.Replace($"({checkBox2.Text}) ", "");
            }
            if (Text == "")
            {
                Text = "Ejercicio #1";
            }
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox3.Checked == true)
            {
                checkBox3.Font = new Font("Cascadia Code", 12F, FontStyle.Bold, GraphicsUnit.Point);
                if (Text == "Ejercicio #1") Text = string.Format("({0}) ", checkBox3.Text);
                else Text += string.Format("({0}) ", checkBox3.Text);
            }
            else
            {
                checkBox3.Font = new Font("Cascadia Code", 12F, FontStyle.Regular, GraphicsUnit.Point);
                Text = Text.Replace($"({checkBox3.Text}) ", "");
            }
            if (Text == "")
            {
                Text = "Ejercicio #1";
            }
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox4.Checked == true)
            {
                checkBox4.Font = new Font("Cascadia Code", 12F, FontStyle.Bold, GraphicsUnit.Point);
                if (Text == "Ejercicio #1") Text = string.Format("({0}) ", checkBox4.Text);
                else Text += string.Format("({0}) ", checkBox4.Text);
            }
            else
            {
                checkBox4.Font = new Font("Cascadia Code", 12F, FontStyle.Regular, GraphicsUnit.Point);
                Text = Text.Replace($"({checkBox4.Text}) ", "");
            }
            if (Text == "")
            {
                Text = "Ejercicio #1";
            }
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.Close();
            Menu.Show();
        }
    }
}
