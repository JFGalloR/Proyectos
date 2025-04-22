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
    public partial class Eliminar : Form
    {
        // Variable para determinar si se pudo eliminar el alumno del archivo.
        bool eliminado = false;
        public Eliminar()
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
        // Evento que se desencadena cunado se presiona el bototn de eliminar.
        private void button1_Click(object sender, EventArgs e)
        {
            if (validar())
            {
                Archivo ar = new Archivo();
                if (ar.Eliminar(id.Text))
                {
                    eliminado = true;
                    this.Close();
                }
            }
            else
            {
                MessageBox.Show("Ingresa datos correctamente.", "Eliminar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        // Método encargado de mandar el mensaje según el booleano de determinación.
        void mensaje()
        {
            string mensaje;
            MessageBoxIcon icon;
            if (eliminado)
            {
                mensaje = "Alumno eliminado correctamente";
                icon = MessageBoxIcon.Asterisk;
            }
            else
            {
                mensaje = "Proceso no completado. Alumno no eliminado.";
                icon = MessageBoxIcon.Warning;
            }
            MessageBox.Show(mensaje, "Eliminar Alumno", MessageBoxButtons.OK, icon);
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
