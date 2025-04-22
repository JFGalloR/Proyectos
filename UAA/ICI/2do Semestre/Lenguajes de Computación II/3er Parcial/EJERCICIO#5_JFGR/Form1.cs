namespace EJERCICIO_JFGR
{
    public partial class Form1 : Form
    {
        const string contraseña = "abc123";
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (label2.Text != string.Empty)
            {
                label2.Text = string.Empty;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            switch (textBox1.Text)
            {
                case "":
                    label2.ForeColor = Color.Red;
                    label2.Text = "Ingresa contraseña";
                    break;
                case contraseña:
                    label2.ForeColor = Color.Green;
                    label2.Text = "Contraseña correcta";
                    break;
                default:
                    label2.ForeColor = Color.Red;
                    label2.Text = "Contraseña incorrecta";
                    break;
            }
            textBox1.Focus();
            textBox1.SelectAll();
        }

        private void button2_MouseDown(object sender, MouseEventArgs e)
        {
            textBox1.UseSystemPasswordChar = false;
        }

        private void button2_MouseUp(object sender, MouseEventArgs e)
        {
            textBox1.UseSystemPasswordChar = true;
            textBox1.Focus();
        }
    }
}