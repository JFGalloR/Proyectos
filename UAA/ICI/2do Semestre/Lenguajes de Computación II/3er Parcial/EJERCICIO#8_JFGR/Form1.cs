﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejercicio
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Text = String.Empty;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(textBox1.Text != String.Empty && comboBox1.Text != String.Empty)
            {
                Text = String.Format("{0} | {1}", textBox1.Text, comboBox1.Text);
            }
        }
    }
}
