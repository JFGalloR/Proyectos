namespace EJERCICIO_JFGR
{
    public partial class Menu : Form
    {
        public Menu()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Ejercicio_1_Click(object sender, EventArgs e)
        {
            Ejercicio1 ejercicio1 = new Ejercicio1();
            this.Hide();
            ejercicio1.Show();
        }

        private void Ejercicio_2_Click(object sender, EventArgs e)
        {
            Ejercicio2 ejercicio2 = new Ejercicio2();
            this.Hide();
            ejercicio2.Show();
        }
        private void Ejercicio_3_Click(object sender, EventArgs e)
        {
            Ejercicio3 ejercicio3 = new Ejercicio3();
            this.Hide();
            ejercicio3.Show();
        }

        private void Ejercicio_1_MouseMove(object sender, MouseEventArgs e)
        {
            Ejercicio_1.ForeColor = Color.White;
            label2.Visible = true;
            label2.Text = "El objetivo es colocar 7 objetos de la clase Button con los dias de la semana. Fijar en los atributos Text de cada botón los días de la semana. Al presionar un botón mostrar en un objeto de la clase Label el día seleccionado.";
        }

        private void Ejercicio_2_MouseMove(object sender, MouseEventArgs e)
        {
            Ejercicio_2.ForeColor = Color.White;
            label2.Visible = true;
            label2.Text = "El objetivo es realizar un formulario que muestre tres objetos de la clase Button, disponer como etiqueta en cada botón los valores 1,2 y 3. Cuando se presiona el botón mostrar en el título del formulario el valor de la etiqueta del botón presionado.";

        }
        private void Ejercicio_3_MouseMove(object sender, MouseEventArgs e)
        {
            Ejercicio_3.ForeColor = Color.White;
            label2.Visible = true;
            label2.Text = "El objetivo es modificar el ejercicio 2 anterior para que se acumulen (Como es texto se van a concatenar) en el título del formulario los valores de los botones presionados.";
        }
        private void Ejercicio_1_MouseLeave(object sender, EventArgs e)
        {
            Ejercicio_1.ForeColor = Color.Black;
            label2.Visible = false;
        }

        private void Ejercicio_2_MouseLeave(object sender, EventArgs e)
        {
            Ejercicio_2.ForeColor = Color.Black;
            label2.Visible = false;
        }

        private void Ejercicio_3_MouseLeave(object sender, EventArgs e)
        {
            Ejercicio_3.ForeColor = Color.Black;
            label2.Visible = false;
        }

        private void Menu_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}