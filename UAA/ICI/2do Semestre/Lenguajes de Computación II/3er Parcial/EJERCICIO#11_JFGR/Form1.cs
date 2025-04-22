namespace EJERCICIO_IngresarDatos
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsLetter(e.KeyChar) && !char.IsControl(e.KeyChar) && e.KeyChar != ' ')
            {
                e.Handled = true;
            }
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsLetter(e.KeyChar) && !char.IsControl(e.KeyChar) && e.KeyChar != ' ')
            {
                e.Handled = true;
            }
        }

        private void textBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != '\b')
            {
                e.Handled = true;
            }
        }

        bool verificar()
        {
            if (textBox1.Text == string.Empty || textBox2.Text == string.Empty || textBox3.Text == string.Empty ||
                comboBox1.Text == string.Empty || radioButton1.Checked == false && radioButton2.Checked == false ||
                radioButton3.Checked == false && radioButton4.Checked == false || checkBox1.Checked == false &&
                checkBox2.Checked == false && checkBox3.Checked == false)
            { return true; }
            else
            { return false; }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (verificar()) { MessageBox.Show("Faltan Datos", "Advertencia", MessageBoxButtons.OK, MessageBoxIcon.Exclamation); }
            else
            {
                string mensaje;
                string genero;
                string consulta;
                string presenta = string.Empty;

                if (radioButton1.Checked) { genero = radioButton1.Text; }
                else { genero = radioButton2.Text; }

                if (radioButton3.Checked) { consulta = radioButton3.Text; }
                else { consulta = radioButton4.Text; }

                if (checkBox1.Checked) { presenta = string.Format($"    >{checkBox1.Text}\n"); }
                if (checkBox2.Checked) { presenta += string.Format($"    >{checkBox2.Text}\n"); }
                if (checkBox3.Checked) { presenta += string.Format($"    >{checkBox3.Text}\n"); }

                mensaje = string.Format("=============== HISTORIAL DEL PACIENTE ==============\n\n\n" +
                                        "El paciente ingresado se llama {0} {1} de {2} años de edad. " +
                                        "Vive en {3}. " + "Es de género {4}. " + "Ingreso por {5}.\n\n" +
                                        "Presenta:\n\n{6}" +
                                        "\n\n=============================================="
                                        , textBox1.Text, textBox2.Text, textBox3.Text, comboBox1.Text, genero, consulta, presenta);
                MessageBox.Show(mensaje, "PACIENTE", MessageBoxButtons.OK);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}