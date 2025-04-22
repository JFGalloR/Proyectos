using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EJERCICIO_ArchivosTxt
{
    public partial class Modificar : Form
    {
        // Variable para eterminar si se pudo modificar el alumno en el archivo.
        bool modificado = false;
        public Modificar()
        {
            InitializeComponent();
            tabControl1.Enabled = false;
            button2.Enabled = false;
        }
        // Evento que valida la entrada en la entrada de la ID.
        private void id_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
            }
        }
        // Evento que valida la entrada en la entrada de la ID a modificar.
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
            }
        }
        // Evento que especifica los items del segundo comboBox según la opción del primer comboBox.
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox2.Items.Clear();
            switch (comboBox1.SelectedIndex)
            {
                case 0:
                    comboBox2.Items.Add("Ing. en Agronomía");
                    comboBox2.Items.Add("Ing. en Alimentos");
                    comboBox2.Items.Add("Médico Veterinario Zootecnista");
                    break;
                case 1:
                    comboBox2.Items.Add("Ing. Bioquímica");
                    comboBox2.Items.Add("Ing. en Computación Inteligente");
                    comboBox2.Items.Add("Ing. en Electrónica");
                    comboBox2.Items.Add("Ing. en Sistemas Computacionales");
                    comboBox2.Items.Add("Ing. Industrial Estadístico");
                    comboBox2.Items.Add("Ing. en Biología");
                    comboBox2.Items.Add("Ing. en Biotecnología");
                    comboBox2.Items.Add("Lic. en Informática y Tec. Comp.");
                    comboBox2.Items.Add("Lic. en Matemáticas Aplicadas");
                    comboBox2.Items.Add("Químico Farmacéutico Biólogo");
                    break;
                case 2:
                    comboBox2.Items.Add("Ing. Automotriz");
                    comboBox2.Items.Add("Ing. Biomédica");
                    comboBox2.Items.Add("Ing. en Diseño Mecánico");
                    comboBox2.Items.Add("Ing. en Energías Renovables");
                    comboBox2.Items.Add("Ing. en Manufactura y Automatización Industrial");
                    comboBox2.Items.Add("Ing. Robótica");
                    break;
                case 3:
                    comboBox2.Items.Add("Lic. en Cultura Física y Deporte");
                    comboBox2.Items.Add("Lic. en Enfermería");
                    comboBox2.Items.Add("Lic. en Nutrición");
                    comboBox2.Items.Add("Lic. en Optometría");
                    comboBox2.Items.Add("Lic. en Terapia Física");
                    comboBox2.Items.Add("Médico Cirujano");
                    comboBox2.Items.Add("Médico Estomatólogo");
                    break;
                case 4:
                    comboBox2.Items.Add("Arquitectura");
                    comboBox2.Items.Add("Ing. Civil");
                    comboBox2.Items.Add("Lic. en Diseño de Interiores");
                    comboBox2.Items.Add("Lic. en Diseño de Moda en Indumentaria y Textiles");
                    comboBox2.Items.Add("Lic. en Diseño Gráfico");
                    comboBox2.Items.Add("Lic. en Diseño Industrial");
                    comboBox2.Items.Add("Lic. en Urbanismo");
                    break;
                case 5:
                    comboBox2.Items.Add("Contador Público");
                    comboBox2.Items.Add("Lic. en Administración de Empresas");
                    comboBox2.Items.Add("Lic. en Administración de la Producción y Servicios");
                    comboBox2.Items.Add("Lic. en Administración Financiera");
                    comboBox2.Items.Add("Lic. en Comercio Internacional");
                    comboBox2.Items.Add("Lic. en Economía");
                    comboBox2.Items.Add("Lic. en Gestión Turística");
                    comboBox2.Items.Add("Lic. en Mercadotecnia");
                    comboBox2.Items.Add("Lic. en Relaciones Industriales");
                    break;
                case 6:
                    comboBox2.Items.Add("Lic. en Administración y Gestión Fiscal de PYMES");
                    comboBox2.Items.Add("Lic. en Agronegocios");
                    comboBox2.Items.Add("Lic. en Comercio Electrónico");
                    comboBox2.Items.Add("Lic. en Logística Empresarial");
                    break;
                case 7:
                    comboBox2.Items.Add("Lic. en Asesoría Psicopedagógica");
                    comboBox2.Items.Add("Lic. en Ciencias Políticas y Administración Pública");
                    comboBox2.Items.Add("Lic. en Comunicación Corporativa Estratégica");
                    comboBox2.Items.Add("Lic. en Comunicación e Información");
                    comboBox2.Items.Add("Lic. en Derecho");
                    comboBox2.Items.Add("Lic. en Docencia de Francés y Español como Lenguas Extranjeras");
                    comboBox2.Items.Add("Lic. en Docencia del Idioma Inglés");
                    comboBox2.Items.Add("Lic. en Filosofía");
                    comboBox2.Items.Add("Lic. en Historia");
                    comboBox2.Items.Add("Lic. en Psicología");
                    comboBox2.Items.Add("Lic. en Sociología");
                    comboBox2.Items.Add("Lic. en Trabajo Social");
                    break;
                case 8:
                    comboBox2.Items.Add("Lic. en Actuación");
                    comboBox2.Items.Add("Lic. en Artes Cinematográficas y Audiovisuales");
                    comboBox2.Items.Add("Lic. en Estudios del Arte y Gestión Cultural");
                    comboBox2.Items.Add("Lic. en Letras Hispánicas");
                    comboBox2.Items.Add("Lic. en Música");
                    break;
            }
        }
        // Método para validar que se haya puesto la entrada correctamente.
        bool validar()
        {
            bool validacion = true;

            if (string.IsNullOrEmpty(id.Text))
            {
                errorProvider1.SetError(id, "Ingresa ID");
                id.Focus();
                validacion = false;
            }
            else
            {
                errorProvider1.Clear();
            }

            return validacion;
        }
        // Método para validar que se haya puesto la entrada correctamente.
        bool validar1()
        {
            bool validacion = true;

            if (string.IsNullOrEmpty(comboBox2.Text))
            {
                errorProvider2.SetError(comboBox2, "Ingresa una opción");
                comboBox2.Focus();
                validacion = false;
            }
            else
            {
                errorProvider2.Clear();
            }

            if (string.IsNullOrEmpty(comboBox1.Text))
            {
                errorProvider3.SetError(comboBox1, "Ingresa una opción");
                comboBox1.Focus();
                validacion = false;
            }
            else
            {
                errorProvider3.Clear();
            }

            if (string.IsNullOrEmpty(textBox2.Text))
            {
                errorProvider4.SetError(textBox2, "Ingresa Nombre");
                textBox2.Focus();
                validacion = false;
            }
            else
            {
                errorProvider4.Clear();
            }

            if (string.IsNullOrEmpty(textBox1.Text))
            {
                errorProvider5.SetError(textBox1, "Ingresa ID");
                textBox1.Focus();
                validacion = false;
            }
            else
            {
                errorProvider5.Clear();
            }

            return validacion;
        }
        // Método que sobreeescribe los valores anteriores en las casillas a rellenar.
        void asignar()
        {
            try
            {
                string[] lineas = File.ReadAllLines("Alumnos_UAA.txt");

                using (StreamWriter sw = new StreamWriter("Alumnos_UAA.txt"))
                {

                    for (int i = 0; i < lineas.Length; i += 5)
                    {
                        if (id.Text == lineas[i])
                        {
                            textBox1.Text = lineas[i];
                            textBox2.Text = lineas[i + 1];
                            comboBox1.Text = lineas[i + 2];
                            comboBox2.Text = lineas[i + 3];

                        }
                        sw.WriteLine(lineas[i]);
                        sw.WriteLine(lineas[i + 1]);
                        sw.WriteLine(lineas[i + 2]);
                        sw.WriteLine(lineas[i + 3]);
                        sw.WriteLine(lineas[i + 4]);
                    }
                }
            }
            catch (IOException)
            {
                MessageBox.Show("No se pudo autocompletar casillas.", "Modificar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        // Evento que se desencadena cuando se busca el alumno.
        private void button1_Click(object sender, EventArgs e)
        {
            tabControl1.Enabled = false;
            button2.Enabled = false;
            textBox1.Text = string.Empty;
            textBox2.Text = string.Empty;
            comboBox1.Text = string.Empty;
            comboBox2.Text = string.Empty;

            if (validar())
            {
                Archivo ar = new Archivo();
                if (ar.Buscar(id.Text))
                {
                    tabControl1.Enabled = true;
                    button2.Enabled = true;
                    asignar();
                }
            }
            else
            {
                MessageBox.Show("Ingresa datos correctamente.", "Modificar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        // Evento que se desencadena cuando se presiona el botón de modificar.
        private void button2_Click(object sender, EventArgs e)
        {
            if (validar1())
            {
                Archivo ar = new Archivo();
                if (ar.Modificar(id.Text, textBox1.Text, textBox2.Text, comboBox1.Text, comboBox2.Text))
                {
                    modificado = true;
                    this.Close();
                }
            }
            else
            {
                MessageBox.Show("Ingresa datos correctamente.", "Modificar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        // Método encargado de mandar el mensaje según el booleano de determinación.
        void mensaje()
        {
            string mensaje;
            MessageBoxIcon icon;
            if (modificado)
            {
                mensaje = "Alumno modificado correctamente";
                icon = MessageBoxIcon.Asterisk;
            }
            else
            {
                mensaje = "Proceso no completado. Alumno no modificado.";
                icon = MessageBoxIcon.Warning;
            }
            MessageBox.Show(mensaje, "Modificar Alumno", MessageBoxButtons.OK, icon);
        }
        // Evento que se desencadena cunado se cierra el form.
        private void Eliminar_FormClosed(object sender, FormClosedEventArgs e)
        {
            mensaje();
        }
        // Evento para dar efecto al botón de salida.
        private void pictureBox2_MouseMove(object sender, MouseEventArgs e)
        {
            pictureBox2.Size = new Size(38, 38);
            pictureBox2.Location = new Point(12, 7);
        }
        // Evento para dar efecto al botón de salida.
        private void pictureBox2_MouseLeave(object sender, EventArgs e)
        {
            pictureBox2.Size = new Size(32, 32);
            pictureBox2.Location = new Point(12, 10);
        }
        // Evento para el botón de salida.
        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
