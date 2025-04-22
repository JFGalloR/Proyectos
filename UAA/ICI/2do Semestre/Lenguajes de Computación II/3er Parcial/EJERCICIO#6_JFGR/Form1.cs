using System.Windows.Forms.VisualStyles;

namespace EJERCICIO_CheckBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_MouseMove(object sender, MouseEventArgs e)
        {
            label3.Text = "Programa que muestra 3 objetos de la clase CheckBox \r\ncon etiquetas de tres idiomas.";
        }

        private void button1_MouseLeave(object sender, EventArgs e)
        {
            label3.Text = string.Empty;
        }

        private void button2_MouseMove(object sender, MouseEventArgs e)
        {
            label3.Text = "Programa que muestra un objeto CheckBox para simular \r\naceptar condiciones.";
        }

        private void button2_MouseLeave(object sender, EventArgs e)
        {
            label3.Text = string.Empty;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 Ejercicio_1 = new Form2(this);
            this.Hide();
            Ejercicio_1.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form3 Ejercicio_2 = new Form3(this);
            this.Hide();
            Ejercicio_2.ShowDialog();
        }
    }
}