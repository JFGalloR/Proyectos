namespace EJERCICIO_ComboBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_MouseMove(object sender, MouseEventArgs e)
        {
            label3.Text = "Cargar en un ComboBox los nombres de varios colores. \r\nAl seleccionar alguno mostrar en la barra de título del \r\nForm el string seleccionado.\r\n";
        }

        private void button1_MouseLeave(object sender, EventArgs e)
        {
            label3.Text = string.Empty;
        }

        private void button2_MouseMove(object sender, MouseEventArgs e)
        {
            label3.Text = "Al presionar un botón pintar el fondo del Form con\r\nel color que se genera combinando los valores de los \r\nComboBox.";
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