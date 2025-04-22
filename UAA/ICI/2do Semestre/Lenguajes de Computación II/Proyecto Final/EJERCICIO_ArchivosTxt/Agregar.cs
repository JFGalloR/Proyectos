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
    public partial class Agregar : Form
    {
        // Variable para determinar si se pudo agregar el alumno al archivo.
        bool agregado = false;
        public Agregar()
        {
            InitializeComponent();
        }
        // Evento que valida la entrada en la entrada de la ID.
        private void id_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
            }
        }        
        // Evento que especifica los items del segundo comboBox según la opción del primer comboBox.
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            carrera.Items.Clear();
            switch (centroA.SelectedIndex)
            {
                case 0:
                    carrera.Items.Add("Ing. en Agronomía");
                    carrera.Items.Add("Ing. en Alimentos");
                    carrera.Items.Add("Médico Veterinario Zootecnista");
                    break;
                case 1:
                    carrera.Items.Add("Ing. Bioquímica");
                    carrera.Items.Add("Ing. en Computación Inteligente");
                    carrera.Items.Add("Ing. en Electrónica");
                    carrera.Items.Add("Ing. en Sistemas Computacionales");
                    carrera.Items.Add("Ing. Industrial Estadístico");
                    carrera.Items.Add("Ing. en Biología");
                    carrera.Items.Add("Ing. en Biotecnología");
                    carrera.Items.Add("Lic. en Informática y Tec. Comp.");
                    carrera.Items.Add("Lic. en Matemáticas Aplicadas");
                    carrera.Items.Add("Químico Farmacéutico Biólogo");
                    break;
                case 2:
                    carrera.Items.Add("Ing. Automotriz");
                    carrera.Items.Add("Ing. Biomédica");
                    carrera.Items.Add("Ing. en Diseño Mecánico");
                    carrera.Items.Add("Ing. en Energías Renovables");
                    carrera.Items.Add("Ing. en Manufactura y Automatización Industrial");
                    carrera.Items.Add("Ing. Robótica");
                    break;
                case 3:
                    carrera.Items.Add("Lic. en Cultura Física y Deporte");
                    carrera.Items.Add("Lic. en Enfermería");
                    carrera.Items.Add("Lic. en Nutrición");
                    carrera.Items.Add("Lic. en Optometría");
                    carrera.Items.Add("Lic. en Terapia Física");
                    carrera.Items.Add("Médico Cirujano");
                    carrera.Items.Add("Médico Estomatólogo");
                    break;
                case 4:
                    carrera.Items.Add("Arquitectura");
                    carrera.Items.Add("Ing. Civil");
                    carrera.Items.Add("Lic. en Diseño de Interiores");
                    carrera.Items.Add("Lic. en Diseño de Moda en Indumentaria y Textiles");
                    carrera.Items.Add("Lic. en Diseño Gráfico");
                    carrera.Items.Add("Lic. en Diseño Industrial");
                    carrera.Items.Add("Lic. en Urbanismo");
                    break;
                case 5:
                    carrera.Items.Add("Contador Público");
                    carrera.Items.Add("Lic. en Administración de Empresas");
                    carrera.Items.Add("Lic. en Administración de la Producción y Servicios");
                    carrera.Items.Add("Lic. en Administración Financiera");
                    carrera.Items.Add("Lic. en Comercio Internacional");
                    carrera.Items.Add("Lic. en Economía");
                    carrera.Items.Add("Lic. en Gestión Turística");
                    carrera.Items.Add("Lic. en Mercadotecnia");
                    carrera.Items.Add("Lic. en Relaciones Industriales");
                    break;
                case 6:
                    carrera.Items.Add("Lic. en Administración y Gestión Fiscal de PYMES");
                    carrera.Items.Add("Lic. en Agronegocios");
                    carrera.Items.Add("Lic. en Comercio Electrónico");
                    carrera.Items.Add("Lic. en Logística Empresarial");
                    break;
                case 7:
                    carrera.Items.Add("Lic. en Asesoría Psicopedagógica");
                    carrera.Items.Add("Lic. en Ciencias Políticas y Administración Pública");
                    carrera.Items.Add("Lic. en Comunicación Corporativa Estratégica");
                    carrera.Items.Add("Lic. en Comunicación e Información");
                    carrera.Items.Add("Lic. en Derecho");
                    carrera.Items.Add("Lic. en Docencia de Francés y Español como Lenguas Extranjeras");
                    carrera.Items.Add("Lic. en Docencia del Idioma Inglés");
                    carrera.Items.Add("Lic. en Filosofía");
                    carrera.Items.Add("Lic. en Historia");
                    carrera.Items.Add("Lic. en Psicología");
                    carrera.Items.Add("Lic. en Sociología");
                    carrera.Items.Add("Lic. en Trabajo Social");
                    break;
                case 8:
                    carrera.Items.Add("Lic. en Actuación");
                    carrera.Items.Add("Lic. en Artes Cinematográficas y Audiovisuales");
                    carrera.Items.Add("Lic. en Estudios del Arte y Gestión Cultural");
                    carrera.Items.Add("Lic. en Letras Hispánicas");
                    carrera.Items.Add("Lic. en Música");
                    break;
            }
        }
        // Método para validar que se haya puesto la entrada correctamente.
        bool validar()
        {
            bool validacion = true;

            if (string.IsNullOrEmpty(carrera.Text))
            {
                errorProvider1.SetError(carrera, "Ingresa una opción");
                carrera.Focus();
                validacion = false;
            }
            else
            {
                errorProvider1.Clear();
            }

            if (string.IsNullOrEmpty(centroA.Text))
            {
                errorProvider2.SetError(centroA, "Ingresa una opción");
                centroA.Focus();
                validacion = false;
            }
            else
            {
                errorProvider2.Clear();
            }

            if (string.IsNullOrEmpty(nombre.Text))
            {
                errorProvider3.SetError(nombre, "Ingresa Nombre");
                nombre.Focus();
                validacion = false;
            }
            else
            {
                errorProvider3.Clear();
            }

            if (string.IsNullOrEmpty(id.Text))
            {
                errorProvider4.SetError(id, "Ingresa ID");
                id.Focus();
                validacion = false;
            }
            else
            {
                errorProvider4.Clear();
            }

            return validacion;
        }       
        // Evento que se desencadena cunado se presiona el bototn de agregar.
        private void button1_Click(object sender, EventArgs e)
        {
            if (validar())
            {
                Archivo ar = new Archivo();
                if (ar.Agregar(id.Text, nombre.Text, centroA.Text, carrera.Text))
                {
                    agregado = true;
                    this.Close();
                }
            }
            else
            {
                MessageBox.Show("Ingresa datos correctamente.", "Agregar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        // Método encargado de mandar el mensaje según el booleano de determinación.
        void mensaje()
        {
            string mensaje;
            MessageBoxIcon icon;
            if (agregado)
            {
                mensaje = "Alumno agregado correctamente";
                icon = MessageBoxIcon.Asterisk;
            }
            else
            {
                mensaje = "Proceso no completado. Alumno no agregado.";
                icon = MessageBoxIcon.Warning;
            }
            MessageBox.Show(mensaje, "Agregar Alumno", MessageBoxButtons.OK, icon);
        }        
        // Evento que se desencadena cunado se cierra el form.
        private void Agregar_FormClosed(object sender, FormClosedEventArgs e)
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
