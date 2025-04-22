namespace EJERCICIO_RadioButton
{
    public partial class Form1 : Form
    {
        int x, y;
        public Form1()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            x = 640; y = 480;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            x = 800; y = 600;
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            x = 1024; y = 768;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Size = new Size(x, y);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

   
    }
}