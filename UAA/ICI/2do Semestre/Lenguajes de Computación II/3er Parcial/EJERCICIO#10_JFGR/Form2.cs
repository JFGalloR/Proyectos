using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EJERCICIO_Fomrs
{
    public partial class Form2 : Form
    {
        Form1 form1;
        public Form2(Form1 form1, string txt)
        {
            InitializeComponent();
            this.form1 = form1;
            label3.Text = txt;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
            form1.Show();
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            form1.Show();
        }
    }
}
