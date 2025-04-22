namespace EJERCICIO_Fomrs
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == string.Empty)
            {
                label3.Text = "Ingresa un mensaje!!!";
                textBox1.Focus();
            }
            else
            {
                this.Hide();
                Form2 form2 = new Form2(this, textBox1.Text);
                form2.Show();
                textBox1.Text = string.Empty;
                textBox1.Focus();
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (label3.Text != string.Empty)
            {
                label3.Text = string.Empty;
            }
        }
    }
}