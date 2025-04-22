/*======================================================================
    EJERCICIO INTEGRADOR. Archivos Text.
  --------------------------------------------------------------------
    OBJETIVO:
    Realizar un programa que permita al usuario crear un archivo txt,
    en el cual podrá ingresar mediante un Textbox multiline cualquier 
    carácter o texto tecleado por el usuario, además contendrá 3 
    botones, uno para crear el archivo y enviar la información del 
    textbox al archivo txt, otro para eliminar el archivo de texto y 
    por último otro para imprimir la información. 
  --------------------------------------------------------------------
    ELABORADOR:
        > Juan Francisco Gallo Ramírez
  --------------------------------------------------------------------
    02 de Junio de 2023.
    UAA. I.C.I.
======================================================================*/


namespace Práctica_Archivos_Txt
{
    public partial class Form1 : Form
    {
        bool modificar = false;
        public Form1()
        {
            InitializeComponent();
        }
        // Botón de agregar.
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBox1.Text != string.Empty)
                {
                    using (StreamWriter sw = new StreamWriter("Texto.txt", true))
                    {
                        sw.WriteLine(textBox1.Text);
                        MessageBox.Show("Texto agregado correctametne.", "Archivo Text", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                        textBox1.Text = string.Empty;
                    }
                }
                else
                {
                    MessageBox.Show("Ingresa texto.", "Archivo Text", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    textBox1.Focus();
                }
            }
            catch(Exception) 
            {
                MessageBox.Show("No se pudo agregar el texto.", "Archivo Text", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            
        }
        // Botón de eliminar.
        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = string.Empty;
            try
            {
                string[] texto = File.ReadAllLines("Texto.txt");

                if (texto.Length > 0)
                {
                    StreamWriter sw = new StreamWriter("Texto.txt");
                    sw.Close();
                    MessageBox.Show("Texto eliminado correctametne.", "Archivo Text", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                }
                else
                {
                    MessageBox.Show("No hay texto que eliminar.", "Archivo Text", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            catch (Exception)
            {
                MessageBox.Show("No se pudo eliminar el texto.", "Archivo Text", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            textBox1.Focus();
        }
        // Botón de consultar.
        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text = string.Empty;
            string[] texto = File.ReadAllLines("Texto.txt");

            if(texto.Length > 0)
            {
                foreach (string linea in texto)
                {
                    textBox1.Text += linea;
                }
                modificar = false;
            }
            else
            {
                MessageBox.Show("No hay texto que mostrar.", "Archivo Text", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        // evento que elimina el texto en textBox para evitar mandar el mismo textoa agregar.
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(!modificar)
            {
                textBox1.Text = string.Empty;
                modificar = true;
            }
        }
    }
}