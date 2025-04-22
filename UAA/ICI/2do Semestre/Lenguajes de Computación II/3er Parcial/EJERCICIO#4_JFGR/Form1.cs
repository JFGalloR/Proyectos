using Microsoft.VisualBasic.ApplicationServices;
using System;
using System.DirectoryServices;
using System.Drawing;
using System.Globalization;
using System.Numerics;

namespace EJUERCICIO_JFGR
{
    public partial class Calculadora : Form
    {
        bool cambio = true, operacion = false, operando = false, bloquear = false;
        double num1 = 0, num2 = 0;
        string operador = string.Empty;
        public Calculadora()
        {
            InitializeComponent();
        }

        private void Ce_btn_Click(object sender, EventArgs e)
        {
            textBox1.Text = string.Empty;
        }

        private void C_btn_Click(object sender, EventArgs e)
        {
            label1.Text = string.Empty;
            textBox1.Text = string.Empty;
            num1 = 0;
            num2 = 0;
            operador = string.Empty;
            cambio = true; operacion = false; operando = false; bloquear = false;
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '\b' && e.KeyChar != '.')
            {
                e.Handled = true;
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            int index = textBox1.Text.Length - 1;

            if (textBox1.Text.Replace(".", "").Length < textBox1.Text.Length - 1)
            {
                textBox1.Text = textBox1.Text.Remove(index);
                textBox1.SelectionStart = textBox1.Text.Length;
            }
            if (textBox1.Text.Replace(".", "").Length > 12)
            {
                textBox1.Text = textBox1.Text.Remove(index);
                MessageBox.Show("Números válidos de hasta 12 dígitos.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                textBox1.SelectionStart = textBox1.Text.Length;
            }
            switch (textBox1.Text.Length)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                    textBox1.Font = new Font("Cascadia Code", 50, FontStyle.Bold, GraphicsUnit.Point);
                    break;
                case 9:
                    textBox1.Font = new Font("Cascadia Code", 45, FontStyle.Bold, GraphicsUnit.Point);
                    break;
                case 10:
                    textBox1.Font = new Font("Cascadia Code", 40, FontStyle.Bold, GraphicsUnit.Point);
                    break;
                case 11:
                    textBox1.Font = new Font("Cascadia Code", 36, FontStyle.Bold, GraphicsUnit.Point);
                    break;
                case 12:
                    textBox1.Font = new Font("Cascadia Code", 33, FontStyle.Bold, GraphicsUnit.Point);
                    break;
                case 13:
                    textBox1.Font = new Font("Cascadia Code", 31, FontStyle.Bold, GraphicsUnit.Point);
                    break;
            }
        }

        private void igual_Click(object sender, EventArgs e)
        {
            if (operador != string.Empty)
            {
                num2 = Convert.ToDouble(textBox1.Text);
                if (CalculatorProcess().ToString().Length > 12)
                {

                    textBox1.Text = CalculatorProcess().ToString("0.00E+0");
                }
                else
                {
                    textBox1.Text = CalculatorProcess().ToString();
                }
                if (operacion)
                {
                    label1.Text += num2 + " = ";
                    num1 = num2;
                }
                else
                {
                    label1.Text = num2 + " " + operador + " " + num1 + " = ";
                }
                cambio = true;
                operacion = false;
                operando = false;
            }
        }
        private void ButtonNumero_Click(object sender, EventArgs e)
        {
            Button boton = (Button)sender;
            if (!operacion)
            {
                C_btn_Click(sender, e);
                operacion = true;
            }
            if (cambio)
            {
                textBox1.Text = boton.Text;
                cambio = false;
            }
            else
            {
                textBox1.Text += boton.Text;
            }

            bloquear = false;
        }
        private void ButtonOperador_Click(object sender, EventArgs e)
        {
            Button boton = (Button)sender;
            if (textBox1.Text != string.Empty)
            {
                if (!bloquear)
                {
                    if (operando)
                    {

                        num2 = Convert.ToDouble(textBox1.Text);
                        num2 = CalculatorProcess();
                        if (CalculatorProcess().ToString().Length > 12)
                        {
                            textBox1.Text = num2.ToString("0.00E+0");
                        }
                        else
                        {
                            textBox1.Text = num2.ToString();
                        }
                        num1 = num2;
                    }
                    else
                    {
                        num1 = Convert.ToDouble(textBox1.Text);
                    }
                }
                operador = boton.Text;
                label1.Text = num1 + " " + operador + " ";
                bloquear = true;
                cambio = true;
                operando = true;
                operacion = true;
            }
        }

        private double CalculatorProcess()
        {
            double resultado = 0;

            switch (operador)
            {
                case "+":
                    resultado = num1 + num2;
                    break;
                case "-":
                    resultado = num1 - num2;
                    break;
                case "*":
                    resultado = num1 * num2;
                    break;
                case "/":
                    if (num2 != 0)
                    {
                        resultado = Math.Round(num1 / num2, 2);
                    }
                    else
                    {
                        MessageBox.Show("Error: No se puede dividir por cero", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                    break;
            }
            if (num1 == 420 && num2 == num1)
            {
                Icon icono = new Icon("C:\\Users\\xxjfg\\Desktop\\EJERCICIO_JFGR_1\\planta.ico");
                Icon = icono;
            }
            return resultado;
        }
    }
}