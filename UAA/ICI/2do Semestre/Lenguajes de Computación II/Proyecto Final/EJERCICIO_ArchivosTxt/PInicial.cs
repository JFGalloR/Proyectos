using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace EJERCICIO_ArchivosTxt
{
    public partial class PantallaInicial : Form
    {
        public PantallaInicial()
        {
            InitializeComponent();
        }
        // Evento encargado de dar efecto al los botones.
        private void button_MouseMove(object sender, MouseEventArgs e)
        {
            Button button = (Button)sender;

            button.ForeColor = Color.Black;
            button.Font = new Font("Leelawadee", 14F, FontStyle.Bold, GraphicsUnit.Point);
        }
        // Evento encargado de dar efecto al los botones.
        private void button_MouseLeave(object sender, EventArgs e)
        {
            Button button = (Button)sender;

            button.ForeColor = Color.FromArgb(36, 44, 88);
            button.Font = new Font("Leelawadee", 12F, FontStyle.Regular, GraphicsUnit.Point);
        }
        // Evento que se desencadena al pulsqar el botón #1.
        private void button1_Click(object sender, EventArgs e)
        {
            Agregar agregar = new Agregar();
            agregar.ShowDialog();
        }
        // Evento que se desencadena al pulsqar el botón #2.
        private void button2_Click(object sender, EventArgs e)
        {
            string[] lineas = File.ReadAllLines("Alumnos_UAA.txt");

            if (lineas.Length == 0)
            {
                MessageBox.Show("No hay alumnos registrados.", "Eliminar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                Eliminar eliminar = new Eliminar();
                eliminar.ShowDialog();
            }
        }
        // Evento que se desencadena al pulsqar el botón #3.
        private void button3_Click(object sender, EventArgs e)
        {
            string[] lineas = File.ReadAllLines("Alumnos_UAA.txt");

            if (lineas.Length == 0)
            {
                MessageBox.Show("No hay alumnos registrados.", "Modificar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                Modificar modificar = new Modificar();
                modificar.ShowDialog();
            }
        }
        // Evento que se desencadena al pulsqar el botón #4.
        private void button4_Click(object sender, EventArgs e)
        {
            string[] lineas = File.ReadAllLines("Alumnos_UAA.txt");

            if (lineas.Length == 0)
            {
                MessageBox.Show("No hay alumnos registrados.", "Consultar Alumno", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                Consultar consultar = new Consultar();
                consultar.ShowDialog();
            }
        }
        // Evento para el botón de salida.
        private void pictureBox4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        // Evento para dar efecto al botón de salida.
        private void pictureBox4_MouseMove(object sender, MouseEventArgs e)
        {
            pictureBox4.Size = new Size(38, 38);
            pictureBox4.Location = new Point(12, 7);
        }
        // Evento para dar efecto al botón de salida.
        private void pictureBox4_MouseLeave(object sender, EventArgs e)
        {
            pictureBox4.Size = new Size(32, 32);
            pictureBox4.Location = new Point(12, 10);

        }
    }
}